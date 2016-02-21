#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
int get_current_day_phase();
static mapping *day_phase = NATURE_D->query_day_phase(); 

int perform(object me, object target)
{
	object weapon, ob;
	string msg; 
	int phase = get_current_day_phase(); 
	int extra,count = 0;
 
	
	 if( !target ) target = offensive_target(me);
         if( !target || !target->is_character() || !me->is_fighting(target) )
 	      return notify_fail("「眩刀」只能对战斗中的对手使用。\n");
        
        if(me->query("family/family_name")!="大雪山")
 	return notify_fail("「眩刀」只有大雪山门人才可以用！\n");

	
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
        
        if (phase < 0 || phase > 5) {tell_object(me,"没有日光怎么用「眩刀」？\n");return 1;}

         //用冰刀加2招
         if(weapon->query("id") != "ice blade") count = 2;
         
           
         
	if( (int)me->query("force") < 200 )
		return notify_fail("你的内力不够了！\n");

	if( (int)me->query_skill("blade") < 160 ||
	    me->query_skill_mapped("blade") != "bingpo-blade")
		return notify_fail("你的「基本刀法」还不到家，无法使用「眩刀」！\n");
        
        if( (int)me->query_skill("blade") < 160 )
            return notify_fail("你的「冰魄寒刀」还不到家，无法使用「眩刀」！\n");
	
        msg = HIW "$N猛然将刀身一横，明晃晃的刀身在日光下反射一片白光,直射$n的面门！\n" NOR;
        message_vision(msg, me, target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )	
	 {  msg = HIW "$N只觉一道眩光刺得双眼什么都看不见了，$n见状大喜连续三刀，从三个不同的方向砍来！\n" NOR;	
	    message_vision(msg, target,me);
	     extra = me->query_skill("bingpo-blade",1) / 50;
	    if(extra>6) extra = 6 ; target->start_busy(extra + count);
	  }else{
	       msg = "可是$n看破了$N的企图，往旁一闪躲了过去。\n" NOR;
	       message_vision(msg, me, target);
               me->start_busy(random(3));
	       return 1;
           }
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add("force", -150);
	me->start_busy(random(3));
	return 1;
}



int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
        if (t>=day_phase[i]["length"])
            t -= (int)day_phase[i]["length"];
        else
            break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}
