// dodge.c
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"但是和$p$l偏了几寸。\n",
	"但是被$p机灵地躲开了。\n",
	"但是$n身子一侧，闪了开去。\n",
	"但是被$p及时避开。\n",
	"但是$n已有准备，不慌不忙地躲开。\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "笨手笨脚" NOR,     
		BLU "步伐轻盈" NOR,
		HIB "身形灵动" NOR,     
		HIB "身轻如燕" NOR,
		HIB "疾若飞鸿" NOR,
		CYN "踏雪无痕" NOR,
		CYN "登萍渡水" NOR,
		CYN "来去如风" NOR,     
		HIC "一泻千里" NOR,
		HIC "移形换影" NOR,
		HIW "凌空渡虚" NOR     
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

