//风回
//requirement: snowsword >120, being killed by target, 
//max_qixue under 50%

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你要打谁？\n");
      if(me->query("family/family_name") != "月宫")
                return notify_fail("[回风剑]是月宫不传之密！\n");
        
      if((int)me->query_skill("snowsword", 1) <120)
            return notify_fail("你的回风雪舞剑法火候还不够！\n");
      if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("回风剑必须配合圆月心法才能使用。\n");
     if (me->query_skill("moonforce",1)<120) 
         return notify_fail("你的圆月心法不够纯熟。\n");
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (!target->is_killing(me->query("id")))
             return notify_fail("好端端的比武，何必性命相搏？\n");
       eff_qi=me->query("eff_kee");
       max_qi=me->query("max_kee");
       qi_pcg=eff_qi*100/max_qi;
       if (qi_pcg>=50) 
           return notify_fail("还未到山穷水尽的地步，不要胡乱出手。\n");
       if (me->query("force")<200)
           return notify_fail("你内力不继，心有余而力不足。\n");

        me->set("kee", 0);
        me->set("eff_kee",eff_qi*random(10)/100);
        me->set("sen",0);
        me->set("eff_sen",me->query("eff_sen")*random(10)/100);
        me->set("force",0);
        me->set("mana",0);

        msg = HIW"\n$N眼见不敌，银牙一咬，突然高高纵起，凝聚全身功力，人剑合一，"
                 +"化做一道白光，疾风般扑向$n！\n" NOR;
        ap = me->query_skill("snowsword", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;  //more badly you're hurt, more chance you will succeed
        if( random(ap + dp) <  dp ) {
              msg += HIW "$n一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR;
              message_vision(msg, me, target);
         } else {
//                  target->set("kee",-1)
                  target->receive_damage("kee",target->query("kee")*2,me);
                  msg += HIW "$n不料$N如此决绝，为此气势所慑，竟然楞在当地，忘了招架。\n
说时迟，那时快，这道白光已在$n身上当胸穿过！\n"NOR;
                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(2+random(3));
          target->start_busy(random(3));
          return 1;
}

