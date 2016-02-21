// dabutian.c 大补天
// written by mind 2001/2
// /daemon/class/sanxian/butian-force/dabutian.c

#include <ansi.h>

int exert(object me, object target, int amount)
{       
        int skill,force;  
        skill = (int)me->query_skill("butian-force",1);  
        if(skill < 50) return notify_fail("你的补天心法太差了，不能运转大补天心法！\n"); 
        if( !target || target == me)  return notify_fail("你要对谁使用大补天心法？\n" );
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法使用大补天心法！\n");
        if((int)me->query("max_force") < 400)
                return notify_fail("你的内力不够强。\n");
        if((int)me->query("max_force") <= (int)target->query("max_force"))      
                return notify_fail("你的内力还没有"+target->name()+"的强，不能为其运转大补天心法！\n"); 
        message_vision(
                HIR "$N运起大补天心法，全身流光溢彩，骈指急点$n周天大穴....\n\n"
                "过了不久，$n浑身氤氲一团蒙蒙白气，顶上三花光彩夺目，$N却昏倒在地。\n" NOR,
                me, target );
        me->set_skill("butian-force",skill-2);
        me->add("max_force",-400);
        me->set("force",0);
        target->add("max_force",200);
        me->unconcious();
        return 1;
}

