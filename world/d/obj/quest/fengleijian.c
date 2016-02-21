//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
      set_name("风雷锏",({"fenglei jian","jian"}));
        set_weight(80);
        set("channel_id", "寻物精灵");
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","这是尉迟恭的惯用兵器。\n");
                set("unit", "件");
           set("owner_name", "尉迟恭");
           set("owner_id", "yuchi gong");
        }
}

