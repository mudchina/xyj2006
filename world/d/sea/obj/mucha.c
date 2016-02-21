// gangcha.c

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("Ä¾²æ", ({ "fork", "cha"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                set("value", 100);
                set("material", "iron");
        }
        init_fork(5);
        setup();
}

