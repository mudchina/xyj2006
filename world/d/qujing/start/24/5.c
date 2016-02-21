//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("阎罗王", ({"yanluo wang", "wang"}));
       	set("gender", "男性");
       	set("age", 50);
	set("title", "阴间十王之");
        set("class", "youling");
       	set("attitude", "friendly");
       	set("rank_info/respect", "大王");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 1800);
       	set("max_gin", 1800);
       	set("max_sen", 1800);
       	set("force", 2000);
       	set("max_force", 2000);
       	set("force_factor", 80);
       	set("max_mana", 2000);
       	set("mana", 2000);
       	set("mana_factor", 80);
       	set("combat_exp", 1000000);
        set("daoxing", 2000000);

        set_skill("jinghun-zhang", 150);
        set_skill("tonsillit", 100);
        set_skill("gouhunshu", 150);
       set_skill("unarmed", 150);
        set_skill("whip", 150);
        set_skill("hellfire-whip", 150);
        set_skill("sword", 150);
        set_skill("zhuihun-sword", 150);
       set_skill("dodge", 150);
        set_skill("ghost-steps", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
        set_skill("stick", 150);
        set_skill("kusang-bang", 150);

        map_skill("sword", "zhuihun-sword");
        map_skill("parry", "zhuihun-sword");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");
        map_skill("spells", "gouhunshu");

        set("nk_gain", 500);

        set_temp("apply/armor", 50);
        set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
                (: cast_spell, "inferno" :),
                (: cast_spell, "invocation" :),
        }) );


	setup();
        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

