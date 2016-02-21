// ice_fire_zhang.c 玄冰烈焰掌
// /daemon/skill/ice_fire_zhang.c
// writted by mind 2001/2
#include <ansi.h>
inherit SKILL;



mapping *action = ({
([      "action" : "$N一式"+HIC"「卷起千堆雪」"NOR+"，双掌大开大合，直向$n的$l击去",
        "dodge": -10,
        "parry": -10,
        "force": 100,
        "damage_type" : "瘀伤",
        "weapon" : "双掌",
]),
([      "action" : "$N身形一变，一式"+HIC"「独钓寒江雪」"NOR+"，双掌似曲似直，拍向$n的$l",
        "dodge": 0,
        "parry": -20,
        "force": 150,
        "damage_type" : "瘀伤",
        "weapon" : "双掌",
]),
([      "action" : "$N使一式"+HIC"「春雪缠绵入梦来」"NOR+"，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
        "dodge": 10,
        "parry": -30,
        "force": 200,
        "damage_type": "刺伤",
        "weapon": "右手掌",
]),
([      "action" : "$N两掌一分，一式"+HIR"「九阳熔熔照沧海」"NOR+"，隐隐发出龙吟，向$n横击过去",
        "dodge": -10,
        "parry": -20,
        "force": 120,
        "damage_type" : "砸伤",
        "weapon" : "双掌",
]),
([      "action" : "$N身形一转，使出一式"+HIR"「如日中天」"NOR+"，只见漫天掌影罩住了$n的全身",
        "dodge": 0,
        "parry": -30,
        "force": 170,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N突然身形一缓，使出一式"+HIR"「非枯非荣」"NOR+"，左掌凝重，右掌轻盈，击往$n的$l",
        "dodge": 10,
        "parry": -40,
        "force": 220,
        "damage_type": "刺伤",
        "weapon": "右手掌",
]),
([      "action" : "$N使一式"+HIC"「风雪凭临江山娇」"NOR+"，双掌挟狂风暴雪之势，猛地劈向$n的$l",
        "dodge": 40,
        "parry": -10,
        "force": 250,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招"+HIC"「玄霜凝梅意阑珊」"NOR+"，双掌带着萧瑟的寒气，拍向$n的$l",
        "dodge": 60,
        "parry": -50,
        "force": 300,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N身法陡然一变，使出一式"+HIR"「凤凰涅磐」"NOR+"，掌影千变万幻，令$n无法躲闪",
        "dodge": 50,
        "parry": -60,
        "force": 300,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N清啸一声，左掌一式"+HIC"「冰魄刀」"NOR+"，右手招展"+HIR"「火焰刀」"NOR+"，两股截然不同的气劲击向$n的$l",
        "dodge": 0,
        "parry": 0,
        "force": 500,
        "damage_type" : "瘀伤",
])
});

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry" ;
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练玄冰烈焰掌必须空手。\n");
    
    if ((int)me->query("max_force") < 400)
   return notify_fail("你的内力太弱，无法练玄冰烈焰掌");
        if( (string)me->query_skill_mapped("force")!= "butian-force")
                return notify_fail("你的内功心法不对无法练习。\n");
    return 1;
}


mapping query_action(object me, object weapon)
{
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee")<30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 40)
                return notify_fail("你的内力不够练玄冰烈焰掌。\n");
        me->receive_damage("kee",30);
        me->add("force",-30);
        write(HIW"浑身忽青忽红，闪烁不停。\n"NOR);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int force;
        if( random(me->query_skill("ice_fire_zhang")) > 20 )
        victim->apply_condition("ice_fire_poison", random(me->query_skill("ice_fire_zhang")/10) + 1 + victim->query_condition("ice_fire_poison"));
        if( damage_bonus >60 ) {
        if( random(damage_bonus/2) > (victim->query_str()/2)) {
                victim->receive_wound("kee", (damage_bonus - 60) / 4 );
                switch(random(3)) {
                        case 0: return HIR"$n的$l被$N催动的火焰刀烧得血肉模糊！\n"NOR;
                        case 1: return HIC"$N寒劲一催，一道凛冽劲气击中$n的$l！\n"NOR;
                        case 2: return HIG"$N左手冰魄刀，右手火焰刀，两道截然不同的内劲全在$n体内爆发！\n"NOR;
                }
        }
        }
        if( random(3*(me->query_skill("ice_fire_zhang"))) > 2*damage_bonus)
        {
                        victim->receive_wound("kee", (damage_bonus - 50));
                        victim->receive_wound("sen", (damage_bonus - 50));
                        force = victim->query("force");
//                        victim->set("force", force-random(10)-1);
//                        victim->set("max_force", 0);
                        return
HIB"$n觉得浑身空荡荡的，元神涣散，顶上三花黯然无光！\n"NOR;
        }
}

string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/ice_fire_zhang/" + func;
}

void skill_improved(object me)
{
        if( (string)me->query("family/family_name")!="三界散仙")
        {
                tell_object(me,
                        HIW "\n你控制不住体内的寒毒和业火，气息一窒走火入魔了！！....\n\n" NOR);
                me->skill_death_penalty();
                me->delete_skill("ice_fire_zhang");
                me->unconcious();
        } 
}

