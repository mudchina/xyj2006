//Cracked by Roath
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string curse, spl, trg;
	object target;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" 你上一个动作还没有完成，不能下降头。\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("这里不准下降头。\n");

	if( !arg ) return notify_fail("指令格式：curse <降头> [on <目标>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
                if(!objectp(target)) 
	 		return notify_fail(" 你的降头要用在谁身上？\n");
//        if( userp(target) &&
//                (int) target->query("combat_exp") < LOWER_LIMIT &&
//                !me->query("licensed_to_kill")
//          )
//                return notify_fail("唉！你可不可以改掉以强凌弱的恶习？\n");
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("这里没有 " + trg + "。\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");
	if( stringp(curse= me->query_skill_mapped("cursism")) )
		return (int)SKILL_D(curse)->curse_curses(me, spl, target);
		
	return notify_fail("你请先用 enable curse指令选择你要使用的降头术体系。\n");
}

int help (object me)
{
        write(@HELP
指令格式：curse <降头> [on <目标>]
 
HELP
        );
        return 1;
}
