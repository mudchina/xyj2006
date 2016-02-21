// jiading.c

inherit NPC;

void create()
{
       set_name("小学徒", ({"xuetu"}));

set("long","瘦瘦小小，还是个孩子．\n在帮老李头打炼铁器．\n");
       set("gender", "男性");
       set("age", 15+random(4));
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 200+random(400));
	setup();

}

