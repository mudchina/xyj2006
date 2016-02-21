// 清心普善咒
// 专解情毒，这么好，什么时候帮我也解解，呵呵
// xintai 2/3/2001

#include <ansi.h>

int cast(object me, object target)
{

        if ( !target
          || !userp(target)
          || target->is_corpse()
          || target==me)
                return notify_fail("你想替谁解除情毒？\n");
        if (!target->query_condition("xiangsi"))
        return notify_fail("那个人根本没中情毒，开什么玩笑？！\n");
        if( me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法解毒！\n");

        if( (int)me->query("faith")  <  500 )
                return notify_fail("你还没有学会清心普善咒。\n");
        if( (int)me->query("mana")  <  1200 )
                return notify_fail("你的法力不够。\n");

        if ( (int)me->query_skill("pansi-dafa") < 120)
                return notify_fail("你的盘丝大法等级不够，不要勉强啦！\n");
        
        message_vision(
                 );
       
                target->apply_condition("xiangsi",0);
                
        me->add("mana", -300);
        return 1;
}

