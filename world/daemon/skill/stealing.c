// perception.c
#include <ansi.h>

inherit SKILL;

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "贼头贼脑" NOR,     
		HIB "贼手贼脚" NOR,
		HIB "快手快脚" NOR,     
		CYN "出手如风" NOR,
		HIC "手到擒来" NOR,     
		HIW "妙手神偷" NOR,
	});

	grade = level / 10;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

