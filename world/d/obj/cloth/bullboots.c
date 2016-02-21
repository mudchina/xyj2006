#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("ţƤѥ", ({"leather boots", "boots"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long","һ˫Ƥѥ���ϵ�ţƤ�Ƴɡ�\n");
                set("value", 400);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}

