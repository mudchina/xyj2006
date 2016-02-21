//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("一柱香", ({"yizhu xiang", "xiang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "在商店里面很常见的一种香。\n");
                set("unit", "根");
                set("owner_name","烧香老太太");
            set("owner_id","lao taitai");
        }
}
