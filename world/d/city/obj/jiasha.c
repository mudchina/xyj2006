#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"护法袈裟"NOR, ({ "jia sha", "cloth" }) );
        set("long","一件金光灿灿的护法袈裟。");
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}

