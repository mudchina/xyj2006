// 妖法－－速疗

#include <ansi.h>

int cast(object me, object target)
{
	int mymana=me->query("mana"), cost=200, cure;
	string msg;

	if(me->is_busy())
		return notify_fail("你正忙着呢，过会儿再念咒吧！\n");
	if(me->query("family/family_name") != "陷空山无底洞"
	|| me->query_skill("yaofa", 1) < 70)
		return notify_fail("你非鼠类，体格无法承受速疗。\n");

        if( mymana < cost*2 )
                return notify_fail("你的法力不够。\n");

	if (cost<mymana/2) cost=mymana/2-1;

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		cost=cost*2;

	cure=me->query("max_kee")-me->query("eff_kee");
	cure=cure/2;

	if(!me->is_fighting())
	{
		cost=cost/2;
		msg=HIY"$N双手举在胸前，做个火焰状，念了几句咒。\n"NOR,
		msg+=HIY"随即，$N将双手在全身上下擦了一遍，双手到处，伤口居然好了大半！\n"NOR;
		me->start_busy(random(8-me->query_kar()/5));
	}
	else
	{
		msg=HIY"百忙之中，$N突然越出战圈，掐指念了段咒。\n"NOR;
		msg+=HIY"一瞬间，$N面部黄气大盛。待黄气下去时，$N身上大半伤口居然已经收口了！\n"NOR;
		me->start_busy(1);
	}
        me->receive_curing("kee", cure);
        me->add("mana", -cost);
	message_vision(msg, me);
        return 1;
}


