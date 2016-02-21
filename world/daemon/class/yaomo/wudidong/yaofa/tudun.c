//cast function: escape.c 可用于各种逃遁。
//useful only when fighting, other cases only waste fali.
//modified for wudidong, 10-4-97 pickle

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	int ap, dp, success;
	target = offensive_target(me);
	//always use the one who is fighting me as target.
         if(me->query("family/family_name")!="陷空山无底洞")
            return notify_fail("无底洞弟子才可以用！\n");

	if( me->is_busy())
		return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

        if( environment(me)->query("short") == HIR"CS休息室"NOR )
return notify_fail("你还是先呆着吧。\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("你精神太差，难以集中精力念咒。\n");

	if( (int)me->query_skill("yaofa", 1) < 20)
		return notify_fail("你未曾学会土遁。\n");

	if(environment(me)->query("under_water"))
		return notify_fail("你在水中，没法施用土遁！\n");

        if(me->query_temp("in_tiaozhan"))
        return notify_fail("你还在挑战中，怎么能离开呢？\n");
	
        ap=me->query_skill("spells")+me->query("max_mana")/10;
	if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

	if(!me->is_fighting() )
	{
		message_vision(YEL"$N向空中抛了一把土，念句咒，钻入土中不见了。\n"NOR,me);
		me->add("sen", -me->query("max_sen")/8);
		me->add("mana", -80);
		success=1;
	}
	else
	{
		msg=YEL"激战中，$N突然跳出战圈，向空中抛一把土，喃喃念了几句咒。\n"NOR;
		if(random(ap+dp)>dp/2)
		{
			msg+=YEL"只听$N喝了一声「走！」，人影已经不见了。\n"NOR;
			me->add("sen", -me->query("max_sen")/6);
			me->add("mana", -50);
			success=1;
		}
		else msg+=YEL"但$n的身影已紧紧跟上，将$N拦了下来。\n"NOR;
		me->add("mana", -50);
		message_vision(msg, me, target);
	}
	if(success)
	{
		start=me->query("env/destination");
		start=me->query("记号/"+start);
		if(!start || !find_object(start))
			start=me->query("startroom");
		if(!start) start="/d/qujing/wudidong/kitchen";
		me->move(start);
		message("vision", YEL+me->name()+"突然从地下钻了出来。\n"NOR,
				  environment(me), me);
		tell_object(me, YEL"你的身影突然出现在一阵尘土中。\n"NOR);
		return 3+random(3);
	}
	return 5+random(5);
	//if failed, can't use for a while.
}

