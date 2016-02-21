//Cracked by Roath
//【哭丧棒】kusang-bang.c

/*
哭丧棒    dodge  0    parry  -10    damage  25
哭丧棒诡异绝伦，棒势多走偏锋，令人防不胜防，而此棒以
致人死地为主，下手绝不留情。
*/

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "凄风长号",
                "action":
"$N发出一声厉叫，手中$w以一招"+HIB"「凄风长号」"NOR"狂风骤雨般地向$n的$l连连扫去",
                "dodge":                15,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "怨妇伤情",
                "action":               
"$N身形一转，面带戚色，一招"+HIB"「怨妇伤情」"NOR"使出，\n手中$w好像沾上了$n，甩也甩不开",
                "dodge":                -15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "寒夜祭灵",
                "action":
"$N舞动$w，咯咯一笑，一招"+HIB"「寒夜祭灵」"NOR"夹着点点磷光砸向$n的$l",
                "dodge":                10,
		"parry":		0,
                "damage":               20,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "荒野求食",
                "action":
"$N面露乞怜之色，手中$w却轻轻一抖，一招"+HIB"「荒野求食」"NOR"阴毒无比地刺向$n$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "月下独行",
                "action":
"$N身形往后一缩，手中$w突然暴长数尺，发出青绿之光，\n一招"+HIB"「月下独行」"NOR"带着森森鬼气砸向$n$l",
                "dodge":                -5,
		"parry":		0,
                "damage":               20,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "小楼夜哭",
                "action":
"$N喉咙里发出几声嚎叫，高举$w，不顾一切地冲向$n，几乎与$n贴脸而立！\n手中$w却悄无声息地刺向$n的$l，好厉害的"+HIB"「小楼夜哭」"NOR"",
                "dodge":                -20,
		"parry":		-20,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":               
"$N大喝一声，手中$w宛若矫龙飞在半空，大有"+HIB"「横空出世」"NOR"的气概。\n$n只觉得全身俱在$w笼罩之下",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "饿鬼拦路",
                "action":               "$N手中$w一抖，幻出几许银光，就在一恍惚间，$w已斜斜地点上了$n的$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练哭丧棒。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棒子才能练哭丧棒。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	string name;
	int i;
	mapping actions;

	
        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        actions=action[random(6)];
        }else {
        actions=action[i];
        }
	name=actions["name"];
	me->set_temp("kill_msg","special_msg");
	me->set_temp("special_msg",name);
	return actions;
        
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习哭丧棒。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍哭丧棒。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("kusang-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/kusang-bang/" + func;
}

