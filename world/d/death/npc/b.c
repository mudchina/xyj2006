// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
	HIB "ºÚÎŞ³£ËµµÀ£ºÎ¹£¡ĞÂÀ´µÄ£¬Äã½ĞÊ²÷áÃû×Ö£¿\n\n" NOR,
	HIB "ºÚÎŞ³£ÓÃÆæÒìµÄÑÛ¹â¶¢ÖøÄã£¬ºÃÏñÒª¿´´©ÄãµÄÒ»ÇĞËÆµÄ¡£\n\n" NOR,
	HIB "ºÚÎŞ³£¡¸ºß¡¹µÄÒ»Éù£¬´ÓĞäÖĞÌÍ³öÒ»±¾ÏñÕÊ²áµÄ¶«Î÷·­¿´Öø¡£\n\n" NOR,
	HIB "ºÚÎŞ³£¡õÉÏ²á×Ó£¬ËµµÀ£ºß×£¿ÑôÊÙÎ´¾¡£¿Ôõ÷á¿ÉÄÜ£¿\n\n" NOR,
	HIB "ºÚÎŞ³£É¦ÁËÉ¦Í·£¬Ì¾µÀ£º°ÕÁË°ÕÁË£¬Äã×ß°É¡£\n\n"
		"Ò»¹ÉÒõÀäµÄÅ¨ÎíÍ»È»³öÏÖ£¬ºÜ¿ìµØ°üÎ§ÁËÄã¡£\n\n" NOR,
});

void create()
{
	set_name("ºÚÎŞ³£", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"ºÚÎŞ³£ÉìÖø³¤³¤µÄÉàÍ·µÉÖøÄã£¬÷îºÚµÄÁ³ÉÏ¿´²»³öÈÎºÎÏ²Å­°§ÀÖ¡£\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
		"ºÚÎŞ³£·¢³öÒ»ÕóÏñÉëÒ÷µÄÉùÒô£¬µ±Ëû·¢ÏÖÄãÕı×¢ÊÓÖøËûµÄÊ±ºò£¬µÉÁËÄãÒ»ÑÛ¡£\n",
		"ºÚÎŞ³£°Ñ³¤³¤µÄÉàÍ·Éì³öÀ´£¬»º»ºµØÌòÁËÌò×Ô¼ºÓÖºÚÓÖ³¤µÄÊÖÖ¸¡£\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
  set("daoxing", 50000);

	set("max_gin", 900);
	set("max_kee", 900);
	set("max_sen", 200);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) ) return;

	if( !ob->is_ghost() ) {
		command("say Î¹£¡ÑôÈËÀ´Òõ¼ä×öÊ²÷á£¿");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	ob->move(REVIVE_ROOM);
	message("vision",
		"ÄãºöÈ»·¢ÏÖÇ°Ãæ¶àÁËÒ»¸öÈËÓ°£¬²»¹ıÄÇÈËÓ°ÓÖºÃÏñÒÑ¾­ÔÚÄÇÀï\n"
		"ºÜ¾ÃÁË£¬Ö»ÊÇÄãÒ»Ö±Ã»·¢¾õ¡£\n", environment(ob), ob);
}


ÿ