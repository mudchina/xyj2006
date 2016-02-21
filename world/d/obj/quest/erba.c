//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

#include <task.h>
void create()
{
        set_name("耳朵拔子", ({"er ba", "ba zi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "顺风耳的耳朵拔子.\n");
                set("unit", "件");
               set("owner_name","顺风耳");
              set("owner_id","shunfeng er");
        }
}
