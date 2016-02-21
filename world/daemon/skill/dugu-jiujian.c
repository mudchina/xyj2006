//Cracked by Roath

// dugu-jiujian.c 独孤九剑

inherit SKILL;
/*
string *parry_msg = ({
        "却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
                "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
                "$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
                "$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n",
        "$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
                "$n突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！\n"
                "$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
                "只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地挡住了$P的\n进攻。\n",
                "$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招\n",
});*/

mapping *action = ({
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「天柱云气」\n及「雁回祝融」衡山五神剑！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的是这十九\n剑便如一招，手法之快，直是匪夷所思！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山\n剑势击向$n的$l！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「泰山十八盘」\n为一剑攻向$n！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中途，突然转\n向，大出$n意料之外！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑式有如云\n卷雾涌，旁观者不由得目为之眩！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地\n缠向$n！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩剑」的剑意\n表露无遗！",
        "damage" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招！",
        "damage": 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏魔剑」\n的「龙吞式」。",
        "damage" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好！",
        "damage": 45,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫得$n不得不守！",
        "damage": 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n难以看清\n剑招来势！",
        "damage": 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式。",
        "damage": 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议！",
        "damage": 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l！",
        "damage": 45,
        "damage_type" : "刺伤"
]),
([
    "action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！",
        "damage": 45,
        "damage_type" : "刺伤"
])
});


int valid_enable(string usage)
{
        return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 1000)
                return notify_fail("你的内力不够。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query_skill("dugu-jiujian",1) <50)
        return notify_fail("你的独孤九剑还不够火候(需要50)，还是老实学学吧。\n");
        if (me->query_skill("dugu-jiujian",1) >149 && me->query_int() < 50)
        return notify_fail("练独孤九剑要很高的悟性，还是跟师傅学吧。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan")+"/dugu-jiujian/" + action;
}