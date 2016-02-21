// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name(YEL"枯骨刀"NOR, ({"kugu dao", "kugudao", "kugu", "dao", "blade", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 0);
		set("is_monitored", 1);
		set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("material", "bone");
		set("name_recognized", "枯骨刀");
		set("long", "这是一柄暗黄色的单刀，份量很轻。\n");
		set("wield_msg", "$N的脸上突然掠过一抹暗红色，再看时，手中多了一柄$n。\n");
		set("unequip_msg", "$N反手将$n插会鞘中，脸色也随之一亮。\n");
	}
	init_blade(80);
	setup();
}
