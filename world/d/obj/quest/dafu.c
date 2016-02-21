//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("大斧",({"big axe", "axe"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是程咬金的惯用兵器。\n");
                set("unit", "件");
          set("owner_name", "程咬金");
          set("owner_id", "cheng yaojin");
        }
}

