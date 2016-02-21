#include <armor.h>

inherit CLOTH;
inherit F_CLOTHNAME;

void create()
{
    set_name(woman_cloth(), ({ "yi fu","cloth" }) );
    set_weight(400);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "Ì×");
        set("value",0);
        set("material", "cloth");
        set("armor_prop/armor", 50);
    }
    setup();
}
