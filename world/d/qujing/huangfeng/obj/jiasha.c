// d/qujing/huangfeng/obj/jiasha.c
//降魔袈裟      created by smile 12/14/1998

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void init()
{
  cloth::init();
  unique::init();
}

void create()
{
	set_name(HIY"降魔袈裟"NOR, ({ "xiangmo jiasha", "jiasha" }) );
	set("long", "此乃我祖如来所赐之降魔袈裟，穿上可增强降魔法力。\n");
	set_weight(2800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 60);
		set("armor_prop/spells", 40);
		set("armor_prop/dodge", 30);
		set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 50000);
	}
	setup();
}

