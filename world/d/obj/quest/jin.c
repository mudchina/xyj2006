//Cracked by Roath


// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("手巾", ({"shou jin", "jin"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这块手斤可救过秦大人的命呢。\n");
                set("unit", "块");
               set("owner_name","秦琼");
               set("owner_id","qin qiong");
        }
}
