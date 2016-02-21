// laoyu.c

inherit NPC;

void create()
{
       set_name("老余头", ({"laoyu"}));
       set("long", "老高家的看门人，正在打瞌睡．\n");
       set("title", "看门大爷");
       set("gender", "男性");
	set("combat_exp", 100);
       set("age", 56);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 15);
	setup();
       add_money("silver", 5);
}

