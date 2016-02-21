// /daemon/class/sanxian/mysticism/silent.c
// writted bye mind
// 2001-2

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int lvl;
        if( target ) return notify_fail("闭关修炼只能对自己使用。\n");
        if( me->query("max_mana") < 900 )
                return notify_fail("你的法力不够！\n");
        lvl = (int) me->query_skill("mysticism",1);
        if( me->query("faith") <= 900000 )
                return notify_fail("对不起,近期暂时不能用这个命令！\n");
        me->add("mana", -50);
        me->receive_damage("sen", 100);
        message_vision(HIW "$N盘膝而座，开始闭关修炼静思入定 ...\n" NOR, me);
        if( random(me->query_skill("spells")) > (int)me->query_int() * 4) {
               if( random(me->query("max_mana")) < (int)me->query("mana") / 2) {
                        me->set_skill("mysticism", lvl -1 );
                        write( HIR "你觉得脑中一片混乱，你的玄玄神机降低了！\n" NOR );
                        return 1;
                }
                        me->set_skill("mysticism", lvl + 1);
                        write( HIW "你的玄玄神机提高了！\n" NOR );
                        return 1;
        }
        write("可是你只觉得一无所获。\n");
        return 1;
}

