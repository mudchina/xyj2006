//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("弹珠", ({"tan zhu", "zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "龙少爷小时候玩的弹珠。\n");
                set("unit", "件");
               set("owner_name","龙少爷");
               set("owner_id","long shaoye");
        }
}

