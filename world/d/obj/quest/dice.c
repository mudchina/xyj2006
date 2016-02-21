//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("象牙骰子", ({ "toothdice","dice" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一颗象牙骰子，用金粉刻着点，应该有三粒。\n");
                set("unit", "粒");
                set("owner_name", "小管家");
          set("owner_id", "guan jia");
                
        }
        
        setup();
}
