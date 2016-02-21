#include <weapon.h>

inherit BOW; 

void create()
{
        set_name("木弓", ({"mu gong", "bow", "gong"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一张木制的短弓。\n");
                set("unit", "张");
		set("value", 100);
                set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
                set("material", "wood");
        }

        init_bow(1);
        setup();
}

