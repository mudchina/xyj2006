#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
        string *style_mix= ({
HIG "$N回首一笑，手上迅速发出一招。\n" NOR,
HIW "$N曼然出手，使得风姿绰约，飘逸无比。\n" NOR,
HIG "$N偷眼相觑，依恋回护。\n" NOR,
HIW "$N晕生双颊，腼腆羞涩。\n" NOR,
HIG "$N使出最后一招，心意中温雅款款，风光旖旎。\n" NOR,
});

	int extra_me, extra_you,i,gen;
	object you;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［心心相映］只能对战斗中的对手使用。\n");
        if(!me->query("married"))
          return notify_fail("你尚未结婚，使不出［心心相映］。\n");
        if(!objectp(you=present(me->query("couple/id"),environment(me))))
          return notify_fail("你的配偶不在此处！\n");
	if(me->is_busy()||you->is_busy())
	  return notify_fail("你们正忙着呢！\n");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        if(me->query("gender")=="男性")gen=0;
        else gen=1;
        
        you->kill_ob(target);
        message_vision(HIC"$N手中招式陡然加紧，形成一片冰轮横空、清光铺地的光景。\n"
                       +"$n朝$N一笑，马上跃入战团。"NOR,me,you);
	for(i=0;i<sizeof(style_mix);i++)
	if(i%2==gen){
	  message_vision(style_mix[i],me);
	  COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR);
	}
	else{
	    message_vision(style_mix[i],you);
	    COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR);
	}

        me->add_temp("apply/damage",-(extra_you+extra_me)/2);
        you->add_temp("apply/damage",-(extra_you+extra_me)/2);
        message_vision(HIC"这一路武功使来，$N和$n心中都蕴含着无限的柔情蜜意。"NOR,me,you);
	me->start_busy(2);
	you->start_busy(2);
	return 1;
}

