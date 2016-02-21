//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name("朱笔", ({"zhu bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这可是宝贝啊。\n");
                set("unit", "只");
               set("owner_name","崔珏");
               set("owner_id","cui jue");
        }
}
