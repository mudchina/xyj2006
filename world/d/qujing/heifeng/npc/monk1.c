//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/heshang.c
 
inherit NPC;

void create()
{
        set_name("念经和尚", ({"he shang","monk"}));
        set("long", "一位大和尚，看起来慈善的很，口里还不停的咏经。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 10+random(10));
        set("combat_exp", 15000);
        set("shen_type", 1);
        set("per", 25);
        set("max_kee", 380);
        set("max_gin", 300);
        set("force", 250);
        set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}

void init()
{
        object ob = this_player();

        if( ob->query_temp("fired") )
        {
        command("fear");
        command("say 袈裟.....不见了。");
        return;
}
}
