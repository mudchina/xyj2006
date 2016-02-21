//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("冰袋", ({"bing dai" ,"dai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",   "一个用来装冰块的袋子。\n");
                set("unit", "件");
               set("owner_name","秃鹰尊者");
               set("owner_id","tuying zunzhe");
        }
}

