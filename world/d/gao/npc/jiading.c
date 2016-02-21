// jiading.c

inherit NPC;

void create()
{
       set_name("家丁", ({"jiading"}));

set("long","一个体型魁悟，看起来孔武有力的大个子．\n正狠巴巴的瞪着你．\n");
       set("gender", "男性");
       set("age", 26);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 1800);
        set_skill("stick", 15);
	set_skill("parry", 25);
	set_skill("dodge", 35);
	set("force_factor", 3);
	setup();
        add_money("coin", 50);
        carry_object("/d/gao/obj/bang")->wield();

}

