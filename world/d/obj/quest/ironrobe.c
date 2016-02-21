//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("铁甲袍", ({ "ironrobe" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "iron");
                set("owner_name","独角兕大王");
                     set("owner_id","dujiaosi dawang");
               }
        setup();
}
