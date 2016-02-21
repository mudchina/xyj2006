
//lestat modi for dtxy 2001

inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$N身形稍退，使出一招",
        "$N于朦朦胧胧中，使出一招",
        "$N四处游走，一招",
        "$N神态悠闲，一招",
        "$N中宫直进，突然一招",
        "$N双脚一顿，笔直跃起，一招",
});

string* skill_tail =({
        "，手中$w不停地颤抖着",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，手中$w去势飘忽不定，只看得$n眼花缭乱",
        "，手中$w带起点点寒光，指向$n前胸穴道",
});

mapping *action = ({
		([	"name":			"御剑生风",
		"action":
"$N双脚一顿，笔直跃起，手中$w不停地颤抖着，\n"
"笼罩住$n全身。这势"+HIC"「御剑生风」"NOR"果然是无孔不入",
		"dodge":		-5,
		"parry":		-10,
		"damage":		 50,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑如虹",
		"action":
"$N手中$w带起点点寒光，指向$n前胸穴道。$n正专心致志地对付着剑招，\n"
"不料$N左手运力拍向$n的$l。这势"+HIM"「御剑如虹」"NOR"亦真亦幻，实是难防",
		"dodge":		-5,
		"parry":		15,
		"damage":		40,
		"damage_type":		"震伤"
	]),
	([	"name":			"御剑成龙",
		"action":
"$N在$n四周游走，一招"+HIY"[御剑成龙]"NOR",手中$w去势飘忽不定，只看得$n眼花缭乱。\n"
"趁此良机，$N于朦朦胧胧中一抖$w，向$n的$l疾挑",
		"dodge":		-15,
		"parry":		10,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑行空",
		"action":
"$N仗起手中$w，带出点点寒光，罩住$n的胸腹，只等$n的破绽。\n"
"这招"+HIR"「御剑行空」"NOR"直如细雨般紧密，$n实在不知$w将要指向自己身上何处",
		"dodge":		25,
		"parry":		-10,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑无影",
		"action":
"$N手中$w中宫直进，疾速刺向$n的前心。\n"
"这招"+HIB"「御剑无影」"NOR"令人耳目一新。$n只觉浑身一紧，$w已刺到了$l",
		"dodge":		-15,
		"parry":		15,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑飞腾",
		"action":
"$N手中$w向$n的右手疾刺，但正当$n要招架时，\n"
"$w却突然转向了$n的左足！这招"+HIG"「御剑飞腾」"NOR"确实神鬼莫测",
		"dodge":		10,
		"parry":		-15,
		"damage":		45,
		"damage_type":		"刺伤"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，御剑术学了也没用。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练御剑术有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练御剑术有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍御剑术。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}
mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_yujianshu");
     if(me->query("skill_yujianshu")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}

string perform_action_file(string func)
{
	return CLASS_D("shushan") + "/yujianshu/"+func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("yujianshu",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对御剑术的领悟加深了，你的御剑术进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对御剑术领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_yujianshu");
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
//   if(!arg||arg==" ")arg="御剑术绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIW"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_yujianshu",m_actions);
   me->add("zichuang/times",1);
}
 

