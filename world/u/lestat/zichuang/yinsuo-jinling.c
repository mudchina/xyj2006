//银索金铃
inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N不闪不避，一式",
        "$N身形一幌，使出",
        "$N妍然一笑，一式",
        "$N飞身跃起，使出",
});
string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w舞出满天鞭影罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，$w从右肩急甩向后，陡地击向$n$l。",
});

mapping *action = ({
   ([   "action":
"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开，一招"+HIM"「宫韵」"NOR"已悄然划向$n的后心",
     "dodge":     -5,
                "parry":                -10,
     "damage":     40,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"飞身跃起，$n抬眼一望，但见得$N手中$w舞出满天鞭影，"+HIC"[商韵]"NOR"已将$n笼罩",
     "dodge":     -15,
                "parry":                -25,
     "damage":     40,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中$w轻轻一抖，手中$w如鬼魅一般,一式"+HIG"[角韵]"NOR"无形的刺向$n的左肋",
     "dodge":     -10,
                "parry":                -15,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w犹似一条柔丝，竟如没半分重量，身子忽东忽西，忽进忽退，在$n身周飘荡不定，正是一招"+HIW"[羽韵]"NOR"",
     "dodge":     -10,
                "parry":                -5,
     "damage":     50,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"突然之间，$N身形一闪一晃，疾退数丈，使出一招"+HIB"「支韵」"NOR"，$w从右肩急甩向后，陡地击向$n$l，正如天外游龙，矢矫而至",
     "dodge":     -20,
                "parry":                -10,
     "damage":     45,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;
//if( (string)me->query("gender") !="女性")
//return notify_fail("银索金铃只有女子才能学习!!\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练银索金铃。\n");

   if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("银索金铃必须配合盘丝洞的九阴心经才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("你必须先找一把鞭子才能练鞭法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
 int i;
 mapping* m_actions;
 i=me->query_action("YSJL_perform");
 if( ! me->query_temp("YSJL_perform"))
      {
     if(me->query("skill_yinsuo-jinling")==0) return action[random(5)];
     if(random(2))return action[random(5)];
     m_actions=me->query("skill_yinsuo-jinling");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
   {
  return action[5];
  }
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习银索金铃。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write("你按着所学练了一遍银索金铃。\n");
   return 1;
}


string perform_action_file(string func)
{
return CLASS_D("pansi") + "/yinsuo-jinling/" + func;
}


void skill_improved(object me)
{
   int m_skill=me->query_skill("yinsuo-jinling",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对银索金铃的领悟加深了，你的银索金铃进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对银索金铃领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_yinsuo-jinling");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+2*me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);
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
//   if(!arg||arg==" ")arg="银索金铃必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIR"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_yinsuo-jinling",m_actions);
   me->add("zichuang/times",1);
}
 

