// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skillname;
	int skill, skill_basic;

	seteuid(getuid());

	if( environment(me)->query("no_fight") || 
		environment(me)->query("no_magic") )
		   return notify_fail("这里不是练功的地方。\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( me->is_busy() )
		return notify_fail("你现在很忙，不能练习。\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没「学会」这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

	if( skill*skill*skill/10 > (int)me->query("combat_exp") )
		return notify_fail("你的武学修为还没到这个境界，练得再多也没用。\n");
	//note, if a magic skill can also be practiced...need change this.

	notify_fail("你现在不能练习这项技能。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	// mon 10/19/98
	if(MISC_D->random_capture(me,20000,0)) return 1;

	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

        //added by mon. 7/24/97
	if(skill_basic <= skill && random(100)==0)
	  write("你的" + to_chinese(skillname)+ 
            "很难提高了，还是向你师父请教请教吧！\n");

	if( SKILL_D(skillname)->practice_skill(me) ) {
                me->improve_skill(skillname, skill_basic/2 +1, skill_basic > skill? 0: 1);
		write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@TEXT
指令格式：practice <技能种类>

这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。

如果你该项的基本技能足够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
TEXT
	);
	return 1;
}
