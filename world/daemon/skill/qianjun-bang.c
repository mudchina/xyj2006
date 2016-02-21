//千钧棒法
//lestat modi 2001 for dtxy

inherit SKILL;
#include <ansi.h>;
string* skill_head =({
        "$N身形稍退，使出一招",
        "$N仰天长笑，看也不看，一招",
        "$N一个虎跳，使出",
        "$N一声巨喝，好一个",
        "$N使出",
        "$N连翻几个筋斗云，一招",

});

string* skill_tail =({
        "，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来",
        "，随手一棒向$n当头砸下",
        "，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l",
        "，就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l",
        "，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭",
        "，手中$w转得如风车一般，\n一连三棒从半空中击向$n顶门",
});

mapping *action = ({
        ([      "name":                 "大闹阎罗府",
                "action":
"$N身形稍退，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来",
                "dodge":                5,
     "parry":   -10,
                "damage":               45,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "谈笑退天兵",
                "action":
"$N仰天长笑，看也不看，一招"+HIY"「谈笑退天兵」"NOR+"，随手一棒向$n当头砸下",

                "dodge":                0,
     "parry":     0,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "勇斗二郎神",
                "action":
"$N一个虎跳，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l",
                "dodge":                10,
     "parry":   -20,
                "damage":               45,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "脱困老君炉",
                "action":
"$N一声巨喝，好一个"+HIW"「脱困老君炉」"NOR+"！\n就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "醉闹蟠桃会",
                "action":
"$N使出"+HIB"「醉闹蟠桃会」"NOR+"，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭",
                "dodge":                -5,
     "parry":     -5,
                "damage":               40,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "三打白骨精",
                "action":
"$N连翻几个筋斗云，手中$w转得如风车一般，一连三棒从半空中击向$n顶门",
                "dodge":                5,
     "parry":   -10,
                "damage":               50,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "千钧澄玉宇",
                "action":
"$N手中$w一抖，化为千万道霞光，\n就在$n目眩神摇之时，再一抖，霞光顿收，\n$w已到了$n的$l！这一招有个名堂，叫作"+HIC"「千钧澄玉宇」"NOR+"",
                "dodge":                0,
                "parry":   -20,
                "damage":               55,
                "damage_type":  "砸伤"
        ]),
   ([   "name":        "乾坤一棒",
     "action":   "$N将手中$w迎风一挥，幻出万千虚影，蓄力劲发，高举过顶，
$w对准$n的脑门就砸了下去。这一下要是打中，恐怕连大罗金仙也难逃一命",
     "parry":   -40,
     "dodge":   -70,
     "damage":   200,
//     "force":   200,//兵器功夫增加force伤害,威力增加
     "damage_type":  "砸伤"
   ]),
([	"name":			"霹雳流星",
		"action":	HIW"只见$N身体一歪，手中$w迎风一抖，光芒暴涨，流星赶月般直罩$n。\n
$n眼睁睁看着$w袭来，呆呆怔立当场，浑然不知闪躲。"NOR,
		"parry":	-30,
		"dodge":	-50,
		"damage":	100,
		"damage_type":  "砸伤"
	]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练千钧棒法，
多练些内力再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棒子才能练棒法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
   int i;
   mapping* m_actions;
   i=me->query_temp("QJB_perform");
   if( !me->query_temp("QJB_perform")) {
     if(me->query("skill_qianjun-bang")==0) return action[random(8)];
     if(random(2))return action[random(8)];
     m_actions=me->query("skill_qianjun-bang");
     return m_actions[random(sizeof(m_actions))];
   }else {
     return action[i];
   }
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习千钧棒法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        write("你按着所学练了一遍千钧棒法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("puti") + "/qianjun-bang/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("qianjun-bang",1);       
   
   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对千钧棒的领悟加深了，你的千钧棒进入了一个新的境界！\n"NOR);
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
     tell_object(me,HIW"你突然福至心灵，对千钧棒领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_qianjun-bang");
   if(!pointerp(m_actions))m_actions=({});
   
   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+2*me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);
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
//   if(!arg||arg==" ")arg="千钧棒绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIG"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qianjun-bang",m_actions);
   me->add("zichuang/times",1);
}


