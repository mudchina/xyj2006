// chixin-jian.c
// 痴心情长剑法
// Juney: 07/04/97: Genesis.
//lestat 2001 修改for盘丝洞红颜白发
//痴心情长剑为白晶晶绝技

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit SKILL;
string *xue_name = ({ 
HIR"劳宫穴"NOR,HIR"膻中穴"NOR,HIR"曲池穴"NOR,
HIG"关元穴"NOR,HIG"曲骨穴"NOR,HIG"中极穴"NOR,
HIY"承浆穴"NOR,HIY"天突穴"NOR,HIY"百会穴"NOR,
HIM"幽门穴"NOR,HIM"章门穴"NOR,HIM"大横穴"NOR,
HIW"紫宫穴"NOR,HIW"冷渊穴"NOR,HIW"天井穴"NOR,
HIC"极泉穴"NOR,HIC"清灵穴"NOR,HIC"至阳穴"NOR,}); 
string *baifa= ({
HIB"$N念着口诀：情投意合展欢颜，突来横祸阴阳隔。\n"NOR,
HIY"$N念着口诀：朝朝暮暮频思忆，千里婵娟只是空。\n"NOR,
CYN"$N念着口诀：生生世世长相伴，却恨天公不作美。\n"NOR,
MAG"$N念着口诀：聚日无多相思苦，此恨绵绵无绝期。\n"NOR,
HIG"$N念着口诀：黯然神伤泪满面，愿人长久空遗恨。\n"NOR,
HIW"$N念着口诀：今世未能偕白头，来生还盼续前缘。\n"NOR,
HIM"$N念着口诀：此情不移坚似钢，质问天公不开眼。\n"NOR,
HIC"$N念着口诀：痴痴伤怀动情时，但舞痴心情长剑。\n"NOR
});
mapping *action =
({
([
"action" : 
"$N使一式"+HIC"『情投意合展欢颜』"NOR+"，面露微笑，手中$w一抖，剑光
暴长，洒向$n的$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"skill_name"  : "『情投意合展欢颜』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIC"『突来横祸阴阳隔』"NOR+"，身形骤闪，剑招陡变，手中$w
从一个绝想不到的方位斜斜刺向$n的$l",
"dodge"  : -10,
"damage" : 15,
"parry"  : -10,
"skill_name"  : "『突来横祸阴阳隔』",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N使一式"+HIC"『朝朝暮暮频思忆』"NOR+"，暴退数尺，低首抚剑片刻，随
后手中$w骤然穿上，刺向$n的$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : -20,
"skill_name"  : "『朝朝暮暮频思忆』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIC"『千里婵娟只是空』"NOR+"，身形一晃，疾掠而上，手中$w
龙吟一声，对准$n的$l连递数剑",
"dodge"  : 10,
"damage" : 25,
"parry"  : -10,
"skill_name"  : "『千里婵娟只是空』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIC"『生生世世长相伴』"NOR+"，一闪而上扑向$n，如影相随，
手中$w“铮”然有声，往$n的$l刺去",
"dodge"  : 10,
"damage" : 20,
"parry"  : -10,
"skill_name"  : "『生生世世长相伴』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIC"『却恨天公不作美』"NOR+"，一个侧身，手中$w疾往斜上挑
起，直指$n的$l",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"skill_name"  : "『却恨天公不作美』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIC"『聚日无多相思苦』"NOR+"，微微一个转身，手中$w却已自
肋下穿出，罩向$n的$l",
"dodge"  : -20,
"damage" : 30,
"parry"  : 10,
"skill_name"  : "『聚日无多相思苦』",
"damage_type" : "内伤",
]),
([
"action" : 
"$N使一式"+HIC"『此恨绵绵无绝期』"NOR+"，神色微变，剑招陡然变得凌厉无
比，手中$w如匹链般洒向$n的$l",
"dodge"  : -10,
"damage" : 20,
"parry"  : 5,
"skill_name"  : "『此恨绵绵无绝期』",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N使一式"+HIC"『黯然神伤泪满面』"NOR+"，缓缓低首，暗自叹了口气，眼中
莹光流动，接着手中$w中宫直进，迅捷无比地往$n的$l刺去",
"dodge"  : 10,
"damage" : 20,
"parry"  : -10,
"skill_name"  : "『黯然神伤泪满面』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIC"『愿人长久空遗恨』"NOR+"，腾身飞跃，手中$w于半空中闪下，
化作一道白色长弧洒向$n的$l",
"dodge"  : 20,
"damage" : 20,
"parry"  : -10,
"skill_name"  : "『愿人长久空遗恨』",
"damage_type" : "刺伤",
]),
([
"action" : "$N使一式"+HIC"『今世未能偕白头』"NOR+"，矮身侧步，手中$w反手疾挑而出，
“唰”的一声往$n的$l刺去",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"skill_name"  : "『今世未能偕白头』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIC"『来生还盼续前缘』"NOR+"，蓦地疾退一步，又冲前三步，手中
$w化为光弧往$n的$l刺去",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"skill_name"  : "『来生还盼续前缘』",
"damage_type" : "内伤",
]),
([
"action" : "$N使一式"+HIC"『此情不移坚似钢』"NOR+"，纵身跃起，不见踪影，接着却又从
半空中穿下，双手握着$w，声势逼人地刺向$n的$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"skill_name"  : "『此情不移坚似钢』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N使一式"+HIC"『质问天公不开眼』"NOR+"，手中$w“嗤”的一声斜刺向天空，
随即向下“唰唰”两下，划出一个叉字，往$n的$l刺去",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"skill_name"  : "『质问天公不开眼』",
"damage_type" : "内伤",
]),
([
"action" : "$N使一式"+HIC"『痴痴伤怀动情时』"NOR+"，左腿微抬，手中$w自下方挑起，
激起一股劲风反挑$n的$l",
"dodge"  : -5,
"damage" : 20,
"parry"  : -10,
"skill_name"  : "『痴痴伤怀动情时』",
"damage_type" : "割伤",
]),
([
"action" : 
"$N倾尽全力舞出"+HIC"『但舞痴心情长剑』"NOR+"，神色十分激动，眼中泪珠
滚动，手中$w疾舞不停，全身都已笼罩在迫人的剑气中，$n不由骇然，只见$N
身形微变，无数道剑气已逼向$n的$l",
"dodge"  : -10,
"damage" : 50,
"parry"  : -25,
"skill_name"  : "『但舞痴心情长剑』",
"damage_type" : "内伤",
]),
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me) {
    if ((int)me->query_skill("jiuyin-xinjing",1) < 20 )
	return notify_fail("你的九阴心法为尚浅，没法学痴心情长剑！\n");
    if ((int)me->query_skill("yueying-wubu", 1) < 20)
        return notify_fail("你的月影舞步修为尚浅，没法学痴心情长剑！\n");
    return 1;
}

mapping *action_baifa =
({
([
"action" : 
RED"$N十指尖尖拨动琴弦，抚弄一曲，名曰："+HIG"「风入松」"+NOR+RED"，音韵幽扬，如万壑松涛，一丝丝"+NOR+HIW"白发"+NOR+RED"向周身百骸袭来"NOR,
"parry_msg" :
"$n轻敲檀板，宛转歌喉，音若笙，满楼亮。一首"+HIB"「缘定三生」"+NOR"，$N只听的颠倒情怀，竟垂手而立，洗耳恭听。",
"parry_power":		10,
"dodge"  : -10,
"parry" : -10,
"force" : 100,
"skill_name"  : "风入松",
"damage_type" : "刺伤",
]),
([
"action" : 
RED"$N拨动琴弦，一曲"+NOR+HIM"「花满楼」"+NOR+RED"，$N"+NOR+HIW"白发"+NOR+RED"随琴声满天飞舞，但听铮一声响，漫天"+NOR+HIW"白发"+NOR+RED"同时刺向$n"NOR+xue_name[random(sizeof(xue_name))],
"parry_msg" :
"$n满头"+NOR+HIW"白发"+NOR"往来穿梭,破空之音竟似一曲"+HIM"「梅花三弄」"+NOR"，将$N的招式一一截住。",
"parry_power":		10,
"dodge"  : -20,
"parry" : -10,
"force" : 100,
"skill_name"  : "花满楼",
"damage_type" : "刺伤",
]),
([
"action" : 
RED"只听音韵真如戛玉鸣球，清婉欲绝，一曲"+NOR+HIW"「寒江雪」"+NOR+RED"今$n尘襟顿爽，突然"+NOR+HIW"一缕白发"+NOR+RED"划破琴音破空刺向$n"NOR+xue_name[random(sizeof(xue_name))],
"parry_power":		10,
"parry_msg" :
"$n双手拨动琴弦，一曲"+HIY"「阳关三叠」"+NOR"如凤鸣鸾啼，一丝丝罡气随琴音汹涌而至，$N急忙撤招回防。",
"dodge"  : -20,
"parry" : -10,
"force" : 100,
"skill_name"  : "寒江雪",
"damage_type" : "刺伤",
]),
([
"action" : 
RED"$N手姿俊雅，将琴拨动，一曲"+NOR+HIC"「月牙泉」"+NOR+RED"，琴音叮叮咚咚，妙不可言。$n只听得神荡意迷，情飞心逸，如醉如痴，
不觉"+NOR+HIW"一缕缕白发"+NOR+RED"已悄然刺向"NOR+xue_name[random(sizeof(xue_name))],
"parry_power":		10,
"parry_msg" :
"$n抚弄一曲"+HIC"「三潭映月」"+NOR"，朱唇轻启，随曲唱道：杨柳依依弄晚风，桃花半吐映日红；芳草绵绵铺锦绣，任他车马各西东。$N听得入神招式一滞，被"+NOR+HIW"一缕缕白发"+NOR"一一化解。",
"dodge"  : -20,
"parry" : -20,
"force" : 100,
"skill_name"  : "月牙泉",
"damage_type" : "刺伤",
]),
});
mapping query_action(object me, object weapon)
{
 if(me->query_temp("BAIFA_perform") )
  {
 return action_baifa[random(sizeof(action_baifa))];
        }
 else{  
 return action[random(sizeof(action))];}
}
string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}
int practice_skill(object me) {
    object weapon, target;
    if (!objectp(weapon = me->query_temp("weapon")) ||
	(string)(weapon->query("skill_type")) != "sword")
	return notify_fail("你这才想起手里没剑，怎么练痴心情长剑啊？ :)\n");
//	if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
//     return notify_fail("痴心情长剑法必须配合盘丝洞的九阴心法才能练。\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("kee", 30);
    message_vision(baifa[random(sizeof(baifa))], me, target);
    return 1;
}
void skill_improved(object me)
{
        if( (int)me->query_skill("chixin-jian", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 50);
        }
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;
        if(!me->query_temp("BAIFA_perform")) return 0;
        me->add("force", -damage_bonus);
        me->add("sen", -100);
        
}
string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/chixin-jian/" + action;
}
