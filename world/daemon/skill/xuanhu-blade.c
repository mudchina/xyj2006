//玄狐长恨刀
// dodge 0    parry -5        damage 25
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":		"「马嵬坡下泥土中，不见玉颜空死处」",
		"action":	"$N一式"+HIG"「马嵬坡下泥土中，不见玉颜空死处」"NOR"，脚踏「巽」位，
身形一晃，从$n眼前消失，闪现在$n身后，
以刀当剑，手中$w毫无声息地刺向$n的$l",
 "dodge":        0,
"parry":        0,
		"damage":	20,
		"damage_tupe":	"刺伤",
		"parry_msg":	"$N一式「马嵬坡下泥土中，不见玉颜空死处」，脚踏「巽」位，
身形一晃，从$n眼前消失，闪现在$n身后",
		"parry_power":	10,
	]),
	([	"name":		"「迟迟钟鼓初长夜，耿耿星河欲曙天」",
		"action":	"$N一式"+HIG"「迟迟钟鼓初长夜，耿耿星河欲曙天」"NOR"，抢占「坎」位，
手中$w化做一道刀光, 似银河倒泻般挥向$n$l",
 "dodge":        0,
		"parry":	0,
		"damage":	25,
		"damage_type":	"砍伤",
		"parry_msg":	"$N一式「迟迟钟鼓初长夜，耿耿星河欲曙天」，抢占「坎」位，
手中$w化做一道刀光, 磕开$n的攻势",
		"parry_power":	10,
	]),
	([	"name":		"「上穷碧落下黄泉，两处茫茫皆不见」",
		"action":       "$N一式"+HIG"「上穷碧落下黄泉，两处茫茫皆不见」"NOR"，闪向「震」位，
手中$w化为漫天刀影，夹着隐隐雷声，攻向$n全身各处",
"dodge":        0,
		"parry":	-10,
		"damage":	25,
		"damage_type":	"劈伤",
		"parry_msg":	"$N一式「上穷碧落下黄泉，两处茫茫皆不见」，闪向「震」位，
手中$w化为漫天刀影，夹着隐隐雷声，护住$N全身各处",
		"parry_power": 10,
	]),
	([	"name":		"「楼阁玲珑五云起，其中绰约多仙子」",
		"action":	"$N一式"+HIG"「楼阁玲珑五云起，其中绰约多仙子」"NOR"，绕$n急速旋转，
化为一圈幻影，在「艮」位突发一刀，以泰山压顶之式劈向$n$l",
"dodge":        -5,
		"parry":	0,
		"damage":	30,
		"damage_type":	"砍伤",
		"parry_msg":	"$N一式「楼阁玲珑五云起，其中绰约多仙子」，绕$n急速旋转，
化为一圈幻影，躲开$n的攻势",
		"parry_power":	10,
	]),
	([	"name":		"「风吹仙袂飘飘举，犹似霓裳羽衣舞」",
		"action":	"$N一式"+HIG"「风吹仙袂飘飘举，犹似霓裳羽衣舞」"NOR"，身体急速旋转，
在「离」位如一团旋风，手中$w唰地砍向$n的$l",
 "dodge":        0,
		"parry":	0,
		"damage":	20,
		"damage_type":	"砍伤",
		"parry_msg":	"$N一式「风吹仙袂飘飘举，犹似霓裳羽衣舞」，身体急速旋转，
在「离」位如一团旋风，化去$n的攻势",
		"parry_power": 	10,
	]),
	([	"name":		"「玉容寂寞泪阑干，梨花一枝春带雨」",
		"action":	"$N一式"+HIG"「玉容寂寞泪阑干，梨花一枝春带雨」"NOR"，占住「兑」位，
将手中$w化做点点星光，洒向$n全身",
 "dodge":        -10,
		"parry":	-10,
		"damage":	30,
		"damage_type":	"劈伤",
		"parry_msg":	"$N一式「玉容寂寞泪阑干，梨花一枝春带雨」，占住「兑」位，
将手中$w化做点点星光，击在$n的$l，化去$n的攻势",
		"power_power":	10,
	]),
	([	"name":		"「在天愿作比翼鸟，在地愿为连理枝」",
		"action":	"$N一式"+HIG"「在天愿作比翼鸟，在地愿为连理枝」"NOR"，连踏「乾」「坤」二位，
手中$w从两个方向向$n的$l击去",
 "dodge":        0,
		"parry":	0,
		"damage":	20,
		"damage_type":	"割伤",
		"parry_msg":	"$N一式「在天愿作比翼鸟，在地愿为连理枝」，连踏「乾」「坤」二位，
从$n的攻势中闪了出去",
		"parry_power":	10,
	]),
	([	"name":		"「天长地久有时尽，此恨绵绵无绝期」",
		"action":	"$N一式"+HIG"「天长地久有时尽，此恨绵绵无绝期」"NOR"，由「坤」向「乾」疾退，
手中$w化做一道长虹向$n$l击去",
 "dodge":        -10,
		"parry":	-20,
		"damage":	30,
		"damage_type":	"割伤",
		"parry_msg":	"$N一式「天长地久有时尽，此恨绵绵无绝期」，由「坤」向「乾」疾退，
手中$w化做一道长虹荡开了$n的锋芒",
		"parry_power":	10,
	]),
});
int valid_learn(object me)
{
        object ob;

        if( (string)me->query("gender") != "女性" )
                return notify_fail("玄狐长恨刀只有女性才能练。\n");

        if( (int)me->query("max_force") < 200 )
                return
notify_fail("你的内力不够，没有办法学玄狐长恨刀法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return
notify_fail("你必须先找一把刀才能学玄狐长恨刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀，才能练刀法。\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("moon") + "/xuanhu-blade/" + func;
}
