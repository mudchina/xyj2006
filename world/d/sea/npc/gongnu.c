inherit NPC;

void create()
{
       set_name("宫女", ({"gongnu"}));

set("long","一个小丫环．\n");
       set("gender", "女性");
       set("age", 26);
	set("per", 30);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 120);
        setup();
//        add_money("silver", 1);
//        carry_object("/d/gao/obj/blade")->wield();

}

