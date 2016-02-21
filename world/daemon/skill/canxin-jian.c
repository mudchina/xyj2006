//Cracked by Roath
// canxin-jian.c【残心剑法】
// DHXY_EVIL 2000.7.5
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "name":   "昨日总总",
    "action" : "$N身体左转，左手剑指，剑尖前端一寸处短促抖腕发力，\n"
    "一招"HIR"「昨日总总」"NOR"，手中$w轻轻颤动，一剑自上而下扎向$n．",
    "dodge" : 5,
    "damage" : 15,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "心深种",
    "action" : "$N身形不动，右前臂外旋，剑刃上崩，一招"HIR"「心深种」"NOR"，\n"
    "手中$w向前下反刺，一剑指向$n",
    "dodge" : 10,
    "damage" : 20,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "他夜梦里",
    "action" : "$N左脚向前，蹬地跳起，右手$w突向前刺，随转体变向，\n"
    "使出一式"HIR"「他夜梦里」"NOR"，剑光如匹练般泄向$n",
    "dodge" : 5,
    "damage" : 25,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "再续未了缘",
    "action" : "$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手$w使出一式"HIR"「再续未了缘」"NOR"，"
    "剑锋往来运转如梭，连绵不绝刺向$n",
    "dodge" : -5,
    "damage" : 35,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "情丝难断",
    "action" : "$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手$w使出\n"
    "一式"HIR"「情丝难断」"NOR"刺向$n",
    "dodge" : -10,
    "damage" : 30,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "心难负",
    "action" : "$N左上步，抱剑当胸，右手$w一式"HIR"「心难负」"NOR"，"
    "剑意圆润，刺向$n",
    "dodge" : 0,
    "parry"  :15,
    "damage" :30,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "仗剑江湖",
    "action" : "$N侧身退步，左手剑指划转，右手$w一记"HIR"「仗剑江湖」"NOR"，"
    "自下上撩指向$n",
    "dodge" : -10,
    "damage" : 40,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "梦已远",
    "action" : "$N碎步急进，提剑沿剑身方向疾速上崩，一招"HIR"「梦已远」"NOR"直取$n",
    "dodge" : -5,
    "damage" : 40,
    "parry"  :25,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "忽见灵池一朵莲",
    "action" : HIG"\n第一剑「仙灵仙岛难觅仙，忽见灵池一朵莲．」，自上而下！"NOR,
    "dodge" : -15,
    "damage" : 40,
    "force"  : 100,
    "parry"  :-100,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "红颜如月有圆缺",
    "action" : HIG"\n第二剑「红颜如月有圆缺，君名逍遥莫悲切．」，从左到右！"NOR,
    "dodge" : -15,
    "damage" : 50,
    "parry"  :-100,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "参天树下识苗女",
    "action" : HIG"\n第三剑「参天树下识苗女，同赴密林寻宝途。」，旋转而至！"NOR,
    "dodge" : -10,
    "damage" : 60,
    "parry"  :-100,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),

});
int valid_enable(string usage) { 
    return (usage == "sword") || (usage == "parry");
}
int valid_learn(object me)
{
    if ((int)me->query("force") < 100)
   return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("force", 1) < 10)
   return notify_fail("你的内功火候太浅。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("xiangsi");
	if( !me->query("xiangsi") ) {
        return action[random(8)];
	}else {
	return action[i];
	}
}        
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习三清剑法。\n");
	me->add("kee", -30);
	me->add("force", -3);
	write(HIC"天若有情天仪老，月如无恨月长圆。\n"NOR,me);
	return 1;
}
string perform_action_file(string func) {
  return CLASS_D("shushan") + "/canxin-jian/" + func;
}

