//【龙形搏击】dragonfight.c
// cglaem...12/19/96.
//meipai skill(only dragon related NPCs can use it)
// tomcat 修改
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N纵身跃起",
        "$N似退反进",
        "$$N一旋身",
        "$N忽发龙吟，使出一招",
        "$N一个筋斗翻在半空",
        "$N身形一长",
});

string* skill_tail =({
        "，双掌以排山倒海之势击向$n。",
        "，对准$n一把腰间抓了过去",
        "，双臂如铁铸一般扫向$n",
        "，双臂一阵横扫，直逼$n得连连倒退",
        "，直逼的$n节节后退。",
        "，全身劲气疾卷$n",
});

mapping *action = ({
        ([      "action":
"$N纵身跃起，一招"+HIR"「飞龙在天」"NOR"，双掌以排山倒海之势击向$n的$l",
                "dodge":                -40,
                "parry":                -40,
                "force":                180,
                "damage_type":          "瘀伤",
                "weapon" :              "双掌",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
        ([      "action":
"$N似退反进，突然欺身向前，五指如钩，一招"+HIW"「潜龙勿用」"NOR"，对准$n的$l一把抓了过去",
                "dodge":                -60,
                "parry":                -40,
                "force":                250,
                "damage_type":          "抓伤",
                "weapon":               "右手五指",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
        ([      "action":
"只见$N一旋身，双腿如铁棍一般扫向$n。这一招"+HIB"「神龙摆尾」"NOR"当真是防不胜防",
                "dodge":                -50,
                "parry":                -40,
                "force":                250,
                "damage_type":          "砸伤",
                "weapon":               "双腿",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
        ([      "action":
"$N忽发龙吟，使出一招"+HIY"「龙战于野」"NOR"，啸声中和身而上，向$n直撞而来",
                "dodge":                -60,
                "parry":                -40,
                "force":                200,
                "damage_type":          "撞伤",
                "weapon":               "全身",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
            ([  "action":
"只见$N一个筋斗翻在半空，一招"+HIC"「龙腾四海」"NOR"将发未发，但是全身劲气疾卷$n",
                "dodge":                -40,
                "parry":                -20,
                "force":                250,
                "damage_type":          "内伤",
                "weapon":               "劲气",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
            ([  "action":
"$N身形一长，朝$n劈面就是一拳。这招"+HIG"「苍龙出海」"NOR"势若奔雷，锐利无比",
                "dodge":                -10,
                "parry":                -50,
                "force":                180,
                "damage_type":          "瘀伤",
                "weapon":               "拳头",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
                return notify_fail("你的龙神心法还不够精湛，无法领会更深层的龙形搏击！\n");


        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练龙形博击必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}


int practice_skill(object me)
{
        if( (int)me->query_skill("dragonforce",1) < (int)me->query_skill("dragonfight",1)/2)
                return notify_fail("你的龙神心法还不够精湛，无法领会更深层的龙形搏击！\n");

        if( (int)me->query("sen") < 50)
                return notify_fail("你的精神无法集中了，休息一下再练吧。\n");

        if( (int)me->query("kee") < 50 )
                return notify_fail("你现在手足酸软，休息一下再练吧。\n");

        if( (int)me->query("force") < 20 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("kee", 30);
        me->add("force", -20);

        return 1;
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_dragonfight");
if( !me->query_temp("HTH_perform")) {
if(me->query("skill_dragonfight")==0)
return action[random(6)];
if(random(2)) return action[random(6)];
return m_actions[random(sizeof(m_actions))];
}else{ return action[6];}
  return action[random(sizeof(action))];
}


string perform_action_file(string func)
{
        return CLASS_D("dragon") + "/dragonfight/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str()/10) {
                victim->receive_wound("kee", damage_bonus / 2 );
                switch(random(3)) {
                        case 0: return HIB"你听到「喀啦」一声轻响，竟似是骨碎的声音！\n"NOR;
                        case 1: return HIB"$N劲力一吐，$n的$l发出「喀」地一声爆响！\n"NOR;
                        case 2: return HIB"只听见$n的$l「喀」地一声 ...\n"NOR;
                }
        }
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("dragonfight",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对龙形搏击的领悟加深了，你的龙形搏击进入了一个新的境界！\n"NOR);
     if(me->query("zichuang/times")>7){
        tell_object(me,HIW"然而你的功夫已经练至顶峰，不能再创出新招了。\n"NOR);
        return;
     }
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if((random(me->query("int")/2)+(int)me->query_skill("literate")/50)<10){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对龙形搏击领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
	string *banned_name = ({
                "你", "你", "我", "他", "她", "它", "爸", "妈",
                "爷", "奶", "巫师", "天神", "神仙",
        });
   mapping* m_actions;
   mapping m_act=([]);
   int content, i=strlen(arg);
   string msg;

   m_actions=me->query("skill_dragonfight");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+me->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/2;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"瘀伤"]);
if (!arg || arg=="") 
     {
          tell_object(me,"请为你的新招式取一个名字：");
          input_to( (: call_other, __FILE__, "name_skill", me:));
          return;
     }
     else while(i--) 
     {
                if( arg[i]<=' ' ) 
                {
                        tell_object(me,"招式名字不能使用控制字元，请重新设定一个名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if(strsrch(arg, "　") >= 0) 
                {
                        tell_object(me,"招式名字不能有空格，请重新设定一个名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) 
                {
                        tell_object(me,"请您用「中文」为你的新招式取名字：");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
     }
     if( member_array(arg, banned_name)!=-1 ) 
     {
     tell_object(me,"对不起，这种名字会造成其他人的困扰。请重新设定一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
     if( (strlen(arg) < 8) || (strlen(arg) > 16 ) ) 
     {
     tell_object(me,"对不起，招式名字必须是 ４ 到 ８ 个中文字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
//   if(!arg||arg==" ")arg="龙形搏击绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIC"「"+arg+"」"NOR+skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_dragonfight",m_actions);
   me->add("zichuang/times",1);
}


