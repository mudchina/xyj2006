//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("竹篮",({"zhu lan"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是七仙女采摘蟠桃用的竹篮子。\n");
                set("unit", "个");
          set("owner_name", "素衣仙女");
            set("owner_id", "suyi xiannu");
        }
}
