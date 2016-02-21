#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("妈祖", ({"ma zu","mazu","haishen","niangniang"}));

	set("long","传说中守护海界的女神，保佑海民出海平安．\n");
    set("gender", "女性");
       set("age", 30);
       set("title", HIB"海神娘娘"NOR);
       set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 8260000);
       set("daoxing", 9500000);
       set("per", 40);
       set("str", 1000);
       set("max_kee", 6000);
       set("max_gin", 6000);
       set("max_sen", 6000);
       set("force", 16000);
       set("max_force", 8000);
       set("force_factor", 300);
       set("max_mana", 8000);
       set("mana", 16000);
       set("mana_factor", 400);
       set_skill("huntian-hammer", 280);
       set_skill("hammer", 250);
       set_skill("literate", 250);
       set_skill("unarmed", 250);
       set_skill("dodge", 250);
       set_skill("force", 280);
       set_skill("parry", 280);
       set_skill("fork", 300);
       set_skill("spells", 280);
	set_skill("seashentong", 280);
	set_skill("dragonfight", 250);
	set_skill("dragonforce", 280);
	set_skill("fengbo-cha", 300);
	set_skill("dragonstep", 250);
	map_skill("hammer", "huntian-hammer");
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "fengbo-cha");
	map_skill("parry", "fengbo-cha");
	map_skill("dodge", "dragonstep");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "freez" :),
                (: cast_spell, "water" :),
                (: exert_function, "roar" :),
                (: exert_function, "shield" :),
                (: perform_action, "unarmed", "sheshen" :),
                (: perform_action, "fork", "fengbo" :),
                }) );
        create_family("东海龙宫", 1, "水族");
	set_temp("apply/armor",250);
	set_temp("apply/damage",250);
	setup();

        carry_object("/d/sea/obj/longpao")->wear();
        carry_object("/d/sea/obj/tuotiancha")->wield();
}

void attempt_apprentice(object ob)
{	
       
       
       if (ob->query("obstacle/number") < 26) {
        command("say 这位" + RANK_D->query_respect(ob) + "你还是先出去闯荡一番吧！\n");
        command("sigh");
        return;
        }

      if (((int)ob->query("daoxing") < 1000000 )) {
         command("say " + RANK_D->query_rude(ob) + "这点三脚猫的把式怎么能拜我为师？回去练练把!");
         return;
       }
       
       
       command("smile");
        command("say 难得" + RANK_D->query_respect(ob) +
		"有此心志，还望日后多加努力，为我水族争光。\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
              ob->set("class", "dragon");
        ob->set("title", HIB"妈祖娘娘传人"NOR);
}

