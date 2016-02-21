// yinshen.c 隐身术

inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
	int howlong;
	int spell;
	spell=me->query_skill("spells")/2 + me->query_skill("buddhism");
	if(spell < 100)
		return notify_fail("你还没学会隐身法。。。\n");
	if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("不是佛门弟子不能用「隐身法」！\n");

	if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");

	message_vision("$N喃喃地念了几句咒语。\n", me);

	if( random(me->query("max_mana")) < 200 ) {
		me->add("mana",-(int)me->query_skill("spells"));
		me->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 5+random(5);
	}

	me->add("mana", -2*(int)me->query_skill("spells"));
	me->receive_damage("sen", 20);

	howlong = 15 + random((me->query_skill("spells") -100));
	if (!me->query("env/invisibility"))
		call_out("free", howlong, me, howlong);
	me->set_temp("yinshentime", howlong+(int)me->query_temp("yinshentime"));

        me->set("env/invisibility", 2);
	me->set_temp("no_heal_up/yinshen",1);
	
	message_vision(HIW"\n只见一道白光闪过，$N踪迹皆无。\n\n"NOR, me);
	
	return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
	if (!user->query("env/invisibility")) return;
	if (user->query_temp("yinshentime") - howlong) {
		user->set_temp("yinshentime", 
			user->query_temp("yinshentime") - howlong);
		call_out("free", user->query_temp("yinshentime"), 
			user, user->query_temp("yinshentime"));
		return;
		}
	user->delete_temp("yinshentime");
	user->set("env/invisibility", 0);      
	user->save();
	message_vision(HIW"\n白光闪过之后，$N又现出了身形。\n\n"NOR, user);
	user->delete_temp("no_heal_up/yinshen");
	return;
}

