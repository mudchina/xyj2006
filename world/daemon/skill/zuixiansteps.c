//zuixiansteps.c 醉仙望月步
//DHXY-EVIL       2000.7.6
inherit SKILL;

string *dodge_msg = ({
"$n忽然「咯」的一声喷出口酒气，刚巧腹部一缩，躲过了$N这一招。\n",
"$n醉眼朦胧，右脚一软，顺势倒入$N的怀里，$N的凌厉攻势一下全部打空。\n",
"$n双眼似睁似闭，顺着$N的招式一个举杯饮酒，全身自膝盖向后平平倒了下去。\n",
"但是$n喝醉了似的身子向后一倒，右脚却直踢而上，将$N逼了开去。\n",
"$n双腿无力，脚下一软坐倒在地，身形顿时矮半截，刚好逼过了$N的招式。\n",
"可是$n摇摇摆摆地乱走了几步，脚下不丁不八却已经转到了$N的身后。\n",
"却见$n左脚踩在自己右脚上一拌，身子向右歪去，刚巧躲过了$N的攻击。\n",
"$n满脸醉相，信步往左一踏，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30)
		return notify_fail("你现在脚下虚浮，先休息一阵吧。\n");
	if((int)me->query("force") < 3 )
		return notify_fail("你现在内力不够，难以继续练下去了。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
