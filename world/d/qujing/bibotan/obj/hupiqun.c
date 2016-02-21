#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name("虎皮披风", ({ "tiger surcoat","surcoat" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件虎皮的披风，穿起来想必是相当威风。\n");
                set("material", "cloth");
                set("unit", "件");
                set("armor_prop/armor", 5);
		set("armor_prop/dodge", 5);
		set("armor_prop/armor_vs_force", 50);
		set("armor_prop/armor_vs_spells", 50);
		set("msg_wear", "$N披上一件$n。\n");
		set("msg_remove", "$N解下$n。\n");
		set("armor_prop/personality", 3);
                set("armor_prop/spirituality", 3);
        }
        setup();
}

