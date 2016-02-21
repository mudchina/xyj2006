//modified by vikee
//2000.12.11

inherit F_CLEAN_UP;

int cast(object me, object target)
{
        if( !me->is_fighting() )
                return notify_fail("你只有在战斗中才能使用复活术。\n");
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
         
        if( !target || !target->is_corpse() ) return notify_fail("你要驱动哪一具尸体？\n");
        
        if( (int)me->query("mana") < 200 ) return notify_fail("你的法力不够！\n");

        message_vision(
                "$N对著地上的$n喃喃地念了几句咒语，$n抽搐了几下竟站了起来！\n", me, target);

        target->animate(me);

        me->add("mana", -50);
        me->receive_damage("sen", 50);

        return 3+random(5);

}
