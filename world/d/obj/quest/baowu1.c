//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("八卦云光帕", ({"yunguang po", "po"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "有坎离震兑之宝，包罗万象之珍\n");
                set("unit", "件");
                set("lingtaibao","fake");
               set("owner_name","嫦娥");
               set("owner_id","chang e");
        }
}

