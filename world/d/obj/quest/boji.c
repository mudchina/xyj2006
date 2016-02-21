//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("竹簸箕",({"zhu boji"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是竹子编织的簸箕。\n");
                set("unit", "个");
          set("owner_name", "培土力士");
          set("owner_id", "li shi");
        }
}
