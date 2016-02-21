//【哭丧棒】kusang-bang.c

/*
大力棒    dodge  10    parry  -10    damage  30
棒号大力，力大势猛，急难招架
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "六丁开山",
                "action":
"$N发出一声厉叫，手中$w以一招「六丁开山」，带着呼呼风声向$n的$l砸去",
                "dodge":                10,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "混沌初破",
                "action":               
"$N身形一转，一招「混沌初破」使出，周围丈内土石乱飞，
霹雳间$w已砸向$n的$l，躲也躲不开了",
                "dodge":                15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "翻江搅海",
                "action":
"$N舞动$w，一式「翻江搅海」，劈头盖脸的向$n的$l砸去",
                "dodge":                15,
		"parry":		0,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "八方风雨",
                "action":
"$N舞动$w，使出「八方风雨」，幻出了无数$w向$n砸去",
                "dodge":                0,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练大力棒。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棒子才能练大力棒。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习大力棒。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍大力棒。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("dali-bang", 1) > 30 
	 && (int)me->query_skill("dali-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 200);
	}
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/dali-bang/"+func;
}
