
//wuyue-spear 五岳神
//lestat modi for dtxy 2001
inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$N使出一招",
        "$N运足精神，好一招",
        "$N一个虎跳使出个",
        "$N神态悠闲，一招",
        "$N人枪合一，突然一招",
        "$N一口气抖出五朵枪花，暗喝一声",
});

string* skill_tail =({
        "，手中$w向$n劈头改脑直扫了下来",
        "，手中$w若有若无地刺向$n$l",
        "，$N手中$w势若飞瀑刺向$n的$l",
        "，手中$w轻妙地划向$n的$l",
        "，枪枪不离$n要害",
        "，手中$w带出一道利闪直奔$n$l",
});

mapping *action = ({
        ([      "action":
"$N使一招"+HIM"「泰山压顶」"NOR"，手中$w向$n劈头改脑直扫了下来",
                "damage":               40,
                "dodge":                -15,
                "parry":                -15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招"+HIC"「华岳插云」"NOR"挑向$n",
                "damage":               40,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N手中$w势若飞瀑刺向$n的$l，好一招"+HIG"「衡峰溪绕」"NOR"",
                "damage":               45,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N 一口气抖出五朵枪花，暗喝一声"+HIB"「五岳朝宗」"NOR"。枪枪不离$n要害",
                "damage":               50,
                "dodge":                10,
                "parry":                -15,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N一个虎跳使个"+HIY"「太室参佛」"NOR"，手中$w带出一道利闪直奔$n$l",
                "damage":               40,
                "dodge":                0,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N腾空飞气，人枪合一，$w只落$n$1，正是一招"+HIW"「恒岭悬空」"NOR"",
                "damage":               40,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "刺伤"
        ]),
});
int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法练五岳神枪。\n");
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
     mapping* m_actions;
     m_actions=me->query("skill_wuyue-spear");
     if(me->query("skill_wuyue-spear")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}
int practice_skill(object me)
{
        object weapon;
		if( (string)me->query_skill_mapped("force")!= "huomoforce")
     return notify_fail("五岳神枪必须配合火魔心法才能练。\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");
        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍五岳神枪。\n");
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/wuyue-spear/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("wuyue-spear",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对五岳神枪的领悟加深了，你的五岳神枪进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对五岳神枪领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_wuyue-spear");
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
//   if(!arg||arg==" ")arg="五岳神枪必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIC"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_wuyue-spear",m_actions);
   me->add("zichuang/times",1);
}
 

