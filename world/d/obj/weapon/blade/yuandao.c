// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
set_name(HIR"鸳刀"NOR, ({"yuan dao", "yuandao",  "dao", "blade", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 0);
		set("is_monitored", 1);
		set("no_sell", 1);
	set("replace_file", "/d/obj/weapon/blade/jindao");
set("material", "steel");
set("long", "这是一柄做工精细的单刀，上面写着两个小篆[仁无]。\n");
	}
	init_blade(80);
	setup();
}
