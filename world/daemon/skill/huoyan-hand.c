// huoyan-hand.c 火焰刀
// /daemon/skill/huoyan-hand.c
// writted by mind 2001/2

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N使出一招"+HIR"「钻木取火」"NOR+"，飞身急转，双掌向前平平拍向$n",
        "skill_name" : "钻木取火",
        "force" : 100,
        "dodge":                -10,
        "parry":                -10,
        "damage_type" : "瘀伤",
        "weapon" :              "双掌",
]),
([      "action" : "$N使出一招"+HIR"「祝融怀焰」"NOR+"，手掌如刀，斜斜劈向$n的$l",
        "skill_name" : "祝融怀焰",
        "force" : 120,
        "dodge":                -10,
        "parry":                -20,
        "damage_type" : "瘀伤",
        "weapon":               "右手掌",
]),
([      "action" : "$N使出一招"+HIR"「业火无边」"NOR+"，双掌一拍，一道内力自掌中攻向$n的$l",
        "skill_name" : "业火无边",
        "force" : 140,
        "dodge":                0,
        "parry":                -30,
        "damage_type" : "瘀伤",
        "weapon" :              "双掌",
]),
([      "action" : "$N使出一招"+HIR"「六道轮回」"NOR+"，双手合十，当头劈向$n",
        "skill_name" : "六道轮回",
        "force" : 160,
        "dodge":        -30,
        "parry":        10,
        "damage_type" : "瘀伤",
        "weapon" :              "双掌",
]),
([      "action" : "$N使出一招"+HIR"「双龙吐焰」"NOR+"，双掌一错，两道内力交叉攻向$n的$l",
        "skill_name" : "双龙吐焰",
        "force" : 180,
        "dodge":                10,
        "parry":                -30,
        "damage_type" : "内伤",
        "weapon":               "劲气",
]),
([      "action" : "$N使出一招"+HIR"「刀山火海」"NOR+"，双掌向下斜拍，顿时万千道内力从四面八方攻向$n",
        "skill_name" : "刀山火海",
        "force" : 200,
        "dodge":                -40,
        "parry":                -40,
        "damage_type" : "瘀伤",
        "weapon" :              "双掌",
]),
([      "action" : "$N使出一招"+HIR"「惊焰烈浪」"NOR+"，左臂回收，右掌引内力直刺$n的$l",
        "skill_name" : "惊焰烈浪",
        "force" : 220,
        "dodge":                0,
        "parry":                20,
        "damage_type" : "瘀伤",
        "weapon":               "右手掌",
]),
([      "action" : "$N使出一招"+HIR"「火内莲花」"NOR+"，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n",
        "skill_name" : "火内莲花",
        "force" : 250,
        "dodge":                20,
        "parry":                -50,
        "damage_type" : "内伤",
        "weapon":               "劲气",
]),
});


int valid_enable(string usage)
{
        return usage=="unarmed";
}


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");

        if ((int)me->query("max_force") < 200)  
                return notify_fail("你的内力不够。\n");

                return 1;
}



mapping query_action(object me, object weapon)
{
   if (random(me->query_skill("unarmed",1)) > 60 &&
   me->query_skill("force",1) > 60 &&
   me->query("force") > 100 ) {
   me->add("force", -100);
   return ([
   "action": "$N奋起全身之力，一招"+HIR"『焚心以火』"NOR+"，凌厉无比地击向$n",
   "force": 400,
   "damage_type": "瘀伤",]);
    }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");
        if ((int)me->query("sen") < 40)
                return notify_fail("你的体力不够，练不了火焰刀。\n");
        if( (int)me->query("force") < 40 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("sen", 30);
        me->add("force", -20);
        write(RED"双掌赤红，细细火焰绕指缠臂而上。\n"NOR);
        return 1;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("huoyan-hand", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 50);
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
return CLASS_D("sanxian") + "/huoyan-hand/" + func;
}
