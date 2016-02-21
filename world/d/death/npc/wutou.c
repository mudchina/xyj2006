//puti.c
inherit NPC;

void create()
{
       set_name("无头鬼", ({"wutou gui", "gui"}));
       set("gender", "男性");
	set("long", "一个没有头，只有身子的野鬼．\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 6000+random(1000));
	set_skill("unarmed",15);
	set_skill("dodge", 15);
	set_skill("parry", 35);


setup();

//        carry_object("/d/diyu/obj/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/diyu/obj/tielian")->wield();
}


