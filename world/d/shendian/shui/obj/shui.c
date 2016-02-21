inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIB "水" NOR , ({ BLINK HIB "shui" NOR, "water" }) );
     set("long", BLINK HIB "汹涌的水流 \n" NOR);
        set("no_get",1);
        setup();
}
