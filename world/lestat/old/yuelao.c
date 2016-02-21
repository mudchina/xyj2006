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
	set("force_factor", 50);
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
//		"news" :,
		"½á»é" : "Ïë½á»é£¿ÄãÒªÕÒµ½ÄãÃüÖĞ×¢¶¨µÄÄÇÒöÔµ£¬È»ºóÒ»Æğµ½ÕâÀïÀ´µÇ¼Ç(jiehun)Íê»é¡£",
		"µÇ¼Ç" : "Ïë½á»é£¿ÄãÒªÕÒµ½ÄãÃüÖĞ×¢¶¨µÄÄÇÒöÔµ£¬È»ºóÒ»Æğµ½ÕâÀïÀ´µÇ¼Ç(register)Íê»é¡£",
		"Àë»é" : "°¦£¬ÊÀµÀ±äÁË£¬ÕâÄêÍ·ÈËĞÄ²»¹Å£¬Àë»éÂÊ¸ßµÃ¿ÉÅÂ¡£°¦£¬²»¹ÜÔõÑù£¬ÎÒÒ²¸ºÔğ´¦ÀíÀë»é(divorce/lihun)ÉêÇë¡£",
		"×öÃ½" : "Ã½ÈËÊÇ½á»é±Ø²»¿ÉÉÙµÄÖ¤ÈË£¬×öÃ½(zuomei)µÄ¸ºÔğ¸øÅ®·½×öÖ¤¡£",
       ]) );

	setup();
}

void init()
{
	add_action("do_register", "register");
	add_action("do_register", "jiehun");
	add_action("do_divorce", "divorce");
	add_action("do_divorce", "lihun");
	add_action("do_zuomei", "zuomei");
}

int do_register()
{
	object me, who, meiren;
	me=this_player();
	message_vision("$NÏòÔÂÏÂÀÏÈË´òÌı½á»éµÄÊÂ¡£\n", me);
	if (! interactive(me))
		return 1;
	if (!me->query("waiting_marry")) {
		command("say ß×£¿ÎÒÕâÒöÔµ²¾ÉÏÃ»ÓĞÄãµÄÃû×ÖÑ½ ... ..."); 
		command("say °¦£¬ÇëÄãÏÈ»ØÈ¥£¬µÈÎÒ¸øÄãÕÒµ½ÄãÄÇÒöÔµÔÙÀ´°É¡£");
		return 1;
	}
	if (me->query("gender")=="Å®ĞÔ") {
		command("say àÅ£¬ÇëÄãµÄÎ´»é·òÉÏÇ°À´¡£");
		return 1;
	}
	if (!objectp(who=present(me->query("partner"),environment(me)))) {
		command("say àÅ£¬ÄãµÄÒöÔµÊÇÓĞÁË£¬¿ÉÊÇÎªÊ²Ã´ÄãµÄÎ´»éÆŞÃ»Ò»ÆğÀ´£¿");
		command("say Çë´øÄãµÄÎ´»éÆŞµ½ÕâÀïÀ´£¬ÎÒ²ÅÄÜÎªÄãÃÇÍê³ÉµÇ¼ÇÊÖĞø¡£");
		return 1;
	}
	if (who->query("partner")!=getuid(me)) {
		command("say °¡£¿£¡£¿ÄãµÄÎ´»éÆŞÎªºÎÓÖ´ğÓ¦Áí¼ŞËûÈËÁË£¿£¡£¿");
		command("say ÄãÃÇÏë¿ªÊ²Ã´ÍæĞ¦£¿£¡¸ãÇå³şÔÙÀ´£¡£¡£¡");
		return 1;
	}
	if (!who->query("meiren")) {
		command("say ÕâÒöÔµÂï£¬Ë×»°ËµµÄºÃ¡°¸¸Ä¸Ö®Ãü£¬Ã½åùÖ®ÑÔ¡±¡£ÕâÄàÌ¶ÀïÎŞ¸¸Ä¸£¬ÄÇÒ²°ÕÁË¡£");
		command("say ÈôÔÙÎŞÃ½åùÖ®ÑÔ£¬ÄÇÒ²Ì«²»Ïñ»°ÁË¡£");
		command("say ÄãÃÇÈ¥ÕÒ¸öÃ½ÈËÀ´°É£¬ÓÉËûÔÚ´Ë×öÖ¤£¬ÎÒ²ÅÄÜÎªÄãÃÇÖ÷»é¡£");
		return 1;
	}
	if (!objectp(meiren=present(who->query("meiren"),environment(me)))) {
		command("say àÅ£¬Äã¶şÈË¶¼ÔÚÕâ¶ùÁË£¬¿ÉÊÇÄÇÃ½ÈËÓÖÅÜÄÄ¶ùÈ¥À²£¿");
		command("say ¿ì°ÑÃ½ÈËÕÒµ½Õâ¶ùÀ´£¬ÎÒ²ÅÄÜÎªÄãÃÇÍê³ÉµÇ¼ÇÊÖĞø¡£");
		return 1;
	}

	command("say ¹ş¹ş¹ş¹ş£¡ºÃ¼«ÁË£¬Ò»ÇĞÆë±¸£¬ÎÒÕâ¾ÍÎªÄãÃÇµÇ¼Ç£¡");
	write("ÔÂÏÂÀÏÈËµÍÍ·°ÑÒöÔµ²¾·­ÁË·­£¬Ğ´ÏÂĞ©Ê²Ã´¡£\n");
	command("say ¹§Ï²£¬¹§Ï²£¡");
	command("chat ¹ş¹ş¹ş¹ş£¡£¡£¡£¡");
	command("chat "+me->name()+"ºÍ"+who->name()+"ÓÉ"+meiren->name()+"×öÃ½£¬½ñÈÕÏ²½áÁ¼Ôµ£¬¸÷Î»ÏÉÓÑ×ö¸ö¼ûÖ¤¡£");
	command("chat ¹§×£Á½Î»°×Í·ÙÉÀÏ£¬ÔçÉú¹ó×Ó¡£");

	log_file("yl.rc",me->name()+"ºÍ"+who->name()+
	  "ÓÉ"+meiren->name()+"×öÃ½£¬ÓÚ"+NATURE_D->game_time()+"("+
	  ctime(time())+")Ï²½áÁ¼Ôµ¡£\n");

	who->delete("waiting_marry");
	who->delete("partner");
	who->delete("meiren");
	who->set("married",1);
	who->set("husband/"+getuid(me), me->name());
	who->set("couple/id", getuid(me));
	who->set("couple/name", me->name());
	me->delete("waiting_marry");
	me->delete("partner");
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

	if (! interactive(me))
		return 1;
 	if (!arg || !objectp(who=present(arg,environment(me)))) {
		tell_object(me,"ÄãÒª¸øË­×öÃ½£¿\n");
		return 1;
	}
	if (arg==me->query("partner")) {
		tell_object(me,"°¡£¿¸ø×Ô¼º×öÃ½£¿ÌıËµ¹ıÂğ£¿£¡£¿\n");
		return 1;
	}
	if (who->query("gender")=="ÄĞĞÔ") {
		tell_object(me, "àÅ£¬ÇëÃ½ÈËÎªÅ®·½×öÃ½¡£\n");
		return 1;
	}
	if (!who->query("waiting_marry")) {
		tell_object(me,"àÅ£¿ÕâÈËÃ»´òËã½á»é°¡£¬ÄãÏ¹ÆğÊ²Ã´ºå£¿£¡£¿\n");
		return 1;
	}
	message_vision("$NĞ¦ÎûÎûµÄËµ£ºÎÒÏë¸øÅ®·½×öÃ½¡£\n", me);
	command("say " + me->query("name") + "Ô­Òâ¸ø" + who->name() + "×öÃ½£¿");
	command("say Õâ¿ÉÊÇ³ÉÈËÖ®ÃÀµÄÉÆÊÂ°¡£¬ºÃ¼«ÁË£¬ÎÒÕâ¾Í¼ÇÂ¼ÏÂÀ´¡£");
	who->set("meiren", getuid(me));
	return 1;
}

int do_divorce(string arg)
{
	object me,who;
	me=this_player();

	if (! interactive(me))
		return 1;
	if (!arg) {
		tell_object(me, "Äã´òËã¸úË­Àë»é£¿\n");
		return 1;
	}
 	if (!me->query("married")) {
		tell_object(me, "Äã¸ù±¾Ã»½á¹ı»é£¡\n");
		return 1; }
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
			return 1; }
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
	command("chat °¦ ... ´Ó½ñÌìÆğ£¬"+me->name()+"ºÍ"+who->name()+"¾Í²»ÔÙÊÇ·òÆŞÁË¡£");
	command("chat ÓÖÒ»×®Ê§°ÜµÄ»éÒö£¬°¦ ... ... ");

        log_file("yl.rc",me->name()+"ºÍ"+who->name()+
	   "ÓÚ"+NATURE_D->game_time()+"("+ctime(time())+")Àë»é¡£\n");

	return 1;
}
ÿ