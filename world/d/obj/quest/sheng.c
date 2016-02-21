//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("索命绳", ({"suoming sheng", "sheng"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这个绳子向你头上一套，你可就。。。。\n");
                set("unit", "个");
               set("owner_name","索命鬼");
               set("owner_id","suoming gui");
        }
}
