// niu.c
// 1996/10/31 by none

inherit NPC;

void create()
{
	set_name("风雪皇后", ({ "queen" }) );
	set("gender", "女性" );
	set("age", 18);
	set("per", 25);
	set("long",
		"其素若何：春梅绽雪。其洁若何：秋兰披霜。
其静若何：松生空谷。其艳若何？霞映澄塘。
其文若何：龙游曲沼。其神若何：月射寒江。\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "风雪天地皇后是也。",
		"here" : "风雪之上，天地之中。",
	]) );
	set_skill("literate", 100);
	setup();
	carry_object("/d/obj/cloth/skirt.c")->wear(); 
	carry_object("/d/obj/cloth/shoes")->wear();
}

