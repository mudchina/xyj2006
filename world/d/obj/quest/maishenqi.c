//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
    set_name("卖身契", ({ "maishen qi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "cloth");
            set("long", "一张破旧的卖身契\n");
            set("owner_name", "金钗女");
          set("owner_id", "jinchai nu");
          }

    setup();
}
