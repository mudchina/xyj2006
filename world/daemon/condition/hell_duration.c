// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	
	if( duration == 35) {
	        object guard;
		seteuid(getuid());
        	guard = new ("/d/death/npc/guard/killer1");

		guard->move(environment(me));
		guard->set_leader(me);
		message_vision("\n\n你眼前蓝光一现，$N从里边走了过来。\n", guard);
		message_vision("\n$N对$n大喝一声，竟敢和我阴府作对，看招！\n", guard, me);
		guard->kill_ob(me);
		me->fight_ob(guard);
	}
        if( duration == 20) {
                object guard;
                seteuid(getuid());
                guard = new ("/d/death/npc/guard/killer2");

                guard->move(environment(me));
                guard->set_leader(me);
                message_vision("\n\n你眼前蓝光一现，$N从里边走了过来。\n", guard);
                message_vision("\n$N对$n大喝一声，竟敢和我阴府作对，看招！\n", guard, me);
                guard->kill_ob(me);
                me->fight_ob(guard);
        }
        if( duration == 2) {
                object guardb;
                seteuid(getuid());
                guardb = new ("/d/death/npc/guard/killer4");
                guardb->move(environment(me));
                guardb->set_leader(me);
                message_vision("\n\n你眼前蓝光一现，$N从里边走了过来。\n", guardb);
                message_vision("\n$N对$n喝道：阎王爷差我来抓你，跟我走吧！\n", guardb, me);
                guardb->kill_ob(me); 
                me->fight_ob(guardb);
        }

        if( duration == 2) {
                object guardw;
                seteuid(getuid());
                guardw = new ("/d/death/npc/guard/killer3");
                guardw->move(environment(me));
                guardw->set_leader(me);
		message_vision("\n\n你眼前蓝光一现，$N从里边走了过来。\n", guardw);
                message_vision("\n$N对$n大喝一声，竟敢和我阴府作对，看招！\n", guardw, me);
                guardw->kill_ob(me); 
                me->fight_ob(guardw);
        }
	

	me->apply_condition("hell_duration", duration - 1);
	if( duration < 1 ) return 0;
	return 1;
}
