// daya-jian.c
//  大雅古剑法

#include <ansi.h>
#define OO YEL"大雅古剑法"NOR
inherit SKILL;

mapping *action = ({
    ([  "action": 
"只见$N手中$w舞动出一片网状，使出"OO"第一式：「盘庚式」，\n"
"将$n周围尽皆罩住。\n",
        "parry_msg" :
"$n使出「“恒”字诀」，口中念道：日月得天而能久照，四时变化而能久成。\n"
"只见$n丝毫不乱，应接不暇，将$N的招式一一截住。",
"parry_power":		10,
 //       "jibie" :15,
        "dodge" :-20,
        "parry" :-30,
        "zhaoshi":"「盘庚式」",
        "damage":90,
        "damage_type":"割伤"    ]),

    ([  "action":
"只见$N手中$w挥动一股霸道的剑气，正是"OO"第二式：「毕命式」，\n"
"对着$n左右斜劈，凛然有风。",
        "parry_msg"  :
"$n使出「“遁”字诀」，口中念道：刚当位而应，与时行也。\n"
"$n见机而动，向外轻巧地跃开。",
"parry_power":		10,
//        "jibie" :30,
        "dodge" :-10,
        "parry" :-10,
        "zhaoshi":"「毕命式」",
        "damage":80,
        "damage_type":"割伤" ]),
    ([  "action":
"只见$N手中$w闪出点点剑光，联成一线，正是"OO"第三式：「罔命式」，\n"
"$w带动光线，在$n面前挥舞。",
        "parry_msg"  :
"$n使出「“萃”字诀」，口中念道：乃乱乃萃，其志乱也。\n"
"$n似乎有些散乱，竟尔突然定住，顿时将$N的攻势化解于无形。",
"parry_power":		10,
//        "jibie" :45,
        "dodge" :-10,
        "parry" :-20,
        "zhaoshi":"「罔命式」",
        "damage":90,
        "damage_type":"割伤"    ]),
    ([  "action":
"只见$N舞动手中$w，正是"OO"第四式：「大畜式」，\n"
"剑光霍霍之中，从一个意想不到的角度突然挑出一剑，向$n的下颚直刺。",
        "parry_msg"  :
"$n使出「“革”字诀」，口中念道：文明以说，大亨以正。\n"
"$n在千钧一发之际，突然不知从什么地方横出一剑，拦住了$N的这一招。",
"parry_power":		10,
//        "jibie" :60,
        "dodge" :-10,
        "parry" :-30,
        "zhaoshi":"「大畜式」",
        "damage":80,
        "damage_type":"割伤"    ]),
        ([      "action":
"只见$N手中$w发出龙吟之声，阴阳相和，高声琨，正声缓，正是"OO"\n"
"第五式：「瞽蒙式」，剑锋直向$n左肩刺过去。",
                "parry_msg" :
"$n使出「“比”字诀」，口中念道：舍逆取顺。\n"
"$n低头躲过$N这一招，闪身跃开。",
        "zhaoshi":"「瞽蒙式」",
"parry_power":		10,
//        "jibie":75,
        "dodge":-15,
        "parry":-40,
        "damage":60,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N身体在原地游走，脚步散而不乱，正是"OO"第六式：「述而式」，\n"
"手中$w摆动，不时向$n刺出一剑。",
                "parry_msg" :
"$n使出「“需”字诀」，口中念道：刚健而不陷，其义不穷困矣。\n"
"$n无偏不偏，恰恰从$N的攻势中躲了开去。",
        "zhaoshi":"「述而式」",
"parry_power":		10,
//        "jibie":90,
        "dodge":-20,
        "parry":-20,
        "damage":100,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N身体十分稳重，正是"OO"第七式：「至诚式」，\n"
"手中$w若有若无，缓缓击出一剑，向$n的肩部搭了过去。",
                "parry_msg" :
"只见$N身体十分稳重，手中$w若有若无，缓缓击出一剑。\n"
"$n急忙撤招回守。",
        "zhaoshi":"「至诚式」",
"parry_power":		10,
//        "jibie":105,
        "dodge":-30,
        "parry":-20,
        "damage":120,
        "damage_type":"割伤"
        ]),
        ([      "action":
"只见$N使出的正是"OO"第八式：「止戢式」，\n"
"手中$w剑光柔和，隐隐有风雷之声，向$n扑面涌去，令人顿有退避之意。",
                "parry_msg" :
"手中$w剑光柔和，隐隐有风雷之声，令人听来顿有退避之意。",
        "zhaoshi":"「止戢式」",
"parry_power":		10,
//        "jibie":120,
        "dodge":-10,
        "parry":-50,
        "damage":100,
        "damage_type":"割伤"
        ]),
});

string *daya= ({
"$N念着口诀：载戢戈，载蠹弓矢，我求懿德，肆于时夏。\n",
"$N念着口诀：若网在纲，有条不紊。\n",
"$N念着口诀：彰善潸恶，树之风声。\n",
"$N念着口诀：绳衍纠谬，格其非心。\n",
"$N念着口诀：刚健笃实辉光，日新其德。\n",
"$N念着口诀：鼓琴瑟，以役大师。\n",
"$N念着口诀：志于道，据于德，依于仁，游于艺。\n",
"$N念着口诀：盹盹其仁，渊渊其渊，浩浩其天。\n"
});

int practice_skill( object me )
{
        string msg;
		object target;
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 50 )
                return notify_fail("你的内力或气不够，没有办法练习大雅古剑法。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
    if( me->query("max_force")<2000 )
        return notify_fail("你内力不足以练习此剑法！\n");
if (me->query_skill("daya-jian",1) < 20) return 0;
//    if (me->query("mark/dayaget")!= 1)
//        return notify_fail("你未领悟过大雅古剑谱,怎么也搞不懂。\n"); 
	message_vision(daya[random(sizeof(daya))], me, target);
    return 1;
}

int valid_learn(object me)
{
        if ((int)me->query_skill("daya-jian", 1) > 19)
     return 1;

        return notify_fail("大雅古剑法只能通过研习《大雅古剑谱》来领悟。\n"); 
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}

string perform_action_file(string func)
{
	return CLASS_D("xuanyuan") + "/daya-jian/"+func;
}
