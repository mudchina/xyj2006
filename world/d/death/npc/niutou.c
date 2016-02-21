//puti.c
inherit NPC;

void create()
{
       set_name("牛头鬼", ({"niutou gui", "gui", "niutou"}));
       set("gender", "男性");
       set("age", 30);
	set("long", "一个牛头鬼，脸部是一野牛模样。\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 10);
	set("str",20);
       set("combat_exp", 90000+random(10000));
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("whip", 80);
	set_skill("parry", 80);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 15);
	set("mana", 300);
	set("max_mana", 300);
	set("mana_factor", 15);
	set("max_kee", 800);
	set("max_sen", 800);
set("inquiry", ([
"name": "老子就是杀人无数，爱啃后脑勺的牛头鬼！\n",
"here": "这就是阴曹地府，哼，等着剥皮抽筋吧你！\n",
]) );


setup();

        carry_object("/d/obj/armor/shoupi")->wear();
        carry_object("/d/obj/weapon/whip/tielian")->wield();
}

