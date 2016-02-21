// jiaofu.c 轿夫

inherit NPC;

int do_kill(string);

void create()
{
	set_name("轿夫", ({ "jiaofu" }));
	set("long", "他就是专门负责抬花轿的轿夫。\n"
		"他看起来五大三粗，有把子力气，抬那花轿走着一定很稳当。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 80);
	set("int", 10);
	set("max_kee", 600);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
}

int do_kill(string arg)
{
	if (arg=="jiaofu" && environment()!=find_object("/d/moon/yltw")) {
		write("你想坏人好事，太不道德了吧。\n");
		return 1;
	 }
	return 0;
}
