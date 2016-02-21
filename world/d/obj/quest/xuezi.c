//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("破靴子", ({"po xuezi", "boot"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "断足鬼死之前天天穿的鞋子。\n");
                set("unit", "双");
               set("owner_name","断足鬼");
               set("owner_id","duanzu gui");
        }
}
