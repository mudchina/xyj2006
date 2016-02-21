//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("擀面杖", ({"ganmian zhang", "zhang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "凌汤园做元宵时用的擀面杖。\n");
                set("unit", "根");
               set("owner_name","凌汤圆");
               set("owner_id","ling");
        }
}
