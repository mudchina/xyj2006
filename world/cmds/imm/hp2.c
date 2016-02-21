// hp cmds (Mon  09-04-95)
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
 
int main(object me, string arg)
{
	object ob;
	mapping my;
	int  year, day, hour;
 
	seteuid(getuid(me));
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
 
	my = ob->query_entire_dbase();
 
    printf(" 精  ： %s%4d/ %4d %s(%3d%%)" NOR "    灵力： %s%4d / %4d (+%d)\n" NOR,
		status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
		status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
		status_color(my["atman"], my["max_atman"]),	my["atman"], my["max_atman"],
		my["atman_factor"] );
    printf(" 气血： %s%4d/ %4d %s(%3d%%)" NOR "    内力： %s%4d / %4d (+%d)\n" NOR,
		status_color(my["kee"], my["eff_kee"]),	my["kee"], my["eff_kee"],
		status_color(my["eff_kee"], my["max_kee"]),	my["eff_kee"] * 100 / my["max_kee"],
		status_color(my["force"], my["max_force"]),	my["force"], my["max_force"],
		my["force_factor"] );
    printf(" 精神： %s%4d/ %4d %s(%3d%%)" NOR "    法力： %s%4d / %4d (+%d)\n" NOR,
		status_color(my["sen"], my["eff_sen"]),	my["sen"], my["eff_sen"],
		status_color(my["eff_sen"], my["max_sen"]),	my["eff_sen"] * 100 / my["max_sen"],
		status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		my["mana_factor"] );
    printf(" 食物： %s%4d/ %4d      " NOR "     潜能： %s%d\n" NOR,
    //printf(" 食物： %s%4d/ %4d      " NOR "     悟力： %s%d\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIY,
        (int)ob->query("potential") - (int)ob->query("learned_points"));

	year = my["combat_exp"] / 1000; 
	day = (my["combat_exp"] - year * 1000) / 4;
	hour = (my["combat_exp"] - year * 1000 - day * 4) * 3; 
    //printf(" 饮水： %s%4d/ %4d      " NOR "     经验： %s%d\n" NOR,
    printf(" 饮水： %s%4d/ %4d      " NOR "     道行： %s",
	//%s年%s天%s时辰\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM );
    if(year) printf("%s年", chinese_number(year));
    if(day) printf("%s天", chinese_number(day));
    if(hour) printf("%s时辰", chinese_number(hour));
	if(!year && !day && !hour)  printf("你还没有道行。");
	//my["combat_exp"] );
	printf("\n"NOR);
	return 1;
}
 
string status_color(int current, int max)
{
	int percent;
 
	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
 
int help(object me)
{
	write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}
