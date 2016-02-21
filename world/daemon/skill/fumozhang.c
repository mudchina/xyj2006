//伏魔掌
inherit SKILL;
mapping *action = ({
([ "action":  "$N侧过身去，右臂从左臂的下方忽然捣出一拳，好一个「飞岫拳」",
"dodge":  -20,
"parry": -20,
"force": 60,
  "damage_type": "瘀伤",
]),
 ([ "action":  "$N忽然向$n点出一指。正是林月如之杀手「气剑指」",
"dodge":  -10,
"parry": -10,
"force": 100,
 "damage_type": "刺伤",
                        "weapon": "剑气",
]),
([ "action":  "$N一声怒吼，双掌平平推出，乃是当年林天南赖以成名的绝技——伏魔掌",
"dodge":  0,
"parry": 0,
"force": 160,
"damage_type": "瘀伤",
]),
});
int valid_learn(object me)
{
 if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
 return notify_fail("练伏魔掌必须空手。\n");
return 1;
}
int valid_enable(string usage)
{
 return usage=="unarmed";
}
mapping query_action(object me, object weapon)
{
return action[random(sizeof(action))];
}
int practice_skill(object me)
{
if( (int)me->query("sen") < 30)
  return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
if( (int)me->query("kee") < 30 )
  return notify_fail("你现在手足酸软，休息一下再练吧。\n");
 if( (int)me->query("force") < 10 )
  return notify_fail("你的内力不够了。\n");
me->receive_damage("sen", 30);
me->add("force", -10);
return 1;
}
string perform_action_file(string func)
{
return CLASS_D("shushan") + "/fumozhang/" + func;
}
