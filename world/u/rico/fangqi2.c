// abandon.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
	int skill_lvl, lvl=0;
	string skill;

	if(!arg || arg == "" || sscanf(arg, "%s %d", skill, lvl)!=2 &&
	   sscanf(arg, "%s", skill)!=1)
		return notify_fail("你要重新设定哪一项技能？\n");
	skill_lvl = me->query_skill(skill,1);
	if( lvl <0 )
		return notify_fail("技能级别不能为负。\n");
	if( lvl == skill_lvl && lvl>0)
		return notify_fail("你不就是这级别吗？\n");
	if( lvl > skill_lvl || lvl > 400)
		return notify_fail("你这项技能并没有学到这个级别。\n");
	if( !me->delete_skill(skill) )
		return notify_fail("你并没有学过这项技能。\n");
	write("你重新设定了 " HIR+ to_chinese(skill) + NOR" 到设定级别数值\n");
	if( lvl > 0 ) me->set_skill(skill, lvl);
	return 1;
}

int help()
{
	write(@TEXT
指令格式：fangqi2 <技能名称> [要放弃“到”的级别！！！]

重新设定一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中重新设定到一定的级别。

但如果你在放弃命令时没有输入级别，将全部放弃这项技能。

这个指令使用的场合通常是用来设定一些「不小心」练出来或练过了的的技能。
TEXT
	);
	return 1;
}
