//Cracked by Roath
// xiao  奏箫之技   qin  抚琴之技
#include <ansi.h>

inherit SKILL;

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "初领妙道" NOR,     
		HIB "略通乐理" NOR,
		HIB "精通音律" NOR,     
		CYN "高情雅致" NOR,
		HIC "妙曲通神" NOR,     
		HIW "琴技无双" NOR,
	});

	grade = level / 30;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

