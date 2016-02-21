//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("Ä¦éàÊ×ÂŞ", ({"moyou shouluo", "shouluo"}));
       	set("gender", "ÄĞĞÔ");
       	set("age", 80);
        set("class", "taoist");
       	set("attitude", "friendly");
        set("per", 10);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 1000);
       	set("max_gin", 1000);
       	set("max_sen", 1000);
       	set("force", 2000);
       	set("max_force", 2000);
       	set("force_factor", 50);
       	set("max_mana", 3000);
       	set("mana", 3000);
       	set("mana_factor", 100);
       	set("combat_exp", 700000);
        set("daoxing", 2000000);

       	set_skill("dodge", 100);
       	set_skill("parry", 100);
        set_skill("jienan-zhi", 100);
        set_skill("spells", 200);
        set_skill("buddhism", 200);
        set_skill("lotusmove", 100);
	set_skill("unarmed", 100);

        map_skill("spells", "buddhism");
        map_skill("dodge", "lotusmove");
        map_skill("unarmed", "jienan-zhi");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: cast_spell, "lianhua" :),
                (: cast_spell, "bighammer" :),
        }) );


	setup();
	carry_object("/d/obj/cloth/jiasha")->wear();
}

