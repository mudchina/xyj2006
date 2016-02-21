//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("木桃剑", ({"mutao jian", "jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "袁天罡施法时用的桃剑。\n");
                set("unit", "把");
               set("owner_name","袁天罡");
               set("owner_id","yuan tiangang");
        }
}
