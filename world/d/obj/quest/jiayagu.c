//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <task.h>
void create()
{
    set_name("假牙箍", ({ "jiaya gu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "gold");
            set("long", "一个发黄的假牙箍\n");
            set("owner_name", "大肚虾婆");
          set("owner_id", "xia po");
          }

    setup();
}
