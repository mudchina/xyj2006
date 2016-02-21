//Cracked by Roath
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object soldier;
	int strategy,leadership, exp, MAX_GUARD;
	if ((string)me->query("class") != "official")
	return notify_fail("你不是朝廷命官，还是自己照顾自己吧！\n");
        if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
	if((int)me->query("sen")< 100)
	return notify_fail("你的神太差了！\n");
	strategy = (int)me->query_skill("strategy");
	leadership = (int)me->query_skill("leadership");
	exp = (int)me->query("combat_exp");
	if(strategy < 10 || leadership < 10)
	return notify_fail("你兵法和用人之技太差了，没人愿意理你！\n");	
	MAX_GUARD = strategy * leadership / 10000 + 1;
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("以你现在的官位，你已经受道足够的保护！\n");
	seteuid(getuid());
	me->receive_damage("sen",100);
	soldier= new("/obj/npc/danei");
	soldier->move(environment(me));
        soldier->invocation(me, (leadership+strategy));
        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
        me->remove_all_killer();
	message_vision(HIB "\n$N发出一声长求援！\n" NOR, me);	
	message_vision(HIB "\n$N应声而来！\n" NOR, soldier);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：alert
 
这个指令让官员呼唤高手来保护自己.
 
HELP
    );
    return 1;
}
