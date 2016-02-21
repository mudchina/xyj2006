//无私锏法，wusi-mace.c
//created 5-12-97 pickle
  
/*
无私锏法    dodge  5    parry  -5    damage  25
原名秦家无敌锏，为秦家祖传秘技，后秦琼决定公开传给
大唐官兵，皇上感其无私，赐名无私锏法。此锏法相当实
用，上阵杀敌，势如破竹。
*/

// 呕心，沥血，捕风，捉影，
// 追魂，夺命，杀手，无情。

inherit SKILL;

mapping *action = ({
  ([
    "name":		"呕心锏",
    "action":
"$N挺起手中$w，朝$n的前心猛插下去。这招「呕心锏」毫无花巧，但威力惊人",
    "dodge":		5,
    "parry":		-5,
    "damage":		35,
    "damage_type":  "戳伤"
   ]),
  ([
    "name":		"沥血锏",
    "action":
"$N挥起$w，朝$n的后心猛砸。这招「沥血锏」若是打中了，$n定会呕血数升",
    "dodge":		15,
    "parry":		-10,
    "damage":		30,
    "damage_type":  "震伤"
   ]),
  ([
    "name":		"捕风锏",
    "action":
"$N运起轻功在$n周围疾速转圈，身上的衣服带起阵阵轻风。\n"
"正当$n眼花缭乱之际，$N挺起手中$w向$n的$l打去",
    "dodge":		-10,
    "parry":		0,
    "damage":		15,
    "damage_type":  "震伤"
   ]),
  ([
    "name":		"捉影锏",
    "action":
"$N跟在$n背后，有如影子一般，锏锏不离$n后心。\n"
"这势「捉影锏」果然把$n逼得手忙脚乱",
    "dodge":		5,
    "parry":		-5,
    "damage":		20,
    "damage_type":  "戳伤"
   ]),   
  ([
    "name":		"追魂锏",
    "action":
"$N运足内力一声巨吼，惊得$n魂飞魄散。\n"
"趁此良机，$N挥起$w向$n的$l猛砸",
    "dodge":		10,
    "parry":		-5,
    "damage":		25,
    "damage_type":  "砸伤"
   ]),   
  ([
    "name":		"夺命锏",
    "action":
"$N以左手掌力牵制住$n，右手$w猛地向$n的头部横扫！\n"
"若是这势「夺命锏」打实了，$n定无幸免之理",
    "dodge":		5,
    "parry":		-5,
    "damage":		25,
    "damage_type":  "撞伤"
   ]),   
  ([
    "name":		"无情锏",
    "action":
"$N战得兴起，索性挥起$w向四面八方各打一锏。\n"
"这招「无情锏」使开来，五尺之内，不论敌友，尽皆笼罩在劲风中",
    "dodge":		5,
    "parry":		5,
    "damage":		15,
    "damage_type":  "砸伤"
   ]),   
  ([
    "name":		"杀手锏",
    "action":
"$N跃起数尺，居高临下，一锏向$n当头砸下。\n"
"这招「杀手锏」乃是秦家无私锏中的绝招，果然气势威猛",
    "dodge":		5,
    "parry":		-15,
    "damage":		35,
    "damage_type":  "砸伤"
   ]),
});


int valid_learn(object me)
{
  object ob;
  
  if( (int)me->query("max_force") < 150 )
    return notify_fail("你的内力不够，不能学无私锏法， 多练些内力再来吧。\n");
  if (!(ob = me->query_temp("weapon"))
      ||      (string)ob->query("skill_type") != "mace" )
    return notify_fail("你必须先找一柄锏才能练锏法。\n");
  
  return 1;
}

int practice_skill(object me)
{
  string myforce=me->query_skill_mapped("force");
  if (myforce != "lengquan-force")
    return notify_fail("无私锏需配合将军府冷泉神功才可发挥威力。\n");
  if ((int)me->query("kee") < 35)
    return notify_fail("你体质欠佳，强练锏法有害无益。\n");
  if ((int)me->query("force") < 5)
    return notify_fail("你内力不足，强练无私锏有走火入魔的危险。\n");
  me->receive_damage("kee", 30);
  me->add("force", -5);
  message_vision("$N运起内力练了一套无私锏法。\n", me);
  return 1;
}

int valid_enable(string usage)
{
  return usage=="mace"||usage=="parry";
}
string perform_action_file(string func)
{
return CLASS_D("fighter") + "/wusi-mace/" + func;
}

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}










