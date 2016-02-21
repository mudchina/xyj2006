//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("烂鱼网", ({"lan yuwang", "wang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "别看网烂，却可以捉到鱼。\n");
                set("unit", "条");
               set("owner_name","张顺");
                set("owner_id","zhang shun");
        }
}

