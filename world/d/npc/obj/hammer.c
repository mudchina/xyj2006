#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIC"神锤"NOR, ({ "shen chui","chui","hammer" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", MAG"上古十二神兵之一：神锤。\n"NOR);
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
//                set("no_give",1);

                set("material", "wood");
                set("wield_msg", "$N拿出一把$n，试了试重量，然后握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(100+random(100));
        setup();
}

