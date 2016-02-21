//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("人血", ({"ren xue", "xue"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "碧鼠精最爱吃的东西。\n");
                set("unit", "滴");
               set("owner_name","碧鼠精");
               set("owner_id","bi shu");
        }
}
