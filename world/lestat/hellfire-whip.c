//【烈火鞭】hellfire-whip.c
//write by yesi
/*
烈火鞭    dodge  -10    parry  -10    damage  20
烈火鞭善缠绕攻敌，一旦被卷入其攻击范围则极难幸免，
且此鞭曲折转拐，来去无踪，要招架抵挡也甚为不易。
特点是杀伤不大。

Attention: 烈火鞭前六招是六道轮回中出的，而第13，14两招是苦丧棒
和惊魂掌中，用来 Perform 的，而玩家平常并不会用到。
*/
inherit SKILL;
#include <ansi.h>
int ratio;
string* skill_head =({
        "$N手腕一翻，一招",
        "长笑声中$N一个倒翻，使出",
        "$N使出",
        "$N喉咙里发出几声嚎叫，一式",
        "$N贴地而出，发出一招",
        "$N右手一引，一招",
});

string* skill_tail =({
        "，手中$w抖得笔直，带出一股锐啸猛刺$n$l",
        "，手中$w霹啪有声，一圈套一圈地卷向$n",
        "，手中$w绕了个圈，套向$n。",
        "，手中$w如长蛇一般，绕着$n转个不停",
        "，$w紧逼$n的$l",
        "，手中$w如夕阳的炊烟，袅袅不绝",
});


mapping *action = ({
        ([      "name":                 "天界求佛",
                "action":
"$N面有喜色，手中$w一迎，飘然间「"+BLINK""+HIY"天界求佛"+NOR"」这招业已使出",
                "dodge":                -40,
                "parry":                -50,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "人间苦难",
                "action":
"$N满面愁容，情意缠绵，鞭意更缠绵，「"+BLINK""+HIG"人间苦难"+NOR"」使得怅然苦楚，$n为之黯然神伤",
                "dodge":                -50,
                "parry":                -100,
                "damage":               55,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "地狱受刑",
                "action":
"$N杀气笼罩一身，$w如铁链般疯狂砸去，「"+BLINK""+HIM"地狱受刑"+NOR"」的威力发挥得淋漓尽致",
                "dodge":                -40,
                "parry":                -100,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "修罗无敌",
                "action":
"$N怒发冲冠，$w舞得如天罗地网，$n方悟得这招叫「"+BLINK""+HIR"修罗无敌"+NOR"」",
                "dodge":                -100,
                "parry":                -100,
                "damage":               80,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "饿鬼讨羹",
                "action":
"$N悲愤之色俱现于形，所生之力贯彻于$w朝$n抽出「"+BLINK""+HIB"饿鬼讨羹"+NOR"」这招",
                "dodge":                -10,
                "parry":                -50,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "牲畜投胎",
                "action":
"$N百无聊奈，顺手一掷，$w却绷直如箭，朝$n射去，好一招「"+BLINK""+YEL"牲畜投胎"+NOR"」",
                "dodge":                -10,
                "parry":                -80,
                "damage":               70,
                "damage_type":  "刺伤"
        ]),               
        ([      "name":                 "地藏点卯",
                "action":
"$N手腕一翻，一招"+BLINK""+HIW"「地藏点卯」"NOR"$w抖得笔直，带出一股锐啸猛刺$n$l",
                "dodge":                0,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "横空出世",
                "action":               
"$N大喝一声，手中$w宛若矫龙飞在半空，大有"+BLINK""+HIR"「横空出世」"NOR"的气概。\n$n只觉得全身俱在$w笼罩之下",
                "dodge":                -20,
                "parry":                -20,
                "damage":               50,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "歌舞阎罗",
                "action":
"$N右手一引，一招"+BLINK""+MAG"「歌舞阎罗」"NOR"$w贴地而飞，再疾卷而上，仿佛带出了地狱中的烈火，夹头夹脑地扑向$n",
                "dodge":                -5,
                "parry":                -15,
                "damage":               45,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "枉死城中渡鬼魂",
                "action":
"也不知$N如何动了一动，一招"+BLINK""+RED"「枉死城中渡鬼魂」"NOR"但见长空中青光一闪，$n只觉$w已击上了$l",
                "dodge":                -15,
                "parry":                -5,
                "damage":               35,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "幽冥做鬼上雷音",
                "action":
"$N身形往前滑出，手中$w霹啪有声，一圈套一圈地卷向$n,好一招"+BLINK""+HIC"「幽冥做鬼上雷音」"NOR"",
                "dodge":                -5,
                "parry":                0,
                "damage":               35,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"长笑声中$N一个倒翻，手中$w急绞，但见方圆丈许飞沙走石，劲气纵横！\n$n不知如何才能脱困而出，脸都绿了",
                "dodge":                -15,
                "parry":                -20,
                "damage":               50,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "小楼夜哭",
                "action":
"$N喉咙里发出几声嚎叫，高举$w，不顾一切地冲向$n，几乎与$n贴脸而立！\n手中$w却悄无声息地刺向$n的$l，好厉害的"+BLINK""+HIB"「小楼夜哭」"NOR"",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "秋坟鬼唱",
                "action":               "$N左手虚晃，右掌飘飘，掌心呈碧绿，一招"+BLINK""+HIB"「秋坟鬼唱」"NOR"击向$n$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),

});
string *liudao=({
                HIY"\n$N口中唱道：天界道，神仙道，金碧琉璃谁人造? "NOR,
                HIG"\n$N口中唱道：人界道，好了道，爱欲痴情谁忘了？"NOR,
                HIM"\n$N口中唱道：冥界道，负债道，辜罪刑罚谁还掉？"NOR,
                HIR"\n$N口中唱道：修罗道，杀戮道，斗战征伐谁最骁？"NOR,
                HIB"\n$N口中唱道：饿鬼道，无常道，卤肴羹炙谁吃到？"NOR,
                YEL"\n$N口中唱道：牲畜道，断欲道，猪狗牛马谁说好？"NOR
                });
                




int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练烈火鞭。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("你必须先找一根鞭子才能练烈火鞭。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i,j;
	    mapping* m_actions;
		string strs;
		m_actions=me->query("skill_hellfire-whip");

        if( !me->query_temp("ldlh") ) {
           if(me->query("skill_hellfire-whip")==0) 
		    	return action[6+random(6)];
           if(random(2))
		    	return action[6+random(6)];
          return m_actions[random(sizeof(m_actions))];
		}
       else 
		   j=me->query_temp("lunhui")%6;
           message_vision(liudao[j],me);
           me->add_temp("lunhui",1);
        return action[j];
}
                

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习烈火鞭。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("你按着所学练了一遍烈火鞭。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("ghost") + "/hellfire-whip/" + func;
}

mixed hit_ob(object me, object victim)
{     int damage;
        if (me->query_temp("ldlh"))
     {
     switch (me->query_temp("lunhui")%6)
        {
                        case 1: {victim->receive_wound("kee",random(me->query_skill("spells")));
							     ratio=(int)victim->query("kee") * 100 /(1+(int)victim->query("max_kee"));
                                 break;
                                }
                        case 2: {victim->receive_wound("sen",random(me->query_skill("spells")));
                                 ratio=(int)victim->query("sen") * 100 /(1+(int)victim->query("max_sen"));
                                 break;
                                } 
                        case 3: {victim->add("mana",-random(me->query_skill("spells")));
                                 if (victim->query("mana")<0) victim->set("mana",0);
                                 break;
                                 }
                        case 4: {victim->add("force",-random(me->query_skill("force")));
                                 if (victim->query("force")<0) victim->set("force",0);
                                 break;
                                }
                        case 5: {victim->add("food",-random(me->query_skill("whip")));
                                 if (victim->query("food")<0) victim->set("food",0);
                                 break;
                                }
                        case 0: {victim->add("water",-random(me->query_skill("whip")));
                                if (victim->query("water")<0) victim->set("water",0);
                                }

                }          
          }
}

mixed fail_hit(object me, object victim)
{    if (me->query_temp("ldlh"))
      {
      switch (me->query_temp("lunhui")%6)
                    {
                        case 1: return HIC"$n不为欲仙欲圣的美景所惑，收紧心神，弹指间便离天界道而去。\n"NOR;
                        case 2: return HIC"$n硬起心肠，无视身旁的是是非非，快步离开人界道。\n"NOR;
                        case 3: return HIC"$n对惨号声不屑于顾，游弋之中胜似闲庭信步。\n"NOR;
                        case 4: return HIC"$n对付修罗游刃有余，很快就杀出一条血路离开了。\n"NOR;
                        case 5: return HIC"$n看到一大群饿鬼就远远的躲了开去。\n"NOR;
                        case 0: return HIC"$n看中了一匹白马，跳上马背星夜兼程离开了牲畜界。\n"NOR;
                        //default: return 1;
                    }
       }   
}      

mixed hit_ob_msg(object me,object victim)
{   string strs;
        if (me->query_temp("ldlh"))
      {//me->add_temp("lunhui",1);
      switch (me->query_temp("lunhui")%6)
              {
                        case 1: return HIY"天界美奂美仑，霞举虹飞入目，轻舞罗香侍鼻，丝竹声不绝于耳，$n陶醉于中而不知返。\n"NOR;
                        case 2: {strs="( $n" + COMBAT_D->sen_status_msg(ratio)+ " )\n";
                                 strs=HIG"$n想起人世间的殇情冷暖，悲欢离合，不觉黯然。\n"NOR+strs;
                                 return strs;
                                }
                        case 3: return HIM"$n被阵阵撕心裂肺的叫喊声包围，吓得浑身直冒冷汗。\n"NOR;
                        case 4: return HIR"$n被从四方赶至的修罗追杀，失措逃亡，精疲力竭。\n"NOR;
                        case 5: return HIB"$n看到饿鬼的样子感觉自己的喉咙也被勒成只有一条细缝不能进食。\n"NOR;
                        case 0: return YEL"$n感叹牲畜的愚昧无知和可怜，不知不觉就耽误了行程。\n"NOR;
               }
       }
}        
void skill_improved(object me)
{
   int m_skill=me->query_skill("hellfire-whip",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对烈火鞭的领悟加深了，你的烈火鞭进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对烈火鞭领悟出了一招新的用法！\n"NOR);
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

   m_actions=me->query("skill_hellfire-whip");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;//应该为str
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"抽伤"]);

   if(!arg||arg==" ")arg="烈火鞭秘技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_hellfire-whip",m_actions);
}

