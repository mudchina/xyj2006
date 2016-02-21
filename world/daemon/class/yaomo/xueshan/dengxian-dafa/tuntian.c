// tuntian.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;


	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展魔兽吞天？\n");
        if(me->query("family/family_name")!="大雪山")
          return notify_fail("[魔兽吞天]只有雪山弟子才可以用！\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		write("坏了，青面狮子不知跑哪去了！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"qi", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "\n$N口中念了句咒文，半空闪出一只青面獠牙的狮子，张开血盆大口向$n咬去！\n" NOR,
			//initial message
		HIR "\n结果$n被咬了个正着！\n" NOR, 
			//success message
		HIC "\n$n连忙一侧身闪在一旁。\n" NOR, 
			//fail message
		HIC "只见$n一声怒吼，青面狮子吓得辨不青方向，反而咬中了$N！\n" NOR, 
			//backfire initial message
		HIC "结果$n被咬了个正着！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

