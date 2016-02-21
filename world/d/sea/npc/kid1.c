inherit NPC;

void create()
{
       set_name("小螃蟹", ({"kid"}));

set("long","一个小螃蟹，在和小虾米玩．\n");
       set("gender", "男性");
       set("age", 6);
	set("per", 10);
       set("attitude", "friendly");
       set("shen_type", 1);
        set("combat_exp", 60);
        setup();
//        add_money("silver", 1);
//        carry_object("/d/gao/obj/blade")->wield();

}

