// lingpai.c
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("令牌",({"ling pai", "ling", "pai", "lingpai"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",RED"
\t\t\t白
\t\t\t虎
\t\t\t岭
\t\t\t白
\t\t\t狼
\t\t\t洞
\t\t\t白
\t\t\t骨
\t\t\t夫
\t\t\t人
\t\t\t令
\n"NOR);
		set("unit","块");
		set("value", 0);
		set("name_recognized", "白骨令");
		set("material","bone");
		set("wield_msg","$N掏出一块$n，对它拜了三拜，然后横握在手中。\n");
		set("unwield_msg","$N小心翼翼的包好$n收了起来，好像这块$n很珍贵似的。\n");
	}
	init_dagger(5);
	setup();
}








