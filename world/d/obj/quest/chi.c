//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("戒尺", ({"jie chi", "chi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "平等王用来执法的戒尺。\n");
                set("unit", "把");
               set("owner_name","平等王");
               set("owner_id","pingdeng wang");
        }
}
