// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
        string *order = ({"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"});

        set_name( (order[random(12)]) + "阴鬼卒", ({ "hell guard", "guard" }) );

	set("long", "这是一位来自阴界的守护神，专门担任护法之责。\n");
	set("attitude", "friendly");
	set("per", 10);
	set("class", "youling");
	set("max_gin", 400);
	set("max_kee", 400);
	set("max_sen", 400);
	set("age", 40);

	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 10);

	set("str", 30);
	set("cor", 30);
	set("cps", 30);

        set_temp("apply/damage", 10);	
	set("combat_exp", 50000);

	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "喝道：孽障！随我赴阴司受审吧。\n"
	}) );

	set_skill("fork", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("force", 40);
	set_skill("tonsillit", 40);
        map_skill("force", "tonsillit");

	setup();

	carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
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
	message("vision","\n" +
		HIB + name() + "说道：谁与我们阴府作对，那不是自讨苦吃吗！\n\n"
		+ name() + "的身形发出幽暗的蓝光，沉入地下不见了。\n\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

