//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("天童寺慈悲刀刀谱",({"dao pu"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是浙江鄞县天童寺秘门绝技慈悲刀的残缺刀谱。\n");
                set("unit", "本");
          set("owner_name", "慈悲和尚");
          set("owner_id", "cibei heshang");
        }
}
