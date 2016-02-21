//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("傻帽", ({"sha mao", "cap"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "鹦鹉将军喜欢戴的帽子。\n");
                set("unit", "件");
               set("owner_name","鹦鹉将军");
               set("owner_id","yingwu jiangjun");
        }
}
