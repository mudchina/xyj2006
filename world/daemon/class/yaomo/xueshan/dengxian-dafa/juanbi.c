//扭转乾坤

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;

        string tar_spells,tar_dodge;

        int ap,dp,dg,damage;

	if( !target ) target = offensive_target(me);

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("你要对谁用扭转乾坤？\n");
        if(me->query("family/family_name")!="大雪山")
          return notify_fail("[扭转乾坤]只有雪山弟子才可以用！\n");

        if (!target->is_fighting(me))
               return notify_fail("只有在战斗中才能使用扭转乾坤！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你体力不足，用不了扭转乾坤！\n");

        if((int)me->query("force") < 100 )
                return notify_fail("你须运足内力才能使用扭转乾坤！\n");

	if((int)me->query_skill("dengxian-dafa", 1) < 40 )
		return notify_fail("你的登仙大法还不够纯熟。\n");

	if((int)me->query("mana") < 300 )
		return notify_fail("你的法力不足以变作神象伤敌！\n");

        msg = HIW"\n$N趁$n不备，怒吼一声，转瞬间化作一只黄牙老象，"
                 +"伸出蛟龙般的鼻子向$n卷去！\n" NOR;

        ap=(int)me->query_skill("dengxian-dafa", 1)
              +(int)me->query_skill("spells", 1)/2;

        tar_spells=target->query_skill_mapped("spells");
        if (! tar_spells) dp=(int)target->query_skill("spells", 1)/2;
        else dp=(int)target->query_skill("spells", 1)/2
              +(int)target->query_skill(tar_spells, 1);

        tar_dodge=target->query_skill_mapped("dodge");
        if (! tar_dodge) dg=(int)target->query_skill("dodge", 1)/2;
        else dg=(int)target->query_skill("dodge", 1)/2
              +(int)target->query_skill(tar_dodge, 1);
        if (dp!=0) dp=100*ap/dp/3+random(100*ap/dp)/2; else dp=100;
        if (dg!=0) dg=100*ap/dg/3+random(100*ap/dg)/2; else dg=100;
//printf("dp=%5d dg=%5d",dp,dg);
        damage=me->query("max_mana")/20+1;
        damage=(me->query("mana_factor")+me->query("str")+random(damage))*2;
        if (dp<30)
          {           
          msg += HIW "不料$n早有准备，扭转身形轻舒猿臂一把抓住了$N的鼻子！\n"
              +"$N疼得一声闷哼，身不由己的被$n拖了过去！\n"NOR;
          message_vision(msg, me, target);
          me->add("kee", me->query("str")*2);
          me->start_busy(30-dp+random(10));
          }
        else if (dp<60 && dp>30)
          {           
          msg += HIW "$n连忙扭转身形运转神功将$N的长鼻荡开。\n"NOR;
          message_vision(msg, me, target);
          me->start_busy(1+random(2));
          }
        else if (dg<50)
          {           
          msg += HIW "$n纵身向后一跃，闪过了这一击。\n"NOR;
          message_vision(msg, me, target);
          me->start_busy(1+random(2));
          target->start_busy(random(3));
          }
        else 
          {           
          msg += HIW "$n促不击防，被$N的长鼻高高卷起，$N用力一甩，"
              +"$n如断了线的风筝般飞了出去！\n"NOR;
          message_vision(msg, me, target);
          target->receive_damage("kee",damage,me);
          me->start_busy(random(2));
          target->start_busy(1+random(3));
          COMBAT_D->report_status(target); 
          }

        me->add("force", -30);
        me->add("mana", -30);

        target->kill_ob(me);
//        message_vision(msg, me, target);

        return 1;
}

