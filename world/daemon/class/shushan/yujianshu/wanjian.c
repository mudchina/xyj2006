#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
int i,j,k,u,damage;
string msg,str; 
weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");
        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("非蜀山不能用「万剑诀」！\n");
        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");
        if( time()-(int)me->query_temp("xiao_end") < 5 )
          return notify_fail("绝招用多就不灵了！\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内功太差。\n");
        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("taoism", 1) < 100)
                return notify_fail("你的天师正道等级不够，不能使用这一招！\n");
        k=(int)me->query_skill("sword");
       j=(int)target->query_skill("dodge");
                  if(k<150)        
                return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
u=1+k/50;
if (u>9) u=9;
me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIB"\n$N仰天大喝了一声："NOR,me,target);
message_vision(HIW"\n助我克敌者赏神剑一柄！"NOR,me,target);
message_vision(HIB"\n一刹那间千万剑光破空而来，劈面罩向$n"NOR,me,target);
for (i=0;i<=u;i++)
{
if (random(k+j)>j/2) {
           message_vision(HIY"\n$n一个不慎，中了一剑"NOR,me,target);
damage=100+random(150);
target->receive_damage("kee",damage);
target->receive_wound("kee",damage/2);
            COMBAT_D->report_status(target);
me->receive_damage("sen", 10);
me->add("force", -20);
}
             else {
           message_vision(HIY"\n$n左跳右闪，好不容易避开了一轮剑雨"NOR,me,target);
me->receive_damage("sen", 10);
me->add("force", -20);
}
}
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"被"+me->name()+"用蜀山秘传"NOR+HIC"「万剑诀」"+HIM"杀死了，据说尸体竟然插满数万灵剑！";
	                 message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	               }
    me->set_temp("xiao_end",time());
return 1;
}
