// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
	set_name("ĞşÖÇºÍÉĞ", ({ "master bonze", "master", "bonze" }) );

	set("gender", "ÄĞĞÔ");
	set("age", 74);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("apprentice_available", 10);

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 2000);
	set("max_atman", 2000);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 5);

	set("mana", 600);
	set("max_mana", 600);

	set("combat_exp", 1000000);
  set("daoxing", 1000000);

	set("score", 9000);

	set("inquiry", ([
		"Ìê¶È" : (: ask_for_join :),
		"³ö¼Ò" : (: ask_for_join :),
	]) );

	set_skill("staff", 100);
	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("dodge", 30);
	set_skill("literate", 60);
	set_skill("chanting", 100);
	set_skill("parry", 50);
	set_skill("magic", 100);

	set_skill("cloudstaff", 100);
	set_skill("lotusforce", 100);
	set_skill("buddhism", 100);
	set_skill("essencemagic", 100);

	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("force", "lotusforce");
	map_skill("magic", "essencemagic");

	create_family("É½ÑÌËÂ", 26, "×¡³Ö");

	setup();

	carry_object(__DIR__"buddha_staff")->wield();
}

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me;

	me = this_player();

	if( (string)me->query("class")=="bonze" )
		return "°¢ÃÖÍÓ·ğ£¡ÄãÎÒÍ¬ÊÇ³ö¼ÒÈË£¬ºÎ¹Ê¸úÀÏñÄ¿ªÕâµÈÍæĞ¦£¿\n";
	if( (string)me->query("gender") != "ÄĞĞÔ" )
		return "°¢ÃÖÍÓ·ğ£¡Å®Ê©Ö÷£¬ÕâÀïÊÇËÂÃí£¬Çë¡õµ½ÄáâÖÈ¥Ìê¶È°É¡£\n";

	me->set_temp("pending/join_bonze", 1);
	return "°¢ÃÖÍÓ·ğ£¡ÉÆÔÕ£¡ÉÆÔÕ£¡Ê©Ö÷ÈôÕæĞÄğ§ÒÀÎÒ·ğ£¬Çë¹òÏÂ(kneel)ÊÜ½ä¡£\n";
}

int do_kneel()
{
	string *prename =
	 ({ "¿Õ", "Ã÷", "Ô²", "¾»", "Ğé", "Îò",
		"·½", "¶É", "»Û", "·¨" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(
		HIC "$NË«ÊÖºÏÊ®£¬¹§¹§¾´¾´µØ¹òÁËÏÂÀ´¡£\n\n"
			"$nÉì³öÊÖÕÆ£¬ÔÚ$NÍ·¶¥ÇáÇáµØÄ¦êıÁË¼¸ÏÂ£¬½«$NµÄÍ··¢¾¡ÊıÌêÈ¥¡£\n\n" NOR,
		this_player(), this_object() );
	name = this_player()->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say ´Ó½ñÒÔááÄãµÄ·¨Ãû½Ğ×ö" + new_name + "¡£");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("class", "bonze");

	return 1;
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ÂıÖø£¬Ò»¸öÒ»¸öÀ´¡£");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say ÀÏÄÉ½ñÌìÒÑ¾­ÊÕÁËÊ®¸öµÜ×Ó£¬²»ÏëÔÙÊÕÍ½ÁË¡£");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "ÄĞĞÔ" )
		command("say °¢ÃÖÍÓ·ğ£¬Å®Ê©Ö÷²»Òª¸úÀÏÄÉ¿ªÍæĞ¦¡£");
	else if( (string)ob->query("class") != "bonze" )
		command("say °¢ÃÖÍÓ·ğ£¬Ê©Ö÷Ô¸Èë·ğÃÅ£¬ÇëÏÈµ½Ğ¡ËÂÌê¶È³ö¼Ò¡£");
	else {
		command("say °¢ÃÖÍÓ·ğ£¬ÉÆÔÕ£¡ÉÆÔÕ£¡");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		add("apprentice_availavble", -1);
		return 1;
	}
}

int accept_fight(object me)
{
	if( (string)me->query("class")=="bonze" )
		command("say °¢ÃÖÍÓ·ğ£¡³ö¼ÒÈË½ä³ÑÇ¿¶ñ¶·£¡ÀÏñÄ²»¸ÒÎ¥·´Çå¹æ¡£");
	else
		command("say Ê©Ö÷¼ÈÈ»Éí¸º¾øÒÕ£¬ÀÏñÄÅå·ş±ãÊÇ£¬Ò²²»±Ø½ÏÁ¿ÁË¡£");
	
	return 0;
}
ÿ