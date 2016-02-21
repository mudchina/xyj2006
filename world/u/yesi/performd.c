//write by yesi

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

int skill_power(object ob, string skill, int usage)
{
    int status, level, power;

    if( !living(ob) ) return 0;

    level = ob->query_skill(skill);

    switch(usage) {
        case SKILL_USAGE_ATTACK:
            level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
            level += ob->query_temp("apply/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
            level += ob->query_temp("apply/defense");
            break;
    }

    if( !level ) return (int)ob->query("combat_exp") / 2;

    power = (level*level*level) / 3;
    if( (status = ob->query("max_sen")) > 0 )  {
        if ( power > 100000 )
           power = power / status * (int)ob->query("sen");
        else
           power = power * (int)ob->query("sen") / status;
    }

    power +=  ob->query("combat_exp");

    return power;
}

int hit_target(object me,object target,string attack_skill)
{
	int ap,dp,pp,defence;
	
	ap = skill_power(me,attack_skill,SKILL_USAGE_ATTACK);
	dp = skill_power(target,"dodge",SKILL_USAGE_DEFENSE);
	dp /=2;
	pp = skill_power(target,"parry",SKILL_USAGE_DEFENSE);
	pp /=2;
	
	defence = dp + pp;
	if(target->is_busy()) defence /=3;
	
	if (random(ap+defence) > defence)
	    return 1;
	 else return 0;
}

int perform_damage(object me, object target, int base_damage)
{
	int damage,damage_bonus;
	int myexp, youexp,mystr,wound;

	mystr=me->query_str();
	damage_bonus=mystr*(me->query("apply/damage")/2+me->query("force_factor"))/100;
	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	
	
	wound=random(damage-(int)target->query_temp("apply/armor"))/2;
	if(damage>0) {
		      target->receive_damage("kee", damage, me);
		      if(wound>0) target->receive_wound("kee", wound, me);
		      me->add("force",-me->query("force_factor"));
		      if(me->query("force")<0) me->set("force",0);
		      }	
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d   wound: %d\n" NOR, damage,wound));

	return damage;
}	 
	
	
	