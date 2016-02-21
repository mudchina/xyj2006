
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¿à¹Ï", ({"kug"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "Ò»¿ÅÐÂÏÊµÄ¿à¹Ï¡£\n");
                set("unit", "¿Å");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
