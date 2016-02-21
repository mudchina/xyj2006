// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "初通文理" NOR,
		BLU "略知一二" NOR,
		HIB "知书达理" NOR,
		HIB "文采斐然" NOR,
		YEL "博学多才" NOR,
		YEL "高才硕望" NOR,
		CYN "饱学鸿儒" NOR,
		HIW "学贯古今" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

