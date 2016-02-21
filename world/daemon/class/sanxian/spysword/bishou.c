
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,dlkm,temp_extra;
        object weapon;
       if (!(wizardp(me))) {
       if((string)me->query("family/family_name") != "三界散仙")
                return notify_fail("你的刺客剑法不是亲传，不能使出[图穷匕现]！\n");
       }
        extra = me->query_skill("spysword",1);
        temp_extra=extra;
if(me->query("force") < 1000||me->query("mana")<1000||me->query("max_force")<1200) return notify_fail("你的状态不好，无法使出[图穷匕现]。\n");
        if ( extra < 120) return notify_fail("你的刺客剑法级别还不够，使用这一招还有一定难度！\n");
        if( (int)me->query_skill("sword", 1) < 120)
                return notify_fail("你的剑法还欠缺熟练，无法得心应手。\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［图穷匕现］只能在战斗中使用。\n");
       if(time()-me->query_temp("bishou_end")<4) return notify_fail("刺客剑法不能用得这么频繁！\n");         
        me->set_temp("bishou_end",time());
        weapon = me->query_temp("weapon");
        msg = HIW "\n$N突然收起手中"+ weapon->name()+ HIW"，悄无声息地走到$n身边！\n" NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",temp_extra/5);
        me->add_temp("apply/damage",temp_extra/5);
          dlkm = random(5)+2;
        for(i=1;i<=dlkm;i++)
        {msg="";
         if(i==1)  msg = HIG "\n［刺客剑法］-- 白虹贯日！\n" NOR;
         else if(i==2)  msg = HIR "\n［刺客剑法］-- 流血五步！\n" NOR;
         else if(i==3)  msg = HIY "\n［刺客剑法］-- 天下缟素！\n" NOR;
         else     {  
                   msg = HIW "\n［刺客剑法］--禁招-- 图穷匕首现！" NOR;
                       target->receive_wound("sen",extra);
                     target->receive_wound("kee",extra);
                   me->receive_heal("kee",extra); // grin，补自己的气
                  }
        message_vision(msg,me,target);
        if(random((int)me->query("combat_exp")) >(int)target->query("combat_exp")/2)
              {
                msg =HIC"\n得手了！"NOR;
                switch(random(3)) {
                        case 0:{ msg += YEL "$n躲闪不及，被"+ weapon->name()+ YEL "刺个正着！鲜血从胸口汩汩而出！\n" NOR;
                                      break;};
                                
                        case 1:{ msg += MAG "眨眼间，$N手中的"+ weapon->name()+MAG "无声无息地刺中了$n的腰部！\n" NOR;
                                      break;};
                                
                        case 2:{ msg += HIM "$n突然头部一阵剧痛，原来被$N手上的"+ weapon->name()+HIM "狠狠刺伤！\n" NOR;
                                       break;};                               
                              }
                  if (extra>300) extra=300;
                target->receive_damage("kee",extra);
              target->receive_wound("kee",extra/2);
                message_vision(msg,me,target);  
                COMBAT_D->report_status(target,0);
       } 
       else COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        me->add("force",-100);   
      }
        me->add_temp("apply/attack",-temp_extra/5);
        me->add_temp("apply/damage",-temp_extra/5);
        me->start_busy(1+random(1));
        return 1;
 }
