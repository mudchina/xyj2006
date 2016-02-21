// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("酆都鬼使", ({"hell guard", "guard"}));
	set("long", "这是一位来自阴界的守护神，专门担任护法之责。\n");
	set("attitude", "friendly");
	set("class", "youling");
	set("max_gin", 600);
	set("max_kee", 600);
	set("max_sen", 600);
	set("age", 50);

	set("max_force", 400);
	set("force", 400);
	set("force_factor", 20);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);

	
	set("combat_exp", 100000);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 15);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！随我赴阴司受审吧。\n"
	}) );

	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("tonsillit", 70);
	set_skill("ghost-steps", 70);
	set_skill("jinghun-zhang", 70);

	map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");

	setup();

	carry_object("/d/obj/armor/shoupi")->wear();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision", "\n" +
		HIB + name() + "说道：谁与我们阴府作对，那不是自讨苦吃吗！\n\n"
		+ name() + "的身形发出幽暗的蓝光，沉入地下不见了。\n\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

