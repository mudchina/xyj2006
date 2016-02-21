//Cracked by Roath
//Necromancy.c Bual

#include <ansi.h>

inherit F_CLEAN_UP;
int check_skeleton(object me, object target, object guard);
int add_skeleton(object me, object target);
int add_status(object me, object guard, object target, int n);

int cast(object me, object target)
{
	object guard;
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
	if( !target || !target->query("is_skeleton")) 
		return notify_fail("你要驱动哪一具骷髅？\n");
	
	if( (int)me->query("mana") < 200 ) 
		return notify_fail("你的法力不够！\n");

	if( (int)me->query_skill("gouhunshu", 1) < 20 )
		return notify_fail("你的勾魂术等级还不够。\n");

	me->add("mana", -50);

	if( me->query_temp("necromancy")
	&& objectp(guard=present(me->query_temp("necromancy"), environment(me))) ) { 
		check_skeleton(me, target, guard);
		return 1;
	} else {
		add_skeleton(me, target);
		return 1;
	}
}

int add_skeleton(object me, object target)
{
	object guard;
	
	message_vision("$N对着地下的$n念了几句咒语。\n", me, target);

	seteuid(getuid());
	guard = new("/obj/npc/skeleton");
	guard->move(environment(me));
	guard->invocation(me);
	
	message_vision("$N竟摇摇晃晃地站了起来。\n", target);

	me->set_temp("necromancy", guard);
	
	destruct( target );

	return 1;
}

int check_skeleton(object me, object target, object guard)
{
	int n;

	n = guard->query("people");

	if( me->query_skill("gouhunshu",1)/20 >= n ) {
		add_status(me, guard, target, n);
		return 1;
	}
	tell_object(me, "你的勾魂术等级不够，没法控制更多的骷髅兵。\n");
	return 1;
}

int add_status(object me, object guard, object target, int n)
{
	n=n+1;
	guard->set("people", n);

	guard->add("max_kee", 200);
	guard->add("eff_kee", 200);
	guard->add("kee", 200);

	guard->add("max_sen", 200);
	guard->add("eff_sen", 200);
	guard->add("kee", 200);

        message_vision("$N竟摇摇晃晃地站了起来。\n", target);

	guard->reset_status();
	destruct( target );
	return 1;
}
