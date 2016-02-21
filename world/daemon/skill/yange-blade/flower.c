#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string *style_siqi = ({
HIG "小苑莺歌歇－－$N舒臂轻弹手中$w，直刺$n的$l！\n" NOR,
HIG "长门蝶舞多－－$N手中$w化做流云，飘向$n的$l！\n" NOR,
HIG "眼看春又去－－$N纤腰摆动，手中$w似流水般袭向$n的$l！\n" NOR,
HIG "翠辇不曾过－－$N手中$w似重逾千斤，磕向$n的$l！\n" NOR
});
/*
       string *style_qiusheng= ({
HIR "江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！\n" NOR,
HIR "余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！\n" NOR,
HIR "声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！\n" NOR
});
*/
        string *style_mix= ({
HIG "小苑莺歌歇－－$N舒臂轻弹手中$w，直刺$n的$l！\n" NOR,
HIR "江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！\n" NOR,
HIG "长门蝶舞多－－$N手中$w化做流云，飘向$n的$l！\n" NOR,
HIR "余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！\n" NOR,
HIG "眼看春又去－－$N纤腰摆动，手中$w似流水般袭向$n的$l！\n" NOR
HIR "声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！\n" NOR,
HIG "翠辇不曾过－－$N手中$w似重逾千斤，磕向$n的$l！\n" NOR,
});

	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIM "［彩蝶念花］只能对战斗中的对手使用。\n"NOR);
	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("yange-daofa")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "blade"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("blade") != "yange-daofa") {FLAG=0; continue;}
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("blade");
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/5);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/5);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->kill_ob(target);
	for(i=0;i<sizeof(style_mix);i++)
	if(i%2) COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
	else    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/5);
        me->add_temp("apply/damage",-(extra_you+extra_me)/2);
        you->add_temp("apply/attack",-(skl_you+skl_me)/5);
        you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/10);
        me->add_temp("apply/damage",extra_me/3);
        for(i=0;i<sizeof(style_siqi);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_siqi[i]);
        me->add_temp("apply/attack",-skl_me/10);
        me->add_temp("apply/damage",-extra_me/3);
	}	
	me->start_busy(3);
	return 1;
}

