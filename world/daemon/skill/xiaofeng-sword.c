// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 晓风残月剑，qingyu-sword.c
// created 5-13-97 pickle

/*
晓风残月剑    dodge  -10    parry  0    damage  20
此剑法用意高妙，轻巧潇洒，剑中颇含诗意，多为江湖
年少所喜。
*/

// 皓月当空，水银泄地，花明月暗，清雨朦胧
// 飞花似梦，丝雨如愁，潇湘夜雨，月白风清
// 金波低转

inherit SKILL;
#include <ansi.h>
mapping *action = ({
   ([   "name":        "皓月当空",
     "action":
"$N轻飘飘地纵身跃起，手中$w连续划出几个光环，向$n的$l圈去",
     "dodge":     -15,
     "parry":     10,
     "damage":     20,
     "damage_type":     "割伤"
   ]),
   ([   "name":        "水银泄地",
     "action":
"$N双脚一顿，笔直跃起，手中$w不停地颤抖着，\n"
"笼罩住$n全身。这势「水银泄地」果然是无孔不入",
     "dodge":     -5,
     "parry":     -10,
     "damage":     35,
     "damage_type":     "刺伤"
   ]),
   ([   "name":        "花明月暗",
     "action":
"$N手中$w带起点点寒光，指向$n前胸穴道。$n正专心致志地对付着剑招，\n"
"不料$N左手运力拍向$n的$l。这势「花明月暗」亦真亦幻，实是难防",
     "dodge":     -5,
     "parry":     -5,
     "damage":     45,
     "damage_type":     "震伤"
   ]),
   ([   "name":        "清雨朦胧",
     "action":
"$N在$n四周游走，手中$w去势飘忽不定，只看得$n眼花缭乱。\n"
"趁此良机，$N于朦朦胧胧中一抖$w，向$n的$l疾挑",
     "dodge":     -15,
     "parry":     5,
     "damage":     45,
     "damage_type":     "刺伤"
   ]),
   ([   "name":        "飞花似梦",
     "action":
"激战中，$N从$n面前斜斜跃过，手中$w划出五朵桃花，点向$n的$l",
     "dodge":     -5,
     "parry":     0,
     "damage":     35,
     "damage_type":     "刺伤"
   ]),
   ([   "name":        "丝雨如愁",
     "action":
"$N展开身形，$w之攻势绵绵不绝地缠向$n的$l。\n"
"诗云：无边丝雨细如愁。$N的这招果然深得诗中三味",
     "dodge":     -20,
     "parry":     10,
     "damage":     40,
     "damage_type":     "割伤"
   ]),
   ([   "name":        "潇湘夜雨",
     "action":
"$N仗起手中$w，带出点点寒光，罩住$n的胸腹，只等$n的破绽。\n"
"这招「潇湘夜雨」直如细雨般紧密，$n实在不知$w将要指向自己身上何处",
     "dodge":     -5,
     "parry":     -10,
     "damage":     40,
     "damage_type":     "刺伤"
   ]),
   ([   "name":        "月白风清",
     "action":
"$N手中$w中宫直进，疾速刺向$n的前心。\n"
"这招「月白风清」令人耳目一新。$n只觉浑身一紧，$w已刺到了$l",
     "dodge":     -15,
     "parry":     15,
     "damage":     45,
     "damage_type":     "刺伤"
   ]),
   ([   "name":        "金波低转",
     "action":
"$N手中$w向$n的右手疾刺，但正当$n要招架时，\n"
"$w却突然转向了$n的左足！这招「金波低转」确实神鬼莫测",
     "dodge":     -5,
     "parry":     -15,
     "damage":     45,
     "damage_type":     "刺伤"
   ]),
([ "name": "花前月下",
   "action":
HIC"$N一招「花前月下」,左剑自上而下搏击,模拟冰轮横空,清光铺地的光景.\n"
"右剑却是不住颤动,如鲜花招展风中,来回挥削,只晃得$n眼花撩乱."NOR,
    "dodge": -80,
    "parry": -50,
     "damage": 150,
     "force" : 100,
    "damage_type": "刺伤"
]),
});
int valid_learn(object me)
{
   object ob;
// if( (string)me->query("gender") !="男性")
//  return notify_fail("晓风残月剑只有男子才能学习!!\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力修为不够深，晓风残月剑学了也没用。\n");
   if (!(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一柄剑才能练习剑法。\n");
   return 1;
}

int practice_skill(object me)
{
   int dod=(int)me->query_skill("dodge");
   int swo=(int)me->query_skill("xiaofeng-sword");
//    if( (string)me->query("gender") !="男性")
//   return notify_fail("晓风残月剑只有男子才可以练习!!\n");
if (dod<swo/2)
     return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
   if ((int)me->query("kee") < 30)
     return notify_fail("你体质欠佳，强练晓风残月风剑有害无益。\n");
   if ((int)me->query("force") < 5)
     return notify_fail("你内力不足，强练晓风残月风剑有走火入魔的危险。\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   message_vision("$N默默回忆了一会儿，然后练了一遍晓风残月剑。\n", me);
   return 1;
}

mapping query_action(object me, object weapon)
{
 int i;
 i=me->query_action("XFS_perform");
 if ( ! me->query_temp("XFS_perform")) {
 return action[random(8)];
 } else {
 return action[9];
}
 return action[random(sizeof(action))];
}
int valid_enable(string usage)
{
   return usage=="sword"||usage=="parry";
}

string perform_action_file(string func)
{
return CLASS_D("zhenyuan") + "/xiaofeng-sword/" + func;
}

