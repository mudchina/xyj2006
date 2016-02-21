// gangcha.c

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("银叉", ({ "silver fork", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "iron");
                set("long", "一柄小巧的银叉。\n");
                set("wield_msg", "$N抄起一柄$n轻轻的握在手里。\n");
        }
        init_fork(40);
        setup();
}

