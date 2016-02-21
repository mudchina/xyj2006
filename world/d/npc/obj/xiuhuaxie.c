// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
	set_name(HIM "绣花鞋" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "上古十二神甲之：绣花鞋。  \n");
		set("material", "cloth");
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("no_sell",1);
		set("unit", "双");
		set("armor_prop/armor", 20 );
                set("armor_prop/dodge", 20 );
	}
	setup();
}


