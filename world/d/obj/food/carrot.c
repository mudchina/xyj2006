// carrot.c ºúÂÜ²·

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ºúÂÜ²·", ({"carrot", "huluobo"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "Ò»¿ÅĞÂÏÊ¿ÉÈËµÄºúÂÜ²·¡£\n");
                set("unit", "¿Å");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
