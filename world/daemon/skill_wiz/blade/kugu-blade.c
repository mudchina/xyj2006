//枯骨刀法, kugu-blade.c
//modified 4-17-97 pickle

/*
枯骨刀    dodge  -5    parry  -5    damage  20
无底洞之杀手绝学，刀法专注进攻，使用此项武功需持
枯骨刀才能发挥出威力，因其重招不重力，用普通的刀
伤害力不大。
*/
//pickle, haven't changed settings yet, please try to be compatible 
//with above parameters...weiqi.

// 尸横遍野，行尸走肉，尸山血海，借尸还魂，马革裹尸，毁尸灭迹

inherit SKILL;

mapping *action = ({
        ([      "name":                 "尸横遍野",
                "action":
"$N在$n四周滚来滚去，手中$w招招不离$n的下盘，\n"
"这招「尸横遍野」果然奏效，逼得$n手忙脚乱",
                "dodge":                -10,
		"parry":		-15,
                "damage":               20,
                "damage_type":  	"砍伤",
		"dodge_msg":
"$n连打七八个滚，虽看似狼狈不堪，却巧妙地躲过了$N的攻势。\n",
		"dodge_power":		10,
		"parry_msg":
"$n眼见来势凌厉，忙翻身倒下，顺手以$W将$N向上荡开。\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "借尸还魂",
                "action":
"激战中，$N忽然将$w收在身旁，直挺挺的倒下。正在$n不知所措之时，\n"
"$N的$w如毒蛇一般突然向$n的$l飞去，正是一招「借尸还魂」",
                "dodge":                -15,
		"parry":		-10,
                "damage":               20,
                "damage_type":  	"戳伤",
		"dodge_msg":
"$N似乎已经打中了$n时，$n突然原地疾转，化为一片黑影不见了。\n",
		"dodge_power":		10,
		"parry_msg":
"$n连忙使一招「借尸还魂」，举$W一挡，借势疾退开去。\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "尸山血海",
                "action":
"$N左手运起排山倒海的掌力，右手$w舞出夺目的寒光，笼罩住$n的全身",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"劈伤",
		"dodge_msg":
"$n平平跃起，在空中连转数圈，落在$N身后。原来是「尸山血海」。\n",
		"dodge_power":		10,
		"parry_msg":
"$n展开$W疾挥，但见漫天刀影，这招「尸山血海」果然将$N的攻势挡了回去。\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "毁尸灭迹",
                "action":
"$N忽然间脸色苍白，身体软软的消失在黑暗中。$n在激战中突然不见了敌人，\n"
"惊慌失措间，$N运起了「毁尸灭迹」的半招进攻，一刀向$n的后脑砍去",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"砍伤",
		"dodge_msg":
"$N似乎就要击中了$n，但$n腰身连扭数下，将攻势避了过去。\n"
"$N虽然看得一清二楚，却道不出这招「毁尸灭迹」的奥妙。\n",
		"dodge_power":		10,
		"parry_msg":
"$n看准来势，举$W迎去。只听「噗」地一声闷想，$n的人影已不见了。\n",
		"parry_power":		10,
        ]), 
        ([      "name":                 "马革裹尸",
                "action":
"只见$N运起轻功，好似一堵无形的墙壁，向$n徐徐推近。\n"
"急转中$N忽然一刀砍向$n的$l，好一招「马革裹尸」",
                "dodge":                -10,
		"parry":		0,
                "damage":               25,
                "damage_type":  	"砍伤",
		"dodge_msg":
"$n「吱吱」尖叫数声，双脚一点，从$N头顶翻了过去。\n",
		"dodge_power":		10,
		"parry_msg":
"$n原地不动，身子如陀螺般疾转。$N虽然命中，却被$n卸去劲力。\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "行尸走肉",
                "action":
"$N门户大开，就象丧失了神志一般，自身跟着手中的$w向$n扑去。\n"
"这招「行尸走肉」虽然凶险，但威力奇大，逼的$n连连倒退",
                "dodge":                10,
		"parry":		10,
                "damage":               40,
                "damage_type":  	"砍伤",
		"dodge_msg":
"$n忙用一招「行尸走肉」，膝盖不弯，硬梆梆地连蹦数下，居然避过了$N的招数。\n",
		"dodge_power":		10,
		"parry_msg":
"$n眼见招来，竟然不避不让，以身相迎。只听「噗」地一声，\n"
"$N的进攻如中败竹，居然对$n毫无影响。\n",
		"parry_power":		10,
        ]),
});


int valid_learn(object me)
{
        object ob;

	if(me->query("family/family_name") != "陷空山无底洞")
		return notify_fail("你不习惯血腥，学不了枯骨刀！\n");
        if( (int)me->query("max_force") < 350 )
                return notify_fail("你的内力不够，不能学枯骨刀法，多练些内力再来吧。\n");

	if ((int)me->query_skill("kugu-blade")>=me->query("wudidong/sell_reward"))
	    return notify_fail("你的枯骨刀已经到了极限，需要更多的血腥来加深修为！\n");
        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能练刀法。\n");
        return 1;
}

int practice_skill(object me)
{
    if (me->query_skill("kugu-blade", 1) < 180)
        return notify_fail("你的修为还不足以练枯骨刀。\n");
    if ( me->query("family/master_id") != "yu shu" )
	return notify_fail("师父还没有教你如何练习枯骨刀的法门。\n");
    if (me->query("kee") < 50)
	return notify_fail("你的体力不足，无法练枯骨刀。\n");
    if (me->query("force") < 50)
	return notify_fail("你的内力太低，无法在纵跃的同时舞刀。\n");
    me->add("kee", -30);
    me->add("force", -30);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="dodge"||usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}
string query_dodge_msg(string limb)
{
	return action[random(sizeof(action))]["dodge_msg"];
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if ((int)me->query_skill("kugu-blade", 1) % 10 == 0 ) {
		tell_object(me, "\n你突然觉得身上缺了点什么东西…\n\n");
		me->add_maximum_force(-2);
	}
}

string perform_action_file(string func)
{
	return CLASS_D("yaomo") + "/wudidong/kugu-blade/"+func;
}
