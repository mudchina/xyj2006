// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hammer.c

#include <weapon.h>

inherit STAFF;

void create()
{
          set_name("拐杖", ({"staff", "zhang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                 set("long", "这是一把用檀木做成的手杖．\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(25);
        setup();
}

