#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("龙头杖", ({ "dragon staff", "staff" }));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long",
"一条又粗又长的铁杖，上有一龙头，周围镶著六个铜环。\n");
                set("value", 5000);
                set("material", "brass");
                set("wield_msg", "$N拿出一根金光灿然的$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(50);
        setup();
}

