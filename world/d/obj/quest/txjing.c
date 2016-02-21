//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("白首太玄经",({ "taixuan jing" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("long", "这是一本讲述古时侠客精彩跌宕的江湖传奇\n");
                set("owner_name", "游侠儿");
          set("owner_id", "youxia er");
        }
}
