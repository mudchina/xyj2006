// blade.c

#include <weapon.h>

inherit BLADE;

string *names = ({
  "柳月刀",
  "凤鸣刀",
  "鬼头刀",
  "紫金刀",
});

string *ids = ({
  "liu yue dao",
  "feng ming dao",
  "gui tou dao",
  "zi jin dao",
});


void create()
{
        int ii;
        ii=random(sizeof(names));
        set_name(names[ii], ({ids[ii], "blade", "dao"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 1500);
		set("material", "steel");
		set("long", "一柄寒光闪闪的"+this_object()->query("name")+"。\n");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(35);
	setup();
}
