// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
string *death_msg = ({
        HIB "ºÚÎÞ³£ËµµÀ£ºÎ¹£¡ÐÂÀ´µÄ£¬Äã½ÐÊ²Ã´Ãû×Ö£¿\n\n" NOR,
        HIB "ºÚÎÞ³£ÓÃÆæÒìµÄÑÛ¹â¶¢×ÅÄã£¬ºÃÏñÒª¿´´©ÄãµÄÒ»ÇÐËÆµÄ¡£\n\n" NOR,
        HIB "ºÚÎÞ³£¡¸ºß¡¹µÄÒ»Éù£¬´ÓÐäÖÐÌÍ³öÒ»±¾ÏñÕÊ²áµÄ¶«Î÷·­¿´Öø¡£\n\n" NOR,
        HIB "ºÚÎÞ³£ºÏÉÏ²á×Ó£¬ËµµÀ£ºß×£¿ÑôÊÙÎ´¾¡£¿ÔõÃ´¿ÉÄÜ£¿\n\n" NOR,
        HIB "ºÚÎÞ³£É¦ÁËÉ¦Í·£¬Ì¾µÀ£º°ÕÁË°ÕÁË£¬Äã×ß°É¡£\n\n"
                "Ò»¹ÉÒõÀäµÄÅ¨ÎíÍ»È»³öÏÖ£¬ºÜ¿ìµØ°üÎ§ÁËÄã¡£\n\n" NOR,
});

void create()
{
        set_name("ºÚÎÞ³£", ({ "black gargoyle", "gargoyle" }) );
        set("long",

"ºÚÎÞ³£Éì×Å³¤³¤µÄÉàÍ·µÉ×ÅÄã£¬÷îºÚµÄÁ³ÉÏ¿´²»³öÈÎºÎÏ²Å­°§ÀÖ¡£\n");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({

"ºÚÎÞ³£·¢³öÒ»ÕóÏñÉëÒ÷µÄÉùÒô£¬µ±Ëû·¢ÏÖÄãÕý×¢ÊÓ×ÅËûµÄÊ±ºò£¬µÉÁËÄãÒ»ÑÛ¡£\n",

"ºÚÎÞ³£°Ñ³¤³¤µÄÉàÍ·Éì³öÀ´£¬»º»ºµØÌòÁËÌò×Ô¼ºÓÖºÚÓÖ³¤µÄÊÖÖ¸¡£\n"
        }) );
	set("per", 100);
	set("str", 25);
	set("int", 20);
        set("age", 217);
	set("class", "youling");
        set("combat_exp", 120000);
  set("daoxing", 200000);

        set("max_kee", 800);
        set("max_sen", 800);
	set("max_gin", 400);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 500);
	set("mana_factor", 30);
        set("title", "ËÍ»êÊ¹Õß");
        set_temp("apply/damage", 10);
        set_skill("ghost-steps", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 80);
        set_skill("parry", 70);
  	set_skill("kusang-bang", 70);
        set_skill("spells", 70);
        set_skill("gouhunshu", 70);
        set_skill("force", 70);
        set_skill("stick", 70);
        set_skill("tonsillit", 70);
        set_skill("jinghun-zhang", 80);
        map_skill("spells", "gouhunshu");
        map_skill("dodge", "ghost-steps");
        map_skill("force", "tonsillit");
	map_skill("stick", "kusang-bang");
	map_skill("parry", "kusang-bang");
        map_skill("unarmed", "jinghun-zhang");
	create_family("ÑÖÂÞµØ¸®", 3, "ÄãºÃ");
        setup();
	carry_object("/d/obj/cloth/hei")->wear();
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
        	        command("say Î¹£¡ÑôÈËÀ´Òõ¼ä×öÊ²Ã´£¿ÄÑµÀÊÇ»îµÄÑá¾ëÁËÂð£¿\n");
                	kill_ob(ob);
               		ob->fight_ob(this_object());
                	return;
        	}
		return;
	}

        if ((int)ob->query("max_gin") <= 0 ||
            (int)ob->query("max_kee") <= 0 ||
            (int)ob->query("max_sen") <= 0)
                return;

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
{       object me;
        me = this_player();
        if ( (string)me->query("family/family_name")=="ÑÖÂÞµØ¸®") {
        if (((int)me->query("combat_exp") < 10000 )) {
        command("say " + RANK_D->query_rude(me) + "µÄÐÄ»¹²»¹»ºÚ£¬ÀÏ·ò²»Ð¼ÊÕÄã£¡\n");
        return;
        }
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
        command("shake");
        command("say " + RANK_D->query_rude(me) +
"»¹ÊÇÏÈÈ¥Ñ§Ð©»ù´¡¹¦·ò°É£¡\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}


ÿ