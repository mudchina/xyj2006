
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "你手里一松，潜龙丹从指间滑落！\n");
                set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
	    set("no_give", "这么宝贵的丹药，你自己留着吧！\n");
	}
	add_action("do_eat", "eat");
}

void create()
{
	set_name( HIC "潜龙丹" NOR , ({"dan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗血红色的丹丸，略微能闻到些许香气。\n");
		set("value", 10000);
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int pot,learned,dif;

	 pot=me->query("potential");
	 learned=me->query("learned_points");
	 dif=pot-learned;

	if (arg!="dan")	return 0;

	me->set("potential", pot+random(100-dif));

        message_vision(HIC "$N轻轻掰开一颗潜龙丹送入嘴中，一时间香气四溢。\n" NOR, me);

	destruct(this_object());
	return 1;
}
