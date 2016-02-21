// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit STICK;

void destroy();
void init();
void init()
{
    call_out("destroy", 120);
}
void create()
{
	set_name( HIY "金箍棒" NOR, ({ "jin gu bang", "jingubang", "bang" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        set("value", 1000000000000);
      set("no_sell","小店小本经营，买不起这么贵重的宝物。\n");
    set("no_give","金箍棒对对方而言太重了。\n");
		set("material", "gold");
                set("no_drop", "怎么，连这如意金箍棒都舍的扔？");
		set("replace_file", "/d/obj/weapon/stick/bintiegun");
		set("long", "此棒两头以金为箍，中间乃一段乌铁。上铸一行小字：“如意金箍棒”。\n");
		set("wield_msg", "$N一伸手，连喝几声：大！大！大！掌中忽然多了一条$n。\n");
		set("unwield_msg", "$N一吹气，几声轻喝：小！小！小！$n在$N掌中转了几转，忽然不见了。\n");
	}
	init_stick(250);
	setup();
}
void destroy()
{
  destruct(this_object());
}
