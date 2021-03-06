int query_prevent_shadow() { return 1; }

/* beware editing this file.
 * Make sure you know what you are doing.  stuffing this up could be
 * fatal in some ways.
 */
mixed members;
mapping access;

void create() {
  int i;
  mapping map;

  members = ([ ]);
  access = ([ ]);
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
  restore_object(file_name(this_object()));
  if (pointerp(members)) {
    map = ([ ]);
    for (i=0;i<sizeof(members);i++)
      map[members[i]] = "newbie";
    members = map;
  }
} /* create() */

void save_me() {
  seteuid((string)"/secure/master"->get_root_uid());
  save_object(file_name(this_object()));
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
} /* save_me() */

string query_lord() { return LORD; }

int add_permission(string euid, string path, int mask) {
  if (previous_object() != find_object("/secure/master"))
    return 0;
  if (!access[path])
    access[path] = ([ euid: mask ]);
  else
    access[path][euid] |= mask;
  save_me();
  return 1;
} /* add_permission() */

int remove_permission(string euid, string path, int mask) {
  if (previous_object() != find_object("/secure/master"))
    return 0;
  if (!access[path])
    return 0;
  if (!access[path][euid])
    return 0;
  access[path][euid] &= mask;
  if (!access[path][euid])
    map_delete(access[path], euid);
  if (!sizeof(access[path]))
    map_delete(access, path);
  save_me();
  return 1;
} /* remove_permission() */

int check_permission(string euid, string *path, int mask) {
  int i;
  string p;

  if (euid == LORD) return 1;
  p = "/"+path[0];
  for (i=1;i<sizeof(path);i++) {
    p = p+"/"+path[i];
    if (access[p] && (access[p][euid] & mask))
      return 1;
  }
  return 0;
} /* check_permission() */

/*
 * Please note, the following functions only set up defaults.
 * This is all over ridden by the permission code above which is
 * called first.
 * Same goes for valid_write.
 */
int valid_read(string *path, string euid, string funct) {
  int i;

/* to make this house open... Uncomment the next line
 * return 1;
 */
  if (euid == "Dom: "+DOMAIN) return 1;
  if (euid == query_lord())
    return 1;
  return (members[euid] != 0);
} /* valid_read() */

int valid_write(string *path, string euid, string funct) {
  int i;
  
  if (euid == query_lord())
    return 1;
  if (path[2] == "master" || path[2] == "master.c" || path[2] == "master.o")
    return 0;
  if (euid == "Dom: "+DOMAIN) return 1;
/*
 * Blue..  Uncomment this if you want all your creators to have
 * write everywhere in the domain.
  return (members[euid] != 0);
 */
  return 0;
} /* valid_write() */

void dest_me() {
  destruct(this_object());
} /* dest_me() */

/* please note the + ({ })... this is for security reasons.
 * If you don't do this the members of your house can be changed at will
 * by any other wizard.
 */
string *query_members() { return keys(members) + ({ }); }

int add_member(string name) {
/* only the lord of the domain can add members to it.
 * BTW... change this if you want, it is a bit constrictive but handy as
 * a start point
 */
  if(geteuid(this_player(1)) != query_lord()) return 0;
  if(members[name]) return 0;
  members[name] = "newbie";
  save_me();
  return 1;
} /* add_member() */

int query_member(string name) {
  return !undefinedp(members[name]) || name == LORD;
} /* query_member() */

int remove_member(string name) {
  int i;
/* see above comment...
 */
  if(geteuid(this_player(1)) != query_lord()) return 0;
  if(!members[name]) return 0;
  members = m_delete(members, name);
  save_me();
  return 1;
} /* remove_member() */

int set_project(string name, string pro) {
  if(geteuid(this_player(1)) != query_lord()) return 0;
  if(!members[name]) return 0;
  if(!pro || pro == "") pro = "project unset";
  members[name] = pro;
  save_me();
  return 1;
} /* set_project() */

string query_project(string name) {
  if (!members[name])
    return "project unset";
  return members[name];
} /* query_project() */

void smart_log(string error, string where) {
  write_file("d/"+DOMAIN+"/player_reports", error);
} /* smart_log() */

string log_who(string where) {
  return LORD;
} /* log_who() */

mapping query_access() { return access; }
