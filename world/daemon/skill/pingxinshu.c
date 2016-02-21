// ningxie-force.c  【冰谷凝血功】

#include <ansi.h>

int valid_enable(string usage) { return usage=="pingxinshu"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("平心术只能向师父学。\n");
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else if ( level < 290 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 3 )
		return BLU "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 5 )
		return HIB "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 7 )
		return YEL "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 9 )
		return CYN "第"+chinese_number( stage(level) )+"重　" NOR;
	else 
		return HIW "第"+chinese_number( stage(level) )+"重　" NOR;
}

void skill_improved(object me)
{
	//if stage increased, give bonus...?
	int level = (int)me->query_skill("pingxinshu", 1);
	if ( stage(level) == stage(level-1) + 1)
	{
		//this is to prevent ppls from abondoning skill to get bonus.
		if( (int)me->query("pingxin_bonus") < stage(level) )
		{
			me->set("pingxin_bonus", stage(level));
			me->set("max_kee", (int)me->query("max_kee") + stage(level)*50 );
			// mon 12/13/98
			me->set("eff_kee", (int)me->query("eff_kee") + stage(level)*50 );
			me->save();
			log_file("pingxin-bonus", ctime( time() )+": "
				+me->query("name")+"("+me->query("id")+")"
				+" got max_kee "+(stage(level)*50)+".\n");
			message_vision(HIW "$N默默的研习了学过的平心术,突然感觉身轻体健,跃跃欲飞！\n" NOR, me);

		}
	}
			
}
