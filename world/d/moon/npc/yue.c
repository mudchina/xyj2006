// yuelao.c ÔÂÏÂÀÏÈË
// AceP
// mon 1/2/97

inherit NPC;

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
	set_name("ÔÂÏÂÀÏÈË", ({ "yuexia laoren", "yuelao", "laoren" }));
	set("long", 
"Ëû¾ÍÊÇ×¨¹ÜÌìÉÏµØÏÂÒöÔµµÄÔÂÏÂÀÏÈËÁË¡£
ËûÂúÁ³ºì¹â£¬ĞëÃ¼½Ô°×£¬Õı×øÔÚÄÇ¶ù·­¿´Ò»±¾Êé£¬
ÊÖÉÏğ¤×ÅÒ»¸ùºìÉş£¬¿ÚÖĞÕı×ÔÑÔ×ÔÓï×ÅĞ©Ê²Ã´¡£\n");
	set("gender", "ÄĞĞÔ");
	set("per", 100);
	set("age", 101);
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("per", 25);
      
	set("max_kee", 1200);
	set("max_gin", 1000);
	set("max_sen", 1200);
	set("force", 1000);
	set("max_force", 1000);
	set("max_mana", 1200);
	set("mana", 1200);
	set("combat_exp", 500000);
  set("daoxing", 5000000);


	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("literate", 150);

	set("inquiry", ([
		"name" : "ÇøÇøÕıÊÇÔÂÀÏ£¬ÔÚ´Ë¸ºÔğÌìÉÏµØÏÂËùÓĞµÄÒöÔµ£¬ÒÑÓĞ²»ÖªµÀ¶àÉÙÄêÁË¡£",
		"here" : "Õâ¶ù¾ÍÊÇÎÒ°ì¹«µÄµØ·½£¬ËùÓĞµÄÒöÔµ¶¼ÊÇÎÒÔÚÕâ¶ùÍµÍµÇ£µÄÏß£¬Ò²ÊÇÔÚÕâ¶ù×¢²áÍê»éµÄ¡£",
		"½á»é" : "Ïë½á»é£¿ÄãÒªÕÒµ½ÄãÃüÖĞ×¢¶¨µÄÄÇÒöÔµ£¬È»ºóÒ»Æğµ½ÕâÀïÀ´µÇ¼ÇÍê»é¡£",
		"Àë»é" : "°¦£¬ÊÀµÀ±äÁË£¬ÕâÄêÍ·ÈËĞÄ²»¹Å£¬Àë»éÂÊ¸ßµÃ¿ÉÅÂ¡£°¦£¬²»¹ÜÔõÑù£¬ÎÒÒ²¸ºÔğ´¦ÀíÀë»é(divorce)ÉêÇë¡£",
		"×öÃ½" : "Ã½ÈËÊÇ½á»é±Ø²»¿ÉÉÙµÄÖ¤ÈË£¬×öÃ½(zuomei)µÄ¸ºÔğ¸øÅ®·½×öÖ¤¡£",
       ]) );

	setup();
}

void init()
{
	add_action("do_divorce", "divorce");
	add_action("do_zuomei", "zuomei");
	add_action("do_propose", "propose");
	add_action("do_marry", "marry");
}


int do_propose(string arg)
{
	object me,who;
	me=this_player();
        if(me->query("age") < 16)
           return notify_fail("Ğ¡º¢×ÓÒ»±ßÍæ¶ùÈ¥¡£\n");

        if (!arg) return notify_fail("ÄãÒªÏòË­Çó»é£¿\n");

        if (me->query("gender")=="Å®ĞÔ")
                return notify_fail("Ö»ÓĞÄĞÈË²ÅÄÜÏò±ğÈËÇó»é£¡\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("ÕâÀïÃ»ÓĞÕâ¸öÈË¡£\n");

        if (!who->is_character())
                return notify_fail("ÏëÇå³ş£¡"+who->name()+"ÊÇÊ²Ã´Ñ½£¡\n");

        if (who==me)
                return notify_fail("¿ªÊ²Ã´ÍæĞ¦£¿£¡£¿\n");

        if (who->query("gender")=="ÄĞĞÔ")
                return notify_fail("àÅ£¿Äã±äÌ¬Âğ£¿£¡£¿\n");

        if (me->query("married"))
                return notify_fail("ºÙºÙ£¬²»ÅÂ" + me->query("couple/name") + "×áÄãÂğ£¿\n");

        if (!living(who))
                return notify_fail("àÅ...Äã»¹ÊÇÏÈ°Ñ"+who->name()+"ÅªĞÑ°É¡£\n");


	if ((me->query("bonze/class")=="bonze")||(who->query("bonze/class")=="bonze"))
		return notify_fail("³ö¼ÒÈËËÄ´ó½Ô¿Õ£¬»é¼ŞÖ®ÊÂ¾ÍÃâÁË°É¡£\n");

        if (who->query("married"))
                return notify_fail("»¹ÊÇËãÁË°É£¬"+who->name()+"ÊÇÓĞ·òÖ®¸¾À²£¡\n");

        message_vision("$N¶Ô×Å$nÅÄ×ÅĞØ¸¬Ëµ£ºÖ»ÒªÄã¼Ş¸øÎÒ£¬Äã½ĞÎÒ×öÊ²Ã´ÎÒ¾Í×öÊ²Ã´£¡\n", me, who);

        me->set("proposing",1);
        me->set("propose_target", getuid(who));
        who->set("proposed",1);
        who->set("propose_man", getuid(me));

        return 1;
}

int do_marry(string arg)
{
	object me,who;
	me=this_player();

	if(me->query("age") < 15)
           	return notify_fail("Ğ¡º¢×ÓÒ»±ßÍæ¶ùÈ¥¡£\n");

        if (me->query("gender")=="ÄĞĞÔ")
                return notify_fail("Ö»ÓĞÅ®ÈË²ÅÄÜ´ğÓ¦±ğÈËµÄÇó»é£¡\n");

        if (!arg) 
		return notify_fail("ÄãÒª¼Ş¸øË­£¿\n");

        if (!me->query("proposed"))
                return notify_fail("àÅ£¿Ã»ÈËÏòÄãÇó»é°¡¡£\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("ÕâÀïÃ»ÓĞÕâ¸öÈË¡£\n");

        if (!who->is_character())
                return notify_fail("ÏëÇå³ş£¡"+who->name()+"ÊÇÊ²Ã´Ñ½£¡\n");

        if (who==me)
                return notify_fail("¿ªÊ²Ã´ÍæĞ¦£¿£¡£¿\n");

        if (!living(who))
                return notify_fail("àÅ...Äã»¹ÊÇÏÈ°Ñ"+who->name()+"ÅªĞÑ°É¡£\n");

        if (me->query("propose_man")!=getuid(who))
                return notify_fail("àÅ£¿"+who->name()+"Ã»ÏòÄãÇó¹ı»é°¡¡£\n");


        if (who->query("propose_target")!=getuid(me))
                return notify_fail("¶Ô²»Æğ£¬"+who->name()+"ÒÑ¾­¸Ä±äÖ÷Òâ²»ÏòÄãÇó»éÁË¡£\n");
	
	if(!me->query("meiren"))
		return notify_fail("´ó¹ÃÄï¼ÒµÄ£¬»¹ÊÇÇë¸öÃ½ÈËÀ´±£Ç×°É£¡\n");

        message_vision("$NÍáÍ·ÏëÁË»á£¬ĞßĞß´ğ´ğµØËµµÀ£ººÃ°É£¡\n",me,who);

        who->delete("proposing");
        who->delete("propose_target");

        me->delete("proposed");
        me->delete("propose_man");

        command("say ¹ş¹ş¹ş¹ş£¡ºÃ¼«ÁË£¬Ò»ÇĞÆë±¸£¬ÎÒÕâ¾ÍÎªÄãÃÇÖ÷»é£¡");
        write("ÔÂÏÂÀÏÈËµÍÍ·°ÑÒöÔµ²¾·­ÁË·­£¬Ğ´ÏÂĞ©Ê²Ã´¡£\n");
        command("say ¹§Ï²£¬¹§Ï²£¡");
        command("say ¹ş¹ş¹ş¹ş£¡£¡£¡£¡");
        command("say "+me->name()+"ºÍ"+who->name()+"ÓÉ"+me->query("meiren")+"×öÃ½£¬½ñÈÕÏ²½áÁ¼Ôµ£¬¸÷Î»ÏÉÓÑ×ö¸ö¼ûÖ¤¡£");
        command("say ¹§×£Á½Î»°×Í·ÙÉÀÏ£¬ÔçÉú¹ó×Ó¡£");

        who->delete("meiren");
        who->set("married",1);
        who->set("husband/"+getuid(me), me->name());
        who->set("couple/id", getuid(me));
        who->set("couple/name", me->name());
        me->set("married", 1);
        me->set("wife/"+getuid(who), who->name());
        me->set("couple/id", getuid(who));
        me->set("couple/name", who->name());
        me->set_temp("marrying",1);
        me->set_temp("bride",getuid(who));

        return 1;
}


int do_zuomei(string arg)
{
	object me, who;
	me=this_player();

 	if (!arg || !objectp(who=present(arg,environment(me)))) {
		tell_object(me,"ÄãÒª¸øË­×öÃ½£¿\n");
		return 1;
	}
        if (who->query("gender")=="ÄĞĞÔ")
                return notify_fail("Õâ¸öÈË²¢²»ĞèÒªÈË×öÃ½£¡\n");

	if (arg==me->query("proposed_target"))
		return notify_fail("°¡£¿¸ø×Ô¼º×öÃ½£¿ÌıËµ¹ıÂğ£¿£¡£¿\n");

	if (arg==me->query("id"))
		return notify_fail("°¡£¿¸ø×Ô¼º×öÃ½£¿ÌıËµ¹ıÂğ£¿£¡£¿\n");

	if (!who->query("proposed")) 
		return notify_fail("àÅ£¿ÕâÈËÃ»´òËã½á»é°¡£¬ÄãÏ¹ÆğÊ²Ã´ºå£¿£¡£¿\n");

	message_vision("$NĞ¦ÎûÎûµÄËµ£ºÎÒÏë¸øÅ®·½×öÃ½¡£\n", me);
	command("say " + me->query("name") + "Ô­Òâ¸ø" + who->name() + "×öÃ½£¿");
	command("say Õâ¿ÉÊÇ³ÉÈËÖ®ÃÀµÄÉÆÊÂ°¡£¬ºÃ¼«ÁË£¬ÎÒÕâ¾Í¼ÇÂ¼ÏÂÀ´¡£");
	who->set("meiren", me->query("name"));
	return 1;
}

int do_divorce(string arg)
{
	object me,who;
	me=this_player();

	if (!arg)
		return notify_fail("Äã´òËã¸úË­Àë»é£¿\n");

 	if (!me->query("married"))
		return notify_fail("Äã¸ù±¾Ã»½á¹ı»é£¡\n");

	if (me->query("gender")=="ÄĞĞÔ") {
		if (!me->query("wife/"+arg))
			return notify_fail("ÔÂÏÂÀÏÈËÆæ¹ÖµØ¿´ÁËÄãÒ»ÑÛ£¬µÀ£ºÕâÈË¸ù±¾²»ÊÇÄãÆŞ×Ó£¡\n");
		if (!(who=find_player(arg))) {
			message_vision("$N³å×ÅÔÂÏÂÀÏÈË´óÉùÈÂÈÂ×Å£ºÕâÈÕ×ÓÃ»·¨¹ıÁË£¬ÎÒÒªÀë»é£¡\n", me);
			command("say ¶Ô²»Æğ£¬Äú·òÈËÏÖÔÚ²»ÔÚÏßÉÏ£¬²»ÄÜ°ìÀíÀë»éÊÖĞø");
			return 1; }
		if (!me->query_temp("divorcing")) {
			message_vision("$N³å×ÅÔÂÏÂÀÏÈË´óÉùÈÂÈÂ×Å£ºÕâÈÕ×ÓÃ»·¨¹ıÁË£¬ÎÒÒªÀë»é£¡\n", me);
			command("say °¦£¬Äãµ±ÕæÏëĞİÁËÄãµÄÆŞ×ÓÂğ£¿Èç¹ûÊÇ£¬ÇëÔÙÏòÎÒÉêÇëÒ»´Î¡£");
			me->set_temp("divorcing",1);
			return 1; }
		me->delete("married");
		me->delete("couple");
		me->delete("wife");
		me->delete_temp("divorcing");
		who->delete("married");
		who->delete("couple");
		who->delete("husband");
		tell_object(who, me->name()+"°ÑÄãĞİÁË¡£");
	}
	else {
		if (!me->query("husband/"+arg))
			return notify_fail("ÔÂÏÂÀÏÈËÆæ¹ÖµØ¿´ÁËÄãÒ»ÑÛ£¬µÀ£ºÕâÈË¸ù±¾²»ÊÇÄãÕÉ·ò£¡\n");
		if (!(who=find_player(arg))) {
			message_vision("$N³å×ÅÔÂÏÂÀÏÈË´óÉùÈÂÈÂ×Å£ºÕâÈÕ×ÓÃ»·¨¹ıÁË£¬ÎÒÒªÀë»é£¡\n", me);
			command("say ¶Ô²»Æğ£¬ÄúÕÉ·òÏÖÔÚ²»ÔÚÏßÉÏ£¬²»ÄÜ°ìÀíÀë»éÊÖĞø");
			return 1; }
		if (!me->query_temp("divorcing")) {
			message_vision("$N³å×ÅÔÂÏÂÀÏÈË´óÉùÈÂÈÂ×Å£ºÕâÈÕ×ÓÃ»·¨¹ıÁË£¬ÎÒÒªÀë»é£¡\n", me);
			command("say °¦£¬Äãµ±ÕæÏëÅ×ÆúÄãµÄÕÉ·òÂğ£¿Èç¹ûÊÇ£¬ÇëÔÙÏòÎÒÉêÇëÒ»´Î¡£");
			me->set_temp("divorcing",1);
			return 1; 
			}

		who->delete("married");
		who->delete("wife");
		who->delete("couple");
		me->delete("married");
		me->delete("couple");
		me->delete_temp("divorcing");
		me->delete("husband");
		tell_object(who, me->name()+"Å×ÆúÁËÄã£¬²»ÖªÊÇ¸úË­Ë½±¼È¥ÁË¡£");
	}
	command("say °¦ ... ...");
	command("say °¦ ... ´Ó½ñÌìÆğ£¬"+me->name()+"ºÍ"+who->name()+"¾Í²»ÔÙÊÇ·òÆŞÁË¡£");
	command("say ÓÖÒ»×®Ê§°ÜµÄ»éÒö£¬°¦ ... ... ");

        log_file("yl.rc",me->name()+"ºÍ"+who->name()+
	   "ÓÚ"+NATURE_D->game_time()+"("+ctime(time())+")Àë»é¡£\n");

	return 1;
}
ÿ