// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hammer.c

#include <weapon.h>

inherit SPEAR;

void create()
{
          set_name("黑缨枪", ({"spear", "qiang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                  set("long", "这是一把黑缨枪，枪尖略显银光．\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_spear(25);
        setup();
}

