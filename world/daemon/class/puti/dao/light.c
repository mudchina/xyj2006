// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 100;
	damage_adj = 100;
        if(me->query("family/family_name")!="方寸山三星洞")
          {
            if(me->query("family/family_name")!="陷空山无底洞")
               return notify_fail("你不能用「苍灵箭」！\n");
          }
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展苍灵箭？\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		write("看来电母今天没空。\n");
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
		HIC "\n$N口中念了句咒文，半空走出一位容貌秀雅的电母，双手各持一枚铜镜。铜镜相转，忽的闪出一道金光射向$n！\n" NOR,
			//initial message
		HIR "\n结果「嗤」地一声，金光从$n身上透体而过，\n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR, 
			//success message
		HIC "结果嗤！地一声$n闻到了一股焦味。还好只烧掉了几根头发。\n" NOR, 
			//fail message
		HIC "但是金光被$n以法力反激，反向$N射去！\n" NOR, 
			//backfire initial message
		HIR "结果金光从$n身上透体而过，拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

