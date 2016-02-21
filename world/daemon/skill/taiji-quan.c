// taiji-quan.c 太极拳
#include <ansi.h>
inherit SKILL;
#include "/daemon/skill/eff_msg.h";
int taiji(object me, object victim);

mapping *action = ({
([  "action" : "$N起太极「起手式」，双手下垂，手背向外，接着两臂慢慢提起至胸前",
    "force" : 65,
    "dodge" : 25,
    "lvl" : 0,
    "skill_name" : "起手式",
    "damage_type" : "震伤"
]),
([  "action" : "$N接着一招「揽雀尾」，双手划了个半圈，左阴右阳，按向$n的$l",
    "force" : 95,
    "dodge" : 15,
    "lvl" : 5,
    "skill_name" : "揽雀尾",
    "damage_type" : "内伤"
]),
([  "action" : "$N面对$n，一招「单鞭」，左右两拳由下至上划弧，一前一后摆至平肩",
    "force" : 105,
    "dodge" : 15,
    "lvl" : 10,
    "skill_name" : "单鞭",
    "damage_type" : "内伤"
]),
([  "action" : "$N变招「提手上势」，两臂慢慢提起至胸前，左臂半环，右臂直伸，插向$n的$l",
    "force" : 125,
    "dodge" : 10,
    "lvl" : 15,
    "skill_name" : "提手上势",
    "damage_type" : "抓伤"
]),
([  "action" : "$N单脚独立，左手虚按，右手使一招「白鹤亮翅」，变拳成抓向$n的$l插去",
    "force" : 95,
    "dodge" : 10,
    "lvl" : 20,
    "skill_name" : "白鹤亮翅",
    "damage_type" : "抓伤"
]),
([  "action" : "$N左腿微曲成虚步，一记「搂膝勾步」，左手向前、向下划弧按于$n$l旁",
    "force" : 100,
    "dodge" : 15,
    "lvl" : 25,
    "skill_name" : "搂膝勾步",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N右臂半环，左手内旋，一招「手挥琶琶」，十指虚张，缓缓挥向$n的$l",
    "force" : 115,
    "dodge" : 10,
    "lvl" : 30,
    "skill_name" : "手挥琶琶",
    "damage_type" : "抓伤"
]),
([  "action" : "$N右腿伸直，左手虚划，接着右臂外旋搬出一记「进步搬拦锤」击向$n的$l",
    "force" : 135,
    "dodge" : 3,
    "lvl" : 35,
    "skill_name" : "进步搬拦锤",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N立半马步，左手内旋虚划，右手向下划弧握拳，一记「指裆锤」击向$n的裆部",
    "force" : 190,
    "dodge" : 15,
    "lvl" : 40,
    "skill_name" : "指裆锤",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手下划握拳，向后向前划弧成圈，一招「双风贯耳」，连消带打击向$n两太阳穴",
    "force" : 150,
    "dodge" : 10,
    "lvl" : 45,
    "skill_name" : "双风贯耳",
    "damage_type" : "内伤"
]),
([  "action" : "$N左步成虚，左手向下虚按，右手成阳，使一招「白蛇吐信」，向$n的$l插去",
    "force" : 135,
    "dodge" : 15,
    "lvl" : 50,
    "skill_name" : "白蛇吐信",
    "damage_type" : "抓伤"
]),
([  "action" : "$N出「揽雀尾」，右脚实，左脚虚，运起挤字诀，粘连粘随，搭住$n，横劲发出",
    "force" : 125,
    "dodge" : 10,
    "lvl" : 55,
    "skill_name" : "揽雀尾",
    "damage_type" : "震伤"
]),
([  "action" : "$N右脚虚立，左手画圈后抚，一招「高探马」，右手圆转向前，朝$n面门挥去",
    "force" : 110,
    "dodge" : 5,
    "lvl" : 60,
    "skill_name" : "高探马",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「伏虎式」，右手阳外划抱住$n，左手阴虚张五指，夹向$n的$l",
    "force" : 125,
    "dodge" : 10,
    "lvl" : 65,
    "skill_name" : "伏虎式",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手变掌横于胸前，右手握拳由肘下穿出，一招「肘底看锤」，锤向$n的$l",
    "force" : 110,
    "dodge" : 9,
    "skill_name" : "肘底看锤",
    "lvl" : 70,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚前踏半步，右手虚张使一招「海底针」，五指由下向上戳向$n的裆部",
    "force" : 130,
    "dodge" : 13,
    "skill_name" : "海底针",
    "lvl" : 75,
    "damage_type" : "抓伤"
]),
([  "action" : "$N一招「闪通臂」，左脚一个弓箭步抢到$n身前，右手上举外撇，发出太极劲力震向$n", 
    "force" : 210,
    "dodge" : 14,
    "skill_name" : "闪通臂",
    "lvl" : 80,
    "damage_type" : "震伤"
]),
([  "action" : "$N右脚踏出，左右手握拳虚划，好似怀中抱月，这记「揽月势」一出，便将$n网在太极圈内",
    "force" : 180,
    "dodge" : 5,
    "lvl" : 85,
    "skill_name" : "揽月势",
    "damage_type" : "内伤"
]),
([  "action" : "$N立半马步，坐腿、松胯、旋腰、扣膝，力发于腰，一招「马步靠」，靠向$n的$l",
    "force" : 160,
    "dodge" : 11,
    "skill_name" : "马步靠",
    "lvl" : 90,
    "damage_type" : "震伤"
]),
([  "action" : "$N左腿收起，右脚独立，使一招「金鸡独立」，双拳划开，两个太极圈圈向$n的$l",
    "force" : 140,
    "dodge" : 14,
    "skill_name" : "金鸡独立",
    "lvl" : 95,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N进步虚踏，双手握拳划弧挥出，使一式「玉女穿梭」，顺着$n手臂直上，打向$n前胸",
    "force" : 200,
    "dodge" : 8,
    "skill_name" : "玉女穿梭",
    "lvl" : 100,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手划圈，右手经腹前经左肋向前撇出，使一招「反身撇锤」，向$n的$l锤去",
    "force" : 130,
    "dodge" : 11,
    "skill_name" : "反身撇锤",
    "lvl" : 105,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚按，左脚直立，右腿虚划一招「转身蹬腿」，向后旋出踢向$n的$l",
    "force" : 140,
    "dodge" : 11,
    "skill_name" : "转身蹬腿",
    "lvl" : 110,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N进步一招「栽锤」，左手划太极圈搂左膝，右手握拳向下划弧，锤向$n的$l",
    "force" : 140,
    "dodge" : 4,
    "skill_name" : "栽锤",
    "lvl" : 115,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N脚踏七星方位，左虚右，双拳交叉成十字，一招「进步七星」，向$n的$l推去",
    "force" : 230,
    "dodge" : 5,
    "skill_name" : "进步七星",
    "lvl" : 120,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N身体微转，左手略直，右臂微曲，阴阳相合，使一招「倒撵猴」，扛起$n向后直甩出去",
    "force" : 150,
    "dodge" : 10,
    "skill_name" : "倒撵猴",
    "lvl" : 125,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手伸开，整个上身划出一个大圆弧，一招「转身摆莲」，将$n浑身上下笼罩在重重太极圈中",
    "force" : 170,
    "dodge" : 7,
    "skill_name" : "转身摆莲",
    "lvl" : 130,
    "damage_type" : "内伤"
]),
([  "action" : "$N右手缓缓后收，左手握拳向前推出，拳意如箭，一招「弯弓射虎」，直奔$n$l而去",
    "force" : 120,
    "dodge" : 11,
    "skill_name" : "弯弓射虎",
    "lvl" : 135,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使出一招「云手」，左手高，右手低，一个圆圈已将$n$l套住，太极柔劲随即发出",
    "force" : 300,
    "dodge" : 15,
    "lvl" : 140,
    "skill_name" : "云手",
    "damage_type" : "震伤"

]),
([  "action" : "$N轻跳一步「猢狲跃」，双手划太极圈拂开$n的攻击，借力打力抓起$n就往后掷出！",
    "force" : 140,
    "dodge" : 10,
    "lvl" : 145,
    "skill_name" : "猢狲跃",
    "damage_type" : "瘀伤"
]),
([  "action" : "当下$N一招「斜飞势」，将$n力量引偏，双拳内划，合阴阳两股劲力一齐推向$n",
    "force" : 170,
    "dodge" : 25,
    "lvl" : 150,
    "skill_name" : "斜飞势",
    "damage_type" : "瘀伤"
]),
([  "action" : "跟着$N换招「抱虎归山」，双拳划开，身体斜转，在$n身后一推，借力打力要将$n推出",
    "force" : 160,
    "dodge" : 15,
    "lvl" : 155,
    "skill_name" : "抱虎归山",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N来个「野马分鬃」，转向$n身后，右前左后，两臂平伸在$n身上一靠，想将他震飞",
    "force" : 270,
    "dodge" : 17,
    "lvl" : 160,
    "skill_name" : "野马分鬃",
    "damage_type" : "震伤"
]),
([  "action" : "$N施出「左转身搬拦捶」，上体左转，左拳外旋搬出，立拳打向$n的$l",
    "force" : 180,
    "dodge" : 18,
    "lvl" : 165,
    "skill_name" : "左转身搬拦捶",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左右手臂外旋变掌，两手交叉，继而左右分开，成半招「如封似闭」推向$n$l",
    "force" : 205,
    "dodge" : 10,
    "lvl" : 170,
    "skill_name" : "如封似闭",
    "damage_type" : "震伤"
]),
([  "action" : "$N施出「转身搬拦捶」，上体右转，右拳由下向上经左臂内侧搬向$n的$l",
    "force" : 190,
    "dodge" : 15,
    "lvl" : 175,
    "skill_name" : "转身搬拦捶",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「右转身搬拦捶」，身体再右转，屈膝弓步，右拳内旋立拳向前冲打$n",
    "force" : 200,
    "dodge" : 5,
    "lvl" : 180,
    "skill_name" : "右转身搬拦捶",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N两手臂向内旋下至腹前，屈臂坐腕，再由下向上，出「如封似闭」划前弧线推向$n",
    "force" : 185,
    "dodge" : 17,
    "lvl" : 185,
    "skill_name" : "如封似闭",
    "damage_type" : "震伤"
]),
([  "action" : "$N上体微右转，屈膝坐胯，出招「十字手」，两只手臂微内旋，分别向体两侧划弧分掌",
    "force" : 140,
    "dodge" : 7,
    "lvl" : 190,
    "skill_name" : "十字手",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N上体微左转，收招「十字手」，两臂外旋，从体两侧向前划弧合抱于胸，两腕搭成十字形",
    "force" : 120,
    "dodge" : 3,
    "lvl" : 195,
    "skill_name" : "十字手",
    "damage_type" : "瘀伤"
]),
([  "action" : "$N两前臂内旋前伸，左右分开，臂微屈，腕与肩平，两手心向下徐徐落向$n$l",
    "force" : 60,
    "dodge" : 25,
    "lvl" : 199,
    "skill_name" : "收势",
    "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
    mapping fam  = me->query("family");
//    if (fam["family_name"] != "武当派" || fam["generation"] != 2)
//         return notify_fail("太极拳只能从张三丰处学到。\n");
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练太极拳必须空手。\n");
//    if ((int)me->query_skill("yinyun-ziqi", 1) < 100)
//        return notify_fail("你的氤氲紫气火候不够，无法学太极拳。\n");
    if ((int)me->query("max_force") < 500)
        return notify_fail("你的内力太弱，无法练太极拳。\n");
//    if(me->query("taiji_quest") > me->query("taiji_zsf"))
//        return notify_fail("你觉得对太极拳理还不够理解，无法继续练习太极拳。\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
        for(i = sizeof(action)-1; i >= 0; i--)
               if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];    
}
void skill_improved(object me)
{
   int skill = me->query_skill("taiji-quan", 1);
   if(skill == 50 && !me->query("taiji_quest")) me->set("taiji_quest", 1);
   if(skill == 80 && me->query("taiji_zsf") < 2) me->set("taiji_quest", 2);
   if(skill == 110 && me->query("taiji_zsf") < 3) me->set("taiji_quest", 3);
   if(skill == 140 && me->query("taiji_zsf") < 4) me->set("taiji_quest", 4);
   if(skill == 170 && me->query("taiji_zsf") < 5) me->set("taiji_quest", 5);
   if(skill == 200 && me->query("taiji_zsf") < 6) me->set("taiji_quest", 6);   
   me->add("shen", me->query("combat_exp")/30);
}
mapping query_action(object me, object weapon)
{
    int i, j, level;
    object target; 
    level = (int) me->query_skill("taiji-quan",1);

    if (random(me->query_con()) > 30  &&  level > 120 && me->query("force") > 500){   
           me->add("force", -30);    
              return ([
                "action": HIY"$N左掌阳，右掌阴，目光凝视$n，两掌向$p慢慢合拢，竟是凝重如山，却又轻灵似羽！"NOR,
                "force" : 150,
                "dodge" : 10,
                "damage" : 50,
                "damage_type" : "内伤",
                "post_action": (: taiji :)             
                ]); 
        }         
     for(i = sizeof(action); i > 0; i--) {
         if(level > action[i-1]["lvl"]) {
//            j = NewRandom(i, 20, level/5);
//            target = offensive_target(me);   
            if (me->query_temp("taiji")) {                
                    return ([  
                    "action" : action[j]["action"],
                    "force" : 100+action[j]["force"]*2,
                    "dodge":action[j]["dodge"]*3,
                    "lvl" : action[j]["lvl"],
                    "damage_type" : action[j]["damage_type"],
                    ]);
               }
            return action[j];
            }
         }
}

int practice_skill(object me)
{
    int lvl = me->query_skill("taiji-quan", 1);
    int i = sizeof(action);
    while (i--) if (lvl == action[i]["lvl"]) return 0;
    if ((int)me->query("sen") < 40)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("force") < 20)
        return notify_fail("你的内力不够练太极拳。\n");
    me->receive_damage("sen", 30);
//    if(me->query_skill("juehu-shou", 1))
//      me->add("neili", -(me->query_skill("juehu-shou", 1)/5));
         me->add("force", -20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"taiji-quan/" + action;
}

int taiji(object me, object victim)
{
     string msg;
        if( random(me->query_kar()) > victim->query_kar()/20
           && !victim->is_busy()
           && me->query_skill_mapped("parry") == "taiji-quan") {
             msg = "$p只觉上盘各路已全处在$P双掌的笼罩之下，无可闪避，无可抵御，只得运劲于背，硬接他这一掌，
同时右臂紧挥，只盼两人各受一招，成个两败俱伤之局。\n";
             if(random(20) >= 18 && me->query("force") > 600){
                   msg += HIR"不料$N双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$p在原地急转七八下，
如转陀螺，如旋纺锤，好容易使出“千斤坠”之力定住身形，却已满脸胀得通红，狼狈万状！\n"NOR;
//                   victim->receive_damage("sen", me->query_skill("taiji-quan", 1)*2);
//                   victim->start_busy(2+random(2));
                   me->add("force", -20);
                   }
             else msg += "$N但觉气息微窒，当下一招“斜飞势”，将$N力量引偏，自己也退开两步。\n";
             message_vision(msg, me, victim);
             return 1;
        }
        return 1;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        int p,j,skill, neili, neili1;
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("force");
        neili1 = ob->query("force");

      if(me->query_temp("fanzhen")){
      	 me->delete_temp("fanzhen");
         return 1;
        }
        msg = "$N双手连划，太极圆圈在$n的"+wp1->name()+"上一绕，";
      if(me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "taiji-quan"
//         && me->query_skill("yinyun-ziqi", 1) > 50
         && neili > 100 
         && skill > 50 
         && living(me)
//         && me->query_temp("taiji")
         && !ob->query("env/invisibility")
         && random(10) >= 1)
         {         
         if(random(10) < 15) me->set_temp("fanzhen", 1);   
         if(wp1) msg = "$N双手连划，太极圆圈在$n的"+wp1->name()+"上一绕，";
         else msg = "$N双手划弧，连连打出太极圆圈，";
         if(neili >= neili1/100 + damage/100){
              msg += "结果$n的力道被太极拳借力打力反击回来！\n",              
              ob->receive_damage("kee", damage/2+ob->query("force_factor")*2, me);
              ob->receive_wound("kee", ob->query("force_factor"), me);
              p = ob->query("kee")*100/ob->query("max_kee");
              msg += damage_msg(damage/2, "震伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1/200+random(neili1/200)+random(damage/200)){
            msg += "结果$n的力道被太极拳借力打力卸在一旁！\n", 
              j = -8000;
              }
           else if(neili > neili1/200+damage/200){
              msg += "结果$n的力道被太极拳借力打力卸掉了一部分！\n", 
              j = -(damage/3+random(damage));               
              }
           else{
              msg += "结果$n的力道被太极拳借力打力卸掉了一小半！\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}


