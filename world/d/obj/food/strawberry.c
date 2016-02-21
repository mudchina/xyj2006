// xueli.c Ñ©Àæ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("²ÝÝ®", ({"cao mei", "strawberry","caomei"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "ÏÊºìµÄ²ÝÝ®¡£\n");
                set("unit", "°Ñ");
		set("value", 120);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
