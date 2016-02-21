// created 6/8/97 pickle
// lingjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("令箭",({"ling jian", "ling", "jian", "lingjian"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一枝短短的小箭，上写一个「齐」字。\n");
		set("unit","枝");
		set("name_recognized", "齐府令箭");
		set("value", 0);
		set("material","bone");
		set("wield_msg","$N百忙中在怀里一掏，掏出一枝$n，握在手中。\n");
		set("unwield_msg","$N小心翼翼地把$n放回怀里，心道：幸亏没给碰坏了。\n");
	}
	init_dagger(2);
	setup();
}
