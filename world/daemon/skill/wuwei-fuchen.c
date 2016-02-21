// wuwei-fuchen无为拂尘
// /daemon/skill/wuwei-fuchen.c
// writted by mind 2001/2
//lestat modi for dtxy 2001

#include <ansi.h>

inherit SKILL;
string* skill_head =({
        "$N身形稍退，使出一招",
        "$N不闪不避，一式",
        "$N使出",
        "$N面露微笑，一式",
        "$N一个急转，使出",
});
string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w化为一道金光罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，顿时一阵幽香飘向$n",
});
mapping *action = ({
([ "action": "$N身形若被狂风吹送，飘然而至。一招"+HIM"「玉带围腰」"NOR+"，手中$w变出一个个圆圈，卷向$n的腰间。",
   "dodge": -5,
   "damage":30,
   "parry": -5,
   "skill_name" : "玉带围腰",
   "damage_type":  "刺伤"
]),
([ "action": "$N伸指在$w上一弹，趁$w轻响之际一招"+HIG"「庸人自扰」"NOR+"，象残照般洒向$n的$l",
   "dodge": -10,
   "damage":50,
   "parry": -10,
   "skill_name" : "庸人自扰",
   "damage_type":  "割伤"
]),
([ "action": "$N将内力注入$w，蓦地使出一式"+HIY"「龙行乾象」"NOR+"，$w矫夭飞舞，直如神龙破空一般抽向$n",
   "dodge": -40,
   "damage":40,
   "parry": 0,
   "skill_name" : "龙行乾象",
   "damage_type":  "抽伤"
]),
([ "action": "$N一声高喝，吸气催力，一式"+HIC"「有所为」"NOR+"，$w急速转动，鞭影纵横，直中有圆，圆中有直，似真似幻，绞向$n",
   "dodge": -10,
   "damage":40,
   "parry": -50,
   "skill_name" : "有所为",
   "damage_type":  "割伤"
]),
([ "action": "$N面露微笑跨前一步，右手$w轻扬，缓缓使出一式"+HIW"「静止观止」"NOR+"，鞭势平和中正，不带丝毫霸气",
   "dodge": -20,
   "damage":30,
   "parry": -30,
   "skill_name" : "静止观止",
   "damage_type":  "鞭伤"
]),
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;

       if( (int)me->query("max_force") < 100 )
               return notify_fail("你的内力不足。\n");

       if ((int)me->query_skill("force") < 30)
               return notify_fail("你的内功火候太浅。\n");

       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("你必须先找一条鞭子才能练无为拂尘。\n");

       return 1;
}


mapping query_action(object me)
{   
	mapping* m_actions;
     m_actions=me->query("skill_wuwei-fuchen"); 
        if (random(me->query_str()) >= 30 && me->query_skill("wuwei-fuchen",1) > 100 &&
             me->query_skill("parry",1) > 100 &&
             me->query("force") > 1000 &&
             me->query("kee")>300) {
                me->add("kee",-10);           
                me->add("force", -30);
                return ([
                "action": HIR "$N手腕一抖，但见飞舞的$w"+HIR"从天而下和$n"+HIR"缠在一起，一股排山倒海的内劲无声息的向$n"+HIR"胸口撞去！"NOR,
                "force": 60,
                "dodge": -85,
                "parry": -85,
                "damage" : 70,
                "damage_type": "内伤"]);
        }
           if (random(me->query_str()) >= 28 && me->query_skill("wuwei-fuchen",1)> 150 &&
                me->query_skill("parry",1) > 150 &&
                me->query("force") > 1500 &&
                me->query("kee")>500) {
                me->add("kee",-20);            
                me->add("force", -50);
                return ([
                "action": HIR "$N把手中$w"+HIR"抖动成圈，绕着$n"+HIR"越转越急，越转越快，$n"+HIR"登时身不由主，被套得连转了几身，眼看就要摔倒！"NOR,
                "force": 120,
                "dodge": -35,
                "parry": -35,
                "damage" : 100,
                "damage_type": "抽伤"]);
        }
     if(me->query("skill_wuwei-fuchen")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "whip")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query_skill("force") < 100)
               return notify_fail("你的内功火候太浅。\n");
       if ((int)me->query("kee") < 50)
               return notify_fail("你的体力不够练无为拂尘。\n");
       me->receive_damage("kee", 15);
       return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weap,weap1;
        weap = victim->query_temp("weapon");
                weap1 = me->query_temp("weapon");

                if( (me->query_skill("wuwei-fuchen") > 60) && (me->query("force") > 100)
                         && (victim->query_temp("weapon")) 
                         && random(10)>5)
                 {
                        message_vision(HIY "只见$N急速挥舞" + weap1->name() + "，转出无数个大小圈子，以阴柔之劲缠住对方的" + weap->name() +"！\n" NOR, me );
                        victim->start_busy(2+random(2));
                        if (random(me->query_str()) > victim->query_str()/2 )
                        {       
                        message_vision(HIY "$N气运手臂用力一拽，" + weap->name() + "却无法从"+weap1->name()+"的缠绕中脱开，情急之下只好放弃了手中的兵刃。\n" NOR, victim );
                        weap->move(environment(me));
                        victim->reset_action();
                        } else {
                        message_vision(HIY "$N暗运巧劲，" + weap->name() + "顺着方向快速旋转数下，解开了"+weap1->name()+"的缠绕。\n" NOR, victim );
                        victim->add("force",-50);
                        }
                        me->add("force", -50);
                 }
                 return 1;
}

string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/wuwei-fuchen/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("wuwei-fuchen",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对无为拂尘的领悟加深了，你的无为拂尘进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对无为拂尘领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_wuwei-fuchen");
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
//   if(!arg||arg==" ")arg="无为拂尘必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_wuwei-fuchen",m_actions);
    me->add("zichuang/times",1);
}


