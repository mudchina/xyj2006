//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("虎皮帽", ({"hupi mao", "mao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "孙大圣取经时戴过的帽子。\n");
                set("unit", "个");
               set("owner_name","六耳猕猴");
               set("owner_id","liuer mihou");
        }
}
