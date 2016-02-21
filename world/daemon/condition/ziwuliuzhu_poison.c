#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->receive_wound("kee",10);
        me->receive_wound("sen",10);
        me->apply_condition("ziwuliuzhu_poison", duration - 1);
        tell_object(me, HIB "你感觉体内似乎多了些什么，又似乎少了些什么，打了个哆嗦。\n" NOR );
        message("vision", me->name() + "神情恍惚，好象子午流注在体内发挥作用了。\n",environment(me), me);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

