// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;

string *death_msg = ({
        HIW "°×ÎÞ³£ËµµÀ£ºÎ¹£¡ÐÂÀ´µÄ£¬Äã½ÐÊ²Ã´Ãû×Ö£¿\n\n" NOR,
        HIW "°×ÎÞ³£ÓÃÆæÒìµÄÑÛ¹â¶¢×ÅÄã£¬ºÃÏñÒª¿´´©ÄãµÄÒ»ÇÐËÆµÄ¡£\n\n" NOR,
        HIW "°×ÎÞ³£¡¸ºß¡¹µÄÒ»Éù£¬´ÓÐäÖÐÌÍ³öÒ»±¾ÏñÕÊ²áµÄ¶«Î÷·­¿´×Å¡£\n\n" NOR,
        HIW "°×ÎÞ³£ºÏÉÏ²á×Ó£¬ËµµÀ£ºß×£¿ÑôÊÙÎ´¾¡£¿ÔõÃ´¿ÉÄÜ£¿\n\n" NOR,
        HIW "°×ÎÞ³£É¦ÁËÉ¦Í·£¬Ì¾µÀ£º°ÕÁË°ÕÁË£¬Äã×ß°É¡£\n\n"
                "Ò»¹ÉÒõÀäµÄÅ¨ÎíÍ»È»³öÏÖ£¬ºÜ¿ìµØ°üÎ§ÁËÄã¡£\n\n" NOR,
});

void create()
{
        set_name("°×ÎÞ³£", ({ "white gargoyle", "gargoyle" }));
        set("long",
"°×ÎÞ³£Éì×Å³¤³¤µÄÉàÍ·µÉ×ÅÄã£¬ËÀ°×µÄÁ³ÉÏ¿´²»³öÈÎºÎÏ²Å­°§ÀÖ¡£\n");
        set("attitude", "peaceful");
set("chat_chance", 15);
set("chat_msg", ({
"°×ÎÞ³£·¢³öÒ»ÕóÏñÉëÒ÷µÄÉùÒô£¬µ±Ëû·¢ÏÖÄãÕý×¢ÊÓ×ÅËûµÄÊ±ºò£¬µÉÁËÄãÒ»ÑÛ¡£\n",

"°×ÎÞ³£°Ñ³¤³¤µÄÉàÍ·Éì³öÀ´£¬»º»ºµØÌòÁËÌò×Ô¼ºÓÖ°×ÓÖ³¤µÄÊÖÖ¸¡£\n"
        }) );
	set("per", 100);
	set("str", 20);
	set("int", 20);
        set("age", 217);
	set("title", "Ó­»êÊ¹Õß");
        set("combat_exp", 100000);
  set("daoxing", 100000);

        set("max_gin", 600);
        set("max_kee", 700);
        set("max_sen", 600);
	set("class", "youling");
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 20);
	set("max_mana", 300);
	set("mana", 300);
	set("mana_factor", 15);
	set_skill("ghost-steps", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("spells", 50);
	set_skill("gouhunshu", 50);
	set_skill("jinghun-zhang", 50);
	set_skill("force", 50);
	set_skill("tonsillit", 50);
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
create_family("ÑÖÂÞµØ¸®", 3, "ÄãºÃ");

        setup();
	carry_object("/d/obj/cloth/bai")->wear();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;

        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        if( !ob || !present(ob) ) return;
        if( !ob->is_ghost()) {
                if( visible(ob)&&(string)ob->query("family/family_name")!="ÑÖÂÞµØ¸®" ){
                        command("say Î¹£¡ÑôÈËÀ´Òõ¼ä×öÊ²Ã´£¿");
			command("kick " + ob->query("id"));
                        return;
                }
                return;
        }

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
		ob->set("gin", (int)ob->query("max_gin"));
        ob->move(REVIVE_ROOM);
        message("vision",
                "ÄãºöÈ»·¢ÏÖÇ°Ãæ¶àÁËÒ»¸öÈËÓ°£¬²»¹ýÄÇÈËÓ°ÓÖºÃÏñÒÑ¾­ÔÚÄÇÀï\n"
                "ºÜ¾ÃÁË£¬Ö»ÊÇÄãÒ»Ö±Ã»·¢¾õ¡£\n", environment(ob), ob);
}


void attempt_apprentice()
{	object me;
	me = this_player();
      command("grin");
	if(me->is_ghost() ){
	me->reincarnate();
	me->set("gin", (int)me->query("max_gin"));
	}
        command("say ºÜºÃ£¬" + RANK_D->query_respect(me) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}

ÿ