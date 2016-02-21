#include <armor.h>

inherit WAIST;

void create()
{
        set_name("护心镜", ({ "huxin jing", "mirror","huxinjing",  "jing", "huxin", "waist" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", "一面黄铜做的护心镜。\n");
                set("material", "copper");
		set("value", 100);
                set("armor_prop/armor", 5);
        }
        setup();
}
