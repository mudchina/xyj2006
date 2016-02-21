//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("水壶", ({"shui hu", "hu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "芭将军在花果山用来盛水的家伙。\n");
                set("unit", "个");
               set("owner_name","芭将军");
               set("owner_id","ba jiangjun");
        }
}
