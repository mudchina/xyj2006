// scribe.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, name;
	object ob;

	// We might need to load new objects.
	seteuid(getuid());

	if( me->is_fighting() )	return notify_fail("战斗时不能画符！\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，无法画符。\n");

	if( !arg
	||	sscanf(arg, "%s on %s", name, ob)!= 2 )
		return notify_fail("指令格式：scribe <符咒> on <物品>\n");

        if ( !(ob=present("paper seal",me)))
                return notify_fail("你只能将符咒画在桃符纸上。\n");


	if( stringp(spells = me->query_skill_mapped("spells")) ) {
		notify_fail("你所学的法术没有这种符。\n");
		if( SKILL_D(spells)->scribe_spell(me, ob, name) ) {
			me->receive_wound("kee", (int)me->query("max_kee")/100);
			me->receive_damage("sen", 30);
			return 1;
		}
		return 0;
	} else 
		return notify_fail("你请先用 enable 指令选择你要使用的咒文系。\n");

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式：scribe <符咒名称> on <物品名称>

在画符用的桃符纸(paper seal)上画符。在你画符之前，你必须
先用 enable 指令来指定你要使用的咒文系。

注：画符会消耗若干气(要咬破手指用鲜血画)与神。
 
HELP
        );
        return 1;
}
