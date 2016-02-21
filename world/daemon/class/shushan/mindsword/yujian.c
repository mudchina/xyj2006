#include <ansi.h>
inherit SSERVER;
string *where = ({"左","右","前","後","左前","左后","右前","右后"});
int perform(object me, object target)
{
        object weapon;
        int skl,i,k;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");
          if((me->query("family/family_name") != "蜀山派")&&(!wizardp(me)))
                return notify_fail("你非我蜀山弟子，怎能使用蜀山绝招?\n");
        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");
        if(target->is_busy())
                return notify_fail("对方正忙着，你的还需要用这招？\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内功太差。\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("taoism", 1) < 120
         ||(int)me->query_skill("spells", 1) < 120)
        	return notify_fail("你的法术等级不够，不能使用这一招！\n");
        skl=(int)me->query_skill("mindsword", 1);
        if((int)me->query_skill("sword")<120
           || skl< 120)      
                  return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
        if(time()-me->query_temp("yjwd_end")<10) return notify_fail("御剑无敌不能用得这么频繁！\n");         
        me->set_temp("yjwd_end",time());
        me->add("force",300);
  k=skl;
  skl/=50;
  if (skl>6) skl=6;
  target->start_busy(random(skl));
  me->set("env/brief_message",1);
  target->set("env/brief_message",1);
  weapon = me->query_temp("weapon");
  message_vision(HIR"\n只见,$N默运天师正道，双目尽赤，全身顿时霞光暴现！！！\n"NOR,me,target);
  message_vision(HIG"\n$N大喝一声：手中$n"+HIG"冉冉升至空中···！\n"NOR,me,weapon);
  for(i=1;i<=skl;i++)
        {
        me->add("force",-60);
        msg=weapon->name(1)+HIB"飞在空中，突然从"+HIR+where[random(sizeof(where))]+HIB+"方射向$n。\n";
        message_vision(HIB+msg+NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1);
        if(!random(3)&&random(me->query("combat_exp"))>target->query("combat_exp")/2)
            { 
            msg="\n"+weapon->name(1)+HIW"突然又飞了回来，从"HIG"完全不可能的角度"HIW"刺伤$n。\n";
            message_vision(HIW+msg+NOR,me,target);         
            target->receive_wound("sen",k);
            target->receive_wound("kee",k);
            COMBAT_D->report_status(target,0);
            COMBAT_D->report_sen_status(target,0);
            }
        }
if(random(3)) message_vision(HIG"\n$n"HIG"在空中飞了一圈，又飞回到$N手中！\n"NOR,me,weapon);        
else {
     weapon->move(environment(me));
     message_vision("\n$n"HIR"在空中飞了一圈，突然斜插在地上！\n"NOR,me,weapon); 
}
me->start_busy(2+random(3));
return 1;
 }
