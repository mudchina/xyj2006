//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("山羊胡子", ({"shanyang huzi", "huzi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把老龙王的山羊胡子。\n");
                set("unit", "把");
               set("owner_name","敖广");
               set("owner_id","ao guang");
        }
}
