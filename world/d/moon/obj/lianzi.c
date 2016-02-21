
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("莲子", ({"lian zi", "lianzi","lotus seed"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "苦苦的莲子，可以清心消火。\n");
                set("unit", "颗");
		set("value", 10);
		set("food_remaining", 1);
		set("food_supply", 10);
	}
}
