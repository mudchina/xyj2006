#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("ÕäÖé", ({"pearl"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",    "Ò»¿Å»ëÔ²µÄÕäÖé¡£\n");
                set("unit", "¿Å");
                set("base_unit", "¿Å");
                set("base_weight", 1);
                set("base_value", 1000);
                set("value", 1000);
		set("weapon_prop/personality",1);
		set("wield_msg","$NÇáÇá½«ÕäÖéÄóÔÚÖ¸·ìÖĞ¡£\n");
        }
        set_amount(1);
        init_throwing(20);
        setup();
}

