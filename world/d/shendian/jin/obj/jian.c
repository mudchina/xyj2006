inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIY "剑" NOR , ({ BLINK HIY "sword" NOR, "jian" }) );
         set("long", BLINK HIY "一把被倒挂起来的剑 \n" NOR);
        set("no_get",1);
        setup();
}
