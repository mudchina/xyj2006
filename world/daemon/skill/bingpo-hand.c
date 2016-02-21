// bingpo-hand.c 冰魄刀
// /daemon/skill/bingpo-hand.c
// writted by mind 2001/2


inherit SKILL;
#include <ansi.h>
mapping *action = ({
([  "action": "$N双掌一错，一招"+HIW"「霜华满地」"NOR+"，狂风般扫向$n的$l",
    "dodge": 30,
    "parry": -10,
    "force": 100,
    "damage_type": "瘀伤",
    "weapon" : "双掌",
]),
([  "action": "$N一招"+HIW"「风雪漫中州」"NOR+"，身形突然旋转起来扑向$n，双掌拍向$n的$l", 
    "dodge": 20,
    "force": 150,
    "parry": 10,
    "damage_type": "瘀伤",
    "weapon" : "双掌",
]),
([  "action": "$N将寒毒运至左手，一招"+HIW"「万里鹅毛雪」"NOR+"，迅疾无比地抓向$n的$l",   
    "dodge": 50,
    "force": 200,
    "parry": -40,
    "damage_type": "抓伤",
    "weapon": "右手五指",
]),
([  "action": "$N后退一步，突然一招"+HIW"「冰封千里」"NOR+"，掌挟奇寒之气拍向$n的$l",   
    "dodge": 60,
    "force": 250,
    "damage_type": "刺伤",
    "weapon": "右手掌",
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }   

mapping query_action(object me)
{
   if (random(me->query_skill("unarmed",1)) > 60 &&
   me->query_skill("force",1) > 50 &&
   me->query("force") > 100 ) {
   me->add("force", -100);
   return ([
   "action": "$N凝神含元，浑身透明，一式"+HIW"『冰魄霜魂』"NOR+"，凌厉无比地击向$n",
   "force": 400,
   "damage_type": "撞伤",
   "weapon": "全身",]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练冰魄刀必须空手。\n");
    
    if ((int)me->query("max_force") < 200)
   return notify_fail("你的内力太弱，无法练冰魄刀");
    return 1;
}


int practice_skill(object me)
{
    if ((int)me->query("kee") < 30)
   return notify_fail("你的体力太低了，先休息一下吧。\n");
    if ((int)me->query("force") < 30)
   return notify_fail("你的内力不够练冰魄刀。\n");
    
   me->receive_damage("kee", 30);
    me->add("force", -20);
    write(HIC"双掌发出冰凌般的寒光。\n"NOR);
    return 1;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("bingpo-hand", 1)  % 10 == 0 ) {
                tell_object(me,
                        HIC "\n你突然觉得心境澄清，杀气内敛....\n\n" NOR);
                me->add("bellicosity", -random( (int)me->query_kar() * 10));
                if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
        }
        if( !me->query("m_success/玄冰烈焰") && (int)me->query_skill("bingpo-hand", 1)>80 && (int)me->query_skill("huoyan-hand", 1)>80){
        me->set_skill("ice_fire_zhang",40);
        me->delete_skill("bingpo-hand");
        me->delete_skill("huoyan-hand");        
                tell_object(me,"你融会了冰魄刀和火焰刀的精意，阴阳贯圆，龙虎交济，顿悟出"+chinese_number(40)+"段玄冰烈焰掌。\n");
                me->set("m_success/玄冰烈焰",1);
                
                }
}

string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/bingpo-hand/" + func;
}
