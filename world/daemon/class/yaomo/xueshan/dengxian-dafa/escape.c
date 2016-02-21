//cast function: escape.c 可用于各种逃遁。
//this one is for xueshan...weiqi, 
//useful only when fighting, other cases only waste fali.

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
		return notify_fail("你现在头脑不清醒，没头苍蝇似的可逃不掉！\n");

	if( (string)me->query("family/family_name") != "大雪山" )
		return notify_fail("你并非雪山弟子，大鹏明王不会来救你。\n");

         if(me->query_temp("in_tiaozhan"))
        return notify_fail("你还在挑战中，怎么能离开呢？\n");

	message_vision(HIC "$N喃喃地念了几句咒语，突然仰天大叫：明王救我！\n" NOR, me);
	message_vision(HIC "只见一只金翅大鹏鸟从云端里冲出！\n\n" NOR, me);

	if(me->is_fighting() ) {
              if((random((int)me->query("max_mana")) > (int)target->query("max_mana")/2 && random((int)me->query("mana")) > (int)target->query("mana")/2 )&&(me)) {
			message_vision(HIC "大鹏鸟往下一扑抓住$N，双翅一振，顿时冲上云霄，无影无踪了！\n" NOR, me);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
			if(random(3)==0) me->move("/d/xueshan/binggu");
			else if(random(3)==1) me->move("/d/xueshan/wuchang-c");
			else me->move("/d/xueshan/restroom");
			message_vision(HIC "只听趴！地一声，$N从半空中掉下来，跌了个屁股开花！\n" NOR, me);
		}
		else{
			message_vision(HIC "大鹏鸟往下一扑，却被$n法力逼住，冲不入战团。只好对着$N长唳一声，折了回去！\n" NOR, me, target);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
		}
	}

	else{
		message_vision(HIC "只听趴！地一声，大鹏鸟扑下来一翅打在$N的屁股上，$N跌了个七荤八素！\n" NOR, me);
		me->add("mana", -100);
	}

	return 3+random(5);
}

