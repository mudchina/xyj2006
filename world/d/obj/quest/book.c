//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
#include <task.h>
inherit ITEM;

void create()
{
        set_name("老古董", ({"lao gudong", "gudong"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "贺知章的老古董\n");
                set("unit", "件");
               set("owner_name","贺知章");
               set("owner_id","He zhizhang");
        }
}
