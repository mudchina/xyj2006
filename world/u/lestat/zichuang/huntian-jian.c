//huntian-jian
//lestat modi for dtxy 2001
inherit SKILL;
#include <ansi.h>
string* skill_head =({
        "$N身形稍退，使出一招",
        "$N仰天长笑，看也不看，一招",
        "$N轻轻一跃，使了个",
        "$N神态悠闲，一招",
        "$N身形转个不停，突然一招",
        "$N脚下踏了个七星步，一招",
});
string* skill_tail =({
        "，手中$w势若飞瀑向$n拦腰一斩",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，反手对准$n$l一剑刺去",
        "，趁$n转身之际，挥出一剑",
});

mapping *action =
({
([
"action" : 
"$N使一式"+HIY"『征云迷远谷』"NOR+"，前脚踏出，手中$w一抖，剑光
暴长，洒向$n的$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "『征云迷远谷』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIY"『杀气振遐方』"NOR+"，面露杀气，手中$w
从从四面八方刺向$n的$l",
"dodge"  : -10,
"damage" : 15,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『杀气振遐方』",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N使一式"+HIY"『刀枪如白雪』"NOR+"，手中$w顿时幻出
刀光剑影，刺向$n的$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : -20,
"force"         : 100,
"skill_name"  : "『刀枪如白雪』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIY"『剑戟似堆霜』"NOR+"，身形一晃，疾掠而上，手中$w
龙吟一声，对准$n的$l连递数剑",
"dodge"  : 10,
"damage" : 25,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『剑戟似堆霜』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIY"『旌旗遮绿野』"NOR+"，以退而进扑向$n，
手中$w“铮”然有声，往$n的$l刺去",
"dodge"  : 10,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『旌旗遮绿野』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIY"『金鼓震空桑』"NOR+"，一个侧身，手中$w疾往斜上挑
起，直指$n的$l",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"force"         : 100,
"skill_name"  : "『金鼓震空桑』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIY"『刁斗传新令』"NOR+"，微微一个转身，手中$w却已自
肋下穿出，罩向$n的$l",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"force"         : 100,
"skill_name"  : "『刁斗传新令』",
"damage_type" : "内伤",
]),
([
"action" : 
"$N使一式"+HIY"『时雨庆壶浆』"NOR+"，剑气漫天飞下，手中$w如匹链般
洒向$n的$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "『时雨庆壶浆』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIY"『军行如骤雨』"NOR+"，剑招突变，接着手中$w如暴风骤雨
般的地往$n的$l刺去",
"dodge"  : 10,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『军行如骤雨』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIY"『马走似奔狼』"NOR+"，腾身飞跃，手中$w于半空中闪下，
化作一道白色长弧洒向$n的$l",
"dodge"  : 20,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『马走似奔狼』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIY"『冲冠射碧空』"NOR+"，一片燥雷之声，手中$w反手疾挑
而出，“唰”的一声往$n的$l刺去",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『冲冠射碧空』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIY"『闪闪快如风』"NOR+"，蓦地疾退一步，又冲前三步，手中
$w化为光弧往$n的$l刺去",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "『闪闪快如风』",
"damage_type" : "内伤",
]),
([
"action" : 
"$N使一式"+HIY"『夜吼啼玄鸟』"NOR+"，如大鹏展翅般从半空中穿下，双手
握着$w，声势逼人地刺向$n的$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 100,
"skill_name"  : "『夜吼啼玄鸟』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIY"『朝垂泣子规』"NOR+"，手中$w“嗤”的一声斜刺向天空，
随即向下“唰唰”两下，划出一个叉字，往$n的$l刺去",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"force"         : 100,
"skill_name"  : "『朝垂泣子规』",
"damage_type" : "内伤",
]),
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me) {
if( (string)me->query_skill_mapped("force")!= "xuanzong-force")
        return notify_fail("你的玄宗心法为尚浅，没法学混天一剑！\n");
    if ((int)me->query_skill("kaitian-zhang", 1) < 40)
        return notify_fail("混天一剑必须配合混沌开天掌才可以进步！\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
mapping* m_actions;
m_actions=me->query("skill_huntian-jian");
if(me->query("skill_huntian-jian")==0 )
return action[random(sizeof(action))];
if( random(4) == 1 )
return m_actions[random(sizeof(m_actions))];
else
return action[random(sizeof(action))];
}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)(weapon->query("skill_type")) != "sword")
        return notify_fail("不会吧，手上没剑也想练间？ :)\n");
       if ((int)(me->query("kee")) < 50)
        return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("kee", 30);
        write(HIB"『混沌天地起春雷,万仞山前丢霹雳』\n"NOR);
    return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("kunlun") + "/huntian-jian/" + action;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("huntian-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对混天一剑的领悟加深了，你的混天一剑进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对混天一剑领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_huntian-jian");
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
//   if(!arg||arg==" ")arg="混天一剑必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"「"+arg+"」"NOR
                 +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_huntian-jian",m_actions);
   me->add("zichuang/times",1);
}

