#include <ansi.h>

inherit SKILL;


mapping *action = ({
        ([      "name":                 "无",
                "action":
"$N轻抚手中的$w，突然间只见刀光一闪，再闪，又一闪！
三道刺骨的寒气已然袭上了$n的$l",
     "dodge":     -15,
     "parry":     5,
     "damage":     15,
     "damage_type":     "割伤"
        ]),
        ([      "name":                 "无",
                "action":
"只见$N倒提$w，身形急冲，就在与$n错身之际，
突然反手一刀从$n后脑斜劈而下",
     "dodge":     -15,
     "parry":     5,
                   "damage":                  20,
                  "damage_type":     "劈伤"
        ]),
        ([      "name":                 "无",
                "action":
"$N斜身飞起，带出一片匹练也似的刀光卷向$n的$l",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  15,
                   "damage_type":     "劈伤"
        ]),
        ([      "name":                 "无",
                "action":
"$N突然一脚踢出，手中的$w划出一道轻妙的圆弧，
淡淡的刀光封住了$n的头脸，切断了$n的呼吸",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  20,
                   "damage_type":     "割伤"
        ]),
        ([      "name":                 "无",
                "action":
"只见$N脸色一寒，一招「千里冰封」使出，从眉捷到脚跟，
$n周身的血液都似被这无尽的刀势冻住，而生命也仿佛要离体而去",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  30,
                   "damage_type":     "劈伤"
        ]),   
        ([      "name":                 "无",
                "action":
"$N刀势渐慢，而$w上带出的寒气却越来越浓。
就在这时，$n的心头一紧，一道比针尖还要锐利的寒气已刺上了$n$l",
                  "dodge":                   -15,
     "parry":     5,
                   "damage":                  20,
                   "damage_type":     "刺伤"
        ]),   
        ([      "name":                 "无",
                "action":
"$N也不管三七二十一，高举$w呼！地就是一刀向$n迎面斩下！
虽然只有一刀，可怕的刀势却似万古不化的寒冰封死了$n的一切退路",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  20,
                   "damage_type":     "劈伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练冰魄寒刀，
多练些内力再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        ||      (string)ob->query("material") != "ice" )
                return notify_fail("你必须先找一把冰做的刀才能练冰魄寒刀。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"; //note, should not be able to enable with parry...ice mah:D
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习冰魄寒刀。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍冰魄寒刀。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
    return CLASS_D("yaomo")+"/xueshan/bingpo-blade/"+action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
  object weapon = me->query_temp("weapon");     
  string msg;
       
       if( ( damage_bonus > 250 ) && (userp(me)))
          return 0;
if(me->query("force")<200) return 0;
         if ((string)me->query("family/family_name") != "大雪山" )
             return 0;
 if (me->query_temp("noauto")&&(random(15)!=1)) return 0;
          
        if ((!weapon) ||((string)weapon->query("material") != "ice" ))
                return 0; 
if(damage_bonus<150) damage_bonus= 150;
          
        if (((int)me->query_skill("blade", 1)/2) > random((int)victim->query_skill("force", 1)))
             {
              victim->receive_wound("kee", (300-damage_bonus) );
              msg = HIW
                    "$N默运真气，将冰魄寒刀中寒气逼出，$n一个不察，已被冻伤！\n\n"NOR;
              message_vision(msg,me,victim);
             
             };
                switch(random(3)) {
                        case 0:{ victim->receive_damage("kee",damage_bonus/3*2);
                                 msg = "只见一丝寒气无声无息地钻到$n体内！\n";
                                 break;};
                                
                        case 1:{  victim->receive_damage("kee",damage_bonus/2);
                                  msg = "$N暗使巧力，在$n的伤口上留下一道浅浅的白印！\n";
                                 break;};
                                
                        case 2:{  victim->receive_damage("kee",damage_bonus);
                                 msg ="$n突然觉得体内奇寒难忍...\n";
                                 break;};
                                 
                        }
               
                             message_vision(msg,me,victim);
                return 0;
 }
