#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"绿丹瓶"NOR, ({ "lvdan ping", "ping" }) );
        set_weight(5000);
        set_max_encumbrance(50);
        if( clonep() ) {
                object a;
                  seteuid(getuid());
                if(a=new("/d/sea/obj/cool_dan"))
                  a->move(this_object());

                set_default_object(__FILE__);
        } else {
                set("unit", "个");
                set("long", "一个绿色的小丹瓶，掂在手里重重的。\n");
                set("value", 10000);
		set("no_sell", 1);
        }
}

int is_container() { return 1; }

