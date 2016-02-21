//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("驴鞍", ({"lu an", "an"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是为张果老的小毛驴量身定做的。\n");
                set("unit", "块");
               set("owner_name","张果老");
               set("owner_id","zhang guolao");
        }
}
