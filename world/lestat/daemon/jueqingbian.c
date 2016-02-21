// jueqing-bian.c
// 绝情鞭法
// Juney: 07/04/97: Genesis.
/*绝情鞭法为痴梦所创，鞭法缠绵如丝，如情爱挥之不去，躲之不得，直叫生死相许。
*/
//lestat modi 2001 for moon
inherit SKILL;
#include <ansi.h>
mapping *action =
({
([
"action" : "只见$N纤腰急转，皓腕轻抖，一式"HIM"「天地双飞」"NOR"，$w在身畔化作两道飞虹",
"dodge"  : -5,
"damage" : 40,
"parry"  : -10,
"lvl"         : 0,
"skill_name"  : "天地双飞",
"damage_type" : "割伤",
]),
([
"action" : 
"$N默运冰心决，使出"HIM"「几回寒暑」"NOR"，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉",
"dodge"  : -10,
"damage" : 50,
"parry"  : -5,
//"lvl"         : 10,
"skill_name"  : "几回寒暑",
"damage_type" : "内伤",
]),
([
"action" : 
"$N一式"HIM"「君应有语」"NOR"，神色凄楚惘然，$w斜斜舞出，$n心中一凛，只觉得这目光似曾相识，却又说不上来",
"dodge"  : -5,
"damage" : 70,
"parry"  : -5,
"skill_name"  : "君应有语",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N霞袖慢垂，莲步急趋，手中$w似影随形，一招"HIM"「只影向谁」"NOR"愈显落落欲往，矫矫不群",
"dodge"  : -10,
"damage" : 50,
"parry"  : -10,
"skill_name"  : "只影向谁",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N徐徐舞动$w，却是一招"HIM"「万里层云」"NOR"，只见招断意连，缠绵婉转，一鞭未绝，便隐隐有万鞭相随",
"dodge"  : 0,
 "damage" : 40,
"parry"  : 0,
"skill_name"  : "万里层云",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式"HIM"「千山暮雪」"NOR"，$w挥洒自如，霎时间绛雪纷纷，娇如柳絮，弱似梨花，密密裹住$n全身",
"dodge"  : -10,
 "damage" : 45,
"parry"  : -10,
"skill_name"  : "千山暮雪",
"damage_type" : "刺伤",
]),
([
"action" : 
"只见$N一路"HIM"「寂寞箫鼓」"NOR"，$w回风舞雪，暗合韵理，虽无丝竹之音，反倒别有幽愁暗恨生，此时无声胜有声",
"dodge"  : -10,
"damage" : 55,
"parry"  : -10,
"skill_name"  : "寂寞箫鼓",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式"HIM"「荒烟平楚」"NOR"，手中$w吞吐不定，仿佛一层轻烟薄雾飘上$n肩头，若即若离，似真似幻，极尽悱恻哀艳之美",
"dodge"  : -20,
"damage" : 40,
"parry"  : 0,
"skill_name"  : "荒烟平楚",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一声娇叱，$w上内劲贯注，矫夭飞舞，一路"HIM"「莺燕黄土」"NOR"所过之处落英缤纷，红消香断，劲风只刮得$n脸颊生痛",
"dodge"  : 0,
"damage" : 40,
"parry"  : -10,
"skill_name"  : "莺燕黄土",
"damage_type" : "内伤",
]),
([
"action" : 
"忽然间$N鞭势陡变，$w浏漓顿挫，古意盎然，一式"HIM"「千秋万古」"NOR"如月之曙，如气之秋，纵有千载情愁，亦化于这一招之中",
"dodge"  : -10,
"damage" : 45,
"parry"  : 0,
"skill_name"  : "千秋万古",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一式"HIM"「情是何物」"NOR"，鞭意缱绻缠绵，如泣如诉，犹似双丝网，中有千千结，直教$n剪之不断，理之还乱",
"dodge"  : -10,
"damage" : 60,
"parry"  : -10,
"skill_name"  : "情是何物",
"damage_type" : "割伤",
]),
([
"action" : 
"$N袖舞时幻起花雨满天，鞭落处化作断霞千缕，一式"HIM"「生死相许」"NOR"鞭人合一，着着抢攻，全然不顾$n进招",
"dodge"  : -20,
"damage" : 40,
"parry"  : -10,
"skill_name"  : "生死相许",
"damage_type" : "刺伤",
]),
});

mapping *action_male =
({
([
"action" : "只见$N身形疾转，手腕轻抖，一式「天地双飞」，$w在身畔化作两道飞虹",
"dodge"  : -20,
"damage" : 20,
"force" : 40,
"skill_name"  : "天地双飞",
"damage_type" : "割伤",
]),
([
"action" : 
"$N默运冰心决，使出「几回寒暑」，一缕忽冷忽热的真气沿$w激射而来，径透$n丹田百脉",
"dodge"  : -20,
"damage" : 30,
"force" : 50,
"skill_name" : "几回寒暑",
"damage_type" : "内伤",
]),
([
"action" : 
"$N一式「君应有语」，神色凄楚惘然，$w斜斜挥出，$n心中一凛，只觉得这目光似曾相识，却又说不上来",
"dodge"  : -25,
"damage" : 40,
"force" : 60,
"skill_name"  : "君应有语",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N云袖慢垂，莲步急趋，手中$w如影随形，一招「只影向谁」愈显落落欲往，矫矫不群",
"dodge"  : -25,
"damage" : 50,
"force" : 80,
"skill_name"  : "只影向谁",
"damage_type" : "擦伤",
]),
([
"action" : 
"$N徐徐舞动$w，却是一招「万里层云」，只见招断意连，缠绵婉转，一鞭未绝，便隐隐有万鞭相随",
"dodge"  : -30,
"damage" : 60,
"force" : 100,
"skill_name"  : "万里层云",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「千山暮雪」，$w挥洒自如，霎时间绛雪纷纷，柔如柳絮，弱似梨花，密密裹住$n全身",
"dodge"  : -30,
"damage" : 70,
"force" : 110,
"skill_name"  : "千山暮雪",
"damage_type" : "刺伤",
]),
([
"action" : 
"只见$N一路「寂寞箫鼓」，$w回风舞雪，暗合韵理，虽无丝竹之音，反倒别有幽愁暗恨生，此时无声胜有声",
"dodge"  : -35,
"damage" : 80,
"force" : 120,
"lvl"         : 60,
"skill_name"  : "寂寞箫鼓",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一式「荒烟平楚」，手中$w吞吐不定，仿佛一层轻烟薄雾飘上$n肩头，若即若离，似真似幻，极尽悱恻哀艳之美",
"dodge"  : -35,
"damage" : 80,
"force" : 125,
"lvl"         : 70,
"skill_name"  : "荒烟平楚",
"damage_type" : "割伤",
]),
([
"action" : 
"$N一声清啸，$w上内劲贯注，矫夭飞舞，一路「莺燕黄土」所过之处落英缤纷，红消香断，劲风只刮得$n脸颊生痛",
"dodge"  : -40,
"damage" : 90,
"force" : 130,
"lvl"         : 80,
"skill_name"  : "莺燕黄土",
"damage_type" : "内伤",
]),
([
"action" : 
"忽然间$N鞭势陡变，$w浏漓顿挫，古意盎然，一式「千秋万古」如月之曙，如气之秋，纵有千载情愁，亦化于这一招之中",
"dodge"  : -40,
"damage" : 90,
"force" : 150,
"lvl"         : 90,
"skill_name"  : "千秋万古",
"damage_type" : "刺伤",
]),
([
"action" : 
"$N一式「情是何物」，鞭意缱绻缠绵，如泣如诉，犹似双丝网，中有千千结，直教$n剪之不断，理之还乱",
"dodge"  : -45,
"damage" : 150,
"lvl"         : 100,
"skill_name"  : "情是何物",
"damage_type" : "割伤",
]),
([
"action" : 
"$N袖舞时幻起花雨满天，鞭落处化作断霞千缕，一式「生死相许」鞭人合一，着着抢攻，着着抢攻，全然不顾$n进招",
"dodge"  : -45,
"damage" : 150,

"force" : 160,
"lvl"         : 110,
"skill_name"  : "生死相许",
"damage_type" : "刺伤",
]),
});

mapping *action_sanshou =
({
([
"action" : 
HIY"第一招"+HIG"「无孔不入」"+NOR+HIY"，乃是向对手全身各处大穴进攻，$n"+NOR+HIY"只觉得香风袭袭，周身百骸都是$w"+NOR+HIY"的影子"NOR,
"dodge"  : -50,
"damage" : 80,
"force" : 80,
"lvl"         : 100,
"skill_name"  : "无孔不入",
"damage_type" : "刺伤",
]),
([
"action" : 
HIM"紧跟着$N"+HIM"使出"+NOR+HIC"「无所不至」"+NOR+HIM"，虽为一招，其实千头万绪，$w"+NOR+HIM"同时点向$n"+NOR+HIM"周身诸处偏门穴道"NOR,
"dodge"  : -50,
"damage" : 70,
"force" : 100,
"lvl"         : 100,
"skill_name"  : "无所不至",
"damage_type" : "刺伤",
]),
([
"action" : 
HIW"第三招"+NOR+HIB"「无所不为」"+NOR+HIW"，不再点穴，而专击$n"HIW"眼睛、咽喉、小腹、下阴等诸般柔软之处，阴毒无比"NOR,
"dodge"  : -50,
"damage" : 50,
"force" : 120,
"lvl"         : 100,
"skill_name"  : "无所不为",
"damage_type" : "刺伤",
]),
});

int valid_enable(string usage) {
    return usage == "whip" || usage == "parry";
}

int valid_learn(object me) {
//   if (me->query("family/master_id") != "chi meng" && (int)me->query_skill("jueqingbian",1)<101 )
//    return notify_fail("你与痴梦无缘,无法学习绝情鞭法!\n");

 if ((int)me->query_skill("moonshentong",1) < 40 )
        return notify_fail("你的圆月修心法为尚浅，没法学绝情鞭！\n");
    if ((int)me->query_skill("moondance", 1) < 50)
        return notify_fail("你的冷月凝香舞修为尚浅，没法学绝情鞭！\n");
    return 1;
}
string query_skill_name(int level) {
    int i;
    for (i=sizeof(action)-1; i>=0; i--)
        if (level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
 int i;
 i=me->query_action("JQB_perform");
 if( ! me->query_temp("JQB_perform")) {
 return action[random(10)];
} else {
 return action_sanshou[random(sizeof(action_sanshou))];
}
  return action[random(sizeof(action))];
}
int practice_skill(object me) {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)(weapon->query("skill_type")) != "whip")
        return notify_fail("你这才想起手里没鞭子，怎么练绝情鞭啊？ :)\n");
    if ((int)(me->query("kee")) < 50)
        return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("kee", 30);
    return 1;
}
string perform_action_file(string action)
{
return CLASS_D("moon") + "/jueqingbian/" + action;
}

