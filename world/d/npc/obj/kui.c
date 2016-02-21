#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(MAG"×Ï½ð¹Ú"NOR, ({ "hat" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_put",1);
                set("no_give",1);
                set("no_zm",1);
                set("unit", "¶¥");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 30);
        }
        setup();
}

