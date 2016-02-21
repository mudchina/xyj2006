//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("招牌", ({"zhao pai", "pai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "货行老板 戴文重的老字号招牌。\n");
                set("unit", "块");
               set("owner_name","戴文重");
               set("owner_id","dai wenzhong");
        }
}
