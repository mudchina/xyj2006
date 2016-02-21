// mudage.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int sec, min, hrs, day, mon, age;
	string out_str;
	
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不能集中来算自己的年岁。\n");
		
	age = (int)me->query("mud_age");		
	sec = age % 60;
	age /= 60;
	min = age % 60;
	age /= 60;
	hrs = age % 24;
	age /= 24;
	day = age % 30;
	mon = age / 30;
	
	out_str = (mon? chinese_number(mon)+"月":"")
		+ (day? chinese_number(day)+"天":"")
		+ (hrs? chinese_number(hrs)+"小时":"");
	
	me->add("sen", -5);
              write("你已经为"HIC"西游记2006"NOR"奋斗" + out_str + "了。\n");
	return 1;
}
