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
                return notify_fail("你要对谁用翻天手印？\n");

        if (!target->is_fighting(me))
               return notify_fail("只有在战斗中才能使用翻天手印！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你体力不足，用不了翻天手印！\n");

        if((int)me->query("force") < 100 )
                return notify_fail("你须运足内力才能使用翻天手印！\n");

        if((int)me->query_skill("yuxu-spells", 1) < 40 )
                return notify_fail("你的玉虚仙法还不够纯熟。\n");

        if((int)me->query("mana") < 300 )
                return notify_fail("你的法力不足以招来翻天印御敌！\n");

        msg = HIC"\n$N双目怒视$n，突然伸手一挥，一个金色大印从天而下"
                 +"一道金光向$n罩去！\n" NOR;

        ap=(int)me->query_skill("yuxu-spells", 1)
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
          msg += HIC "不料$n早以看穿，法力一顶，金光反向$N罩去！\n"
              +"$N疼得哇哇乱叫，身子己被金光罩了进去！\n"NOR;
          message_vision(msg, me, target);
          me->add("kee", me->query("str")*2);
          me->start_busy(30-dp+random(10));
          }
        else if (dp<60 && dp>30)
          {           
          msg += HIC "$n连忙后退将$N的金光逼开。\n"NOR;
          message_vision(msg, me, target);
          me->start_busy(1+random(2));
          }
        else if (dg<50)
          {           
          msg += HIC "$n纵身向后一跃，闪过了这一击。\n"NOR;
          message_vision(msg, me, target);
          me->start_busy(1+random(2));
          target->start_busy(random(3));
          }
        else 
          {           
          msg += HIC "$n眼看着金光罩来，竟没法逼开，被$N的金光牢牢罩住，$N连忙再出一道金光，"
              +"$n被劈了个正着！\n"NOR;
          message_vision(msg, me, target);
          target->receive_damage("kee",damage,me);
          me->start_busy(random(3));
          target->start_busy(1+random(3));
          COMBAT_D->report_status(target); 
          }

        me->add("force", -30);
        me->add("mana", -30);

        target->kill_ob(me);
//        message_vision(msg, me, target);

        return 1;
}
