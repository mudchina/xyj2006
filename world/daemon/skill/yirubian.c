//Cracked by Roath
//【忆如鞭】dhxy-evil 2000.7.5
//鞭法亦如林月如其人，性格乖张,但又情意缠绵。
//习武少女,仗剑江湖。鞭法招式也是记载了林月如一生敢爱敢恨.
inherit SKILL;
#include <ansi.h>
mapping *action =
({
([
"action" : "$N抖动$w，一式"HIM"「傲啸江湖」"NOR"漫天鞭影夹带着清脆的响声，震聋发出．",
"dodge"  : -5,
"damage" : 20,
"parry"  :  5,
"name"   : "傲啸江湖",
"damage_type" : "割伤",
]),
([
"action" : 
"$N秀发飞扬，仪态万千，使出一招"HIM"「魂萦梦牵」"NOR"，豪气中带有三分飘逸，美妙动人．",
"dodge"  : -10,
"damage" : 30,
"parry"  : 5,
"lvl"         : 10,
"damage_type" : "内伤",
"name"   : "魂萦梦牵",
]),
([
"action" : 
"$N反身使招"HIM"「月下隐士」"NOR"以巧劲顺势带开$n攻势，动作悠扬．\n"
"好似隐逸高人，在山巅明月之中，抚琴纾忧解闷。",
"dodge"  : -5,
"damage" : 20,
"parry"  : 5,
"lvl"         : 20,
"damage_type" : "刺伤",
"name"   : "月下隐士",
]),
([
"action" : 
"$N回剑指向自己心口，瞬即反弹出去，暴射出一股红光，挥洒如涌泉奔浪，\n"
"搅起一片血海。这招"HIM"「铁血丹心」"NOR"，映得众人眉发皆赤，粉颊红晕，娇容动人。",
"dodge"  : -10,
"damage" : 30,
"parry"  : -10,
"lvl"         : 30,
"damage_type" : "擦伤",
"name"   : "铁血丹心",
]),
([
"action" : 
"$N缓出左手抽出长鞭，劈面朝$n打去。$n慌忙逃开，$N皓腕一翻，"
"一招"HIM"「情缘不变」"NOR"打个正着。",
"dodge"  : 0,
"damage" : 20,
"parry"  : 0,
"lvl"         : 40,
"damage_type" : "割伤",
"name"   : "情缘不变",
]),
([
"action" : 
"$N娇躯微侧，一招"HIM"「临风傲立」"NOR"，运起十成鞭芒，望空疾刺向$n．"
,
"dodge"  : -10,
"damage" : 25,
"parry"  : -10,
"lvl"         : 50,
"damage_type" : "刺伤",
"name"   : "临风傲立",
]),
([
"action" : 
"只见$N一路"HIM"「梦无痕」"NOR"，$w黯然挥动，$n不免有些痴心情意．",
"dodge"  : -10,
"damage" : 20,
"parry"  : -10,
"lvl"         : 60,
"damage_type" : "割伤",
"name"   : "梦无痕",
]),
([
"action" : 
"$N一式"HIM"「往事如烟」"NOR"，手中$w吞吐不定，仿佛早诉说红颜自古多薄命，幽梦一帘几时醒。",
"dodge"  : -20,
"damage" : 30,
"parry"  : 0,
"lvl"         : 70,
"damage_type" : "割伤",
"name"   : "往事如烟",
]),
([
"action" : 
"$N一声娇叱，$w矫夭飞舞，一路"HIM"「随风逝」"NOR"真个是悠悠春梦随云散，片片飞花逐水流。",
"dodge"  : 0,
"damage" : 30,
"parry"  : 10,
"lvl"         : 80,
"damage_type" : "内伤",
"name"   : "随风逝",
]),
([
"action" : 
"$N眉头一皱，忽然收招，回$w翻飞，"HIM"「繁星点点」"NOR"向$n的胸前刺去。",
"dodge"  : -10,
"damage" : 20,
"parry"  : 0,
"lvl"         : 90,
"damage_type" : "刺伤",
"name"   : "繁星点点",
]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练忆如鞭。\n");
        if( me->query("gender") !="女性" )
                return notify_fail(HIC"痴心若遇真情意，翩翩彩蝶化红妆。\n"NOR,me);
        if(me->query("family/master_id") != "lin yueru" && 
            me->quert("family/master_name" != "蜀山剑派") )
		return notify_fail("你虽会使用思如鞭，却不知如何练习。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("你必须先找一根鞭子才能练忆如鞭。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}	
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}	
int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习忆如鞭。\n");
        if( me->query("gender") !="女性")
                return notify_fail(HIC"痴心若遇真情意，翩翩彩蝶化红妆。\n"NOR,me);
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write(HIR"往事如烟，魂萦梦牵，增添我心中思念．\n"NOR,me);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("shushan") + "/yirubian/" + func;
}
