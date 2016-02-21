//Cracked by Roath
// tidu.c

#include <ansi.h>

inherit NPC;

string ask_for_join();
string ask_for_leave();
string ask_for_huansu();

void create()
{
	set_name("Ìê¶ÈÉ®", ({ "tidu seng", "seng" }) );

	set("gender", "ÄĞĞÔ");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 200);
	set("max_atman", 200);

	set("force", 150);
	set("max_force", 150);
	set("force_factor", 5);

	set("mana", 200);
	set("max_mana", 200);

	set("combat_exp", 10000);
	set("daoxing", 50000);

	set("inquiry", ([
		"Ìê¶È" : (: ask_for_join :),
		"³ö¼Ò" : (: ask_for_join :),
		"»¹Ë×" : (: ask_for_huansu :),
		"ÍÑÀë" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
		]) );

	set_skill("staff", 20);
	set_skill("unarmed", 30);
	set_skill("force", 25);
	set_skill("dodge", 20);
	set_skill("literate", 20);
	set_skill("parry", 20);
	set_skill("spells", 10);

	set_skill("lotusforce", 20);
	set_skill("buddhism", 20);

	map_skill("force", "lotusforce");
	map_skill("spells", "buddhism");

	create_family("ÄÏº£ÆÕÍÓÉ½", 4, "µÜ×Ó");

	setup();

	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
        add_action("do_agree", "agree");
        add_action("do_huansu", "huansu");
}

string ask_for_huansu()
{
	object me;

	me = this_player();

	if( (string)me->query("bonze/class")!="bonze" )
		return "°¢ÃÖÍÓ·ğ£¡Äã¼ÈÒÑÉíÏµ³¾ÊÀ£¬ºÎ±Ø´ÕÕâ¸öÈÈÄÖ£¿\n";
	me->set_temp("pending/leave_bonze", 1);
command("say °¢ÃÖÍÓ·ğ£¡Ò»ÈëË×ÊÀ£¬Íò½Ù²»¸´£¬"+RANK_D->query_respect(me)+"Ò»Éí´ó³Ë·ğ·¨Ò²½«ËæÖ®¸¶Öî¶«Á÷¡£»¹Íû"+RANK_D->query_respect(me)+"ÈıË¼¡£");
	return RANK_D->query_respect(me)+"ÈôÒÑ¾ö¶¨£¬±ãÇëÍÑÅÛ»¹Ë×(huansu)¡£\n";
}

int do_huansu()
{
        if( !this_player()->query_temp("pending/leave_bonze") ) return 0;
	message_vision( HIC "$NÍÑÏÂÉíÉÏµÄôÂôÄ£¬¹§¹§¾´¾´µØ¹òÏÂÀ´¿ÄÁË¼¸¸öÏìÍ·£¬´Ó´Ë»Ö¸´ÁË×ÔÓÉÉí¡£\n\n"NOR, this_player(), this_object() );
	this_player()->delete("class");
	this_player()->delete("bonze/class");
	this_player()->delete_skill("buddhism");
	command("say ´Ó½ñÒÔááÄã»Ö¸´³ö¼ÒÇ°µÄË×Ãû" +this_player()->query("bonze/old_name")+"¡£");
	this_player()->set("name", this_player()->query("bonze/old_name") );
	command("sigh");
        this_player()->delete_temp("pending/leave_bonze");
	this_player()->save();
	return 1;
}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("married"))
		return "°¢ÃÖÍÓ·ğ£¡Ê©Ö÷ÓĞÁË¼ÒÍ¥ÍÏÀÛ£¬Ïë±ØÄÑÒÔÇ±ĞÄÏò·ğ¡£\n";
	if( (string)me->query("bonze/class")=="bonze" )
		return "°¢ÃÖÍÓ·ğ£¡ÄãÎÒÍ¬ÊÇ³ö¼ÒÈË£¬ºÎ¹Ê¸úÀÏñÄ¿ªÕâµÈÍæĞ¦£¿\n";
	if( me->query("bonze/justonetime"))
		return "Ê©Ö÷¼ÈÒÑ»¹Ë×£¬ÓÖºÎ¿àÔÙ´Î³ö¼Ò£¿\n";
	me->set_temp("pending/join_bonze", 1);
	return "°¢ÃÖÍÓ·ğ£¡ÉÆÔÕ£¡ÉÆÔÕ£¡Ê©Ö÷ÈôÕæĞÄğ§ÒÀÎÒ·ğ£¬Çë¹òÏÂ(kneel)ÊÜ½ä¡£\n";
}

int do_kneel()
{
	string *prename1 =
	 ({ "¿Õ", "Ã÷", "Ğé", "·¨" });
	string *prename2 =
	 ({ "ÎÄ", "¾»", "·½", "»Û" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(	HIC "$NË«ÊÖºÏÊ®£¬¹§¹§¾´¾´µØ¹òÁËÏÂÀ´¡£\n\n" + 
			"$nÉì³öÊÖÕÆ£¬ÔÚ$NÍ·¶¥ÇáÇáµØÄ¦êıÁË¼¸ÏÂ£¬½«$NµÄÍ··¢¾¡ÊıÌêÈ¥¡£\n\n" NOR,
		this_player(), this_object() );
	name = this_player()->query("name");
	new_name = ( (string)this_player()->query("gender") == "ÄĞĞÔ" )? 
		prename1[random(sizeof(prename1))] + name[0..1]
		:prename2[random(sizeof(prename2))] + name[0..1];
	command("say ´Ó½ñÒÔááÄãµÄ·¨Ãû½Ğ×ö" + new_name + "¡£");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("bonze/class", "bonze");
	this_player()->set("bonze/justonetime", 1);
	this_player()->set("bonze/old_name", name);
        this_player()->set("class", "bonze");
	this_player()->save();
	return 1;
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "ÄÏº£ÆÕÍÓÉ½" ) {
		command("say Äã¼ÈÊÇÖ´ÒâÏÂÉ½£¬Æ¶É®È´ÓĞ¼¸¾ä»°Ëµ¡£");
		me->set_temp("betray", "putuo");
		return ("ÍÑÀëÊ¦ÃÅÒªĞèÒªÓĞÒ»¶¨³Í·££¬Äã¿ÉÔ¸Òâ(agree)?\n");
	}

	return ("Æ¶É®²»Öª¡£\n");
}
			
			
int do_agree(string arg)
{
if(this_player()->query_temp("betray")=="putuo" &&
		this_player()->query("family/family_name") == "ÄÏº£ÆÕÍÓÉ½") {
		message_vision("$N´ğµÀ£ºµÜ×ÓÔ¸Òâ¡£\n\n", this_player());
		this_player()->add("betray/putuo", 1);
		this_player()->add("betray/count", 1);
		command("say ¼ÈÊÇÄãÓë·ğÃÅÎŞÔµ£¬Äã±ãÏÂÉ½È¥°É£¡\n");

this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete_skill("buddhism");
		this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
		this_player()->set_temp("betray", 0);
		command("say ½­ºş·ç²¨£¬ÉÆ¶ñÎŞĞÎ£¬ºÃ×ÔÎªÖ®¡£¡£¡£\n");
		this_player()->save();
		return 1;
	}

}
ÿ
