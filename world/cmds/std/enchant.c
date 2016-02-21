// enchant.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || !sscanf(arg, "%d", pts) ) 
		return notify_fail("指令格式：enchant <法力点数>\n");

	if( pts > ((int)me->query("max_mana")/20+1) )
		return notify_fail("你的法力不足，发不出那么强的威力。\n");

	if( pts < 0 ) return notify_fail("法力点数必须是正数。\n");	
	me->set("mana_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: enchant <法力点数>
 
这个指令让你设定使用魔法武器时要用来导引武器魔力所用的法力强度。
法力点数越高，魔法武器的杀伤力也越强。

HELP
	);
	return 1;
}
