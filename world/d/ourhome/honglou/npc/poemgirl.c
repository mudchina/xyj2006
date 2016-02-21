// poemgirl.c

inherit NPC;

#include <ansi.h>

int send_back(object me);

void create()
{
	set_name("Ì½´º", ({ "tan chun", "chun", "girl" }) );
	set("gender", "Å®ÐÔ" );
	set("age", 16);
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set_skill("literate", 100);
	set_skill("dodge", 100);
	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
}
