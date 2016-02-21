//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("韦陀", ({"wei tuo", "tuo"}));
       	set("gender", "男性");
       	set("age", 40);
	set("title", "护法天尊");
        set("class", "fighter");
       	set("attitude", "friendly");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 2000);
       	set("max_gin", 2000);
       	set("max_sen", 2000);
       	set("force", 3000);
       	set("max_force", 3000);
       	set("force_factor", 80);
       	set("max_mana", 2000);
       	set("mana", 2000);
       	set("mana_factor", 80);
       	set("combat_exp", 2000000);
        set("daoxing", 1200000);

       	set_skill("dodge", 180);
       	set_skill("parry", 180);
        set_skill("staff", 180);
        set_skill("lunhui-zhang", 180);
        set_skill("spells", 160);
        set_skill("buddhism", 160);
        set_skill("lotusmove", 180);
        map_skill("spells", "buddhism");
        map_skill("parry", "lunhui-zhang");
        map_skill("dodge", "lotusmove");
        map_skill("staff", "lunhui-zhang");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :)
        }) );

	setup();
        carry_object("/d/qujing/start/obj/xiangmochu")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

