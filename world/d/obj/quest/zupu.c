//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("乌鸡国族谱",({"zu pu"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是乌鸡国皇家的族谱。\n");
                set("unit", "本");
          set("owner_name", "太子");
          set("owner_id", "tai zi");
        }
}

