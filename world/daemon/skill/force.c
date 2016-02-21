// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/daemon/class/force/" + func;
}

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "若有若无" NOR,
		HIB "初窥门径" NOR,
		HIY "渐入佳境" NOR,
		HIB "气息悠长" NOR,
		YEL "生生不绝" NOR,
		YEL "英华内敛" NOR,
		YEL "通关在即" NOR,
		CYN "豁然贯通" NOR,
		HIC "举世无双" NOR,
		HIC "震古铄今" NOR,
		HIW "深不可测" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
