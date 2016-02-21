// gao.c

inherit NPC;

void create()
{
       set_name("高婆", ({"gao po", "gao", "po"}));
       set("long","高庄主的老婆，虽已四十多岁，看起来还又几分姿色．\n");
       set("gender", "女性");
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("per", 20);
	set("combat_exp", 7400);
        set_skill("unarmed", 10);
	set_skill("dodge", 50);
	set_skill("parry", 20);
	setup();
       add_money("gold", 1);
        carry_object("/d/gao/obj/ao")->wear();

}

