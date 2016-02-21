// guanjia.c

inherit NPC;

void create()
{
       set_name("高才", ({"gao cai", "gao"}));
       set("long","一个小伙计，给管家跑腿．\n");
	set("title", "小伙计");
       set("gender", "男性");
       set("age", 16);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 600);
	setup();

}

