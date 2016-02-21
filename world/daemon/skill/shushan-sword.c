// jadesword. 【玉魔剑法】
// edited 4-16-97 pickle

/*
七修剑法    dodge  5    parry  -10    damage  25
七修剑法为拼命剑法，只求伤敌，不顾自身安危，故其
突防之力颇强。然则往往乱打一气，敌已逃而不觉。
*/

// 五马分尸，六亲不认，七窍生烟，
// 八方风雨，九死一生，十面埋伏

inherit SKILL;
void set_busy();
mapping *action = ({
    ([
      "action":
"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地",
      "dodge":		20,
      "parry":	      -20,
      "damage":		30,
      "damage_type":	"刺伤",
      "name":		"「白影急幌」",
      ]),
    ([
      "action":
"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹",
      "dodge":		10,
      "parry":		-20,
      "damage":		30,
      "damage_type":	"刺伤",
      "name":		"「自己小腹」",
      ]),
    ([
      "action":
"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地",
          "dodge":		 -10,
      "parry":	       -10,
      "damage":		  30,
      "damage_type":	"刺伤",
      "name": 		"「猱身而上」",
      "post_action":	(:set_busy:),
      ]),
	
    ([
      "action":
"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
      "dodge":		    20,
      "parry":	        -20,
      "damage":		   30,
      "damage_type":	"刺伤",
      "name": 		"「招法一变」",
      "post_action":	(:set_busy:),
      ]),
    ([
      "action":
"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
      "dodge":		    -10,
      "parry":	        -10,
      "damage":		    35,
      "damage_type":	"刺伤",
      "name": 		"「疾冲上前」",
      "post_action":	(:set_busy:),
      ]),
    ([
      "action":
"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l",
      "dodge":	       20,
      "parry":	           -15,
      "damage":		30,
      "damage_type":	"刺伤",
      "name": 		"「飞身跃起」",
      ]),
});

int valid_learn(object me)
{
    object ob;
    
    if ((int)me->query("max_force") < 100)
	return notify_fail("你的真气不足，难以领悟剑法的精妙之处。\n");
    
    if (!(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
	return notify_fail("你必须先找一把剑才能练剑法。\n");
    
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if ((int)me->query("kee") < 30)
	return notify_fail("你的气太低，再练下去会有危险的！\n");
    if ((int)me->query("force") < 5)
	return notify_fail("你的内力不够，没有办法运用蜀山剑法。\n");
    me->receive_damage("kee", 30);
	me->add("force", -5);
    write("你按著所学练了一遍蜀山剑法。\n");
    return 1;
}
void set_busy()
{
    object me=this_player();
    me->start_busy(1);
}
