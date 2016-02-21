//百鸟剑法
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N一招",
        "只见$N纵身轻轻跃起,一招",
        "$N使出",
        "$N飘然而进，一式",
        "$N纵身轻轻跃起,剑光如轮急转，一招",
        "$N按剑而发，一招",
});

string* skill_tail =({
        "，手中$w嗡嗡作响,幻成一道白光直刺$n的$l",
        "，$w发出一声清响,剑意若有若无,直取$n的$l",
        "，剑光如轮急转,晃得$n头晕目眩",
        "，手中$w虚幻不定地出现在$n周围.",
        "，剑光如水，洒向$n全身。",
        "，手中$w如正如百鸟之王一样傲视群雄。",
});

mapping *action = ({
   ([  "action": "$N一招「大鹏展翅」,手中$w嗡嗡作响,幻成一道白光直刺$n的$l",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "刺伤"
   ]),
([ "action":"只见$N纵身轻轻跃起,一招「鹰击长空」,剑光如水,一泄千里,洒向$n全身",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N飘然而进,手中$w微微震颤,刹那间连出九剑,分刺$w全身九个部位,正是一招「凤舞九天」.\n",
     "dodge":     0,
     "damage": 35,
     "damage_type":   "割伤"
   ]),
   ([ "action":
"$N中指轻弹剑锋,$w发出一声清响,剑意若有若无,直取$n的$l,却是一招「雄鸡报晓」.\n",
     "dodge":     0,
     "damage": 45,
     "damage_type":   "刺伤"
   ]),
  ([  "action":      
 "$N一招「鹤立云端」,剑尖划出无数圆圈,狂风骤起,笼罩天地.\n",
     "dodge":     0,
     "damage": 40,
     "damage_type":   "刺伤"
   ]),
  ([   "action": 
"$N手中$w自左而右地划了一个大弧,平平刺向$n的$l,正是百鸟剑法之「鸿飞天外」.\n",
     "dodge":     0,
     "damage":     50,
     "damage_type":   "刺伤"
   ]),
  ([ "action": 
"$N一式「杜鹃啼血」,手中$w急转,化为一道血光,虚幻不定地出现在$n周围.\n",
     "dodge":     0,
     "damage":     30,
     "damage_type":   "刺伤"
   ]),
   ([ "action": 
"$N纵身轻轻跃起,剑光如轮急转,晃得$n头晕目眩,正是一招「燕语报春」.\n",
     "dodge":     0,
     "damage":     35,
     "damage_type":   "割伤"
   ]),
   ([ "action": "$N一声清啸,身形拔地而起,接着一招「鹤影寒塘」,剑光直洒$n头部",
      "dodge": 0,
      "damage": 50,
      "damage_type": "刺伤"
]),
 ([ "action":
 "$N手中$w一抖,忽地散出十余道五色霞光,罩住了$n全身,正是一招「孔雀开屏」",
     "dodge": 0,
     "damage": 35,
    "damage_type": "割伤"
]),
([ "action": "$N一招「鹦鹉学舌」,手中$w从一个意想不到的方位直刺$n的右胸",
    "dodge": 0,
    "damage": 45,
    "damage_type": "刺伤"
]),
(["action":
 "$N手中$w一振,忽地分出一道幻影,两道剑光同时游往$n左肩,正是「鸳鸯戏水」",
  "dodge": 0,
  "damage": 50,
  "damage_type": "刺伤"
]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("你的内力不够,没有办法练百鸟剑法.\n");

   if( (string)me->query_skill_mapped("force")!= "ningxie-force")
     return notify_fail("百鸟剑法必须配合冰谷凝血功才能练.\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry"|| usage=="throwing";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_birds-sword");
     if(me->query("skill_birds-sword")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
    return notify_fail("你的内力或气不够,没有办法练习百鸟剑法.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
  write("你按着所学练了一遍百鸟剑法.\n");
   return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("yaomo/xueshan") + "/birds-sword/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("birds-sword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对百鸟剑法的领悟加深了，你的风百鸟剑法进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没
有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对风回雪舞剑领悟出了一招新的用法！\n"NOR
);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_birds-sword");
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

   if(!arg||arg==" ")arg="百鸟剑法必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_birds-sword",m_actions);
}
 
