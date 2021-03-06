inherit "std/object";

/*
 * ok format...
 * name ({ your st, everyone st })
 * or (one arg version ie sigh)
 * name ({ your st, their st, everyone st })
 * or (two only arg version.)
 * name ({ your st, everyone st, arg st, their arg, everyone arg })
 * or (one or two arg version)
 * name ({ ({ as above }), ({ as above }) })
 * for cases where the male and female versions are different.
 * works on targets gender. should really be the two arg only version.
 * hmmm going to need some actual processing.
 *
 * 0 == search for living name
 * 1 == search for living name and change thingy
 * 2 == search for change thingy and living name
 * 3 == search for change thingy
 */

mapping soul_data;
string  lastarg, calc_long,
        global_adj;

mapping query_soul_data() { return soul_data + ([ ]); }
 
create() {
  ::create();
  set_name("soul");
  set_short(0);
  move("/room/void");
  global_adj = ",slowly,happily,sadly,nervously,wryly,broadly,crookedly,"+
         "imaginatively,"+
	  "stupidly,idiotically,condescendingly,ironically,patiently,brightly,"+
	"slightly,nastily,excitedly,strangely,with forced patience,plasticly,"+
	  "carefully,sadistically,lopsidedly,fishily,catishly,faintly,"+
	  "like a train,angrily,paranoically,innocently,frogily,slyly,"+
	  "weakly,humbly,paradoxicaly,sarcastically,viciously,garishly,"+
          "sweetly,innocently,lovingly,dreamily,radiantly,enthusiastically,"+
	  "insolently,quirkily,completely,unconsciously,drunkenly,"+
          "insanely,cutely,maliciously,maybe,fleetingly,"+
	  "absentmindedly,curtly,disturbingly,unbeliveably,quietly,"+
	  "loudly,differently,winningly,in triumph,seductively,"+
          "tightly,gosh there are lots of arguments,softly,"+
          "lividly,demonically,warmly,coldly,"+
          "spasmodically,incandecently,pleasantly,with menace,"+
	  "manically,warily,sardonically,lazily,serenely,disappointedly";
  soul_data =
([ 
  "ack" : ({ ({ 0, "%s", 0, "at %s" }),
           ({ "You ack$ifarg: $arg:seductively,happily,carefully$~$",
              "$mcname$ ack's$ifarg: $lastarg$~$",
              "You ack$ifarg: $arg:seductively,happily,carefully$~$ at "+
                      "$hcname$",
              "$mcname$ ack's$ifarg: $lastarg$~$ at you",
              "$mcname$ ack's$ifarg: $lastarg$~$ at $hcname$", }) }),
  "accuse" : ({ ({ 0, "%s", 2, "%s of %s", 2, "%s %s", 3, "%s" }), ({
      "$ifarg:You accuse $arg:#$$else$The buttler did it!~$", 
      "$mcname$ $ifarg:accuses $lastarg$$else$accuses the butler~$",
      "You accuse $hcname$$ifarg: of $arg:#$~$",
      "$mcname$ accuses you$ifarg: of $lastarg$~$",
      "$mcname$ accuses $hcname$$ifarg: of $lastarg$~$" }) }),
  "admire" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You admire $hcname$$ifarg: $arg:from afar,#$~$",
      "$mcname$ admires you$ifarg: $lastarg$~$",
      "$mcname$ admires $hcname$$ifarg: $lastarg$~$", }), }),
  "apologize" : ({
      ({ 3, "%s", 1, "%s to %s", 1, "%s %s", 2, "%s %s", }), ({
	  "You apologize $arg:profusely,happily,sadly,reservedly,"+
	  "carefully,slowly,perfunctorily,curtly,visciously,"+
	  "sulkily,drunkenly,unhappily,professionaly,pompously,"+
	  "wholeheartedly,partially,wearily,fishily,facetiously,"+
	  "unnecessarily,spontaneously,twice,thoroughly,humbly$",
	    "$mcname$ apologizes $lastarg$",
	  "You apologize $arg:profusely,happily,sadly,reservedly,"+
	  "carefully,slowly,perfunctorily,curtly,visciously,"+
	  "sulkily,drunkenly,unhappily,professionaly,pompously,"+
	  "wholeheartedly,partially,wearily,fishily,facetiously,"+
	  "unnecessarily,spontaneously,twice,thoroughly,humbly$"+
	  "to $hcname$",
	    "$mcname$ apologizes $lastarg$ to you",
	    "$mcname$ apologizes $lastarg$ to $hcname$" }) }),
  "applaud" : ({
      ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
	  "You applaud $arg:wholeheartedly,loudly,softly,vaguely,briefly$",
	  "$mcname$ applauds $lastarg$",
	  "You applaud $hcname$ $arg:wholeheartedly,loudly,softly,vaguely,briefly$",
	  "$mcname$ applauds you $lastarg$",
	  "$mcname$ applauds $hcname$ $lastarg$" }) }),
  "astound" : ({ ({ 0, "%s" }), ({
      "You are astounded!",
      "$mcname$ is astounded!",
      "You astound $hcname$$ifarg:with your $arg:stupidity,cleverness"+
      ",thoughtfulness$~$!",
      "$mcname$ astounds you$ifarg: with $mposs$ $lastarg$~$!",
      "$mcname$ astounds $hcname$$ifarg: with $mposs$ $lastarg$~$" }) }),
  "agree" : ({ ({ 0, "%s", 0, "with %s", 1, "%s with %s", 1, "%s %s",
                  2, "with %s %s", 3, "%s" }), ({
      "You agree $arg:wholeheartedly,partially,wearily$",
      "$mcname$ agrees $lastarg$",
      "You agree $arg:wholeheartedly,partially,wearily$ with $hcname$",
      "$mcname$ agrees $lastarg$ with you",
      "$mcname$ agrees $lastarg$ with $hcname$" }) }),
  "bark" : ({ ({ 3, "%s" }), ({
      "You bark like a $arg:dog,cat,tree,wolf,hunting dog,labrador,"+
            "german shepard,something else that barks,"+
	    "bull terrier,train$",
	"$mcname$ barks like a $lastarg$", }) }),
  "beam" : ({ ({ 3, "%s", 1, "%s at %s", 1, "%s %s", 2, "at %s %s",
             2, "%s %s", 0, "%s" }), ({
      "You beam $arg:brightly,admiringly,strangely,hapilly,ecstaticlly,fishily,"+
           "like a train$",
      "$mcname$ beams $lastarg$",
      "You beam at $hcname$$ifarg: $arg:brightly,admiringly,strangely,hapilly,"+
           "ecstaticlly,fishily,like a train$~$",
      "$mcname$ beams at you$ifarg: $lastarg$~$",
      "$mcname$ beams at $hcname$$ifarg: $lastarg$~$", }) }),
  "beep" : ({ ({ 3, "%s" }), ({
      "You beep $arg:happily,#$",
      "$mcname$ beep $arg:happily,#$" }) }),
  "beg" : ({ ({
      0, "at %s", 0, "%s", 2, "at %s %s", 2, "at %s like a %s",
      1, "like a %s at %s", 1, "%s at %s", 1, "%s %s", 1, "%s %s",
      3, "%s", 3, "like a %s", }), ({
	  "You beg like a $arg:dog,cat,frog,chicken,frisbee,cow,large bear,"+
	  "poodle,chihuahua,train,beggar,noble man,lassie,labrador,german shepard,"+
	  "cannibal,chimpanzee,orang-u-tang,librarian,fish,dolphin,tokzic,"+
	  "banshi,bloodhound,st bernard,virgin mary,husky,wolf,dingo,alsation$",
	  "$mcname$ begs like a $lastarg$",
	  "You beg like a $arg:dog,cat,frog,chicken,frisbee,cow,large bear,"+
	  "poodle,chihuahua,train,beggar,noble man,lassie,labrador,german shepard,"+
	  "cannibal,chimpanzee,orang-u-tang,librarian,fish,dolphin,tokzic,"+
	  "banshi,bloodhound,st bernard,virgin mary,husky,wolf,dingo,alsation,"+
	  "train$ at $hcname$",
	  "$mcname$ begs like a $lastarg$ at you",
	  "$mcname$ begs like a $lastarg$ at $hcname$", }) }),
  "bing" : ({ ({ 0, "at %s", 0, "%s", 1, "%s at %s", 1, "%s %s", 2, "%s %s",
                 2, "at %s %s", 3, "%s" }), ({
      "You bing $arg:happily,sadly,joyfully,sagely,knowingly,quickly,"+
           "loudly,carefully,balefully,excitedly,nervously,brightly,"+
           "uncertainly,threateningly,grumpily$",
      "$mcname$ bings $lastarg$",
      "You bing $arg:happily,sadly,joyfully,sagely,knowingly,quickly,"+
           "excitedly,nervously,brightly,uncertainly,grumpily,"+
           "loudly,carefully,balefully,threateningly$ at $hcname$",
      "$mcname$ bings $lastarg$ at you",
      "$mcname$ bings $lastarg$ at $hcname$" }) }),
  "bingf" : ({ ({ 0, "at %s", 0, "%s", 1, "%s at %s", 1, "%s %s", 2, "%s %s",
                  2, "at %s %s", 3, "%s" }), ({
      "You bing in a $arg:sarcasticaly,sadly,joyfully,sagely,knowingly,"+
           "quickly,"+
           "loudly,carefully,balefully,excitedly,nervously,brightly,"+
           "uncertainly$ but formatted way",
      "$mcname$ bings in a $lastarg$ but formatted way",
      "You bing in a $arg:sarcasticaly,sadly,joyfully,sagely,knowingly,"+
           "quickly,"+
           "loudly,carefully,balefully,excitedly,nervously,brightly,"+
           "uncertainly$ but formatted way with $hcname$",
      "$mcname$ bings in a $lastarg$ but formatted way with you",
      "$mcname$ bings in a $lastarg$ but formatted way with $hcname$", }) }),
  "bird" : ({ ({ 0, "%s" }), ({
      "You raise your middle finger and give $hcname$ the bird",
      "$mcname$ raises $mposs$ middle finger and gives you the bird",
      "$mcname$ raises $mposs$ middle finger and gives $hcname$ the bird" }) }),
  "bite" : ({ ({ 0, "%s", 2, "%s %s", 1, "%s %s" }), ({
      "You bite yourself",
      "$mcname$ bites $mobj$self",
      "You bite $hcname$$ifarg: $arg:hard,nastily,carefuly,politely,fishily,"+
           "lovingly,refreshingly,happily,like a train,pointlessly,"+
          "thoughtfully,"+
           "objectively,sulkily,gently,brightly,excitedly,uncertainly,"+
           "like a dog,wolfishly,mercilessly,ruthlessly,softly,sweetly,"+
           "professionaly,hungrily,mischieviously,ankles,arm,leg,casualy,"+
           "nose,ear,toe,finger$~$",
      "$mcname$ bites you$ifarg: $lastarg$~$",
      "$mcname$ bites $hcname$$ifarg: $lastarg$~$", }) }),
  "blame" : ({ ({ 0, "%s", 2, "%s for %s", 2, "%s %s", 1, "%s %s" }), ({
      "You blame $hcname$$ifarg: for $arg:#$~$",
      "$mcname$ blames you$ifarg: for $lastarg$~$",
      "$mcname$ blames $hcname$$ifarg: for $lastarg$~$", }), }),
  "bleat" : ({ ({ 3, "%s", }), ({
      "You bleat $arg:like a lamb,helplessly,sadly,painfully,quietly,"+
           "rapidly,slowly,for breakfast$",
      "$mcname$ bleats $lastarg$" }), }),
  "bleed" : ({ ({ 3, "%s" }), ({
      "$ifarg:Your $arg:heart,leg,arm,head,ear,nose,profusely"+
      "$ bleeds$else$You bleed~$",
      "$ifarg:$mcname$'s $lastarg$ bleeds$else$$mcname$ bleeds~$", }) }),
  "blink" : ({ ({ 3, "%s" }), ({
      "You blink$ifarg: $arg:owlishly,slowly,carefully$~$",
      "$mcname$ blinks$ifarg: $lastarg$~$" }) }),
  "blush" : ({ ({ 3, "%s" }), ({
      "You blush $arg:in embarassment,redly,comfortably,slightly,worriedly$",
      "$mcname$ blushes $lastarg$" }) }),
  "boggle" : ({ ({ 3, "%s", 0, "at %s", 0, "%s" }), ({
      "You boggle at $arg:the concept,#$", "$mcname$ boggles at $lastarg$",
      "You boggle at $hcname$",
      "$mcname$ boggles at you",
      "$mcname$ boggles at $hcname$", }) }),
  "bonk" : ({ ({ 0, "%s" }), ({
      "B O N K !",
      "$mcname$ goes B O N K !",
      "You bonk $hcname$ on the $arg:head,arm,elk,cabbage$",
      "$mcname$ bonks you on the $lastarg$",
      "$mcname$ bonks $hcname$ on the $lastarg$" }) }),
  "bop" : ({ ({ 0, "%s" }), ({
      "You bop to the beat",
      "$mcname$ bops to the beat",
      "You bop $hcname$ on the head", 
      "$mcname$ bops you on the head",
      "$mcname$ bops $hcname$ on the head" }) }),
  "bounce" : ({ ({ 0, "%s", 1, "%s around %s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "$ifarg:You bounce around $arg:excitedly,fearfully,happily$"+
      "$else$B O U N C E ! !~$",
      "$mcname$ bounces around$ifarg: $lastarg$~$",
      "You bounce around $hcname$$ifarg: $arg:happily,carefully,wildly,"+
         "excitedly,pinkly,joyfully,once,slowly,suggestively,viciously"+
         "sarcasticaly,"+
         "happily,womblely$~$",
      "$mcname$ bounces around you$ifarg: $lastarg$~$",
      "$mcname$ bounces around $hcname$$ifarg: $lastarg$~$", }) }),
  "breakdance" : ({ 0, ({
      "You do a really complicated break-dance manouvre",
      "$mcname$ does a really complicated-break dance manouvre", }) }),
  "breathe" : ({ ({ 3, "%s", }), ({
      "You breathe $arg:quickly,seductively,painfully,nastily,slowly,once,"+
         "heavily,carefully,heatedly$",
      "You breathe $lastarg$", }) }),
  "burp" : ({ ({ 3, "%s" }), ({
      "You burp$ifarg: $arg:disgustingly,faintly,loudly,rudely$~$",
      "$mcname$ burps$ifarg: $lastarg$~$" }) }),
  "bow" : ({ ({ 0, "%s", 0, "to %s", 1, "%s to %s", 1, "%s %s", 3, "%s" }), ({
      "You bow$ifarg: $arg:solemnly,deeply,formally,hastily,slightly," +
         "disgustedly,floridly,flamboyantly,"+
         "insolently,clumsily,dextrously,wildly,colourfuly,with a flourish$~$",
      "$mcname$ bows$ifarg: $lastarg$~$",
      "You bow$ifarg: $arg:solemnly,deeply,formally,hastily,slightly,"+
         "disgustedly,floridly,flamboyantly,"+
         "insolently,clumsily,dextrously,wildly,colourful,with a flourishy$~$ "+
         "to $hcname$",
      "$mcname$ bows$ifarg: $lastarg$~$ to you",
      "$mcname$ bows$ifarg: $lastarg$~$ to $hcname$" }) }),
  "bubble" : ({ ({ 0, "%s", 0, "at %s" }), ({
      "I'm forever blowing bubbles!",
      "$mcname$ starts to blow bubbles",
      "You blow bubbles at $hcname$",
      "$mcname$ blows bubbles at you",
      "$mcname$ blows bubbles at $hcname$" }) }),
  "burn" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You set fire to yourself",
      "$mcname$ sets fire to $mobj$self",
      "You set fire to $mhcname$ $arg:hair,leg,arm,nose,teeth,frog,carpet,"+
           "net lag,fish,invis,bed,ego,eyes,house,furniture,tongue,keyboard,"+
            "brain,code,ideas,hopes,dreams,cat,personality,desires,beliefs$",
      "$mcname$ sets fire to your $lastarg$",
      "$mcname$ sets fire to $mhcname$ $lastarg$", }), }),
  "cackle" : ({ ({ 3, "%s" }), ({
      "You cackle $ifarg:$arg:with glee,maniacaly,mischieviously,nastily,"+
           "depairingly,womblely,backwards$$else$with glee~$",
      "$mcname$ $ifarg:cackles $lastarg$$else$"+
           "throws back $mposs$ head and cackles with glee~$" }) }),
  "calm" : ({ ({ 0, "%s", 0, "%s down" }), ({
      "You calm down",
      "$mcname$ calms down",
      "You calm $hcname$ down",
      "$mcname$ calms you down",
      "$mcname$ calms down $hcname$", }) }),
  "caper" : ({ ({ 3, "%s" }), ({
      "You caper around$ifarg: like a $arg:fool,chicken,womble,jester,"+
         "bimbo,blonde,sulam,seductress,eager person,vivacious person,"+
         "madman,madwomen,madperson,frog on the run,"+
         "happy chap,polite gentleperson,woman,no we aren't sexist$"+
      "$else$ madly~$", /* giggle */
      "$mcname$ capers around$ifarg: like a $lastarg$$else$ madly~$", }) }),
  "caress" : ({ ({ 0, "%s", 2, "%s %s", }), ({ 
      "You caress $hcname$$ifarg: $arg:gently,strangely,violently,"+
      "firmly,seductively,suggestively,slightly,sensually,"+
      "reluctantly,politely,lovingly,vigorously,eagerly,vivaciously$~$",
      "$mcname$ caresses you$ifarg: $lastarg$~$",
      "$mcname$ caresses $hcname$$ifarg: $lastarg$~$", }) }),
  "challenge" : ({ ({ 0, "%s", }), ({
      "Make your own challenges to $hcname$",
      "You turn $mcname$ into a fish",
      "$hcname$ turns $mcname$ into a fish", }) }),
  "chastize" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You chastize $hcname$$ifarg: $arg:loudly,insistantly,argumentatively,"+
           "unmercifully,unexpectedly,enthusiasticaly,calmly,rationaly,"+
           "insanely,madly,lovingly,politely,suggestively,eagerly,"+
           "reluctantly,firmly,excitedly,understandably,irrationaly,"+
           "imaginatively,destructively,cunningly,thoughtlessly,"+
           "carefully,offhandedly,absolutely$~$",
      "$mcname$ chastize's you$ifarg: $lastarg$~$",
      "$mcname$ chastize's $hcname$$ifarg: $lastarg$~$", }), }),
  "chastise" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You chastise $hcname$$ifarg: $arg:loudly,insistantly,argumentatively,"+
           "unmercifully,unexpectedly,enthusiasticaly,calmly,rationaly,"+
           "insanely,madly,lovingly,politely,suggestively,eagerly,"+
           "reluctantly,firmly,excitedly,understandably,irrationaly,"+
           "imaginatively,destructively,cunningly,thoughtlessly,"+
           "carefully,offhandedly,absolutely$~$",
      "$mcname$ chastise's you$ifarg: $lastarg$~$",
      "$mcname$ chastise's $hcname$$ifarg: $lastarg$~$", }), }),
  "cheer" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 1, "%s %s", 2, "at %s %s", 3, "%s" }), ({
      "You cheer $arg:enthusiastically,excitedly,quietly,calmly,carefully,"+
      "politely,wildly,oddly,unconvincingly,happily,slightly,up,loudly$",
      "$mcname$ cheers $lastarg$",
      "You cheer $arg:enthusiastically at,excitedly at,quietly at,calmly at,"+
      "wildly at,unconvincingly at,carefully at,happily at,"+
      "politely at,oddly at,slightly at,up,loudly$ $hcname$",
      "$mcname$ cheers $lastarg$ you",
      "$mcname$ cheers $lastarg$ $hcname$", }) }),
  "choke" : ({ ({ 0, "%s" }), ({
      "You choke",
      "$mcname$ chokes",
      "You choke $hcname$",
      "$mcname$ chokes you",
      "$mcname$ chokes $hcname$$force#breathe pain#2$" }) }),
  "chortle" : ({ 0, ({
      "You chortle in joy",
      "$mcname$ chortles in joy", }), }),
  "chuckle" : ({ ({ 3, "%s" }), ({
      "You chuckle $arg:politely,nastily,demonically$",
      "$mcname$ chuckles $lastarg$" }) }),
  "clap" : ({ ({ 3, "%s" }), ({
      "You clap your hands $arg:briefly,loudly,enthusiasticaly,halfheartedly$",
      "$mcname$ claps $mposs$ hands $lastarg$" }) }),
  "clasp" : ({ ({ 0, "%s", 2, "%s %s", 1, "%s %s" }), ({
      "You clasp$ifarg: $mhcname$ hand $arg:tightly,loosely,wetly,happily,"+
           "lovingly,passionately,prudently,seductively$$else$ $hcname$~$",
      "$mcname$ clasps$ifarg: your hand $lastarg$$else$ you~$",
      "$mcname$ clasps$ifarg: $mhcname$ hand $lastarg$$else$ $hcname$~$",
             }), }), 
  "click" : ({ 0, ({
      "You click your fingers",
      "$mcname$ clicks $mposs$ fingers", }), }),
  "comfort" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You comfort $hcname$$ifarg: $arg:sincerly,wholeheartly,mischieviously,"+
            "halfheartedly,vaguely,eagerly,completely,lovingly,gently,"+
            "tenderly,sadly,in earnest,with your frog,in the ear,in the leg,"+
            "twice,anxiously,carefully,delicately,like someone else$~$",
      "$mcname$ comforts you$ifarg: $lastarg$~$",
      "$mcname$ comforts $hcname$$ifarg: $lastarg$~$" }) }),
  "confess" : ({ ({ 3, "%s" }), ({
      "I confess $ifarg:$arg:#$$else$to being a witch~$",
      "$mcname$ confess's $ifarg:$lastarg$$else$to being a witch, burn "+
           "$mposs$~$", }), }),
  "congrat" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You$ifarg: $arg:heartily,warmly$~$ congratulate everyone",
      "$mcname$$ifarg: $lastarg$~$ congratulates everyone",
      "You$ifarg: $arg:heartily,warmly$~$ congratulate $hcname$",
      "$mcname$$ifarg: $lastarg$~$ congratulates you",
      "$mcname$$ifarg: $lastarg$~$ congratulates $hcname$" }) }),
  "cough" : ({ 0, ({ "You cough", "$mcname$ coughs" }) }),
  "cower" : ({ ({ 3, "%s" }), ({
       "You cower $arg:in a corner,fearfully,slyly,shyly,in shame,"+
             "nastily$",
       "$mcname$ cowers $lastarg$", }), }),
  "cringe" : ({ ({ 3, "%s" }), ({
      "You cringe$ifarg: in $arg:terror,embarassment,anticipation$~$",
      "$mcname$ cringes$ifarg: in $lastarg$~$" }) }),
  "croak" : ({ 0, ({
      "Ribbit",
      "$mcname$ croaks (ribbit)" }) }),
  "cross" : ({ ({ 3, "%s", 3, "my %s" }), ({
      "You cross your $arg:fingers,legs,eyes,arms$",
      "$mcname$ crosses $mposs$ $lastarg$", }) }),
  "crowd" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 2, "%s into %s",
                  3, "%s" }), ({
      "The crowd goes $arg:wild,#$",
      "The crowd goes $arg:wild,#$",
      "You crowd $hcname$ into $arg:a corner,#$",
      "$mcname$ crowds you into $lastarg$",
      "$mcname$ crowds $hcname$ into $lastarg$" }) }),
  "cry" : ({ 0, ({ "Wahhhhhh", "$mcname$ crys loudly" }) }),
  "cuddle" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You cuddle $hcname$",
      "$mcname$ cuddles you",
      "$mcname$ cuddles $hcname$" }) }),
  "curse" : ({ ({ 0, "%s", 1, "%s %s",  1, "%s at %s", 2, "at %s %s",
                  2, "%s %s" , 3, "%s" }), ({
      "You curse$ifarg: $arg:loudly,strongly,rudely,unashamedly,#$~$",
      "$mcname$ curses$ifarg: $lastarg$~$",
      "You curse$ifarg: $arg:loudly,strongly,rudely,unashamedly,#$~$ at "+
        "$hcname$",
      "$mcname$ curses$ifarg: $lastarg$ at~$ you",
      "$mcname$ curses$ifarg: $lastarg$~$ at $hcname$" }) }),     
  "curtsey" : ({ ({
      0, "%s", 0, "to %s", 0, "before %s", 1, "%s %s",
      2, "%s before %s", 2, "%s to %s",3, "%s" }), ({
	  "You curtsey$ifarg: $arg:gracefully,humbly,quickly,low,slightly$~$",
	  "$mcname$ curtsies$ifarg: $lastarg$~$",
	  "You curtsey$ifarg: $arg:gracefully,humbly,quickly,low,slightly$~$ to $hcname$",
	  "$mcname$ curtsies$ifarg: $lastarg$~$ before you",
	  "$mcname$ curtsies$ifarg: $lastagr$~$ to $hcname$" }) }),
  "dance" : ({ ({ 0, "%s", 0, "with %s" }), ({
      "You do the disco duck.  Feels silly doesn't it?",
      "$mcname$ dances the disco duck",
      "You sweep $hcname$ across the dance floor",
      "$mcname$ sweeps you across the dance floor",
      "$mcname$ sweeps $hcname$ across the dance floor" }) }),
  "daydream" : ({ ({ 3, "%s", }), ({
      "You daydream$ifarg: of $arg:#$~$",
      "$mcname$ daydreams$ifarg: of $lastarg$~$", }) }),
  "die" : ({ ({0, "%s",  1, "%s %s",
               1, "%s at %s", 2, "%s %s",
               2, "at %s %s",  3, "%s" }),  ({
      "You die $arg:suddenly,dramatically,of boredom,of hunger,of "+
      "anticipation,pathetically,gracefully,senselessly,stupidly,"+
      "tragically,slowly,painfully,an excruciating death$",
      "$mcname$ dies $lastarg$",
      "You die$ifarg: $arg:suddenly,dramatically,of boredom,of hunger,of "+
      "anticipation,pathetically,gracefully,senselessly,stupidly,"+
      "tragically,slowly,painfully,an excruciating death$~$"+
      " in $mhcname$ general direction",
      "$mcname$ dies$ifarg: $lastarg$~$ in your general direction",
      "$mcname$ dies$ifarg: $lastarg$~$ in $mhcname$ general direction" }) }),
  "disagree" : ({ ({ 0, "%s", 0, "with %s" }), ({
      "You disagree with $hcname$",
      "$mcname$ disagrees with you",
      "$mcname$ disagrees with $hcname$", }), }),
  "dribble" : ({ ({0, "%s", 0, "on %s", 0, "all over %s"  }), ({
      "You start to dribble all over the front of your shirt",
      "$mcname$ starts to dribble all over the front of $mposs$ shirt",
      "You start dribbling on $hcname$",
      "$hcname$ starts dribbling all over your best shirt",
      "$mcname$ starts dribbling all over $hcname$" }) }),
  "drool" : ({ ({ 0, "%s", 0, "at %s" }), ({
      "You start to drool",
      "$mcname$ starts to drool",
      "You drool all over $hcname$",
      "$mcname$ drools all over you",
      "$mcname$ drools all over $hcname$" }) }),
  "duck" : ({ 0, ({
      "You duck $arg:for cover,the snowball,quickly,slowly,badly,"+
               "inappropriately,pointlessly,sadly,carefully$",
      "$mcname$ ducks $lastarg$" }) }),
  "duh" : ({ 0, ({
      "You scream \"Duh!\"",
      "$mcname$ screams \"Duh!\"", }) }),
  "eek" : ({ ({ 3, "%s" }), ({
      "You eeek$ifarg: $arg:like signe,loudly,in shock,in amazement,happily,"+
          "sadly,carefully,brightly$$else$!!!!~$",
      "$mcname$ eeks$ifarg: $lastarg$$else$!!!!~$", }), }),
  "envy" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", }), ({
      "You envy $mhcname$ $arg:frog,#$",
      "$mcname$ envies your $lastarg$",
      "$mcname$ envys $mhcname$ $lastarg$", }), }),
  "eye" : ({ ({ 0, "%s" }), ({
      "You eye $hcname$ over",
      "$mcname$ eyes you over",
      "$mcname$ eyes $hcname$ over", }), }),
  "exp" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You raise yourself to the power of$ifarg: $arg:#$~$",
      "$mcname$ raises $mobj$self to a random power",
      "You raise $hcname$ to the power of$ifarg: $arg:#$~$",
      "$mcname$ raises you to the power of$ifarg: $lastarg$~$",
      "$mcname$ raises $hcname$ to the power of$ifarg: $lastarg$~$" }) }),
  "expect" : ({  ({ 0, "%s", 0, "at %s" }), ({
      "You look expectantly at $hcname$",
      "$mcname$ looks expectantly at you",
      "$mcname$ looks expectantly at $hcname$" }) }),
  "explode" : ({ 0, ({
      "You explode into thousands of tiny pieces",
      "$mcname$ explodes into thousands of tiny pieces", }) }),
  "faint" : ({ ({ 3, "%s", 0, "%s" }), ({
      "You faint$ifarg: $arg:tiredly,out of boredom$~$",
      "$mcname$ faints$ifarg: $lastarg$~$",
      "You faint on $hcname$",
      "$mcname$ faints on you",
      "$mcname$ faints on $hcname$" }) }),
  "fall" : ({ ({ 0, "%s", 3, "%s", }), ({
      "You fall over$ifarg: $arg:backwards,painfully,awkwardly,accidently,"+
           "purposefully,happily,sadly,quickly,rapidly$~$",
      "You fall over$ifarg: $lastarg$~$",
      "You fall $ifarg:$arg:heavily,slowly,happily,quickly,"+
            "twice$ on $hcname$$else$for $hcname$~$",
      "$mcname$ falls $ifarg:$lastarg$ on you$else$for you~$",
      "$mcname$ falls $ifarg:$lastarg$ on $hcname$$else$for $hcname$~$", }), }),
  "fart" : ({ 0, ({ /* don't like this emote, can you tell?? */ /* yes :) */
      "You fart",
      "$mcname$ farts" }) }),
  "fiddle" : ({ 0, ({
       "You fiddle with something",
       "$mcname$ fiddles with something", }), }),
  "fish" : ({ ({
      0, "%s", 0, "in %s", 1, "for %s in %s pockets",
      1, "for %s in %s", 1, "%s in %s", 2, "%s %s", 3, "%s" }), ({
	  "You fish around in your pockets$ifarg: for a $arg:#$~$",
	  "$mcname$ fishes around in $mposs$ pockets$ifarg: for a $lastarg$~$",
	  "You fish around in $mhcname$ pockets$ifarg: for a $arg:#$~$",
	  "$mcname$ fishes around in your pockets$ifarg: for a $lastarg$~$",
	  "$mcname$ fishes around in $mhcname$ pockets$ifarg: for a $lastarg$~$" }) }),
  "flap" : ({ ({ 3, "%s" }), ({
      "You flap your $arg:ears,arms,wings,eyelashes$",
      "$mcname$ flaps $mposs$ $arg:ears,arms$" }) }),
  "flex" : ({ ({ 3, "%s" }), ({
      "You flex your $arg:muscles,bisceps,triceps,legs,brain,nose,ears$",
      "$mcname$ flexes $mposs$ $lastarg$", }) }),
  "flip" : ({  ({ 3, "%s", 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You flip $arg:head over heels,backwards,forwards,sideways,"+
         "around,carefully,slowly,twice,doggily,awkwardly,disturbingly,"+
         "digustingly,quickly,slowly,gracefully,over the moon,"+
         "around in a really complicated double back roll flip,"+
         "half way around and land on your head, ouch$",
      "$mcname$ flips $lastarg$",
      "You flip $hcname$ $arg:head over heels,off,into the garbage bin,"+
         "visciously,dangerously,spectacularly$",
      "$mcname$ flips you $lastarg$",
      "$mcname$ flips $hcname$ $lastarg$" }) }),
  "flop" : ({ ({ 0, "%s", 3, "%s" }), ({
      "You flop about $arg:helplessly,like a fish out of water,"+
          "badly,like zoroaster,carefully,rudely,a bit,once,like a gherkin,wonderfully,"+
          "impressively,suggestively,lazily,happily,pensively$",
      "$mcname$ flops about $lastarg$" ,
      "You flop on $hcname$",
      "$mcname$ flops on you",
      "$mcname$ flops on $hcname$" }) }),
  "flustered" : ({ 0, ({
      "You look flustered",
      "$mcname$ looks flustered", }) }),
  "flutter" : ({ ({ 0, "%s" }), ({
      "You flutter your eyelids",
      "$mcname$ flutters $mposs$ eyelids",
      "You flutter your eyelids at $hcname$",
      "$mcname$ flutters $mposs$ eyelids at you",
      "$mcname$ flutters $mposs$ eyelids at $hcname$", }) }),
  "fold" : ({ ({ 3, "%s" }), ({
      "You fold your arms$ifarg: $arg:arrogantly,descively,carefully,slowly,"+
           "menacingly,half heartedly,quickly,snapily$~$",
      "$mcname$ folds $mposs$ arms$ifarg: $lastarg$~$" }), }),
  "fondle" : ({ ({ 0, "%s", 1, "%s %s" }), ({
      "You fondle $ifarg:$mhcname$ $arg:#$$else$$hcname$~$",
      "$mcname$ fondles$ifarg: with your $lastarg$$else$ you~$",
      "$mcname$ fondles $ifarg:with $mhcname$ $lastarg$$else$$mhcname$~$" }) }),
  "foo" : ({ ({ 3, "%s" }), ({
      "You foo $arg:vaguely,carefully,slowly,dangerously$",
      "$mcname$ foos $lastarg$", }), }),
  "forgive" : ({ ({ 0, "%s", }), ({
      "You forgive $hcname$",
      "$mcname$ forgives you",
      "$mcname$ forgives $hcname$", }), }),
  "frog" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You frog around $arg:mindlessly,silently,happily,carefully,#$",
      "$mcname$ frogs around $lastarg$",
      "You turn $hcname$ into a frog$ifarg: $arg:slowly,carefully,"+
              "excrutiatingly,happily,gleefully,magicly$~$",
      "$mcname$ turns you into a frog$ifarg: $lastarg$~$",
      "$mcname$ turns $hcname$ into a frog$ifarg: $lastarg$~$"+
              "$force#croak#2$" }) }),
  "french" : ({ ({ 0, "%s" }), ({
      "You give $hcname$ a deep and passionate kiss, it seems to last forever..",
      "$mcname$ gives you a deep and passionate kiss, it seems to last forever..",
      "$mcname$ gives $hcname$ a deep and passionate kiss, it seems to last forever.." }) }),
  "froth" : ({ 0, ({
      "You froth at the mouth",
      "$mcname$ froths at the mouth" }) }),
  "frown" : ({ ({ 0, "%s", 3, "%s", 3, "in %s" }), ({
      "$ifarg:You frown in $arg:concentration,thought,anger,"+
         "depression,like a cat,happily,#$$else$Whats the problem?~$",
      "$ifarg:$mcname$ frowns in $lastarg$$else$$mcname$ frowns~$",
      "You frown at $hcname",
      "$mcname$ frowns at you",
      "$mcname$ frowns at $hcname$" }) }),
  "fume" : ({ ({ 3, "%s", }), ({
      "You fume $arg:quietly,insultingly,despairingly,in frustration$",
      "$mcname$ fumes $lastarg$", }) }),
  "gasp" : ({ ({ 3, "%s", 3, "in %s", }), ({
      "You gasp in $arg:astonishment,excitement,terror,fear,fright,pain$",
      "$mcname$ gasps in $lastarg$" }) }),
  "gesture" : ({ ({ 0, "%s", 1, "%s %s", 1, "%s at %s", 2, "%s %s",
                    2, "at %s %s", 3, "%s" }), ({
      "You gesture $arg:wildly,pompously,mysticaly,oddly,strangely,"+
            "carefully,deliberately,off into the distance,rapidly,"+
            "without moving,slowly,ponderously,mindlessly,insanely,"+
            "nastily,suggestively,lovingly$",
      "$mcname$ gestures $lastarg$",
      "You gesture $arg:wildly,pompously,mysticaly,oddly,strangely,"+
            "carefully,deliberately,off into the distance,rapidly,"+
            "without moving,slowly,ponderously,mindlessly,insanely,"+
            "nastily,suggestively,lovingly$ at $hcname$",
      "$mcname$ gestures $lastarg$ at you",
      "$mcname$ gestures $lastarg$ at $hcname$", }) }),
  "gesticulate" : ({ ({ 0, "%s", 1, "%s %s", 1, "%s at %s", 2, "%s %s",
                    2, "at %s %s", 3, "%s" }), ({
      "You gesticulate $arg:wildly,pompously,mysticaly,oddly,strangely,"+
            "carefully,deliberately,off into the distance,rapidly,"+
            "without moving,slowly,ponderously,mindlessly,insanely,"+
            "nastily,suggestively,lovingly$",
      "$mcname$ gesticulates $lastarg$",
      "You gesticulate $arg:wildly,pompously,mysticaly,oddly,strangely,"+
            "carefully,deliberately,off into the distance,rapidly,"+
            "without moving,slowly,ponderously,mindlessly,insanely,"+
            "nastily,suggestively,lovingly$ at $hcname$",
      "$mcname$ gesticulates $lastarg$ at you",
      "$mcname$ gesticulates $lastarg$ at $hcname$", }) }),
  "gibber" : ({ 0, ({
      "You gibber madly",
      "$mcname$ gibbers madly", }) }),
  "giggle" : ({ ({ 3, "%s" }), ({
      "You giggle$ifarg: $arg:inanely,loudly,stupidly,snort,"+
          "quietly,idioticly,fiendishly,insanely,sarcastically,cutely$~$",
      "$mcname$ giggles$ifarg: $lastarg$~$" }) }),
  "glare" : ({ ({
      0, "%s", 0, "at %s", 1, "%s at %s", 2, "at %s %s",
      1, "%s %s", 2, "%s %s", 3, "%s" }), ({
	  "You glare $arg:stonily,sternly,hotly,intently,solemnly,idioticly,evanly,"+
	  "evilly$ at the world in general",
	  "$mcname$ glares $lastarg$ around $mpronoun$",
	  "You glare $arg:stonily,sternly,hotly,intently,solemnly,evilly,evanly,"+
	  "idiotically$ at $hcname$",
	  "$mcname$ glares $lastarg$ at you", 
	  "$mcname$ glares $lastarg$ at $hcname$", }) }),
  "gnash" : ({ ({ 0, "%s", }), ({
      "You gnash your teeth",
      "$mcname$ gnash's $mposs$ teeth",
      "You gnash you teeth at $hcname$",
      "$mcname$ gnash's $mposs$ teeth at you",
      "$mcname$ gnash's $mposs$ teeth at $hcname$", }), }),
  "grate" : ({ ({ 3, "%s" }), ({
      "You grate your teeth $arg:in annoyance,noisily,seductively,in terror,"+
         "together,annoyingly,suggestively,painfully,angrily$",
      "$mcname$ grates $mposs$ teeth $lastarg$", }) }),
  "greet" : ({ ({ 0, "%s" }), ({
      "You greet $hcname$ $arg:happily,sadly,with open arms,"+
      "ecstaticly,carefully,courteously,hysterically,"+
      "reservedly,warmly,coldly,insolently,curtly,"+
      "absentmindedly$",
      "$mcname$ greets you $lastarg$",
      "$mcname$ greets $hcname$ $lastarg$", }) }),
  "grimace" : ({ ({ 3, "%s" }), ({
      "You grimace in $arg:disgust,anger,thought,power,despair$",
      "$mcname$ grimaces in $lastarg$", }), }),
  "grin" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 2, "at %s %s",
                 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You grin$ifarg: $arg:manically,evilly,wickedly,insanely,mischieviously,"+
         "devilishly,"+
         "impishly,cheekily,idiotically,tentatively,wryly,skepticaly$~$",
      "$mcname$ grins$ifarg: $lastarg$~$",
      "You grin$ifarg: $arg:manically,evilly,wickedly,insanely,mischieviously,"+
         "devilishly,"+
         "impishly,cheekily,idiotically,wryly,skepticaly$~$ at $hcname$",
      "$mcname$ grins$ifarg: $lastarg$~$ at you",
      "$mcname$ grins$ifarg: $lastarg$~$ at $hcname$" }) }),
  "grind" : ({ ({ 3, "%s" }), ({
      "You grind your teeth $arg:noisily,seductively,in terror,together,"+
         "annoyingly,suggestively,painfully,angrily$",
      "$mcname$ grinds $mposs$ teeth $lastarg$", }) }),
  "groan" : ({ ({ 3, "%s" }), ({
      "You groan$ifarg: $arg:loudly,resignedly,tiredly,in dissapointment$~$",
      "$mcname$ groans$ifarg: $lastarg$~$" }) }),
  "grope" : ({ ({ 0, "%s", 1, "%s %s" }), ({
      "You grope $ifarg:$mhcname$ $arg:#$$else$$hcname$~$",
      "$mcname$ gropes you$ifarg: $lastarg$~$",
      "$mcname$ gropes $ifarg:$mhcname$ $lastarg$$else$$hcname$~$" }) }),
  "grovel" : ({ ({ 0, "%s", 0, "at %s", 1, "%s %s", 1, "%s at %s", 3, "%s", 2, "at %s %s", }), ({
      "You grovel$ifarg: $arg:shamelessly,violently,unashamedly$~$",
      "$mcname$ grovels$ifarg: $lastarg$~$",
      "You grovel$ifarg: $arg:shamelessly,violently,unashamedly$~$ at"+
      " $mhcname$ feet",
      "$mcname$ grovels$ifarg: $lastarg$~$ at your feet",
      "$mcname$ grovels$ifarg: $lastarg$~$ at $mhcname$ feet" }) }),
  "growl" : ({ ({
      0, "%s", 0, "at %s", 1, "%s %s", 1, "%s at %s",
      2, "at %s %s", 2, "%s %s", 3, "%s" }), ({
	  "You growl $arg:menacingly,nastily,loudly,playfully$",
	  "$mcname$ growls $lastarg$",
	  "You growl $arg:menacingly,nastily,loudly,playfully$ at $hcname$",
	  "$mcname$ growls $lastarg$ at you",
	  "$mcname$ growls $lastarg$ at $hcname$" }) }),
  "grumble" : ({ ({ 3, "%s", }), ({
      "You grumble $arg:quietly,bitterly,menacingly,halfheartedly,"+
      "seductively,suggestively,loudly,annoyingly,devestatingly,carefully,"+
      "wildly,more or less$",
      "$mcname$ grumbles $lastarg$", }) }),
  "gurgle" : ({ ({ 3, "%s" }), ({
      "You gurgle $arg:noisily,rudely,loudly,mischievously,"+
      "happily,carefully,disgustingly,in suprise,"+
      "like a train,quickly,slowly$",
      "$mcname$ gurgles $lastarg$" }) }),
  "hang" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s", }), ({
      "You hang your head in $arg:shame,sorrow,despair,happiness$",
      "$mcname$ hangs $mposs$ head in $lastarg$",
      "You hang onto $hcname$ $ifarg:tightly,passionately,fearfully,"+
           "possessively,paranoically$",
      "$mcname$ hangs onto you $lastarg$",
      "$mcname$ hangs onto $hcname$ $lastarg$", }) }),
  "hassle" : ({ ({ 0, "%s", 2, "%s about %s", 1, "%s %s", 2, "%s %s", }), ({
      "You hassle $hcname$$ifarg: about $arg:frogs,chickens,wombles,#$~$",
      "$mcname$ hassles you$ifarg: about $lastarg$~$",
      "$mcname$ hassles $hcname$$ifarg: about $lastarg$~$", }), }),
  "headbutt" : ({ ({ 0, "%s"}), ({
      "You head butt $hcname$", "$mcname$ headbutts you",
      "$mcname$ headbutts $hcname$" }) }),
  "headstand" : ({ ({ 0, "on %s", 0, "%s" }), ({
      "You stand on your head", "$mcname$ stands on $mposs$ head",
      "You stand on $mhcname$ head", "$mcname$ stands on your head",
      "$mcname$ stands on $mhcname$ head" }) }),
  "hiccup" : ({ 0, ({ /* exciting stuff */
      "You hiccup",
      "$mcname$ hiccups" }) }),
  "high5" : ({ ({ 0, "%s" }), ({
      "Nope",
      "$mcname$ is stupid, isn't $mpronoun$?",
      "Nope, sorry.  Absolutely not",
      "Ignore $mcname$, $mpronoun$'s actually pretty stupid",
      "Ignore $mcname$, $mpronoun$'s acutally pretty stupid" }) }),
  "hold" : ({ ({ 0, "%s", 0, "onto %s", 1, "%s %s", 2, "%s %s", 3, "%s"}), ({
 /* Hold onto me? */
      "You hold your $arg:nose,#$",
      "$mcname$ holds $mposs$ $lastarg$",
      "You hold $hcname$$ifarg: $arg:close,tightly,warmly,gently,lovingly,"+
            "back,up$~$",
      "$mcname$ holds you$ifarg: $lastarg$~$",
      "$mcname$ holds $hcname$$ifarg: $lastarg$~$" }) }),
  "hop" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", }),  ({
      "You hop around a bit",
      "$mcname$ hops around a bit",
      "You hop into $mhcname$ $arg:arms,pool,house,car,bed,frog,television$",
      "$mcname$ hops into your $lastarg$",
      "$mcname$ hops into $mhcname$ $lastarg$",
                 }) }),
  "hoot" : ({ ({ 3, "%s" }), ({
      "You hoot $arg:like Owls,derisively,annoyingly,absentmindedly,"+
            "whilst you work,distractedly,pointlessly,silently,loudly,"+
            "rudely,with laughter,vaguely,obviously,tunelessly$",
      "$mcname$ hoots $lastarg$" }), }),
  "howl" : ({ ({ 3, "%s", 3, "at the %s" }), ({
      "HOOOOOWWWWWWWWWLLLLLL!!",
      "$mcname$ howls$ifarg: $arg:at the moon,at the #$~$" }) }),
  "hug" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You hug $hcname$$ifarg: $arg:tightly,warmly,gently,close$~$",
      "$mcname$ hugs you$ifarg: $lastarg$~$",
      "$mcname$ hugs $hcname$$ifarg: $lastarg$~$" }) }),
  "hum" : ({ ({ 3, "%s" }), ({
      "You hum $arg:a merry tune,tunelessly,annoyingly,vaguely,absentmindedly,"+
            "whilst you work,distractedly,pointlessly,silently,loudly,"+
            "rudely$",
      "$mcname$ hums $lastarg$" }), }),
  "idle" : ({ ({ 0, "%s", 3, "%s" }), ({
      "You idle $arg:like pinkfish,like zoroaster,like biggles,like sloths do,"+
           "like a gherkin,like everyone else is,nonchalantly,quickly,"+
           "unbelievably well,without using your hands,upside-down,"+
           "hyperactively,standing still,artfully,around,intensely,"+
           "like only Bastian can$",
      "$mcname$ idles $lastarg$",
      "You idle like $hcname$",
      "$mcname$ idles like you",
      "$mcname$ idles like $hcname$", }), }),
  "ignore" : ({ ({ 0, "%s" }), ({
      "You ignore the world",
      "$mcname$ ignores the world",
      "You ignore $hcname$",
      "$mcname$ ignores you",
      "$mcname$ ignores $hcname$", }) }),
  "james" : ({ 0, ({
      "Ow! I feel good! da na da na da na da! I knew that I would!",
      "$mcname$ feels good, da na da na da na da!" }) }),
  "juggle" : ({ ({ 3, "%s" }), ({
      "You juggle some $arg:balls,sticks,battons,cats,dogs,frogs,chickens,"+
         "swords,knives,arms,legs,balls,trees,chain saws,bottles,"+
         "guppies,torches,bings,tree stumps,logs,zoroasters,"+
         "wine glasses,water,people,fire,ladies,men,rhinos$ around",
      "$mcname$ juggles some $lastarg$ around", }) }),
  "jump" : ({ ({ 0, "on %s", 0, "%s", 2, "on %s %s",
                 1, "%s on %s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You jump up and down $arg:excitedly,happily,carefully,slowly,"+
         "joyfully,unsteadily,ecstaticly,worriedly,sideways,"+
         "absentmindedly,like pinkfish,like a prancing pirana$",
      "$mcname$ jumps up and down $lastarg$",
      "You jump up and down on $hcname$$ifarg: $arg:"+
      "excitedly,happily,carefully,slowly,"+
      "joyfully,unsteadily,ecstaticly,worriedly,sideways,"+
      "absentmindedly,like pinkfish$~$",
      "$mcname$ jumps up and down on you$ifarg: $lastarg$~$",
      "$mcname$ jumps up and down on $hcname$$ifarg: $lastarg$~$" }) }),
  "kick" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You kick yourself$ifarg: $arg:#$~$",
      "$mcname$ kicks $mobj$self",
      "You kick $hcname$$ifarg: $arg:#$~$",
      "$mcname$ kicks you$ifarg: $lastarg$~$",
      "$mcname$ kicks $hcname$$ifarg: $lastarg$~$" }) }),
  "kiss" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You kiss $hcname$$ifarg: $arg:passionately,deeply,tenderly,gently,"+
      "lovingly,lengthily,fishily,carefully,demandingly,sensuously$~$",
      "$mcname$ kisses you$ifarg: $lastarg$~$",
      "$mcname$ kisses $hcname$$ifarg: $lastarg$~$" }) }),
  "knee" : ({ ({ 0, "%s", 1, "%s %s" }), ({
      "You knee $hcname$$ifarg: $arg:#$~$",
      "$mcname$ knees you$ifarg: $lastarg$~$",
      "$mcname$ knees $hcname$$ifarg: $lastarg$~$" }) }),
  "laugh" : ({ ({
      0, "at %s", 0, "%s", 1, "%s %s", 1, "%s at %s",
      2, "at %s %s", 3, "%s"}), ({
	  "$ifarg:You laugh $arg:nastily,nicely,quietly,uncontrollably,politely,"+
	  "happily,manically,ecstaticly,demonically$"+
	  "$else$You fall down laughing~$",
	  "$ifarg:$mcname$ laughs $lastarg$$else$$mcname$ falls down laughing~$",
	  "You laugh$ifarg: $arg:nastily,nicely,quietly,uncontrollably,politely,"+
	  "happily,manically,ecstaticly,demonically$~$"+
	  " at $hcname$",
	  "$mcname$ laughs$ifarg: $lastarg$~$ at you",
	  "$mcname$ laughs$ifarg: $lastarg$~$ at $hcname$" }) }),
  "leap" : ({ ({ 3, "%s" }), ({
      "You leap$ifarg: $arg:longingly,excitedly,quickly,slowly,awkwardly,"+
         "politlely,quietly,noisily$~$ into the air",
      "$mcname$ leaps$ifarg: $lastarg$~$ into the air", }) }),
  "leer" : ({ ({ 0, "%s", 0, "at %s" }), ({
       "You leer at yourself",
       "$mcname$ leers at $mobj$self, hmm interesting",
       "You leer at $hcname$",
       "$mcname$ leers at you",
       "$mcname$ leers at $hcname$", }), }),
  "lick" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You lick your lips$ifarg: $arg:sensously,seductively,expectantly,"+
             "carefully,suggestively$~$",
      "$mcname$ licks $mposs$ lips$ifarg: $lastarg$~$",
      "You lick $hcname$$ifarg: $arg:carefully,lustily,excitedly,slowly,"+
             "quickly,happily,silently,loudly,absentmindedly$~$",
      "$mcname$ licks you$ifarg: $lastarg$~$",
      "$mcname$ licks $hcname$$ifarg: $lastarg$~$" }) }),
  "listen" : ({ ({ 1, "%s to %s", 0, "%s", 0, "to %s" }), ({
      "You listen $arg:intently,carefully,boredly,patiently,silently,"+
           "rudely$ to $hcname$",
      "$mcname$ listens $lastarg$ to you",
      "$mcname$ listens $lastarg$ to $hcname$", }), }),
  "loom" : ({ ({ 0, "%s", 0, "over %s" }), ({
      "You loom over $hcname$",
      "$mcname$ looms over you",
      "$mcname$ looms over $hcname$", }) }),
  "love" : ({ ({ 0, "%s" }), ({
      "You whisper sweet nothings into $mhcname$ ear",
      "$mcname$ whispers sweet nothings in your ear",
      "$mcname$ whispers to $hcname$" }) }),
  "lower" : ({ 0, ({
      "You lower your eyebrows",
      "$mcname$ lowers $mposs$ eyebrows", }) }),
  "massage" : ({ ({ 0, "%s", 2, "%s %s", }), ({
      "You give $hcname$ a$ifarg: $arg:good,bad,ugly,long,"+
         "refreshing,pink,full body,seductive,sensuous,strange,"+
         "painful,deep,meaningful,ergonomic,economic,"+
         "painless,memorable,different,unwanted,unwarranted,"+
         "unprovoked,unknown,sneaky,unnoticed,unwieldly,back,"+
         "professional,unprofessional,happy,sad,trained,untrained,"+
         "train,virgin mary,compact,quick,foot,leg,arm,head,teeth,"+
         "ear,neck,shoulder,nose$~$ massage",
      "$mcname$ gives you a$ifarg: $lastarg$~$ massage",
      "$mcname$ gives $hcname$ a$ifarg: $lastarg$~$ massage", }) }),
  "melt" : ({ ({ 0, "%s", 3, "%s" }), ({ 
      "You melt$ifarg: $arg:quickly,slowly,into a nice puddle,"+
               "carefully,in anticipation,in extasy,seductively,"+
               "submissively,a little$~$",
      "$mcname$ melts $lastarg$",
      "You melt in $mhcname$ arms",
      "$mcname$ melts in your arms",
      "$mcname$ melts in $mhcname$ arms", }), }),
  "moan" : ({ ({ 3, "%s" }), ({
      "You moan$ifarg: $arg:gently,deeply,sensually,agonisingly,in terror$~$",
      "$mcname$ moans$ifarg: $lastarg$~$" }) }),
  "moon" : ({ ({ 0, "%s" }), ({
      "You drop your pants and moon $hcname$",
      "$mcname$ drops $mposs$ pants and moons you",
      "$mcname$ drops $mposs$ pants and moons $hcname$", }), }),
  "mosh" : ({ 0, ({
      "You mosh $arg:violently,angrily,carefully,thoughtfully,"+
          "wonderingly,vigorously,insanely,loudly$ around the room",
      "$mcname$ moshes $lastarg$ around the room", }) }),
  "mourn" : ({ ({ 0, "%s", 3, "%s" }), ({
      "You mourn $arg:the slow death of frogs,#$",
      "$mcname$ mourns $lastarg$",
      "You mourn $hcname$",
      "$mcname$ mourns you",
      "$mcname$ mourns $hcname$", }), }),
  "muss" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", }), ({
      "You muss $mhcname$ hair$ifarg: $arg:slowly,lovingly,with a brick,"+
              "patronisingly,suggestively,just like kylie would$~$",
      "$mcname$ muss's your hair$ifarg: $lastarg$~$",
      "$mcname$ muss's $mhcname$ hair$ifarg: $lastarg$~$", }), }),
  "mutter" : ({ ({ 3, "%s" }), ({
      "You $ifarg:mutter $arg:#$ under your breath$else$mutter under "+
          "your breath~$",
      "$mcname$ mutters $ifarg:$arg:#$ ~$under $mposs$ breath", }) }),
  "nestle" : ({ ({ 0, "%s", }), ({
      "You nestle up to $hcname$ $arg:affectionately,lovingly,curiously$",
      "$mcname$ nestles up to you $lastarg$",
      "$mcname$ nestles up to $hcname$ $lastarg$", }) }),
  "nibble" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You nibble on $mhcname$ $arg:ear,finger,lip,arm,leg,toe,nose,tongue$",
      "$mcname$ nibbles on your $lastarg$",
      "$mcname$ nibbles on $mhcname$ $lastarg$" }) }),
  "nirg" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 2, "at %s %s",
                 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You nirg$ifarg: $arg:manically,evilly,wickedly,insanely,mischieviously,"+
         "devilishly,"+
         "impishly,cheekily,idiotically,tentatively,wryly,skepticaly$~$",
      "$mcname$ snirg$ifarg: $lastarg$~$",
      "You nirg$ifarg: $arg:manically,evilly,wickedly,insanely,mischieviously,"+
         "devilishly,"+
         "impishly,cheekily,idiotically,wryly,skepticaly$~$ at $hcname$",
      "$mcname$ snirg$ifarg: $lastarg$~$ at you",
      "$mcname$ snirg$ifarg: $lastarg$~$ at $hcname$" }) }),
  "nod" : ({ ({
      0, "%s", 1, "%s at %s", 1, "%s %s", 2, "at %s %s",
      2, "%s %s", 3, "%s" }), ({
	  "You nod $arg:solemnly,happily,brightly,curtly,patiently,slowly,"+
             "eagerly,expectantly,firmly,sagely,emphatically,"+
  	     "knowingly,vigorously,in disagreement,tentatively$",
	  "$mcname$ nods $lastarg$",
	  "You nod $arg:solemnly,happily,brightly,curtly,patiently,slowly,"+
            "eagerly,expectantly,firmly,sagely,emphatically,"+
	    "knowingly,vigorously$"+
	  " at $hcname$",
	  "$mcname$ nods $lastarg$ at you",
	    "$mcname$ nods $lastarg$ at $hcname$", }) }),
  "noise" : ({ ({ 3, "%s" }), ({
      "$ifarg:You make a $arg:bungle,flurgle,zongle-wop,wop,whirr,burble,frog,"+
         "moo,train,hairy,twisted,wap,pop,schwing,gong,koala,"+
         "rat,mouse,chicken,womble,guppy,cow,rabbit,kangaroo,gumby$ noise"+
      "$else$You make a funny noise~$",
      "$ifarg:$mcname$ makes a $lastarg$ noise$else$$mcname$ makes a funny noise~$" }) }),
  "nudge" : ({ ({ 0, "%s", }), ({
      "You nudge $hcname$",
      "$mcname$ nudges you",
      "$mcname$ nudges $hcname$", }) }),
  "nuzzle" : ({ ({ 0, "%s" }), ({
      "You nuzzle $hcname$ affectionately",
      "$mcname$ nuzzles you affectionately",
      "$mcname$ nuzzles $hcname$ affectionately", }), }),
  "raise" : ({ 0, ({ "You raise your eyebrows", "$mcname$ raises $mposs$ eyebrows" }) }),
  "razz" : ({ ({ 0, "%s" }), ({
      "You stick your thumb on your nose and razz $hcname$",
      "$mcname$ sticks $mposs$ thumb on $mposs$ nose and razz's you",
      "$mcname$ sticks $mposs$ thumb on $mposs$ nose and razz's $hcname$" }) }),
  "rock" : ({ ({ 3, "%s" }), ({
      "You rock on your $arg:heels,nose,feet$",
      "$mcname$ rocks on $mposs$ $lastarg$", }), }),
  "rub" : ({ ({ 0, "%s", 3, "%s" }), ({
      "You rub your $arg:hands together,eyes,tummy,nose,leg,arm,eyebrows,head$",
      "$mcname$ rubs $mposs$ $lastarg$",
      "You rub $hcname$ up the wrong way",
      "$mcname$ rubs you up the wrong way",
      "$mcname$ rubs $hcname$ up the wrong way", }) }),
  "ouch" : ({ 0, ({
      "Oooouuuuuchhhh!",
      "$mcname$ screams 'ouch!' in pain", }) }),
  "panic" : ({ 0, ({
      "You panic",
      "$mcname$ panics", }) }),
  "pat" : ({ ({ 0, "%s", 2, "%s on the %s", 2, "%s on %s", 1, "%s %s", 2, "%s %s" }), ({
      "You pat $hcname$ on the $arg:head,back,leg,arm,nose,bottom$",
      "$mcname$ pats you on the $lastarg$",
      "$mcname$ pats $hcname$ on the $lastarg$" }) }),
  "patronise" : ({ ({ 0, "%s" }), ({
      "You patronise $hcname$",
      "$mcname$ patronises you",
      "$mcname$ patronises $hcname$", }), }),
  "pet" : ({ ({ 0, "%s" }), ({
      "You pet Goldie",
      "$mcname$ pets Goldie",
      "You pet $hcname$",
      "$mcname$ pets you",
     /* What???  Zoroaster    */
      "$mcname$ pets $hcname$", }) }),
  "peer" : ({ ({
      0, "%s", 0, "at %s", 1, "%s at %s", 1, "%s %s", 2, "at %s %s",
      2, "%s %s", 3, "%s" }), ({
	  "You peer$ifarg: $arg:suspiciously,quizically,"+
	  "anxiously,stupidly,warningly,expectantly,happily,sadly,desperately,"+
	  "worriedly,strangely,uncertainly,lopsidedly,lazily,rudely,disappointedly,"+
	  "fishily,fearfully,like a train,curiously,tentatively,"+
          "tiredly,"+
	  "warily,nervously,carefully,warningly,owlishly,dazedly$~$ around the room",
	  "$mcname$ peers$ifarg: $lastarg$ around the room~$",
	  "You peer$ifarg: $arg:suspiciously,quizically,warilly,nervously,"+
	  "anxiously,stupidly,warninly,expectantly,happily,sadly,desperately,"+
	  "worriedly,strangely,uncertainly,lopsidedly,lazily,rudely,disapointedly,"+
          "tiredly,"+
	  "fishily,fearfully,like a train,curiously,"+
	  "carefully,warningly,intently,owlishly,dazedly$~$ at $hcname$",
	  "$mcname$ peers$ifarg: $lastarg$~$ at you",
	  "$mcname$ peers$ifarg: $lastarg$~$ at $hcname$", }) }),
  "pick" : ({ ({ 3, "%s" }), ({ 
      "You pick your $arg:nose,ear,#$",
      "$mcname$ picks $mposs$ $lastarg$" }) }),
  "pinch" : ({ ({ 0, "%s", 2, "%s on %s", 2, "%s on the %s", 1, "%s %s", 2, "%s %s" }),({
      "You pinch yourself",
      "$mcname$ pinches $mobj$self",
      "You pinch $hcname$$ifarg: on the $arg:bottom,leg,arm,frog,cheek$~$",
      "$mcname$ pinches you$ifarg: on the $lastarg$~$",
      "$mcname$ pinches $hcname$$ifarg: on the $lastarg$~$",}) }),
  "ping" : ({ ({ 0, "%s" }), ({
      "You ping $hcname$", "$mcname$ pings you$force#ack $mname$#2$",
      "$mcname$ pings $hcname$" })  }),
  "plead" : ({ ({ 3, "%s", }), ({
      "$mcname$ pleads for $arg:mercy,frogs,lots of money,a Decstation 5000,"+
          "this stupid soul to go away,an X windows terminal,insanity,"+
          "creators,bil,pinkfish's sanity,miserably$",
      "$mcname$ pleads for $lastarg$", }) }),
  "point" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 2, "at %s %s" }), ({
      "You point$ifarg: $arg:accusingly,straight$~$ at $hcname$",
      "$mcname$ points$ifarg: $lastarg$~$ at you",
      "$mcname$ points$ifarg: $lastarg$~$ at $hcname$" }) }),
  "poke" : ({ ({ 0, "%s", 2, "%s in the %s", 2, "%s in %s", 2, "%s %s", 1, "%s %s" }), ({
      "You poke $hcname$$ifarg: in the $arg:eyes,ribs,legs,nose,ear,"+
             "stomach,#$~$",
      "$mcname$ pokes you$ifarg: in the $arg:eyes,ribs,legs,nose,ear,"+
             "stomach,#$~$",
      "$mcname$ pokes $hcname$$ifarg: in the $arg:eyes,ribs,legs,nose,ear,"+
             "stomach,#$~$"}) }),
  "ponder" : ({ 0, ({
      "You ponder the situation",
      "$mcname$ ponders the situation" }) }),
  "pounce" : ({ ({ 0, "on %s", 2, "on %s %s", 1, "%s %s", 2, "%s %s", 0, "%s" }), ({
      "You pounce on $hcname$$ifarg: $arg:excitedly,seductively,madly,"+
           "carefully,appreciately$~$",
      "$mcname$ pounces on you$ifarg: $lastarg$~$",
      "$mcname$ pounces on $hcname$$ifarg: $lastarg$~$", }), }),
  "pout" : ({ ({ 3, "%s" }), ({
      "You pout$ifarg: $arg:childishly,silently,resignedly$~$",
      "$mcname$ pouts$ifarg: $lastarg$~$" }) }),
  "praise" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You praise $arg:rabbits and all their little warens,#$",
      "$mcname$ praises $lastarg$",
      "You praise $ifarg:$mhcname$ $arg:great daring and cunning,"+
          "method of jogging on the spot,way of breaking out the rabbits,"+
          "conversational tactics,#$$else$$hcname$~$",
      "$mcname$ praises $ifarg:your $lastarg$$else$you~$",
      "$mcname$ praises $ifarg:$mhcname$ $lastarg$$else$$hcname$~$", }), }),
  "protest" : ({ ({ 3, "%s" }), ({
      "You protest$ifarg: $arg:vehemently,loudly,strongly,weakly,"+
                              "noisily,pointlessly,annoyingly,#$~$",
      "$mcname$ protests$ifarg: $lastarg$~$" }) }),
  "puke" : ({ ({ 0, "on %s", 0, "%s", 0, "at %s"  }), ({
      "You brighten up the place", "$mcname$ does a technicolour yawn",
      "You puke on $hcname$", "$mcname$ pukes on you",
      "$mcname$ pukes on $hcname$" }) }),
  "punch" : ({ ({ 0, "%s" }), ({
      "You punch yourself",
      "$mcname$ punches $mobj$self",
      "You punch $hcname$",
      "$mcname$ punches You",
      "$mcname$ punches $hcname$", }) }),
  "purr" : ({ ({ 3, "%s" }), ({
      "You purr $arg:contentedly,loudly,happily,sensuously$",
      "$mcname$ purrs $lastarg$" }) }),
  "push" : ({ ({ 0, "%s", }), ({
      "You push yourself over",
      "$mcname$ pushes $mobj$self over",
      "You push $hcname$ over",
      "$mcname$ pushes you over",
      "$mcname$ pushes $hcname$ over", }) }),
  "puzzle" : ({ ({ 3, "%s" }), ({
      "$ifarg:You puzzle over $arg:#$$else$You look puzzled~$",
      "$mcname$ $ifarg:puzzles over $lastarg$$else$looks puzzled~$", }) }),
  "quirk" : ({ 0, ({
      "You quirk one eyebrow",
      "$mcname$ quirks one eyebrow" }) }),
  "quiver" : ({ 0, ({
      "You quiver",
      "$mcname$ quivers" }), }),
  "ram" : ({ ({0 ,"%s", 1, "%s %s", 2, "%s %s", 3, "%s"}), ({
      "$ifarg:You ram the $arg:#$$else$You ram the nearest turtle~$",
      "$mcname$ $ifarg:rams the $lastarg$$else$rams the nearest "+
      "turtle. <thwok>~$",
      "You ram $ifarg:$mhcname$ $arg:#$$else$$arg:#$~$",
      "$mcname$ $ifarg:rams into your $arg:#$$else$rams into you~$",
      "$mcname$ $ifarg:rams into $mhcname$ $arg:#$$else$rams into $hcname$~$"
      }), }),

  "roll" : ({ ({ 2, "%s %s", 1, "%s %s", 3, "%s", 0, "%s" }), ({
      "You roll $arg:your eyes,around on the floor laughing,"+
             "over and play dead,up into a ball,your own cigarette,"+
             "sideways,backwards,professionaly,like a spy through an "+
             "imaginary door,fearfully,tightly,slowly$",
      "$mcname$ rolls $lastarg$",
      "You roll $ifarg:$arg:quickly,slowly,painfully,excitededly,lovingly,"+
             "carefully$ ~$over $hcname$",
      "$mcname$ rolls $ifarg:$lastarg$ ~$over you",
      "$mcname$ rolls $ifarg:$lastarg$ ~$over $hcname$" }) }),
  "ruffle" : ({ ({ 0, "%s", 2, "%s %s", 1, "%s %s" }), ({
      "You ruffle $mhcname$ hair$ifarg: $arg:playfully,affectionately$~$",
      "$mcname$ ruffles your hair$ifarg: $lastarg$~$",
      "$mcname$ ruffles $mhcname$ hair$ifarg: $lastarg$~$" }) }),
  "scratch" : ({ ({0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You scratch your $arg:head,leg,arm,nose,ear,finger,bum,"+
                         "cat behind the ears$",
      "$mcname$ scratches $mposs$ $lastarg$",
      "$ifarg:You $arg:visciously,slightly,wombely$ scratch $mhcname$ "+
           "head$else$You scratch $hcname$~$",
      "$ifarg:$mcname$ $lastarg$ scratches your head$else$"+
           "$mcname$ $lastarg$ scratches you~$",
      "$mcname$ $ifarg:$lastarg$ ~$scratches $mhcname$ head"
           }) }),
  "scream" : ({ ({ 3, "%s", 3, "in %s" }), ({
      "$ifarg:You scream in $arg:terror,fright,fear,pain,surprise,frustration,"+
      "despair,anger$$else$Arrggghhhhh!!!!~$",
      "$mcname$ screams$ifarg: in $lastarg$$else$ loudly~$" }) }),
  "scoff" : ({ ({ 3, "%s", }), ({
      "You scoff$ifarg: $arg:loudly,sarcastically,sweetly,sardonicaly$~$",
      "$mcname$ scoffs$ifarg: $lastarg$~$", }) }),
  "scold" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You scold $hcname$$ifarg: $arg:playfully,mercilessly,emphathatically,"+
            "whilst stifling a giggle,lovingly,sneakily,pointlessly,"+
            "uselessly,loudly,endlessly,irritatedly,conviently$~$",
      "$mcname$ scolds you$ifarg: $lastarg$~$",
      "$mcname$ scolds $hcname$$ifarg: $lastarg$~$", }), }),
  "scowl" : ({ ({ 0, "%s" }), ({
      "You scowl", 
      "$mcname$ scowls",
      "You scowl at $hcname$",
      "$mcname$ scowls at you",
      "$mcname$ scowls at $hcname$" }) }),
  "shake" : ({ ({ 0, "%s", 1, "%s with %s", 1, "%s %s", 1, "%s %s", 3, "%s",
                  1, "%s at %s", 3, "my %s", }), ({
      "You shake your head$ifarg: $arg:sorrowfully,carefully,slowly,"+
          "once,quickly,curtly,pinkly,vigorously,completely,fishily,sadly,"+
          "tentatively,in agreement,in disbelief$~$",
      "$mcname$ shakes $mposs$ head$ifarg: $lastarg$~$",
      "You shake$ifarg: $arg:hands with,fins with,fingers with,legs with,"+
             "pinkys with,tentacles with,your fist at$~$ $hcname$",
      "$mcname$ shakes$ifarg: $lastarg$~$ you",
      "$mcname$ shakes$ifarg: $lastarg$~$ $hcname$" }) }),
  "shiver" : ({ ({ 3, "with %s", 3, "in %s" }), ({
      "You shiver$ifarg: $arg:fear,with cold,slightly,#$~$",
      "$mcname$ shivers$ifarg: $lastarg$~$" }) }),
  "shrug" : ({ ({ 3, "%s", }), ({
       "You shrug$ifarg: $arg:resignedly,tiredly,happily,confusedly,"+
            "uncareingly,like ember$~$",
       "$mcname$ shrugs$ifarg: $lastarg$~$", }) }),
  "shudder" : ({ ({ 3, "%s" }), ({
      "You shudder $ifarg:in $arg:fear,revulsion,disapointment,ecstasy"+
      "$$else$from horror~$",
      "$mcname$ shudders $ifarg:in $lastarg$$else$from horror~$", }) }),
  "shuffle" : ({ 0, ({
      "You shuffle your feet in embaresment",
      "$mcname$ shuffles $mposs$ feet in embaresment", }), }),
  "sigh" : ({ ({ 3, "%s" }), ({
      "You sigh$ifarg: $arg:deeply,silently,desperately,tiredly,sadly,slowly,"+
        "dreamily,happily,melodramiticaly,wistfully,"+
        "dramaticaly,"+
        "heavily,suggestively,sarcastically,in relief,with relief$~$",
      "$mcname$ sighs$ifarg: $lastarg$~$" }) }),
  "sing" : ({ ({ 0, "%s", 3, "%s" }), ({
      "You sing $arg:in appreciation of life,#$",
      "$mcname$ $ifarg:sings $lastarg$$else$bursts out into song~$",
      "You seranade $hcname$",
      "$mcname$ seranades you",
      "$mcname$ seranades $hcname$" }) }),
  "sit" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You sit down$ifarg: $arg:quickly,slowly,clumsily,carefully,"+
          "thoughtfully,with one hand tied behind your back,"+
          "in shock,gracefully,gratefully,inconsiderately$~$",
      "$mcname$ sits down$ifarg: $lastarg$~$",
      "You sit on $mhcname$ $arg:lap,face,leg,chest,arm,cat,sofa,"+
           "computer,keyboard,dinner$",
      "$mcname$ sits on your $lastarg$",
      "$mcname$ sits on $mhcname$ $lastarg$", }), }),
  "skip" : ({ ({ 0, "%s", }), ({
      "You skip around happily",
      "$mcname$ skips around happily",
      "You skip around $hcname$",
      "$mcname$ skips around you",
      "$mcname$ skips around $hcname$", }), }),
  "slap" : ({ ({ 0, "%s" }), ({
      "You slap your forehead",
      "$mcname$ slaps $mposs$ forehead",
      "You slap $hcname$$ifarg: $arg:hard,harder,really hard,incredibly hard,"+
           "with a frog,with a gauntlet,with a fish,twice,visciously,"+
           "carefully,lovingly$~$",
      "$mcname$ slaps you$ifarg: $lastarg$~$",
      "$mcname$ slaps $hcname$$ifarg: $lastarg$~$" }) }),
  "sleep" : ({ ({ 0, "%s" }), ({
      "You go to sleep",
      "$mcname$ goes to sleep",
      "You go to sleep in $mhcname$ arms",
      "$mcname$ go to sleep in your arms",
      "$mcname$ goes to sleep in $mhcname$ arms", }) }),
  "slobber" : ({ ({ 0, "%s" }), ({
      "You slobber all over the place",
      "$mcname$ slobbers all over the place",
      "You slobber all over $hcname$",
      "$mcname$ slobbers all over you",
      "$mcname$ slobbers all over $hcname$", }), }),
  "smack" : ({ ({ 0, "%s" }), ({
      "You smack your lips",
      "$mcname$ smacks $mposs$ lips",
      "You smack $hcname$$ifarg: $arg:furiously,with gusto,without a care,"+
                "twice,lots of times,happily,nastily,excitedly$~$",
      "$mcname$ smacks you$ifarg: $lastarg$~$",
      "$mcname$ smacks $hcname$$ifarg: $lastarg$~$", }), }),
  "smirk" : ({ ({ 0, "%s" }), ({ 
      "You smirk",
      "$mcname$ smirks",
      "You smirk at $hcname$",
      "$mcname$ smirks at you",
      "$mcname$ smirks at $hcname$", }) }),
  "smirkle" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You smirkle$ifarg: $arg:happily,sadly,like truilkan,sardonicaly$~$",
      "$mcname$ smirkles$ifarg: $lastarg$~$",
      "You smirkle$ifarg: $arg:happily,sadly,like truilkan,sardonicaly$~$ at $hcname$",
      "$mcname$ smirkles$ifarg: $lastarg$~$ at you",
      "$mcname$ smirkles$ifarg: $lastarg$~$ at $hcname$", }), }),
  "smile" : ({ ({
      0, "at %s", 0, "%s", 1, "%s at %s", 1, "%s %s", 2, "at %s %s",
      2, "%s %s", 3, "%s", }), ({
	  "You smile$ifarg: $arg:happily,sadly,nervously,wryly,broadly,crookedly,"+
	  "stupidly,idiotically,condescendingly,ironically,patiently,brightly,"+
	  "slightly,nastily,excitedly,strangely,with forced patience,plasticly,"+
	  "carefully,sadistically,lopsidedly,fishily,catishly,faintly,"+
	  "like a train,angrily,paranoically,innocently,frogily,slyly,"+
	  "weakly,humbly,paradoxicaly,sarcastically,viciously,garishly,"+
          "sweetly,innocently,lovingly,dreamily,radiantly,enthusiastically,"+
	  "insolently,quirkily,completely,unconsciously,drunkenly,"+
          "insanely,cutely,maliciously,smugly,"+
	  "absentmindedly,curtly,disturbingly,unbeliveably,quietly,"+
	  "loudly,differently,winningly,in triumph,seductively,"+
          "tightly,gosh there are lots of arguments,softly,"+
          "lividly,demonically,warmly,grimly,"+
          "indolently,ingeniously,wickedly,contentedly,statisticaly,"+
          "spasmodically,incandecently,pleasantly,with menace,"+
	  "manically,warily,sardonically,lazily,serenely,disappointedly$~$",
	  "$mcname$ smiles$ifarg: $lastarg$~$",
	  "You smile$ifarg: $arg:happily,sadly,nervously,wryly,broadly,crookedly,"+
	  "stupidly,idiotically,condescendingly,ironically,patiently,brightly,"+
	  "slightly,nastily,excitedly,strangely,with forced patience,plasticly,"+
	  "manically,carefully,sadistically,lopsidedly,fishily,catishly,faintly,"+
	  "weakly,humbly,paradoxicaly,sarcastically,viciously,garishly,"+
	  "insolently,quirkily,completely,unconsciously,drunkenly,"+
	  "absentmindedly,curtly,disturbingly,unbeliveably,quietly,"+
	  "loudly,differently,winningly,in triumph,seductively,"+
          "sweetly,innocently,lovingly,dreamily,radiantly,enthusiastically,"+
	  "like a train,angrily,paranoically,innocently,frogily,slyly,"+
	  "macabrely,ruefully,tentatively,like a dog,"+
          "tightly,gosh there are lots of aruments,softly,"+
          "insanely,cutely,maliciously,smugly,grimly,"+
          "lividly,demonicaly,"+
          "indolently,ingeniously,wickedly,contentedly,statisticaly,"+
          "spasmodically,incandecently,pleasantly,with menace,"+
	  "sardonically,warily,lazily,serenely,disappointedly$~$ at $hcname$",
	  "$mcname$ smiles$ifarg: $lastarg$~$ at you",
	  "$mcname$ smiles$ifarg: $lastarg$~$ at $hcname$" }) }),
  "smug" : ({ 0, ({
      "You look smug",
      "$mcname$ looks smug", }) }),
  "snap" : ({ ({ 0, "%s", 1, "%s at %s", 1, "my %s at %s", 3, "%s" }), ({
      "You snap your $arg:fingers,leg,arm in a quick salute$",
      "$mcname$ snaps $mposs$ $lastarg$",
      "You snap your $arg:fingers,leg,arm in a quick salute$ at $hcname$",
      "$mcname$ snaps $mposs$ $lastarg$ at you",
      "$mcname$ snaps $mposs$ $lastarg$ at $hcname$" }) }),
  "snarl" : ({ ({ 0, "%s", 1, "%s at %s", 1, "%s %s", 2, "at %s %s" }), ({
      "You snarl $arg:visiously,nastily,demonicaly,happily,sadly,"+
         "unexpectedly,suddenly$ at $hcname$",
      "$mcname$ snarls $lastarg$ at you",
      "$mcname$ snarls $lastarg$ at $hcname$", }) }),
  "sneer" : ({ ({ 0, "%s" }), ({
      "You sneer at $hcname$",
      "$mcname$ sneers at you",
      "$mcname$ sneers at $hcname$", }) }),
  "sneeze" : ({ ({ 0, "at %s", 2, "%s at %s", 3, "%s" }), ({
      "You sneeze $arg:violently,loudly,silently,quietly,suddenly,unexpectedly$",
      "$mcname$ sneezes $lastarg$",
      "You sneeze $arg:violently,loudly,silently,quietly,suddenly,unexpectedly$"+
      " at $hcname$",
      "$mcname$ sneezes $lastarg$ at you",
      "$mcname$ sneezes $lastarg$ at $hcname$" }) }),
  "snicker" : ({ ({ 3, "%s" }), ({
      "You snicker$ifarg: $arg:mischieviously,nastily,a bit,like skippy$~$",
      "$mcname$ snickers$ifarg: $lastarg$~$" }) }),
  "sniff" : ({ ({ 3, "%s" }), ({
      "You sniff$ifarg: $arg:dejectedly,noisily,silently,loudly,in disdain$~$",
      "$mcname$ sniffs$ifarg: $lastarg$~$" }) }),
  "snigger" : ({ 0, ({
      "You snigger",
      "$mcname$ sniggers", }) }),
  "snore" : ({ 0, ({
      "You snore loudly",
      "$mcname$ snores loudly" }) }),
  "snort" : ({ 0, ({
      "You snort",
      "$mcname$ snorts", }) }),
  "snuggle" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You snuggle up to $hcname$ $arg:affectionately,warmly,gently$",
      "$mcname$ snuggles up to you $lastarg$",
      "$mcname$ snuggles up to $hcname$ $lastarg$" }) }),
  "sob" : ({ ({ 0, "%s", 3, "%s",  0, "on %s" }), ({
      "You sob $arg:quietly,loudly,despairingly,forlornly,happily,"+
               "completely,unexpectedly,silently,cheekily$",
      "$mcname$ sobs $lastarg$",
      "You sob on $mhcname$ shoulder",
      "$mcname$ sobs on your shoulder",
      "$mcname$ sobs on $mhcname$ shoulder", }) }),
  "sorry" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", }), ({
      "You appologise$ifarg: $arg:profusely,reservedly,profunctily,"+
      "carefully,insultingly,insolently$~$ to $hcname$",
      "$mcname$ appologises$ifarg: $lastarg$~$ to you",
      "$mcname$ appologises$ifarg: $lastarg$~$ to $hcname$", }) }),
  "spank" : ({ ({ 0, "%s", 2, "%s %s" }), ({
      "You spank $hcname$$ifarg: $arg:seductively,carefully,gently,"+
      "uncontrollably,politely,sensuously,selectively,unexpectedly,"+
      "with an evil smirk,painfully,sneakily,unprovoked,professionaly,vigorously,"+
      "reflexively,with a cat,like a train,like a virgin mary,"+
      "with a virgin mary$~$",
      "$mcname$ spanks you$ifarg: $lastarg$~$",
      "$mcname$ spanks $hcname$$ifarg: $lastarg$~$", }) }),
  "spin" : ({ ({ 3, "%s", }), ({
      "You spin $arg:around like a top,about deleriously$",
      "$mcname$ spins $lastarg$", }), }),
  "spit" : ({ ({ 0, "%s", 0, "at %s" }), ({
      "You spit.",
      "$mcname$ spits.",
      "You spit in $mhcname$ face",
      "$mcname$ spits in your face",
      "$mcname$ spits in $mhcname$ face" }) }),
  "spock" : ({ 0, ({
      "You raise one eyebrow",
      "$mcname$ raises one eyebrow", }) }),
  "squeal" : ({ ({ 3, "%s" }), ({
      "You squeal in $arg:delight,terror,pain,mortal fear$",
      "$mcname$ squeals in $lastarg$", }), }),
  "squeeze" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "You squeeze $hcname$ $arg:fondly,gently,tightly$",
      "$mcname$ squeezes you $lastarg$",
      "$mcname$ squeezes $hcname$ $lastarg$" }) }),
  "stagger" : ({ ({ 3, "%s" }), ({
      "You stagger around$ifarg: $arg:#$~$",
      "$mcname$ staggers around$ifarg: $lastarg$~$" }) }),
  "stamp" : ({ ({ 3, "%s", }), ({
      "You stamp your foot$ifarg: $arg:angrily,impatiently,warningly,"+
      "fighteningly$~$",
      "$mcname$ stamps $mposs$ foot$ifarg: $lastarg$~$" }) }),
  "stand" : ({ ({ 3, "%s", }), ({
      "You stand $arg:in uffish thought,about,patiently,on one hand$",
      "$mcname$ stands $lastarg$" }) }),
  "stare" : ({ ({ 0, "%s", 1, "%s %s", 1, "%s at %s", 3, "%s" }), ({
      "You stare$ifarg: $arg:happily,sadly,worriedly,lazily,rudely,dazedly,"+
         "hungrily,macabrely,absent-mindedly,fanaticaly,lovingly,"+
         "respectfully,womblely,frogily,desperately,sternly,"+
         "tentatively,politely,listlessly,jealously,enviously,"+
         "dreamily,intently,mindlessly,expectantly,longingly$~$ into space",
      "$mcname$ stares$ifarg: $lastarg$~$ into space",
      "You stare$ifarg: $arg:happily,sadly,worriedly,lazily,rudely,dazedly,"+
         "hungrily,macabrely,absent-mindedly,fanaticaly,lovingly,"+
         "respectfully,womblely,frogily,desperately,sternly,"+
         "tentatively,politely,listlessly,jealously,enviously,"+
         "dreamily,intently,mindlessly,romantically,expectantly,longingly,"+
         "continuously,annoyingly$~$ at $hcname$",
      "$mcname$ stares$ifarg: $lastarg$~$ at you",
      "$mcname$ stares$ifarg: $lastarg$~$ at $hcname$" }) }),
  "stifle" : ({ 0, ({
      "You stifle a giggle",
      "$mcname$ stifles a giggle", }) }),
  "strangle" : ({ ({ 0, "%s", 1, "%s about %s", 1, "%s %s" }), ({
      "You strangle yourself",
      "$mcname$ strangles $mobj$self",
      "You strangle $hcname$$ifarg: about $arg:#$~$",
      "$mcname$ strangles you$ifarg: about $arg:#$~$",
      "$hcname$ strangles $mcname$$ifarg: about $arg:#$~$", }) }),
  "stretch" : ({ ({ 3, "%s" }), ({
      "You stretch$ifarg: $arg:lazily,slowly,seductively,carefully,excitedly,"+
           "sleepily,sadly,happily,your legs,your arms,your eyebrows$~$",
      "$mcname$ stretches$ifarg: $lastarg$~$", }), }),
  "stroke" : ({ ({ 0, "%s" }), ({
      "You stroke $hcname$",
      "$mcname$ strokes you",
      "$mcname$ strokes $hcname$", }) }),
  "strut" : ({ 0, ({
      "You strut your stuff",
      "$mcname$ struts proudly around the room" }) }),
  "stumble" : ({ ({ 3, "%s" }), ({
      "You stumble $ifarg:$arg:#$$else$around the room~$",
      "$mcname$ stumbles $ifarg:$arg:#$$else$around the room~$" }) }),
  "suck" : ({ ({ 3, "%s" }), ({ 
      "You suck your $arg:thumb,pen,#$",
      "$mcname$ sucks $mposs$ $lastarg$" }) }),
  "sulk" : ({ 0, ({
      "You sulk in the corner",
      "$mcname$ sulks in the corner" }) }),
  "swear" : ({ ({ 3, "%s" }), ({
      "You swear $arg:violently,loudly,on $mposs$ mothers grave$",
      "$mcname$ swears $lastarg$", }), }),
  "sweat" : ({ ({ 0, "%s", 1, "%s on %s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "You sweat $arg:profusely,vigourously,wetly,rudely,petrol,bricks,"+
             "buckets,buckets of igloos,artichokes,"+
             "loudly,igloos,silently,anxiously,patiently,hotly$",
      "$mcname$ sweats $lastarg$", 
      "You sweat $arg:profusely,vigourously,wetly,rudely,petrol,bricks,"+
             "buckets,buckets of igloos,artichokes,"+
             "loudly,igloos,silently,anxiously,patiently,hotly$ on $hcname$",
      "$mcname$ sweats $lastarg$ on you",
      "$mcname$ sweats $lastarg$ at $hcname$", }), }),
  "swim" : ({ 0, ({
      "You give a good imitation of swimming", "$mcname$ swims around" }) }),
  "tackle" : ({ ({ 0, "%s", }), ({
      "You tackle $hcname$ in the $arg:chest,leg,arm,nose,knee,head,"+
      "foot,toe,finger$",
      "$mcname$ tackles you in the $lastarg$",
      "$mcname$ tackles $hcname$ in the $lastarg$", }) }),
  "tap" : ({ ({ 
      0, "%s", 2, "%s on the %s", 2, "%s on %s",
      2, "%s %s", 1, "%s %s", 3, "%s" }), ({ /* this is furrys */
	  "You tap your $arg:foot,head,left leg,right leg,fingers,nose,"+
	  "shoulder,teeth,arm$ impatiently",
	  "$mcname$ taps $mposs$ $lastarg$ impatiently",
	  "You tap $hcname$ on the $arg:shoulder,head,arm,nose,leg,teeth,foot,ear,"+
	  "frog,other thing$",
	  "$mcname$ taps you on the $lastarg$",
	  "$mcname$ taps $hcname$ on the $lastarg$" }) }),
  "taunt" : ({ ({ 0, "%s" }), ({
      "You taunt yourself",
      "$mcname$ taunts $mposs$sely, how strange",
      "You taunt $hcname$",
      "$mcname$ taunts you",
      "$mcname$ taunts $hcname$" }) }),
  "tease" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", }), ({
      "You tease yourself",
      "$mcname$ teases $mbj$self, he appears to enjoy it",
      "You tease $hcname$ $arg:mercilessly,insistantly,annoyingly,"+
           "lovingly,mischieviously,rudely,carefully,quickly,slowly,"+
           "halfheartedly,idlely,obnoxiously$",
      "$mcname$ teases you $lastarg$",
      "$mcname$ teases $hcname$ $lastarg$", }) }),
  "thank" : ({ ({ 0, "%s", 2, "%s %s" }), ({
      "You thank $hcname$$ifarg: $arg:profusely,gratuitously,lots,slightly,"+
      "reservedly$~$",
      "$mcname$ thanks you$ifarg: $lastarg$~$",
      "$mcname$ thanks $hcname$$ifarg: $lastarg$~$" }) }),
  "think" : ({ ({ 3, "%s", }), ({
      "You think $ifarg:$arg:#$$else$carefully~$",
      "$mcname$ thinks $ifarg:$lastarg$$else$carefully~$" }) }),
  "throw" : ({ ({ 0, "%s" }), ({
      "Hi yyyyaaa",
      "$mcname$ throws you to the floor$force#smile h at $mname$#2$",
      "$mcname$ throws $hcname$ to the floor in a happy embrace" }) }),
  "thwok" : ({ ({ 0, "%s"  }), ({
      "T H W O K K ! !",
      "$mcname$ \"T H W O K K ! !\"s",
      "You thwok $hcname$",
      "You are summarily thwokked by $mcname$",
      "$mcname$ thwoks $hcname$" }) }),
  "tickle" : ({ ({ 0,"%s", 1, "%s %s", 2, "%s %s" }), ({
      "You tickle $hcname$$ifarg: $arg:mercilessly,ruthlessly,fearlessly,"+
            "quickly,sneakily,weakly,carefully,gently,harshly,inconcievablely "+
            "slowly,incessantly$~$",
      "$mcname$ tickles you$force#giggle#2$$ifarg: $lastarg$~$",
      "$mcname$ tickles $hcname$$ifarg: $lastarg$~$" }) }),
  "titter" : ({ 0, ({
      "You titter$ifarg: $arg:quietly,silently,sarcastically,falsely$~$",
      "$mcname$ titters$ifarg: $lastarg$~$", }), }),
  "tongue" : ({ ({ 0,"%s", }), ({
      "You poke your tongue out at $hcname$",
      "$mcname$ pokes $mposs$ tongue out at you",
      "$mcname$ pokes $mposs$ tongue out at $hcname$", }) }),
  "tousle" : ({ ({ 0, "%s" }), ({
      "You tousle $mhcname$ hair",
      "$mcname$ tousles your hair",
      "$mcname$ tousles $mhcname$ hair", }), }),
  "tower" : ({ ({ 0, "over %s", 0, "%s", 2, "over %s %s" }), ({
      "You tower over $hcname$$ifarg: $arg:ominously,threateningly$~$",
      "$mcname$ towers over you$ifarg: $lastarg$~$",
      "$mcname$ towers over $hcname$$ifarg: $lastarg$~$", }), }),
  "tremble" : ({ ({ 3, "%s" }), ({
      "You tremble $arg:in fear,in nervousness,in pain,slightly,violently,"+
           "insistantly,carefully,in a pink fit,in anticip.......pation$",
      "$mcname$ trembles $lastarg$", }), }),
  "trip" : ({ ({ 0, "%s" }), ({
      "You trip up",
      "$mcname$ trips up",
      "You trip $hcname$",
      "$mcname$ trips you",
      "$mcname$ trips $hcname$" }) }),
  "tumble" : ({ 0, ({
      "You tumble head of heels",
      "$mcname$ tumbles head over heels", }), }),
  "twang" : ({ ({ 0, "%s", 1, "%s %s", 1, "%s at %s", 2, "%s %s", 3, "%s" }), ({
      "You twang $arg:calmly,with the wolves,a nice little tune,"+
          "up,down,manicaly,rythmicaly,undieingly,backwards,"+
          "beautifully,upsidedown$",
      "$mcname$ twangs $lastarg$",
      "You twang $arg:calmly,with the wolves,a nice little tune,"+
          "up,down,manicaly,rythmicaly,undieingly,backwards,"+
          "beautifully,upsidedown$ at $hcname$",
      "$mcname$ twangs $lastarg$ at you",
      "$mcname$ twangs $lastarg$ at $hcname$", }), }),
  "tweak" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", }), ({
      "You tweak $mhcname$ $arg:bottom,ear,arm,leg,nose,bits$",
      "$mcname$ tweaks your $lastarg$",
      "$mcname$ tweaks $mhcname$ $lastarg$" }), }),
  "twiddle" : ({ ({ 3, "%s" }), ({
      "You twiddle your $arg:thumbs,fingers,hair,nose$",
      "$mcname$ twiddles $mposs$ $lastarg$" }) }),
  "twitch" : ({ ({ 3, "%s" }), ({
       "You twitch your $arg:nose,arm,body,finger,igloo$",
       "$mcname$ twitches $mposs$ $lastarg$" }) }),
  "umm" : ({ 0, ({
       "You scratch your chin and say: \"Ummmm\"",
       "$mcname$ scratches $mposs$ chin and says: \"Ummmm\"" }), }),
  "wake" : ({ ({ 0, "%s", 3, "%s" }), ({
       "You wake $arg:up,up and smell the cat food,the wombles of the world "+
              "up$",
       "$mcname$ wakes up",
       "You wake up $hcname$",
       "$mcname$ wakes you up",
       "$mcname$ wakes up $hcname$", }), }),
  "waggle" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 1, "%s %s",
                   2, "%s %s", }), ({
      "$ifarg:You waggle your $arg:arm,leg,head,nose,ear,frog,pinky,eyebrows,"+
           "toe$$else$What did $hcname$ do wrong??!?~$",
      "$mcname$ waggles $mposs$ $ifarg:$lastarg$$else$finger~$ at you",
      "$mcname$ waggles $mposs$ $ifarg:$lastarg$$else$finger~$ at $hcname$",
        }) }),
  "waltz" : ({ ({ 0, "%s", }), ({
      "You waltz around the room with $hcname$",
      "$mcname$ waltzs around the room with you",
      "$mcname$ waltzs around the room with $hcname$", }) }),
  "wave" : ({ ({
      0, "%s", 0, "at %s", 0, "to %s", 2, "at %s %s", 1, "%s %s", 
      1, "%s to %s", 2, "to %s %s", 0, "at %s", 1, "%s at %s",
      2, "%s %s", 3, "%s" }), ({
	  "You wave$ifarg: $arg:tiredly,sleepily,profunctialy,lazily,sadly,"+
	    "happily,redundantly,forlornly,excitedly,longingly,pointlessly,"+
            "your tentacles,madly,insanely,with complete devotion$~$",
	  "$mcname$ waves$ifarg: $lastarg$~$",
	  "You wave$ifarg: $arg:sleepily,tiredly,profunctialy,lazily,sadly,"+
	    "happily,forlornly,excitedly,longingly,redundantly,pointlessly,"+
	    "passionately,greenly,your tentacles,madly,insanely,"+
            "with complete devotion$~$ to $hcname$",
	  "$mcname$ waves$ifarg: $lastarg$~$ to you",
	  "$mcname$ waves$ifarg: $lastarg$~$ to $hcname$" }) }),
  "weep" : ({ ({ 0, "%s", 0, "for %s", 3, "%s" }), ({
      "You weep $arg:unashamedly,sadly,uncontrollably$",
      "$mcname$ weeps $lastarg$",
      "You weep with $hcname$",
      "$mcname$ weeps with you",
      "$mcname$ weeps with $hcname$", }), }),
  "wibble" : ({ ({ 3, "%s" }), ({
      "You wibble $arg:like bil,loudly,constantly,anoyingly,"+
           "around,up,down,sideways$",
      "$mcname$ wibbles $lastarg$", }) }),
  "wimper" : ({ ({ 3, "%s" }), ({
      "You wimper$ifarg: $arg:painfully,feafully,carefully,dimuatively,"+
            "happily,winningly,in triumph,with the wombles$~$",
      "$mcname$ wimpers$ifarg: $lastarg$~$", }), }),
  "whicker" : ({ 0, ({
      "You wicker like a horse",
      "$mcname$ whickers like a horse", }) }),
  "whine" : ({ ({ 0, "%s", 1, "%s %s", 1, "%s to %s", 2, "%s %s", 3, "%s" }), ({
      "You whine $arg:patheticaly,#$",
      "$mcname$ whines $lastarg$",
      "You whine $arg:patheticaly,#$ to $hcname$",
      "$mcname$ whines $lastarg$ to you",
      "$mcname$ whines $lastarg$ to $hcname$", }), }),
  "whistle" : ({ ({ 0, "%s %s", 2, "%s at %s", 3, "%s" }), ({
      "You whistle $arg:innocently,appreciatively,loudly,musically,pleasantly,"+
          "discordantly,tunelessly$",
      "$mcname$ whistles $lastarg$",
      "You whistle $arg:appreciatively,innocently,loudly,musically,pleasantly,"+
          "discordantly,tunelessly$",
      "$mcname$ whistles $lastarg$ at you",
      "$mcname$ whistles $lastarg$ at $hcname$" }) }),
  "wince" : ({ 0, ({ "You wince", "$mcname$ winces" }) }),
  "wiggle" : ({ ({ 0, "%s", 2, "%s at %s", 3, "%s" }), ({
      "You wiggle your bottom$ifarg: $arg:enticingly,suggestively,vigourously,"+
        "arrogantly,nonchalantly,quickly,tunelessly$~$",
      "$mcname$ wiggles $mposs$ bottom$ifarg: $lastarg$~$",
      "You wiggle your bottom$ifarg: $arg:enticingly,suggestively,vigourously,"+
      "arrogantly,nochalantly,quickly$~$ at $hcname$",
      "$mcname$ wiggles $mposs$ bottom$ifarg: $lastarg$~$ at you",
      "$mcname$ wiggles $mposs$ bottom$ifarg: $lastarg$~$ at $hcname$" }) }),
  "wink" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 1, "%s %s",
                 2, "at %s %s", 2, "%s %s", 3, "%s" }), ({
      "You wink$ifarg: $arg:suggestively,broadly,slowly,loudly,grumpily,"+
           "despairingly,coyly,desperately,insolently,curtly,lovingly,"+
           "coquettishly,knowingly,"+
           "patiently,sadistically,warily,seducitive,lazily$~$",
      "$mcname$ winks$ifarg: $lastarg$~$",
      "You wink$ifarg: $arg:suggestively,broadly,slowly,loudly,grumpily,"+
           "despairingly,coyly,desperately,insolently,curtly,lovingly,"+
           "coquettishly,knowingly,"+
           "patiently,sadistically,warily,seducitive,lazily$~$ at $hcname$",
      "$mcname$ winks$ifarg: $lastarg$~$ at you",
      "$mcname$ winks$ifarg: $lastarg$~$ at $hcname$" }) }),
  "wipe" : ({ ({ 0, "%s", 0, "on %s", 1, "%s on %s", 3, "the %s", 3, "%s" }), ({
      "You wipe the $arg:sweat from your brow,smile off your face$",
      "$mcname$ wipes the $lastarg$",
      "You wipe your $arg:hands,leg,arm,nose$ on $hcname$",
      "$mcname$ wipes $mposs$ $lastarg$ on you",
      "$mcname$ wipes $mposs$ $lastarg$ on $hcname$" }) }),
  "wobble" : ({ ({ 3, "%s" }), ({
      "You wobble $arg:around a bit,like jelly,unsteadily,"+
      "happily$",
      "$mcname$ wobbles $lastarg$", }) }),
  "womble" : ({ ({ 0, "%s", 0, "around %s", 1, "%s around %s", 1, "%s %s", 
                   2, "%s %s", 3, "%s", }), ({ 
      "You womble around$ifarg: $arg:#$~$",
      "$mcname$ wombles around$ifarg: $lastarg$~$",
      "You womble around $hcname$ $arg:happily,peacefully,brightly,sadly,"+
             "greenly,oninocoly,welingtonly,bungoly,tomskly,with your frog,"+
             "commonly,twice,once,doing a dance to the great frog in the "+
             "sky$",
      "$mcname$ wombles around you $lastarg$",
      "$mcname$ wombles around $hcname$ $lastarg$" }) }),
  "wonder" : ({ ({ 3, "%s" }), ({
      "You wonder $ifarg:$arg:#$$else$about reality and how "+
      "boring it can be~$",
      "$mcname$ wonder $ifarg:$arg:#$$else$about reality and how "+
      "boring it can be~$", }) }),
  "worship" : ({ ({ 0, "%s", 3, "%s" }), ({
      "You worship $ifarg:$arg:#$$else$pinkfish~$",
      "$mcname$ worships $ifarg:$lastarg$$else$pinkfish~$",
      "You worship $hcname$",
      "$mcname$ worships you", "$mcname$ worships $hcname$" }) }),
  "wrinkle" : ({ ({ 3, "%s", }), ({
      "You wrinkle your $arg:nose,eyes,leg,cat,time,cheese grater$",
      "$mcname$ wrinkles $mposs$ $lastarg$", }) }),
  "yawn" : ({ ({ 3, "%s" }), ({
      "You yawn $arg:tiredly,boredly,sleepily,happily,brightly,in sympathy$",
      "$mcname$ yawns $lastarg$" }) }) ,
  "yodel" : ({ ({ 0, "%s", 1, "%s at %s", 1, "%s %s", 2, "%s %s", 3, "%s", }), ({
      "You yodel $arg:loudly,sadly,annoyingly,feverishly,quickly,tunelessly,"+
                 "incessantly,constantly,to the tune of william tell's "+
                 "overture$",
      "$mcname$ yodels $lastarg$",
      "You yodel $arg:happily,sadly,annoyingly,romanticaly,dreamily,"+
                 "incessantly,constantly,to the tune of william tell's "+
                 "overture,carefully,loudly,sternly,pinkly,like a blackboard,"+
                 "with the frogs$ to $hcname$",
      "$mcname$ yodels $lastarg$ to you",
      "$mcname$ yodels $lastarg$ to $hcname$", }), }),
  "zip" : ({ ({ 0, "%s" }), ({
      "You zip around the room",
      "$mcname$ zips around the room",
      "You zip around $hcname$",
      "$mcname$ zips around you",
      "$mcname$ zips around $hcname$", }), }),
]);
} /* setup() */

string query_long() {
     int i, j;
     string s, s1, s2, bit;
     string data;

     string *cmds;
     mixed  *values;

     s = "Here are the current soul commands in this hoopy soul.\n"+
         "The # before a soul command means it has strange arguments.\n"+
        "The * after a soul command means you can only use it at someone.\n"+
    "Total number of soul data is "+m_sizeof(soul_data)+"\n"+
   "The + after a soul command means you can use it both at someone and not.\n";
     if (calc_long) {
	 s += sprintf("%#-*s\nShare and enjoy.\nPlease use the \"soul\" " +
		      "command to report errors and additions.\n",
		      this_player()->query_cols(), calc_long);
	 return s; 
     }
     cmds   = m_indices(soul_data);
     values = m_values(soul_data);
     j = 0;
     data = "";
     cmds = sort_array(cmds, "soul_sort", this_object());
     for (i = 0; i < sizeof(cmds);i ++) {
	 j++;
	 bit = cmds[i];
         values = soul_data[cmds[i]];
	 if (sizeof(values[1]) == 3) {
	     bit += "*";
	 } else	if (sizeof(values[1]) == 5) {
	     bit += "+";
	 }
	 if (sscanf(values[1][0],"%s$arg:%s",s1,s2) == 2) {
	     bit = "#"+bit;
	 }
	 data += bit+"\n";
     }

     s += sprintf("%#-*s\nShare and enjoy.\nPlease use the \"soul\" command "+
		  "to report errors and additions.\n",
		  this_player()->query_cols(), data);
     calc_long = data;
     return s;
} /* query_long() */

int soul_sort(string s1, string s2) {
  return strcmp(s1, s2);
} /* soul_sort() */

string long(string str, int dark) {
  return query_long();
}
 
parse_string(s,ob,arg,uhn) {
  string s1,s2,s3,s4,str,s5,arr;
  int i;
 
  str=s;
  s4 = "";
  while (sscanf(str,"%s$%s$%s",s1,s2,s3) == 3)
    switch (s2) {
      case "mcname" :
        str = s1+this_player()->query_cap_name()+s3;
        break;
      case "mname" :
        str = s1+this_player()->query_name()+s3;
        break;
      case "mpronoun" :
        str = s1+this_player()->query_pronoun()+s3;
        break;
      case "hpronoun" :
        str = s1+ob->query_pronoun()+s3;
        break;
      case "mobj" :
        str = s1+this_player()->query_objective()+s3;
        break;
      case "hobj" :
        str = s1+ob->query_objective()+s3;
        break;
      case "mposs" :
        str = s1+this_player()->query_possessive()+s3;
        break;
      case "hposs" :
        str = s1+ob->query_possessive()+s3;
        break;
      case "lastarg" :
        str = s1+lastarg+s3;
        break;
      case "mhcname" :
        if (uhn) {
          str = s1+ob->query_cap_name()+"'s"+s3;
          break;
        }
      case "hcname" :
        if (uhn) {
          str = s1+ob->query_cap_name()+s3;
          break;
        }
      case "hname" :
        if (uhn) {
          str = s1+ob->query_name()+s3;
          break;
        }
      default :
        s4 += s1+"$"+s2;
        if (!s3)
          str = "$";
        else
          str = "$"+s3;
        break;
      }
  str = s4+str;
  while (sscanf(str,"%s$force#%s#%d$%s",s1,s2,i,s3)==4) {
    call_out("do_force", i, ({s2, ob}));
    str = s1+s3;
  }
  while (sscanf(str,"%s$arg:%s$%s",s1,s2,s3)==3) {
    if (arg == "?") {
      string *yellow;

      yellow = explode(s2, ",");
      lastarg = yellow[random(sizeof(yellow))];
      str = s1+lastarg+s3;
      lastarg = replace(lastarg, "your", this_player()->query_possessive());
    } else if (s2 == "#") {
      lastarg = replace(arg, "your", this_player()->query_possessive());
      str = s1+arg+s3;
    } else {
      if (sscanf(","+s2+global_adj+",", "%s,"+arg+"%s,%s", s2, s4, s5) == 3) {
        str = s1+arg+s4+s3;
        lastarg = replace(arg+s4, "your", this_player()->query_possessive());
      } else {
        if (sscanf(","+s2+",", "%s,#,%s", s2, s4) == 2) {
          str = s1+arg+s3;
          lastarg = replace(arg, "your", this_player()->query_possessive());
        } else {
          write(
        "You cannot do that. Available options are "+replace(s2,",",", ")+"\n");
          return 0;
        }
      }
    }
  }
  while (sscanf(str,"%s$ifarg:%s~$%s",s1,s2,s3)==3) {
    string estr;
 
    sscanf(s2,"%s$else$%s",s2,estr);
    if (arg && arg != "")
      str = s1+parse_string(s2,ob,arg, 1)+s3;
    else
      if (estr)
        str = s1+parse_string(estr,ob,arg, 1)+s3;
      else
        str = s1+s3;
  }
  return str;
}
 
find_all_liv(str) {
  object ob, ret;
  int i;

  ret = ({ });
  str = lower_case(str);
  if (str == "creators" && this_player()->query_creator() &&
      !this_player()->check_earmuffs("remote-soul")) {
    ob = users();
    for (i=0;i<sizeof(ob);i++)
      if (ob[i] == this_player() || ob[i]->query_invis() || 
          !ob[i]->query_creator() ||
          ob[i]->check_earmuffs("remote-soul")) {
        ob = delete(ob, i, 1);
        i--;
      }
    return ob;
  }
  if (str == "everyone" && this_player()->query_creator() &&
       !environment(this_player())->query_property("no remote") &&
      !this_player()->check_earmuffs("remote-soul")) {
    ob = users();
    for (i=0;i<sizeof(ob);i++)
      if (ob[i] == this_player() || ob[i]->query_invis() || 
          ob[i]->check_earmuffs("remote-soul")) {
        ob = delete(ob, i, 1);
        i--;
      }
    return ob;
  }
  if (str == "someone" && !this_player()->check_earmuffs("remote-soul") &&
      !environment(this_player())->query_property("no remote")) {
    ob = users() - ({ this_player() });
    if (!sizeof(ob)) return ({ this_player() });
    do {
      ret = ob[random(sizeof(ob))];
    } while (ret->check_earmuffs("remote-soul") || ret->query_invis());
    return ({ ret });
  }
  ob = find_match(str,environment(this_player()));
  for (i=0;i<sizeof(ob);i++)
    if (living(ob[i]) && ob[i] != this_player() &&
        member_array(ob[i], ret) == -1)
      ret += ({ ob[i] });
  if (sizeof(ret)) return ret;
  if ((ob = find_living(str)))
    if (member_array(ob, ret) == -1 &&
      !environment(this_player())->query_property("no remote") &&
        !this_player()->check_earmuffs("remote-soul") && 
        !ob->check_earmuffs("remote-soul"))
      ret += ({ ob });
  return ret;
} /* find_all_liv() */

string get_name(object ob) {
  return (string)ob->query_cap_name();
}
 
soul_command(verb,str) {
     int i, cur, j, lvl;
     object *ob, *tmp_ob;
     string tmp, nick, last, liv, other, s1, s2, livfail;
     mixed  *data;
 
     lastarg = "";
     ob = ({ });
     data = soul_data[verb];
     if (!data) {
	 return 0;
     }

     if (str && sizeof(data[1]) == 2 && data[1][0] != '#') {
	 notify_fail("No matter how hard you try, you fail to manage this.\n");
     }
     if (!data[0] || !str) {
	 liv = 0;
	 other = "";
     } else for (j = 0; j < sizeof(data[0]); j += 2)
     switch (data[0][j]) {
      case 0 :
          if (lvl > 1)
            break;
          if (sscanf(str, data[0][j+1], s1)==1)
            if (sizeof((tmp_ob=find_all_liv(s1)))) {
              lvl = 1;
              other = "";
              liv = s1;
              ob = tmp_ob;
            } else
              livfail = s1;
          break;
      case 1 :
          if (lvl > 2)
            break;
          if (sscanf(str, data[0][j+1], s1, s2)==2)
            if (sizeof((tmp_ob=find_all_liv(s2)))) {
              lvl = 2;
              liv = s2;
              other = s1;
              if (data[0][j+1] != "%s %s")
                lvl++;
              ob = tmp_ob;
            } else
              livfail = s2;
          break;
      case 2 :
          if (lvl > 2)
            break;
          if (sscanf(str, data[0][j+1], s1, s2) ==2)
            if (sizeof((tmp_ob=find_all_liv(s1)))) {
              lvl = 2;
              liv = s1;
              other = s2;
              if (data[0][j+1] != "%s %s")
                lvl++;
              ob = tmp_ob;
            } else
              livfail = s2;
          break;
      case 3 :
          if (lvl > 0)
            break;
          if (sscanf(str, data[0][j+1], s1) == 1) {
            other = s1;
            liv = 0;
            ob = ({ });
          }
          break;
    }
  if (liv) {
    string me,him,every;
 
    if (!liv && (str && data[1][0] != '#'))
      liv = str;
    str = other;
    if (!sizeof(ob)) {
      notify_fail("Sorry, but '"+liv+"' is not logged in.\n");
      return 0;
    }
    if (sizeof(data[1])==3) {
	me = data[1][0];
	him = data[1][1];
	every = data[1][2];
    } else if (sizeof(data[1])==5) {
	me = data[1][2];
	him = data[1][3];
	every = data[1][4];
    } else {
      notify_fail("You cannot use that soul command in two thingy mode.\n");
      return 0;
    }
    if (sizeof(ob) == 1) {
      tmp = parse_string(me, ob[cur], str, 1);
      if (!tmp)
        return 1;
      s2 = parse_string(every, ob[cur], str, 1);
      this_player()->event_soul(this_player(), tmp+".\n");
      ob[0]->event_soul(this_player(), parse_string(him, ob[cur], str, 1)+".\n");
      ob[0]->event_soul_command(this_object(),verb,this_player(), liv, other);
      event(environment(previous_object()), "soul",
              s2+".\n",
              ({ ob[0], previous_object() }), verb, last, ob[0]);
      if (environment(previous_object()) != environment(ob[0]) &&
          environment(ob[0]))
        event(environment(ob[cur]), "soul",
              s2+".\n",
              ({ ob[0], previous_object() }), verb, last, ob[0]);
    } else {
      tmp = parse_string(me, ob, str);
      if (!tmp)
        return 1;
      parse_string(him, ob, str); /* To get the forces */
      s2 = parse_string(every, ob, str);
      tmp_ob = map_array(ob, "get_name", this_object());
      ob = unique_array(ob, "query_current_room");

      this_player()->event_soul(this_player(),
           replace(tmp, ({ "$hcname$", 
                          (s1 = implode(tmp_ob[1..1000],", ")+" and "+tmp_ob[0]),
                          "$mhcname$", s1+"'s" }))+".\n");
      s1 = replace(s2, ({ "$hcname$", 
                          (s1 = implode(tmp_ob[1..1000],", ")+" and "+tmp_ob[0]),
                          "$mhcname$", s1+"'s" }));
      if ((int)this_player()->query_social_points() < sizeof(ob)*3) {
        notify_fail("Not enough social points.\n");
        return 0;
      }
      this_player()->adjust_social_points(-sizeof(ob)*3);
      for (i=0;i<sizeof(ob);i++) {
        event(environment(ob[i][0]), "soul",
               s1+".\n", ({ previous_object() })+ob[i], verb, last, ob[i]);
        for (cur=0;cur<sizeof(ob[i]);cur++)
          ob[i][cur]->event_soul(this_player(), replace(s2, ({ "$hcname$", 
                          implode(tmp_ob - ({ get_name(ob[i][cur])}),", ")+" and you",
                          "$mhcname$", 
                        implode(tmp_ob - ({ get_name(ob[i][cur])}),", ")+" and your",
                           }))+".\n");
      }
    }
/*
    while (cur<sizeof(ob)) {
      if (environment(ob[cur]) != environment(this_player()))
        if (this_player()->query_social_points() < 0) {
          notify_fail("Not enough social points to do that.\n");
          return 0;
        } else
          this_player()->adjust_social_points(-3);
      tmp = parse_string(me,ob[cur],str);
      if (!tmp) {
        return 1;
      }
      this_player()->event_soul(this_player(), tmp+".\n");
      ob[cur]->event_soul(this_player(),
                         parse_string(him,ob[cur],str,last)+".\n");
      ob[cur]->event_soul_command(this_object(),verb,this_player(), liv, other);
      event(environment(previous_object()), "soul",
              parse_string(every, ob[cur], str, last)+".\n",
              ({ ob[cur], previous_object() }), verb, last, ob[cur]);
      if (environment(previous_object()) != environment(ob[cur]) &&
          environment(ob[cur]))
        event(environment(ob[cur]), "soul",
              parse_string(every, ob[cur], str, last)+".\n",
              ({ ob[cur], previous_object() }), verb, last, ob[cur]);
      cur++;
    }
 */
    return 1;
  } else if (sizeof(data[1])==3) {
    if (!livfail)
      notify_fail("You don't have the courage to do that.\n");
    else
      notify_fail("Cannot find '"+livfail+"'.\n");
    return 0;
  }
  if (!other)
    other = "";
  tmp = parse_string(data[1][0],ob,other);
  if (!tmp) {
    return 1;
  }
  this_player()->event_soul(this_player(), tmp+".\n");
  event(environment(previous_object()), "soul",
           parse_string(data[1][1], this_player(), other)+".\n",
           ({ previous_object() }), verb, last, 0);
  return 1;
}

do_force(str) {
  int i;

  if (pointerp(str[1]))
    for (i=0;i<sizeof(str[1]);i++)
      str[1][i]->soul_com_force(str[0]);
  else
    str[1]->soul_com_force(str[0]);
}

void add_soul_command(string name, mixed format, mixed thingo) {
     if (soul_data[name]) {
	 return;
     }

  if (format && !pointerp(format))
    return ;
  if (!stringp(name))
    return ;
  if (!pointerp(thingo))
    return ;
  if (sizeof(thingo) != 3 && sizeof(thingo) != 2 && sizeof(thingo) != 5)
    return ;
  soul_data[name] = ({ format, thingo });
}

void delete_soul_command(string name) {
     soul_data = m_delete(soul_data, name);
}

string help_soul(string str) {
     int j;
     int i, off;
     string s1,s2,s3,s4,ret, *bit;
     object ob;
     mixed *data;
     
     data = soul_data[str];
     if (!data) {
	 return 0;
     }
     ret = "";
     if (!pointerp(data[0])) {
	 return "The soul command "+str+" has no optional paramaters at all.\n";
     }
     for (j = 0; j < sizeof(data[0]);j += 2) {
	 bit = explode(" " + data[0][j+1]+" ","%s");
	   switch (data[0][j]) {
	     case 0: 
	       ret += str+bit[0]+"<person>"+bit[1];
	       break;
	     case 2:
	       ret += str+bit[0]+"<person>"+bit[1]+"<argument>"+bit[2];
	       break;
	     case 1:
	       ret += str+bit[0]+"<argument>"+bit[1]+"<person>"+bit[2];
	       break;
	     case 3:
	       ret += str+bit[0]+"<argument>"+bit[1];
	       break;
	   }
	   ret += "\n";
       }
       ret = "Usage of the soul command "+str+"\n"+
	 sprintf("%-#*s\n\n\n", this_player()->query_cols(), ret);
       if (sizeof(data[1]) == 2 || sizeof(data[1]) == 5) {
	   ret += "In no living object mode.\n";
	   bit = ({ });
	   if (sscanf(data[1][0], "%s$arg:%s$%s", s1,s2,s3) == 3)
	     bit = explode(s2,",");
	   if (sscanf(data[1][0], "%s$ifarg:%s~$%s", s1, s2, s3) == 3) {
	       ret += "Has a different no arguments command.\n"+
		 "The arguments are selected from "+
		   implode(bit,", ")+"\n";
	   } else if (!sizeof(bit))
	     ret += "Has no cute arguments\n";
	   else
	     ret += "Has cute arguments of "+implode(bit,", ")+"\n";
	   ret += "\n\n";
	   off = 2;
       }
       if (sizeof(data[1]) == 3 || sizeof(data[1]) == 5) {
	   ret += "In living object mode\n";
	   bit = ({ });
	   if (sscanf(data[1][off+0], "%s$arg:%s$%s", s1,s2,s3) == 3)
	     bit = explode(s2,",");
	   if (sscanf(data[1][off+0], "%s$ifarg:%s~$%s", s1, s2, s3) == 3) {
	       ret += "Has a different no arguments command.\n"+
		 "The arguments are selected from "+
		   implode(bit,", ")+"\n";
	   } else if (!sizeof(bit))
	     ret += "Has no cute arguments\n";
	   else
	     ret += "Has cute arguments of "+implode(bit,", ")+"\n";
	   off = 2;
       }
       return ret;
}
