// spysword. 【刺客剑法】
// /daemon/skill/spysword.c
// writted by mind 2001/2

#include <ansi.h>
inherit SKILL;

mapping *action = ({
      ([        "action":
"$N一声长叹，$w轻点一招"+HIG"「醉拍春衫惜旧香」"NOR+"向着$n的$l疾刺而去",

                 "dodge": -35,
                 "parry": -5,
                 "damage": 60,
                 "damage_type": "刺伤"
       ]),
        ([      "action":
"$N紧缩眉头，心中似有很深的怨气$w一闪而隐，一招"+MAG"「天将离恨恼梳狂」"NOR+"刺向$n的$l",
 
                 "dodge": 50,
                "parry" : 100,
                 "damage": 55,
                "damage_type": "刺伤"
         ]),
         ([      "action":
"$N仰天不语，脸上掠过一丝忧愁，$w暂缓，一招"+HIC"「有所思」"NOR+
"遥遥刺向$n的$l",

                "dodge": 0,
                "parry": -5,
                "damage": 70,
                "damage_type": "刺伤"
          ]),
          ([      "action":
"$N怔怔而望，若有所思,忽然变招，\n"
"蓦然有骤风席卷，剑招凌烈撒向$n的$l,好一招"+RED"「怒剑狂花」"NOR,

                "dodge": 30,
                "parry": -30,
                "damage": 50,
                 "damage_type": "刺伤"
           ]),
           ([      "action":
"$N衣袂飞舞，身形舒缓如舞，轻歌曼妙\n"
"一招"+MAG"「云渺渺，水茫茫」"NOR+"，$w划向$n的$l",
 
                  "damage": 80,
                 "dodge": -40,
                "parry": 0,
                 "damage_type": "割伤"
           ]),
           ([      "action":
"$N微闭双目，一股落寞的神情布于脸上，剑意凝重,空气顿时压力大增\n"
"一招"+BLU"「寂寞浪子青衫湿」"NOR+"飞刺$n的$l",
                  "dodge": 50,
                "parry": -50,
                  "damage": 60,
                  "damage_type": "刺伤"
           ]),
           ([      "action":
"$N斜倚长剑，轻啸而歌却充满了枯涩的意味，$w自肋下翻刺而出\n"
"一招"+HIM"「相思本是无凭语」"NOR+"刺向$n的$l",
                   "dodge": 0,
                "parry": -15,
                   "damage": 65,
                   "damage_type": "刺伤"
             ]),
             ([      "action":
"$N缓缓摇头，双目中似有泪光闪动$w辉映着苍白的光芒"
"若隐若现的闪现而出,一招"+YEL"「莫向花笺费泪行」"NOR+"刺向$n的$l",
                  "dodge": 40,
                "parry": -5,
                  "damage": 80,
                  "damage_type": "刺伤"
              ]),
              (["action":               HIW"$N手中的$w在一弹指间已向$n的$l连刺数剑",NOR
                "dodge":                30,
                "parry" :               -80,
                "damage" :              50,
                "damage_type":  "刺伤"
                ]),
                (["action":             HIW"$N身形一转，手中的$w从左肋下向$n的$l戳了过去",NOR
                "dodge":                50,
                "parry" :               0,
                "damage":               70,
                "damage_type":  "刺伤"
                ]),
                (["action":             HIW"$N手腕一抖，$w挟著闪闪剑光逼向$n的$l",NOR
                "dodge":                40,
                "parry" :               -30,
                "damage" :              50,
                "damage_type":  "刺伤"
                ]),
                (["action":             HIW"$N身形一矮，手中的$w由下往上刺向$n的$l",NOR
                "dodge":                -40,
                "parry" :               -80,
                "damage":               80,
                "damage_type":  "刺伤"
                ]),
                (["action":             HIW"$N手中$w剑光暴长，如千年蛇蝎往$n$l咬去",NOR
                "dodge":                60,
                "parry" :               -40,
                "damage":               100,
                "damage_type":  "刺伤"
                ]),
                (["action":             HIW"$N手中的$w以无法形容的速度直射$n的$l",NOR
                "dodge":                20,
                "parry" :               -30,
                "damage":               50,
                "damage_type":  "刺伤"
                ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
        return notify_fail("你的内力不够，没有办法练刺客剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     int i;
        i=me->query("dunnoname");
        if( !me->query("dunnoname") ) {
     mapping* m_actions;
     m_actions=me->query("skill_spysword");
     if(me->query("skill_spysword")==0 )
     return action[random(7)];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
        
        return action[random(7)];
        }else {
        return action[i];
        }
     
     
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习刺客剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
          write("你按著所学练了一遍刺客剑法。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/spysword/" + func;
}


