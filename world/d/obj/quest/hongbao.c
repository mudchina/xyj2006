//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
    set_name("压岁红包", ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的红包，给小孩做压岁钱的\n");
            set("owner_name", "老害虫");
          set("owner_id", "xifuhui boss");
          }
    setup();
}
