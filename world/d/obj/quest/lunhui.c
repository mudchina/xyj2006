//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
        set_name("轮回棒", ({"lunhui bang", "bang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "轮回司主「鬼王」王方平的轮回棒\n");
                set("unit", "条");
               set("owner_name","王方平");
               set("owner_id","wang fangping");
        }
}
