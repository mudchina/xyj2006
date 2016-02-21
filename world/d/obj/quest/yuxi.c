//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("大唐玉玺",({"yu xi"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是大唐国皇帝唐太宗的印玺，上面刻了“贞观昌隆”四个篆字。\n");
                set("unit", "件");
          set("owner_name", "唐太宗");
          set("owner_id", "tang taizong");
        }
}

