//涅磐
//requirement: lunhui-zhang >120, being killed by target, 
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
           return notify_fail("你要与谁化蝶？\n");
        
      if((int)me->query_skill("chixin-jian", 1) <120)
            return notify_fail("你的痴心情长剑火候还不够！\n");
	  if((int)me->query_skill("pansi-dafa", 1) <120)
            return notify_fail("你的盘丝大法修为太低！\n");
      if (me->query_skill_mapped("spells")!="pansi-dafa")
                return notify_fail("你不用盘丝大法怎么化蝶?\n");
     if (me->query_skill("jiuyin-xinjing",1)<120) 
         return notify_fail("你的九阴心经不够纯熟。\n");
     if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if (!target->is_killing(me->query("id")))
             return notify_fail("好端端的比武，何必性命相搏？\n");
       eff_qi=me->query("eff_kee");
       max_qi=me->query("max_kee");
       qi_pcg=eff_qi*100/max_qi;
       if (qi_pcg>=50) 
           return notify_fail("你的心力还不够化蝶。\n");
       if (me->query("force")<200)
           return notify_fail("你内力不继，心有余而力不足。\n");

        me->set("kee", 0);
        me->set("eff_kee",eff_qi*random(10)/100);
        me->set("sen",0);
        me->set("eff_sen",me->query("eff_sen")*random(10)/100);
        me->set("force",0);
        me->set("mana",0);

  message_vision(HIY"\n$N双手合十，轻念佛偈：\n" NOR,me,target);
message_vision(HIC"\n“一切恩爱会，无常难得久。\n"NOR,me,target);
message_vision(HIC"\n  生世多畏惧，命危于晨露。\n"NOR,me,target);
message_vision(HIC"\n  由爱故生忧，由爱故生怖。\n"NOR,me,target);
message_vision(HIC"\n  若离于爱者，无忧亦无怖。”\n"NOR,me,target);
message_vision(HIB"\n $N叹道:是耶?非耶?化作蝴蝶......
忽然招式一变舞起一片剑花,似彩蝶翻飞般罩向$n\n\n"NOR,me,target);
                 
        ap = me->query_skill("chixin-jian", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("daoxing");
        dp = target->query_skill("spells");
        dp = dp * dp * dp /20;   
        dp = dp + target->query("daoxing");
        dp = dp*qi_pcg/50;  
        if( random(ap + dp) <  dp ) {
//              msg += HIW "$n一见情势不妙，一个鱼跃,跳出圈外。\n"NOR;
              message_vision(HIW "$n一见情势不妙，一个鱼跃,跳出圈外。\n"NOR, me, target);
         } else {
//                  target->set("kee",-1)
                  target->receive_damage("kee",target->query("kee")*2,me);

                   message_vision(HIM "$n躲闪不及,剑花中但见两只彩蝶穿身而过！\n"NOR, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(1+random(2));
          target->start_busy(2+random(3));
          return 1;
}


