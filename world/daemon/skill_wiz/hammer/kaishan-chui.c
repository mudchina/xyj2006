
//【开山锤】kaishan-chui.c, weiqi...980307
inherit SKILL;

/*
开山锤    dodge  7    parry  -7    damage  27
五庄观功夫。
*/

void hitagain(object,object,object,int);

mapping *action = ({
        ([      "action":               "$N哪管三七二十一，举起$w朝着$n当头就是一家伙",
                "dodge":                15,
                "parry":                -10,
                "damage":               35,
                "damage_type":  "砸伤",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "只见$N眼冒凶光，青筋凸起，抄起$w就朝$n的$l狠命扫了过去",
                "dodge":                10,
                "parry":                -15,
                "damage":               25,
                "damage_type":  "砸伤",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "只听轰！地一声$N的$w在地上砸得尘土飞扬！紧接着$N就势翻了个跟头，又是一下向$n砸了过去",
                "dodge":                5,
                "parry":                -10,
                "damage":               35,
                "damage_type":  "砸伤",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "只见$N稍一运气，手中的$w上中下连扫三圈，逼得$n连退不迭",
                "dodge":                5,
                "parry":                0,
                "damage":               20,
                "damage_type":  "砸伤",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "$N使出了一招「五丁开山」，手中的$w举重若轻，势若疯虎地向$n$l连连砸去",
                "dodge":                5,
                "parry":                0,
                "damage":               20,
                "damage_type":  "砸伤",
                "post_action":          (: hitagain :),
        ]),
        ([      "action":               "但见$N一个转身，手中$w由下而上一荡，$n只听一阵风声擦耳而过！\n$n正在暗叫侥幸之时，$N的$w就势一转，又砸了回来",
                "dodge":                5,
                "parry":                -10,
                "damage":               25,
                "damage_type":  "砸伤",
                "post_action":          (: hitagain :),
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("str") < 25 )
                return notify_fail("开山锤要身强力壮才能发挥作用。\n");

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法学开山锤。\n");

        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一把锤子才能学开山锤。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("str") < 25 )
	        return notify_fail("开山锤要身强力壮才能发挥作用。\n");

        if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
                return notify_fail("你现在太累了，强练无益。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍开山锤。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void hitagain(object me, object victim, object weapon,int damage) {
  if (damage!=-2) return;

  //if victim parried out the attack, we attack again...
  
  message_vision("$N震得两臂发麻，动弹不得$n趁机发动攻击！\n",victim,me);
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}

