//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
        set_name("锄头", ({"chu tou", "tou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "吴文用的锄头。\n");
                set("unit", "个");
               set("owner_name","吴文");
               set("owner_id","wu wen");
        }
}
