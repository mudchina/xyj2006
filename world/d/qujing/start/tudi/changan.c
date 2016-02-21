//Cracked by Roath
// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("武馆弟子", ({ "wuguan dizi", "dizi", "trainee" }) );
	set("gender", "男性" );
	set("age", 18+random(10));
	set("long", "你看到一位身材高大的汉子，正在辛苦地操练着。\n");

	set("combat_exp",4000);


	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
}
