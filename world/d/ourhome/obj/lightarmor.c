// lightarmor.c
inherit EQUIP;

void create()
{
        set_name("ÌÙ¼×", ({"teng jia","tengjia","jia","armor"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
	    set("long", "Ò»¼þÇá±ãÌÙ¼×¡£\n");
                set("value", 5000);
                set("material", "wood");
                set("armor_type", "cloth");
                set("armor_prop/armor", 20);
             }
}
