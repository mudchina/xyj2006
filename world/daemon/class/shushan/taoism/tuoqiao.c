#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	int ap, dp, success;
	target = offensive_target(me);
	//always use the one who is fighting me as target.
if(me->query("family/family_name")!="蜀山派")
                return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");

	if( me->is_busy())
		return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("你精神太差，难以集中精力念咒。\n");

if( (int)me->query_skill("taoism", 1) < 20)
return notify_fail("你未曾学会金蝉脱壳。\n");

         if(me->query_temp("in_tiaozhan"))
        return notify_fail("你还在挑战中，怎么能离开呢？\n");

	ap=me->query_skill("spells")+me->query("max_mana")/10;
	if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

	if(!me->is_fighting() )
	{
message_vision(YEL"$N口中吐出几团丝线，将身形包在茧中。\n"NOR,me);
message_vision(YEL"只见一只金蝉破茧而飞，只留下几缕蚕丝。\n"NOR,me);
		me->add("sen", -me->query("max_sen")/8);
		me->add("mana", -80);
		success=1;
	}
	else
	{
msg=YEL"$N口中吐出几团丝线，将身形包在茧中。\n"NOR;
		if(random(ap+dp)>dp/2)
		{
msg+=YEL"只见一只金蝉破茧而飞，只留下几缕蚕丝。\n"NOR;
			me->add("sen", -me->query("max_sen")/6);
			me->add("mana", -50);
			success=1;
		}
else msg+=YEL"但$n不为所动，斩破茧壳，又与$N战在了一处。\n"NOR;
		me->add("mana", -50);
		message_vision(msg, me, target);
	}
	if(success)
	{
start="/d/shushan/dadian";
		me->move(start);
message("vision", YEL+me->name()+"的身影一闪，不只何时一到了你的面前。\n"NOR,
				  environment(me), me);
tell_object(me, YEL"你的身形一聚，再回首，以是万里开外。\n"NOR);
		return 3+random(3);
	}
	return 5+random(5);
	//if failed, can't use for a while.
}

