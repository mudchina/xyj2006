// transfer.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	object zhenshen;

	if ( me->is_fight() )
		return notify_fail("你还在战斗，要灵魂出壳就死定啦！\n");
	
	if ( me->query_temp("pkgame") )
		return notify_fail("你还是认真比赛吧！\n");

	if ( me->is_ghost() )
		return notify_fail("你已经是鬼了，还要干什么？\n");

	if( (string)me->query("family/family_name")=="阎罗地府" )
		return notify_fail("你是鬼类，那里有什么魂魄。\n");

	if( (int)me->query("max_mana") <100 )
		return notify_fail("你的法力不够！\n");
	
	if( (int)me->query("daoxing") < 30000 )
		return notify_fail("你的道行不够，灵魂出了壳怕很难回来。\n");
	
	if( (int)me->query("mana") - (int)me->query("max_mana") < 50)
		return notify_fail("你的法力不足！\n");

	if( me->query_temp("in_hell") )
		return notify_fail("你的魂魄已经出壳了！\n");
	
	if( environment(me)->query("hell"))
		return notify_fail("你已身处地狱了！\n");

	me->receive_damage("sen", 30);
	me->add("mana", -30);

	if( (int)me->query_skill("spells", 1) - 30 < 10 ) {
		write("你失败了！\n");
                return 1;
        }

	me->set_temp("in_hell", 1);

	message_vision("$N口中喃喃地念了几句咒语。\n", me);
	message_vision(YEL"一股灵气从$N脑门上钻出，随风飘去，转眼就不见了。\n"NOR, me);

	seteuid(getuid());
	zhenshen= new("/obj/npc/zhenshen");
	zhenshen->move(environment(me));
	zhenshen->invocation(me);
	me->set_temp("zhenshen", zhenshen);
	me->move("/d/death/gate");
	message_vision("四出刮起阴风，现出了$N的影子。\n", me);
	me->apply_condition("in_hell", 1);	
	
  
  return 1;
}
int help(object me)
{
write(@HELP
指令格式 : cast chuqiao
 
这个指令可以让你灵魂出壳，你的魂魄则会到地狱中。

使用这个指令是会相当的危险，因为这时你的魂魄在地狱中会受到各
方面的威胁，另一方面，你的真身在阳间也会处与无保护状态，若有
人杀里你的真身，你便会成为一个无身可归的孤魂野鬼。

HELP
    );
    return 1;
}

