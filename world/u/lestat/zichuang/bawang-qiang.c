// bawang-qiang.c 【霸王枪法】
//lestat modi for dtxy 2001

inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$N运足精神，使出一招",
        "$N手腕一翻，一式",
        "$N似欲退走，可是忽地一个转身，百忙中使出一招",
        "$N一个跨步，使一招",
		"$N一按枪把,使出一招",
});
string* skill_tail =({
        "，手中$w连续刺向$n面门，哽嗓，前心。",
        "，手中$w一挺刺向$n$l。",
        "，手中$w势若飞瀑刺向$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，手中$w带出一道寒气，由下而上疾挑$n$l",
});

mapping *action = ({
        ([      "action":
"$N使一招"+HIW"「迎门三不过」"NOR"，手中$w连续刺向$n面门，哽嗓，前心",
                "damage":               50,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招"+HIG"「拨草寻蛇」"NOR"刺向$n$l",
                "damage":               40,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一个跨步，使一招"+HIC"「高山流水」"NOR"，手中$w势若飞瀑刺向$n的$l",
                "damage":               45,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N一按枪把，啪！地一声抖出"+HIM"「五朵枪花」"NOR"。上下左右，虚虚实实刺向$n全身要害",
                "damage":               45,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"只见$N一个斜跨，使个"+HIR"「举火烧天势」"NOR"，手中$w带出一道寒气，由下而上疾挑$n$l",
                "damage":               55,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l。\n这一招"+HIB"「灵蛇出洞」"NOR"快若闪电，毒辣无比",
                "damage":               35,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使个"+MAG"「飞鸟投林势」"NOR"，身形斜飞，从侧面突出一枪，径刺$n$l",
                "damage":               40,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N似欲退走，可是忽地一个转身，百忙中使出一招"+RED"「回马枪」"NOR"，$w一挺刺向$n$l",
                "damage":               50,
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;
     	if(me->query("family/family_name") != "将军府")
		return notify_fail("霸王枪法乃将军府不传之密！\n");
        if( (int)me->query("max_force") < 100 )
                return
         notify_fail("你的内力不够，没有办法练霸王枪法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
 int i;
 mapping* m_actions;
 i=me->query_action("BWQ_perform");
 if( ! me->query_temp("BWQ_perform"))
      {
     if(me->query("skill_bawang-qiang")==0) return action[random(4)];
     if(random(2))return action[random(4)];
     m_actions=me->query("skill_bawang-qiang");
     return m_actions[random(sizeof(m_actions))];
      }
    else 
   {
  return action[4];
  }
   return action[random(sizeof(action))];
}


int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
        write(RED"十步杀一人，千里不留行。\n"NOR);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("fighter") + "/bawang-qiang/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("bawang-qiang",1);


   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对霸王枪法的领悟加深了，你的霸王枪法进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对霸王枪法领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_bawang-qiang");
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
//   if(!arg||arg==" ")arg="霸王枪秘传必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+MAG"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_bawang-qiang",m_actions);
   me->add("zichuang/times",1);
}

