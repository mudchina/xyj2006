#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(RED"玫瑰香精"NOR,({"meigui xiangjing","xiangjing"}));
    set_weight(1000);
    if( clonep() )
         set_default_object(__FILE__);
    else
     {
         set("unit", "盒");
         set("long", "这是一盒玫瑰香精。\n");
         set("value", 50000);
     }
}
