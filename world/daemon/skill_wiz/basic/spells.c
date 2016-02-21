// spells.c
#include <ansi.h>

inherit SKILL;


string cast_spell_file(string spell)
{
        return "/daemon/class/spells/" + spell;
}

//this does not work yet. check later...cglaem.
// Implemented by Dream on 7/22/97.

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "初具法力" NOR,     
		HIB "略晓变化" NOR,
		HIB "腾云驾雾" NOR,     
		HIB "预知祸福" NOR,
		HIB "妙领天机" NOR,     
		CYN "呼风唤雨" NOR,
		CYN "负海担山" NOR,     
		CYN "移星换斗" NOR,
		HIC "随心所欲" NOR,     
		HIC "变换莫测" NOR,
		HIW "法力无边" NOR
	});

	grade = level / 30;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

string type() { return "magic"; }
