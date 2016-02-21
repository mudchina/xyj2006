//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
        set_name("木笛子", ({"mu dizi", "dizi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "韩湘子小时候最喜欢吹笛子，那时没有钱，就自己做了个木笛子。\n");
                set("unit", "支");
               set("owner_name","韩湘子");
               set("owner_id","han xiangzi");
        }
}
