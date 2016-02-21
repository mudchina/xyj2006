#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIY"密信"NOR,({"xiuluo mixin","mixin"}));
    set_weight(100);
    if( clonep() )
         set_default_object(__FILE__);
    else
     {
         set("unit", "封");
         set("long", "这是一封黄色封面的信件。\n");
         set("value", 0);
     }
}
