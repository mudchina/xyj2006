inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIG "树" NOR , ({ BLINK HIG "tree" NOR, "shu" }) );
        set("long", BLINK HIG "一棵参天大树 \n" NOR);
        set("no_get",1);
        setup();
}
