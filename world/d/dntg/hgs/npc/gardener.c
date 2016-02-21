
inherit NPC;

void create()
{
       set_name("花匠", ({"hua jiang", "jiang"}));
       set("long", "东方武馆的花匠，正提着水浇花。\n");
       set("gender", "男性");
        set("combat_exp", 1000);
	set("per", 18);
       set("age", 26);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        setup();
       add_money("silver", 5);
}

