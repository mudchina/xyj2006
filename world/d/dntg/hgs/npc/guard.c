
inherit NPC;

void create()
{
       set_name("老齐", ({"guard"}));
       set("long", "东方武馆的看门人，正在打瞌睡．\n");
       set("title", "门房");
       set("gender", "男性");
        set("combat_exp", 2000);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
        setup();
       add_money("silver", 5);
}

