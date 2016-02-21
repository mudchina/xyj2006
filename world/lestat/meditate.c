// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

int finishb(object me);
int main(object me, string arg)
{
	int sen_cost, busy_time;
	object where = environment(me);
	
	seteuid(getuid());
	
	if(environment(me)->query("no_fight")  ||
	   environment(me)->query("no_magic") )
	      return notify_fail("这里不是修炼法力的地方。\n");

        if( !arg
        ||      !sscanf(arg, "%d", sen_cost) )
                return notify_fail("你要花多少精神冥思？\n");

        if( sen_cost <= 0 && me->query_temp("pending/meditating") ){
//                remove_call_out("exec_int");
                call_out("finish", 1, me);
                return 1;
        }
	      
        if (me->is_busy() || me->query_temp("pending/meditating"))
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能冥思。\n");

	if( !stringp(me->query_skill_mapped("spells")) )
		return notify_fail("你必须先用 enable 选择你要用的法术。\n");

	if( sen_cost < 20 ) return notify_fail("你最少要花 20 点「精神」才能冥思。\n");

	if( (int)me->query("sen") < sen_cost )
		return notify_fail("你现在神智不清,不能再想入非非了。\n");

	write("你盘膝而坐，静坐冥思了一会儿。\n");

	busy_time=sen_cost/20;
	me->start_busy(busy_time*2 + 1);
	me->set_temp("pending/meditating", 1);
	call_out("exec_int", 1, me, where, busy_time);	
//	call_out("finish",busy_time+1, me, sen_cost);
	return 1;
}
int exec_int(object me, object where, int busy_time)
{
	object wherenow;
	int mana_gain;
	wherenow = environment(me);

	if(!me) return 1;
	if(!me->query_temp("pending/meditating")) return 1;

	if( wherenow!=where ){
//		remove_call_out("exec_int");
		finishb(me);
		return 1;
	}
	
	if(!living(me)) return finishb(me);

	mana_gain = (int)me->query_skill("spells",1)/10
		+(int)me->query_spi()/3 + random(3);

	if (mana_gain < 5) mana_gain = 5;
	if (mana_gain > 40) mana_gain = 40;

	mana_gain*=2;
	me->receive_damage("sen", 20);
	me->add("mana", mana_gain);

        if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
                if( (int)me->query("max_mana") >=
              (int)me->query_max_mana() ) {
tell_object(me,
"当你的法力增加的瞬间你忽然觉得脑中一片混乱，似乎法力的提升已经到了瓶颈。\n");
		}else{
                        tell_object(me, "你的法力增强了！\n");
                        me->add("max_mana", 1);

if ( (int)me->query("max_mana") > (int)me->query("maximum_mana"))
me->set("maximum_mana", (int)me->query("max_mana"));

		}
                me->set("mana", me->query("max_mana"));
//                remove_call_out("exec_int");
                call_out("finish", 1, me);
                return 1;
	}
	if (busy_time>1){
		busy_time--;
		call_out("exec_int", 1, me, where, busy_time);
	} else {
		call_out("finish", 1, me);
	}
	return 1;
}
int finishb(object me)
{
	me->delete_temp("pending/meditating");
	me->start_busy(1);
	return 1;
}
int finish(object me)
{
	me->delete_temp("pending/meditating");
	me->start_busy(1);
	tell_object(me, "你行功完毕，从冥思中回过神来。\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : meditate|mingsi [<耗费「神」的量，预设值 30>]
	   meditate|mingsi 0 ：停止冥思
 
静坐冥思，将游离的精神力有效地集中凝聚成能够用来施展法术的能量
，藉以增加自己的法力。

HELP
        );
        return 1;
}

