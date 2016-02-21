//zhuihun-sword
//lestat 2001 for hell

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int yunwu(object me, object victim, object weapon, int damage);
mapping *action = ({
        ([      "name":                 "群魔乱舞",
                "action":
"$N手中$w一抖，"+HIB"「群魔乱舞」"NOR"使将出来，剑招奇变横生，$n瞧得心惊神眩，不知$N究竟出了多少招",
		"parry":		-10,
                "dodge":                -10,
                "damage":               25,
				"lvl" : 0,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "厉鬼缠身",
                "action":               
"$N$w如云雾变化，正是一招"+HIB"「厉鬼缠身」"NOR"，极尽诡奇之能事，动向无定，不可捉摸，$n觉一阵眼花缭乱，顿感穷於应付",
		"parry":		-10,
                "dodge":                -10,
                "damage":               25,
				"lvl" : 20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "百鬼夜行",
                "action":
"$N舞动$w，一招"+HIB"「百鬼夜行」"NOR",突然一个疾冲，$w挟着闪闪剑光刺向$n的$l",
		"parry":		-20,
                "dodge":                -15,
                "damage":               20,
				"lvl" : 40,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "饿鬼拦路",
                "action":
"$N手中$w一抖，幻出几许银光，就在一恍惚间，这招"+HIB"「饿鬼拦路」"NOR"$w已斜斜地点上了$n的$l",
		"parry":		-20,
                "dodge":                -20,
                "damage":               25,
				"lvl" : 60,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "鬼影幢幢",
                "action":
"$N手上$w慢慢点出，突然间在空中一颤，一招"+HIB"「鬼影幢幢」"NOR",剑刃暗发嗡嗡之声，$w来路如鬼如魅，顷刻间竟然已绕到了$n背后",
		"parry":		-10,
                "dodge":                -20,
                "damage":               15,
				"lvl" : 80,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "秋坟鬼唱",
                "action":
"$N猛然间身形一展，使出"+HIB"「秋坟鬼唱」"NOR"，听$w陡发铮然之音，无数光环乱转，霎时之间已将$n裹在一团剑光之中",
		"parry":		-20,
                "dodge":                -20,
                "damage":               20,
				"lvl" : 100,
                "damage_type":  "刺伤"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练追魂剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        string *msg1,*msg2;
        msg1 = ({
		HIB"$N手中$w"+HIB"连连挥舞，声东击西，虚虚实实，幻人耳目，变化古怪之极，$n不禁心下骇然！"NOR,
		HIB"$N手中$w"+HIB"越使越快，一套"+HIR"「歌舞阎罗」"+HIB"有如云卷雾涌，$n不由得目为之眩！"NOR,
		HIB"只见$N手上$w"+HIB"剑招变幻，犹如鬼魅，五花八门，层出不穷，$n觉眼前尽是一片剑光飞舞来去！"NOR,
        });
        msg2 = ({
		HIR"但见一点点鲜血从$w"+HIR"下溅了出来，$n腾挪闪跃，竭力招架，始终脱不出$N的剑光笼罩，鲜血渐渐在身周溅成了一个红圈，$N又已刺出一剑！"NOR,
		HIW"$N一剑既占先机，後着绵绵而至，一柄$w"+HIW"犹如灵蛇，颤动不绝，在$n的攻势中穿来插去，只逼得$n连连倒退！"NOR,
		HIW"$n中了一剑，大骇之下，急向後退，$N手中$w"+HIW"已如狂风骤雨般连攻，当真是兔起鹘落，变化快极！"NOR,

        });
	if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("force", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "dodge" : -50,
        "parry" : -50,
        "damage" : 70,
        "force" : 100,
        "damage_type":"刺伤"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("force", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "dodge" : -60,
        "parry" : -60,
        "damage" : 80,
        "force" : 120,
	"post_action": (: yunwu :),	
        "damage_type":"刺伤"]);
        }

/*
        level   = (int) me->query_skill("zhuihun-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];*/
		return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return notify_fail("你的内力或气不够，没有办法练习追魂剑。\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
//        write("你按着所学练了一遍追魂剑法。\n");
        return 1;
}


int yunwu(object me, object victim, object weapon, int damage)
{

string msg,str; 
        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
        message_vision(HIR"\n见$n伤口中一道血箭如涌泉般向上喷出，原来$p中剑后内力未消，将鲜血逼得从伤口中急喷而出，既诡异，又可怖。\n" NOR, me,victim);
		me->delete_temp("yunwu");
str=victim->name()+HIM"被"+me->name()+"用幽冥绝学"NOR+HIB"「歌舞阎罗」"+HIM"刺死了，据说"+victim->name()+"的尸体满身剑孔！";
message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
                return 1;
	   }
	else{
	me->add("force", -30);
        victim->receive_damage("kee", random(20));
	me->set_temp("yunwu_hit", 1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

	}
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zhuihun-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 100);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/zhuihun-sword/" + func;
}



