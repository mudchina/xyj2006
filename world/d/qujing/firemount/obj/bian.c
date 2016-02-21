// bajiaobian

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("芭蕉鞭", ({"bajiao bian", "bian", "whip"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一条长长的芭蕉鞭，舞起来呼呼怍响．\n");
                set("unit", "条");
                set("value", 500);
        }
        init_whip(5);
        setup();
}

