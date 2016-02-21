//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("绣花针", ({"xiuhua zhen", "zhen"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "浣花平时用来补衣服用的针。\n");
                set("unit", "根");
               set("owner_name","浣花");
               set("owner_id","huan hua");
        }
}
