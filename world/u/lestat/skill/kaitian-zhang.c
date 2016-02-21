//昆仑掌法
//lestat modi for kunlun 2001
#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit SKILL;
string *xue_name = ({ 
HIR"劳宫穴"NOR,HIR"膻中穴"NOR,HIR"曲池穴"NOR,
HIG"关元穴"NOR,HIG"曲骨穴"NOR,HIG"中极穴"NOR,
HIY"承浆穴"NOR,HIY"天突穴"NOR,HIY"百会穴"NOR,
HIM"幽门穴"NOR,HIM"章门穴"NOR,HIM"大横穴"NOR,
HIW"紫宫穴"NOR,HIW"冷渊穴"NOR,HIW"天井穴"NOR,
HIC"极泉穴"NOR,HIC"清灵穴"NOR,HIC"至阳穴"NOR,}); 

mapping *action = ({
([      "action" : "$N一式"HIW"「风火之功起在空」"NOR"，双掌间升起一团淡淡的白雾，缓缓推向$n的$l",
        "dodge" : -30,
        "parry" : -25,
        "force" : 180,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N并掌如剑，一式"HIW"「遍游天下任西东」"NOR"，疾向$n的$l戳去",
        "dodge" : -30,
        "parry" : -25,
        "force" : 180,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式"HIW"「乾坤顷刻须臾到」"NOR"，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
        "dodge" : -30,
        "parry" : -25,
        "force" : 190,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双掌隐隐泛出青气，一式"HIW"「妙理玄功自不同」"NOR"，幻成漫天碧绿的松针，雨点般向$n击去",
        "dodge" : -30,
        "parry" : -25,
        "force" : 200,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形往上一纵，使出一式"HIW"「杀气震乾坤」"NOR"，双掌并拢，笔直地向$n的$l插去",
        "dodge" : -30,
        "parry" : -25,
        "force" : 160,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形一变，使一式"HIW"「细细微微播土尘」"NOR"，双掌带着萧刹的劲气，猛地击往$n的$l",
        "dodge" : -30,
        "parry" : -25,
        "force" : 180,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式"HIW"「无形过树透荆榛」"NOR"，左掌凝重，右掌轻盈，同时向$n的$l击去",
        "dodge" : -30,
        "parry" : -25,
        "force" : 220,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N突地一招"HIW"「麟生雾彩映金光」"NOR"，双掌挟着一阵风雷之势，猛地劈往$n的$l",
        "dodge" : -30,
        "parry" : -25,
        "force" : 200,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式"HIW"「大地乾坤顷刻至」"NOR"，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
        "dodge" : -30,
        "parry" : -25,
        "force" : 210,
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式"HIW"「满院梨花飞瑞雪」"NOR"，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪",
        "dodge" : -30,
        "parry" : -25,
        "force" : 180,
        "damage_type" : "瘀伤"
])
});
mapping *action_baigu = ({
([  "action" : HIW"$N身形微晃，一招"+NOR+BLU"「风云湖海昔犹龙」"+NOR+HIW"，十指如戟，插向$n的"+NOR+xue_name[random(sizeof(xue_name))],
    "force" : 100,
    "dodge" : -10,
    "damage_type" : "内伤",
    "parry" : -20,
    "skill_name" : "风云湖海昔犹龙" ,
]),
([  "action" : HIW"$N出手如风，十指微微抖动，一招"+NOR+HIR"「经卷蒲团笑人生」"+NOR+HIW"抓向$n的"+NOR+xue_name[random(sizeof(xue_name))],  
    "force" : 150,
    "dodge" : -20,
    "damage_type" : "内伤",
    "parry" : -20,
    "skill_name" : "经卷蒲团笑人生" ,
]),
([  "action" : HIW"$N双手忽隐忽现，一招"+NOR+CYN"「傀儡登场皆作戏」"+NOR+HIW"，鬼魅般地抓向$n的"+NOR+xue_name[random(sizeof(xue_name))],  
    "force" : 150,
    "dodge" : -10,
    "damage_type" : "内伤",
    "parry" : -5,
    "skill_name" : "傀儡登场皆作戏" ,
]),
([  "action" : HIW"$N左手当胸画弧，右手疾出，一招"+NOR+HIC"「个中谁是主人公」"+NOR+HIW"，猛地抓向$n的"+NOR+xue_name[random(sizeof(xue_name))],
    "force" : 150,
    "dodge" : -10,
    "damage_type" : "内伤",
    "parry" : -10,
    "skill_name" : "个中谁是主人公" ,
]),
([  "action" : HIW"$N使一招"+NOR+HIB"「一方正后方方正」"+NOR+HIW"，激起漫天的劲风，撞向$n"NOR,
    "force" : 200,
    "dodge" : -10,
    "damage_type" : "内伤",
    "parry" : -10,
    "skill_name" : "一方正后方方正" ,
]),
([  "action" : HIW"$N面无表情，双臂忽左忽右地疾挥，使出"+NOR+HIB"「初步迷时步步迷」"+NOR+HIW"，十指    
忽伸忽缩，迅猛无比地袭向$n全身各处大穴"NOR,
    "force" : 150,
    "dodge" : -20,
    "damage_type" : "内伤",
    "parry" : -10,
    "skill_name" : "初步迷时步步迷" ,
]),
([  "action" : CYN"$N使出"+NOR+YEL"「净不须禅禅须净」"+NOR+CYN"，蓦然游身而上，绕着$n疾转数圈，$n正眼  
花缭乱间，$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的"+NOR+xue_name[random(sizeof(xue_name))],  
    "force" : 150,
    "dodge" : -5,
    "damage_type" : "内伤",
    "parry" : -10,
    "skill_name" : "净不须禅禅须净" ,
]),
([  "action" : CYN"$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手    
收回胸前，接着一招"+NOR+HIW"「未能知有岂知空」"+NOR+CYN"，五指如钩，直抓向$n的"+NOR+xue_name[random(sizeof(xue_name))],
    "force" : 100,
    "dodge" : -10,
    "damage_type" : "内伤",
    "parry" : -20,
    "skill_name" : "未能知有岂知空" ,
]),
});
int valid_enable(string usage) { return usage=="unarmed" ; }

mapping query_action(object me, object weapon)
{
        mapping my;
        my = me->query_entire_dbase();
 if(me->query_temp("BAIGU_perform") )
  {
 return action_baigu[random(sizeof(action_baigu))];
        }
 else{  
 return action[random(sizeof(action))];}
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练混沌开天掌必须空手。\n");
        if ((int)me->query_skill("xuanzong-force", 1) < 20)
                return notify_fail("你的玄宗心法火候不够，无法学混沌开天掌。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练混沌开天掌。\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 40)
                return notify_fail("你的内力不够练混沌开天掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str()/10) {
                victim->receive_wound("kee", (damage_bonus - 50) / 5 );
                switch(random(3)) {
                        case 0: return HIB"你听到「喀啦」一声轻响，竟似是骨碎的声音！\n"NOR;
                        case 1: return HIB"$N劲力一吐，$n的$l发出「喀」地一声爆响！\n"NOR;
                        case 2: return HIB"只听见$n的$l「喀」地一声 ...\n"NOR;
                }
        }
}
string perform_action_file(string action)
{
        return CLASS_D("kunlun") +"/kaitian-zhang/" + action;
}


