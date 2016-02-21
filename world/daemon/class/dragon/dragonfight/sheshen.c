// sheshen.c 		舍身技

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	int mydf;
	int ap, dp, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("不在战斗中，舍什么身？\n");
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用「舍身技」！\n");
	mydf=(int)me->query_skill("dragonfight",1);
	if(mydf<100) 
		return notify_fail("你的修为不够深，还不能领悟舍身技的精髓。\n");
	mydf=(int)me->query_skill("dragonforce",1);
	if(mydf<100) 
		return notify_fail("你的修为不够深，还不能领悟舍身技的精髓。\n");
	
	if((int)me->query("force")<300) return
	    notify_fail("你的内力不够了。\n");

	msg = CYN "$N右掌挥出，斩向$n的左肩，\n";
	mycor=me->query_cor();
	youcps=target->query_cps();
	ob=target->query_temp("weapon");
	str="右手";
	if(objectp(ob)) str="手中的"+ob->query("name");
	ap=COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp/=2;	
	pp=COMBAT_D->skill_power(target,"unarmed", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=me->query_str();
	damage_bonus=mystr*(100+me->query("force_factor"))/100;

	if( random(youcps) < 15 || random(ap+dp)>dp) {
		msg += "$n想用"+str+"挡开，不料却被$N一把抓住。\n";
		msg += "$N顺势上步，使出了「舍身技」！\n\n" NOR;
		msg += CYN "$N左脚铲向$n右腿膝盖，";
		if(random(ap+pp)>pp) {
			msg += "结果正铲在$n的小腿上。\n" NOR;
			damage=calculate_damage(me, target, 100, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
				msg+=COMBAT_D->damage_msg(damage, "内伤");
			}
		}
		else msg+="结果被$n提腿挡开了。\n" NOR;
		msg += CYN "\n紧跟着$N收左脚，提左膝撞向$n的软肋，\n";
		msg += "同时右手曲肘撞向$n的面门，";
		if(random(ap+pp)>pp) {
			msg += "结果正中$n。\n" NOR;
			damage=calculate_damage(me, target, 120, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
				msg+=COMBAT_D->damage_msg(damage, "内伤");
			}
		}
		else msg+="结果被$n挡开了。\n" NOR;
		msg += CYN "\n$N接着顺势用右手抓住$n右臂，半转身将$n摔了出去，";
		if(random(ap+pp)>pp) {
                        msg += "结果$n一跟头摔在地上。\n" NOR;
                        damage=calculate_damage(me, target, 150, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
                                msg+=COMBAT_D->damage_msg(damage, "内伤");
                        }
                }
                else msg+="结果被$n一个踉跄，却没摔倒。\n" NOR;
		message_vision(msg, me, target);
		msg+=COMBAT_D->report_status(target, 0);
	} else {
		msg += "可是$p看破了$P的企图，向后越开。\n" NOR;
		message_vision(msg, me, target);
	}
	delay = random(2)+2;
	me->start_busy(delay);
	me->add("force", -200);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));

	return damage;
}

