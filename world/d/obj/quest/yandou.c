//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("烟斗", ({"yan dou", "dou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "乌鸦先生最喜欢用的烟斗。\n");
                set("unit", "个");
               set("owner_name","乌鸦先生");
set("owner_id","wuya xiansheng");
        }
}
