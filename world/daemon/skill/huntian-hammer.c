
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//【混天锤】??

/*
  dodge  15    parry  -15    damage  30
其锤法直来直去，招招为实，势大力猛，招架抵挡
甚为不易，一但碰上则伤害极大。但不足是不够轻
盈。
*/

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N一招",
        "$N双手一震，发出一招",
        "$N一提气，使出一招",
        "$N一声龙吟长啸，使出",
        "$N使出",
        "$N趁$n防御之际，一招",
});

string* skill_tail =({
        "，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了下来。",
        "，对$n劈头盖脸的砸了下来。",
        "，手中$w斜斜地砸向$n的$l",
        "，手中$w一阵横扫，直逼$n",
        "，直震的$n节节后退。",
        "，手中$w飘渺不定，$n顿时手忙脚乱！",
});
mapping *action = ({
   ([   "action":   "$N手中$w一转，卷着一股强劲的风力挥向$n的$l，
这一下又急又猛，势大力狠，眼见就到了$n身前",
     "dodge":   10,
     "parry":   -10,
     "damage":   30,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N双手一震，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了过去",
     "dodge":   15,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N将$w高举过肩，蓄紧力发，对准$n的$l发出雷霆一击",
     "dodge":   20,
     "parry":   -20,
     "damage":   35,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N身走轻灵，手中$w忽上忽下，令人捉摸不清去路，
就在$n一恍惚间，“唰”地砸向$n的$l",
     "dodge":   0,
     "parry":   -10,
     "damage":   25,
     "damage_type":   "砸伤",
   ]),
   ([   "action":   "$N趁与$n错身之机，倒转$w，锤把戳向了$n，
这一下如白蛇吐芯，悄无声息的点上了$n的$l",
     "dodge":   10,
     "parry":   -10,
     "damage":   20,
     "damage_type":   "戳伤",
   ]),
   ([   "action":   "$N紧握$w猛挥了个大圆，卷的周身长内沙土尘扬，
趁$n不能辨物之记，手中$w斜斜地砸向$n的$l",
     "dodge":   20,
     "parry":   -25,
     "damage":   30,
     "damage_type":   "砸伤",
   ]),
(["action" : "$N一声龙吟长啸,大锤直击$n右肩，此招毫无花巧,但胜在力道雄浑，
相传源自盘古开天时所用的混沌一破。",
    "dodge" : 20,
    "damage" : 200,
    "lvl" : 120,
    "skill_name" : "混天一破",
    "damage_type" : "砸伤"
]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练混天锤。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄大锤才能练混天锤。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_huntian-hammer");
if( !me->query_temp("HTH_perform")) {
if(me->query("skill_huntian-hammer")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];

} else {
return action[6];
}

      return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return
notify_fail("你的内力或气不够，没有办法练习混天锤。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍混天锤。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
return CLASS_D("dragon") + "/huntian-hammer/" + action;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("huntian-hammer",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对浑天锤的领悟加深了，你的浑天锤进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对浑天锤领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_huntian-hammer");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+me->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);

   if(!arg||arg==" ")arg="浑天锤绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_huntian-hammer",m_actions);
}
