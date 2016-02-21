// xiaobutian.c 小补天
// written by mind 2001/2
// /daemon/class/sanxian/butian-force/xiaobutian.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( (string)me->query("family/family_name")!="三界散仙")
                return notify_fail("你非散仙，不能运转小补天心法！\n");
        if( target != me ) return 
                notify_fail("你只能对自己运转小补天心法！\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能运转小补天心法！\n");

        if( (int)me->query("force") < 400 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 4 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 4 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIW "你内视潜元，一手指天，一手点地，开始运转小补天心法。\n" NOR);
        message("vision",
                HIW + me->name() + "一手指天，一手点地，吸取天地日月精华，不久，神采飞扬，精神抖擞。\n" NOR,
                environment(me), me);

        me->receive_curing("kee", (int)me->query("max_kee"));
        me->receive_curing("sen", (int)me->query("max_sen"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("sen", (int)me->query("max_sen"));
        me->add("force", -400);
        me->set("force_factor", 0);
        me->start_busy(2);

        return 1;
}

