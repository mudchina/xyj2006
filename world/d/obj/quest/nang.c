//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("宝囊", ({"bao nang", "nang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "太白金星用来装宝贝的袋子。\n");
                set("unit", "个");
               set("owner_name","太白金星");
               set("owner_id","tai bai");
        }
}
