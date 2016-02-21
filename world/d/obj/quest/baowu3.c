//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("火龙镖", ({"huolong biao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "只见长有七寸五分，放出华光，火焰夺目，名曰：“心钉。”\n");
                set("unit", "件");
                set("lingtaibao","fake");
               set("owner_name","云阳真人");
                     set("owner_id","master yunyang");
        }
}

