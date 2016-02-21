//Cracked by Roath
//xueshu.c

#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIR"血书"NOR, ({"xue shu"}));
        set_weight(50);
                set("unit", "张");
                set("long","当初殷温娇藏在玄奘身上之物.\n");
        setup();
}
