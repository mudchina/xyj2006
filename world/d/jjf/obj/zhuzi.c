// created 6/8/97 pickle
// lingjian.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("柱子",({"zhu zi", "zhu", "zi", "zhuzi", "pillar"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","醉星楼的一截柱子，上面有不少斧劈的痕迹。\n");
		set("unit","截");
		set("name_recognized", "醉星楼柱子");
		set("value", 0);
		set("material","wood");
		set("wield_msg","$N眼见敌人来了，实在腾不出手来，干脆拿$n当武器了。\n");
		set("unwield_msg","$N「咚」的一声把$n放下，长长的吐了一口气。\n");
	}
	init_staff(30, TWO_HANDED);
	setup();
}
