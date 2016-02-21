
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¹şÃÜ¹Ï", ({"hami gua", "mellon","gua"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "ÓÖÏãÓÖÌğµÄ¹şÃÜ¹Ï¡££\n");
                set("unit", "¿Å");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
