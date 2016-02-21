// ghost.c

inherit NPC;

void create()
{
	set_name("¹Â»êÒ°¹í", ({ "wandering ghost", "ghost" }) );
	set("age", 45);
	
	set("str", 24);
	set("cor", 26);

	set("env/wimpy", 70);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);

	setup();
}

int is_ghost() { return 1; }
