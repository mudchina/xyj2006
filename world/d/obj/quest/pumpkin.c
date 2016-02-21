//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <task.h>
void create()
{
        set_name("南瓜", ({ "pumpkin" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个圆圆的，硬邦邦的大南瓜\n");
                set("unit", "个");
                set("value", 15);
                set("owner_name","相公");
                 set("owner_id","xiang gong");
        }
}
