// tong-nan.c

inherit NPC;

void create()
{
	set_name("童男", ({ "tong-nan", "boy" }) );
	set("gender","男性" );
	set("long",
		"这是一个十岁左右的小男孩，长得眉清目秀，\n"
		"非常讨人喜爱。\n"
	);
	set("age",10);
	set("per",30);
	set("combat_exp", 5000);
	set("score",500);
	set("force",100);
	set("max_force",100);
	set_skill("unarmed",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set_skill("force",40);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
}
