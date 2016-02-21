// 青霞剑法
// coded by lestat 2/2/2001
// updated by xintai 2/3/2001

// 青霞剑法 dodge -10   parry -10  damage 20 force 100


inherit SKILL;
#include <ansi.h>
mapping *action =
({
([
"action" : 
"$N使出"+BLINK""+MAG"「清饮小酌」"NOR"剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的$l",
"dodge"  : -20,
"damage" : 15,
"parry"  : 10,
"force"         : 50,
"skill_name"  : "「清饮小酌」",
"damage_type" : "割伤",
]),
([
"action" : 
"$N手中$w由内自外一刺，左手如斟茶壶，使出"+BLINK""+MAG"「扫雪烹茶」"NOR"来",
"dodge"  : -20,
"damage" : 10,
"parry"  : -10,
"force"         : 60,
"skill_name"  : "「扫雪烹茶」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招"+BLINK""+MAG"「抚琴按萧」"NOR"",
"dodge"  : -10,
"damage" : 15,
"parry"  : -5,
"force"         : 40,
"skill_name"  : "「抚琴按萧」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一招"+BLINK""+MAG"「松下对弈」"NOR"，$w自右向左挥一个大弧，刺向$n的$l",
"dodge"  : 0,
"damage" : 20,
"parry"  : -10,
"force"         : 50,
"skill_name"  : "「松下对弈」",
"damage_type" : "割伤",
]),
([
"action" : 
"$N左手如拂五弦，竟以掌为剑攻向$n，却是一招"+BLINK""+MAG"「池边调鹤」"NOR"",
"dodge"  : -15,
"damage" : 20,
"parry"  : -10,
"force"         : 50,
"skill_name"  : "「池边调鹤」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一招"+BLINK""+MAG"「小园艺菊」"NOR"，手中$w迅疾向$n的下盘连点三点",
"dodge"  : -15,
"damage" : 20,
"parry"  : -5,
"force"         : 50,
"skill_name"  : "「小园艺菊」",
"damage_type" : "刺伤",
]),
([
"action" : "$N使出"+BLINK""+MAG"「西窗夜话」"NOR"，手中$w中宫直入，攻向$n的$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 50,
"skill_name"  : "「西窗夜话」",
"damage_type" : "割伤",
]),
([
"action" : 
"$N脚下左高右低，一招"+BLINK""+MAG"「柳荫联句」"NOR"，$w在空中化成一道光环，急攻$n",
"dodge"  : -10,
"damage" : 20,
"parry"  : -5,
"force"         : 70,
"skill_name"  : "「柳荫联句」",
"damage_type" : "内伤",
]),
([
"action" : "$N手中$w由下而上卷起，犹如打起竹帘一般，却是"+BLINK""+MAG"「竹帘临池」"NOR"",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"force"         : 80,
"skill_name"  : "「竹帘临池」"NOR"",
"damage_type" : "割伤",
]),
([
"action" : 
"$N左手剑诀一领，右手$w平平刺向$n的$l，是一招"+BLINK""+MAG"「双蝶迷回」"NOR"",
"dodge"  : -10,
"damage" : 20,
"parry"  : -5,
"force"         : 100,
"skill_name"  : "「双蝶迷回」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N手中$w合身疾刺，一招"+BLINK""+MAG"「孤云出釉」"NOR"，直指$n的$l",
"dodge"  : -10,
"damage" : 35,
"parry"  : -25,
"force"         : 120,
"skill_name"  : "「孤云出釉」",
"damage_type" : "内伤",
]),
([
"action" : 
"$N一招"+BLINK""+MAG"「幽兰空谷」"NOR"，$w看似随意地一挥，从$n不可思议的角度攻入",
"dodge"  : -10,
"damage" : 20,
"parry"  : -25,
"force"         : 120,
"skill_name"  : "「幽兰空谷」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使出"+BLINK""+MAG"「茶花满路」"NOR"，一时间空中尽是$w的影子，令$n不知如何抵挡",
"dodge"  : -10,
"damage" : 20,
"parry"  : -5,
"force"         : 110,
"skill_name"  : "「茶花满路」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一招"+BLINK""+MAG"「陌路采桑」"NOR"，$w连点数点，疾刺$n的$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : -15,
"force"         : 120,
"skill_name"  : "「陌路采桑」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N错开脚步，手中$w突然从自己的肋下刺出，却是一招"+BLINK""+MAG"「琴心剑胆」"NOR"",
"dodge"  : -10,
"damage" : 50,
"parry"  : -25,
"force"         : 130,
"skill_name"  : "「琴心剑胆」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N犹如在水面滑行一般，一招"+BLINK""+MAG"「池塘秋夜」"NOR"，平平地向$n的$l挥去",
"dodge"  : 0,
"damage" : 20,
"parry"  : -25,
"force"         : 80,
"skill_name"  : "「池塘秋夜」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一招"+BLINK""+MAG"「皓腕玉镯」"NOR"，手中$w刺点$n的手腕",
"dodge"  : -10,
"damage" : 15,
"parry"  : -5,
"force"         : 100,
"skill_name"  : "「皓腕玉镯」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一招"+BLINK""+MAG"「牡丹含泪」"NOR"，$w绕出数个银圈，平平地向$n的$l卷去",
"dodge"  : -15,
"damage" : 20,
"parry"  : 15,
"force"         : 150,
"skill_name"  : "「牡丹含泪」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N左脚轻点地面，身形往前一扑，一招"+BLINK""+MAG"「芍药蕴珠」"NOR"，$w向$n的$l刺去",
"dodge"  : 0,
"damage" : 15,
"parry"  : -15,
"force"         : 150,
"skill_name"  : "「芍药蕴珠」",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N脸现黯然之色，随意一招"+BLINK""+MAG"「蒹葭苍苍」"NOR"，$w刺向$n的$l",
"dodge"  : -25,
"damage" : 25,
"parry"  : -25,
"force"         : 180,
"skill_name"  : "「蒹葭苍苍」",
"damage_type" : "刺伤",
]),
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me) {
    if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("青霞剑法必须配合盘丝洞的九阴心法才能练。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
	(string)(weapon->query("skill_type")) != "sword")
	return notify_fail("你这才想起手里没剑，怎么练青霞剑法啊？ :)\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("kee", 30);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 80 ) return 0;

if(me->query("family/family_name") != "盘丝洞")
return 0;
        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 80) / 4 );
                switch(random(3)) {
                        case 0: return HIW"$n身上被剑气划开一道深可见骨的伤口！\n"NOR;
                        case 1: return HIW"$N劲力一吐，一道剑气从$w中冲出击中$n的$l！\n"NOR;
                        case 2: return HIW"$N低喝一声，$w上剑芒吞吐闪烁！\n"NOR;
                }
        }

}


string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/qingxia-jian/" + action;
}
