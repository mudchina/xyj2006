// modified

#include <skill.h>

inherit F_CLEAN_UP;

int finish(object me, int kee_cost);

int main(object me, string arg)
{
        int kee_cost, busy_time ,free;
        
        seteuid(getuid());
        
        if(environment(me)->query("no_fight")  ||
           environment(me)->query("no_magic") )
              return notify_fail("安全区内禁止练功。\n");
              
        if (me->is_busy() || me->query_temp("pending/exercising"))
              return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

        if( !arg
        ||      !sscanf(arg, "%d", kee_cost) )
                return notify_fail("你要花多少气练功？\n");

        if( kee_cost < 10 ) return notify_fail("你最少要花 10 点「气」才能练功。\n");

        if( (int)me->query("kee") < kee_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
        me->receive_damage("kee", kee_cost);
 
        write("你坐下来运气用功，一股内息开始在体内流动。\n"); 
        me->set_temp("pending/exercise", 1);
        free=(int)me->query_skill("force")/40; 
          busy_time=kee_cost/100-free+1;
        if(busy_time>3) busy_time=3;
        me->start_busy(busy_time);
        
        call_out("finish",busy_time, me, kee_cost);
        return 1;
}

int finish(object me, int kee_cost)
{
        int force_gain;

        // This function ranged from 1 to 15 when kee_cost = 30
        force_gain = kee_cost * ((int)me->query_skill("force", 1)/10
                + (int)me->query_con()/2+random(25)) / 30;

        me->set_temp("pending/exercise", 0);
        if( force_gain < 1 ) {
                tell_object(me, "但是当你行功完毕，只觉得全身发麻。\n");
                me->start_busy(1);
                return 1;
        }

        me->add("force", force_gain );
        tell_object(me, "你行功完毕，吸一口气，缓缓站了起来。\n");

        if( (int)me->query("force") > (int)me->query("max_force") * 2) {
                if( (int)me->query("max_force") >= 
                        (int)me->query_max_force() ) {
                        tell_object(me, "当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶颈。\n");
                } else {
                        tell_object(me, "你的内力增强了！\n");
                        me->add("max_force", 1);
                        if ( (int)me->query("max_force") > (int)me->query("maximum_force"))
                        me->set("maximum_force", (int)me->query("max_force"));
                }
                me->set("force", me->query("max_force"));
        }       
        
    me->start_busy(0);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise|dazuo [<耗费「气」的量，预设值 30>]

运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。

请参考 help stats
HELP
        );
        return 1;
}
