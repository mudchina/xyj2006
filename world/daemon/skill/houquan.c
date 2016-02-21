//Cracked by Roath
// houquan.c 猴拳

inherit SKILL;

mapping *action = ({
([  "action" : "\n$N单腿微曲，忽的向前扑出，一式「仙猴摘桃」，二爪直出，抓向$n的
脑袋！\n",
        "force" : 100,
        "dodge" : 5,
        "damage": 10,
        "damage_type" : "抓伤",
        "lvl" : 0,
        "skill_name" : "横空出世"
]),
([      "action" : "$N左手虚晃，一式「灵猴攀枝」，右手直击，反扣$n的肩井大穴",
        "force" : 100,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 8,
        "skill_name" : "灵猴攀枝",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一臂前伸，一臂后指，一式「猿臂轻舒」，攻向$n的两肋",
        "force" : 230,
        "dodge" : 10,
        "damage": 25,
        "lvl" : 15,
        "skill_name" : "猿臂轻舒",
        "damage_type" : "瘀伤"
]),
([      "action" : "\n$N忽然缩成一团，使一式「八方幻影」，双掌无形无定，一爪抓向$n的胸口",
        "force" : 130,
        "dodge" : 25,
        "damage": 20,
        "lvl" : 15,
        "skill_name" : "八方幻影",
        "damage_type" : "内伤"
]),
([      "action" : "$N猛吸一口气，一弯腰，使一式「水中揽月」，双爪疾扣向$n的小腹",
        "force" : 120,
        "dodge" : 15,
        "damage": 10,
        "damage_type" : "瘀伤",
        "lvl" : 20,
        "skill_name" : "水中揽月"
]),
([      "action" : "$N猛的向上高高跃起，一式「落地摘星」，居高临下，一爪罩向$n的头骨",
        "force" : 120,
        "dodge" : 20,
        "damage": 20,
        "damage_type" : "抓伤",
        "lvl" : 30,
        "skill_name" : "落地摘星"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"|| usage=="hand"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练猴拳必须空手。\n");
        return 1;
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
        level = (int)me->query_skill("houquan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 10)
                return notify_fail("你的内力不够练猴拳。\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}
