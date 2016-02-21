//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("滴天髓",({ "ditiansui" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "纸");
                set("material", "paper");
                set("long", "这是一张记载了四柱论命的玄玄神机的纸\n");
                set("owner_name","袁守诚");
                     set("owner_id","yuan shoucheng");
        }
}
