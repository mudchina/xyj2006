// guanjia.c

inherit NPC;

void create()
{
       set_name("高正", ({"gao zheng", "gao"}));
       set("long","老高家的管家，正拿着帐簿算帐．\n");
       set("gender", "男性");
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("title", "老管家");
	set("combat_exp", 6500);
       set_skill("unarmed", 15);
	set_skill("dodge", 15);
	setup();
       add_money("silver", 5+random(8));
        carry_object("/d/gao/obj/magua")->wear();

}
int accept_fight(object me)
{
        command("say 活动活动筋骨也好！\n");
        return 1;
}

