inherit NPC;

void create()
{
       set_name("小水母", ({"kid"}));

set("long","一个漂亮的小水母．\n");
       set("gender", "女性");
       set("age", 6);
	set("per", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 110);
        setup();
//        add_money("silver", 1);
//        carry_object("/d/gao/obj/blade")->wield();

}

