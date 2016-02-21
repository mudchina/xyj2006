
// shancai.c 善财童子
// By Lestat 2001
inherit NPC;
inherit F_MASTER;
#include "place.h"

//string ask_for_partner();
//string ask_mieyao();
//string ask_cancel();

void create()
{
        set_name("善财童子", ({ "shancai tongzi", "shancai", "tongzi" }));
        set("title", "南海观音侍从");   
        set("long", @LONG
南海观音座前护法弟子善财童子。
LONG);
        set("gender", "男性");
        set("age", 15);
        set("attitude", "peaceful");
        set("rank_info/self", "贫僧");
        set("class", "bonze");
    
    set("max_kee", 2000);
        set("max_gin", 600);
           set("max_sen", 2000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 175);
        set("max_mana", 2000);
        set("mana", 2000);
        set("mana_factor", 155);
        set("combat_exp", 1750000);
		set("daoxing", 1750000);

        set("eff_dx", 150000);
        set("nkgain", 300);

        set_skill("literate", 150);
        set_skill("spells", 150);
        set_skill("buddhism", 150);
        set_skill("unarmed", 150);
        set_skill("jienan-zhi", 150);
        set_skill("dodge", 150);
        set_skill("lotusmove", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("lotusforce", 150);
        set_skill("staff", 150);
        set_skill("lunhui-zhang", 150);
        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");


        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
                (: cast_spell, "jingang" :)
        }) );

        create_family("南海普陀山", 2, "弟子");

        setup();
        carry_object("/d/nanhai/obj/sengpao")->wear();
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say " + RANK_D->query_respect(ob) + "未入佛门，恕贫僧不能接纳。\n");
                return;
        }       
        if (((int)ob->query_skill("buddhism", 1) < 70 )) {
                command("say " + RANK_D->query_respect(ob) + "若欲深修，需得熟读佛法。\n");
                return;
        }
        command("nod");
        command("say 很好，贫僧就收下你，希望你多加努力，早成正果。\n");

        command("recruit " + ob->query("id") );
        return; 
}

