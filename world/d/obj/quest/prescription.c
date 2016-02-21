//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("药方",({ "yaofang" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "纸");
                set("material", "paper");
                set("long", "这是一张由名医万春流开的药方。\n");
                set("owner_name", "雾渊道长");
    set("owner_id", "wuyuan daozhang");
        }
}

// prescription.c
