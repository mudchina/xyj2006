//shushan2 by yushu@SHXY 2000.12
#include <armor.h>
inherit F_UNIQUE;
inherit BOOTS;
void create()
{
        set_name("÷ÈÓ°ÉñÑ¥", ({ "meiying shoes", "shoes" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("value", 10000);
		  set("no_sell", 1);
		  set("no_drop", 1);
		  set("no_put", 1);
                set("replace_file", "/d/shushan/obj/shoe");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 60);

        }
        set("is_monitored",1);
        setup();
}

