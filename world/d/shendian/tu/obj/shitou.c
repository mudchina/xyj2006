inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIC "石头" NOR , ({ BLINK HIC "shitou" NOR, "stone" }) );
      set("long", BLINK HIC "一截断石 \n" NOR);
        set("no_get",1);
        setup();
}
