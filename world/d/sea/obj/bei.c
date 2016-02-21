#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("²Ê±´¼×", ({"color shell","jia","armor","shell"}));
        set_weight(8000);
	set_max_encumbrance(3);
        if( clonep() ) {
		object a;
		seteuid(getuid());
		if(a=new("/d/sea/obj/pearl"))
			a->move(this_object());
                set_default_object(__FILE__);
       } else {
                set("unit", "¼þ");
            set("long", "Ò»¼þÆß²Ê±´¼×¡£\n");
                set("value", 0);
		set("no_sell",1);
                set("material", "wood");
                set("armor_prop/armor", 25);
		set("armor_prop/dodge",10);
             }
       setup();
}

