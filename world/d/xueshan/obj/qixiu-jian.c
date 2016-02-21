
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// qixiu-jian.c, 【七修剑】
// edited 4-16-97 pickle

/*
七修剑法    dodge  5    parry  -10    damage  25
七修剑法为拼命剑法，只求伤敌，不顾自身安危，故其
突防之力颇强。然则往往乱打一气，敌已逃而不觉。
*/

// 五马分尸，六亲不认，七窍生烟，
// 八方风雨，九死一生，十面埋伏

#include <ansi.h>;
inherit SKILL;
void set_busy();

string* skill_head =({
        "$N手腕一抖，使出一招",
        "$N不闪不避，一式",
        "$N纵身跃起，一招",
        "$N身化万千，一式",
        "$N如发狂一般，使出一招",
        "$N一声暴叫，发出一式",
});

string* skill_tail =({
        "，手中$w刺向$n的全身。",
        "，手中$w带起万道银光，向$n的面门点去。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w锋芒直射$n",
        "，看似破绽百出，实则密不可透",
        "，$w带着杀气向$n狂卷而来。",
});

mapping *action = ({
    ([
      "action":
"$N手腕一抖，$w剑尖化为五道白光，分别向$n的咽喉、左右肩、和左右脚腕疾刺",
      "dodge":     0,
      "parry":           0,
      "damage":     30,
      "damage_type":   "刺伤",
      "name":     "「五马分尸」",
      ]),
    ([
      "action":
"$N关节僵硬，手中$w如一根树干一般横竖乱扫。\n"
"$n识得这招「六亲不认」的威力，连忙躲避不迭",
      "dodge":     10,
      "parry":     -20,
      "damage":     40,
      "damage_type":   "割伤",
      "name":     "「六亲不认」",
      ]),
    ([
      "action":
"$N纵身跃起，手中$w带起万道银光，向$n的面门点去。\n"
"这招「七窍生烟」果然把$n逼得手忙脚乱",
      "dodge":     5,
      "parry":          -10,
      "damage":     30,
      "damage_type":   "刺伤",
      "name":      "「七窍生烟」",
//      "post_action":   (:set_busy:),
      ]),
   
    ([
      "action":
"$N奋不顾身，手中$w如狂风暴雨般向$n乱劈！\n"
"这招「八方风雨」虽然露出若干空门，但$n也不敢不顾自身安危而贸然进攻",
      "dodge":     5,
      "parry":           -5,
      "damage":     40,
      "damage_type":   "刺伤",
      "name":      "「八方风雨」",
//      "post_action":   (:set_busy:),
      ]),
    ([
      "action":
"$N连人带剑猛扑向$n的$l。若是这招「九死一生」
击不中$n，$N本人就空门大开，任人宰割了",
      "dodge":     10,
      "parry":           -10,
      "damage":     45,
      "damage_type":   "刺伤",
      "name":      "「九死一生」",
//      "post_action":   (:set_busy:),
      ]),
    ([
      "action":
"$N身随剑走，迅速无伦地在$n周围兜圈。\n"
"$n只见周围无数人影，随时都有可能有一柄$w从意想不到的\n"
"位置刺来，实在是危机重重",
      "dodge":          0,
      "parry":     -15,
      "damage":     35,
      "damage_type":   "刺伤",
      "name":      "「十面埋伏」",
      ]),
  ([ "name": "「妖雾冲天」",
     "action":
MAG"$N身化万千,手中的$w"+MAG"亦幻出千条黑影,直罩$n全身,使$n难辨直假!!\n"
"$n正手忙脚乱间,一道墨光无声无息地直取脑后玉枕穴,$n却木然不觉!"NOR,
     "dodge": -70,
     "damage": 120,
     "force": 50,
     "damage_type": "刺伤",
]),
});

int valid_learn(object me)
{
    object ob;
    
    if (me->query("family/family_name") != "陷空山无底洞")
   return notify_fail("你还未习惯血腥，无法学七修剑。\n");
    if ((int)me->query("max_force") < 100)
   return notify_fail("你的真气不足，难以领悟剑法的精妙之处。\n");
    
    if (!(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
   return notify_fail("你必须先找一把剑才能练剑法。\n");
    
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_qixiu-jian");
i=me->query_action("QXJ_perform");
if(!me->query_temp("QXJ_perform")) {
if(me->query("skill_qixiu-jian")==0)
return action[random(5)];
if(random(2)) return action[random(5)];
return m_actions[random(sizeof(m_actions))];
} else {
return action[6];
}
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if (me->query("family/family_name") != "陷空山无底洞")
   return notify_fail("你还未习惯血腥，无法练七修剑。\n");
    if ((int)me->query("kee") < 30)
   return notify_fail("你的气太低，再练下去会有危险的！\n");
    if ((int)me->query("force") < 5)
   return notify_fail("你的内力不够，没有办法运用七修剑。\n");
    me->receive_damage("kee", 30);
   me->add("force", -5);
    write("你按著所学练了一遍七修剑。\n");
    return 1;
}
void set_busy()
{
    object me=this_player();
    me->start_busy(1);
 }
string perform_action_file(string action)
{
return CLASS_D("yaomo/wudidong") + "/qixiu-jian/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("qixiu-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对七修剑的领悟加深了，你的七修剑进入了一个新的境界！\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对七修剑领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
        return ;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_qixiu-jian");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);
   if(!arg||arg==" ")arg="七修剑绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qixiu-jian",m_actions);
}
