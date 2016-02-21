//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("花裙子", ({"hua qunzi", "qunzi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件很漂亮的裙子。\n");
                set("unit", "件");
               set("owner_name","龙婆");
               set("owner_id","long po");
        }
}
