//Cracked by Roath

//Ansi 99.8 
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY"锦衣金袍"NOR, ({"jinjinyi", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件镶有金边的锦衣长袍。\n");
                set("material", "cloth");
                set("unit", "件");
                set("value", 10000);
                set("armor_prop/armor", 10);
     set("armor_prop/personality", 2);
        }
        setup();
}
