// 【宣花三斧】, sanban-axe
// updated 6-16-97 pickle
 
/*
三板斧    dodge  20    parry  -15    damage  35
三板斧以奇见长，令人防不胜防，碰到使三板斧者以远距
游斗为好。再者每斧用力甚巨，一旦砍中，杀伤巨大。
*/

inherit SKILL;
void takeforce();
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N大喊一声"+HIR"「开瓜」"NOR"，手中$w带着这一吼的威猛之势，朝$n当头劈下",
                "damage":               45,
                "dodge":                -20,
                "parry":                -15,
                "damage_type":  	"劈伤",
		"name":			"开瓜",
//		"post_action": 		(:takeforce:),
        ]),
        ([      "action":
"$N大喊一声"+HIC"「剔牙」"NOR"，顺势带过大斧，趁$n一愣之际，以斧尾护手刀向$n面门疾戳",
                "damage":               55,
                "dodge":                -20,
                "parry":                -15,
                "damage_type": 		"刺伤",
		"name":			"剔牙", 
//		"post_action": 		(:takeforce:),
       ]),
        ([      "action":
"$N大喊一声"+HIY"「掏耳朵」"NOR"，翻转斧头，手中$w划出一道银弧，奔着$n的脑袋横劈",
                "damage":               45,
                "dodge":                -20,
                "parry":                -15,
                "damage_type": 		"劈伤",
		"name":			"掏耳朵", 
//		"post_action": 		(:takeforce:),
        ]),
	([       "action":
"$N大喊一声"+HIB"「捅」"NOR"，趁$n换招中的空隙，以斧尾护手刀向$n的$l狠狠戳了下去",
                "damage":               50,
                "dodge":                -20,
                "parry":                -15,
                "damage_type": 		"刺伤", //pickle, 戳伤 not deifined.
		"name":			"捅", 
//		"post_action":		(: takeforce :),
        ]),
});

int valid_learn(object me)
{
        object ob;
        int forcelev=(int)me->query_skill("lengquan-force",1);
        int axelev=(int)me->query_skill("sanban-axe", 1);
        int basicaxelev=(int)me->query_skill("axe", 1);
	int limit, forcelimit;

	if (me->query("betray/count"))
		return notify_fail("你求学之心不专，无缘学宣花三斧。\n");
	if(me->query("family/family_name") != "将军府")
		return notify_fail("宣花三斧乃将军府不传之密！\n");
        if( (string)me->query_skill_mapped("force")!= "lengquan-force")
	return notify_fail("宣花三斧需配合冷泉神功才可发挥威力。\n");
        limit=axelev;
        if(forcelimit<30 || (string)me->query("gender")=="男性")
	forcelimit=30;
	if(limit < 200) {
        	if(forcelev<limit)
			return notify_fail("你对内功领悟不足，无法用内功配合宣花三板斧的攻势。\n");
        	if(basicaxelev<limit)
			return notify_fail("你的斧法不够熟练，怎能就学宣花三斧？若是伤了自己可不是玩的。\n");
	}
        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，无法随意挥动一柄大斧。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "axe" )
                return notify_fail("手里没有斧头怎么能领悟师父所教的奥妙呢？\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="axe") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
    int total=2, current;
    if (me->query_skill("sanban-axe", 1) > 60)
	total=3;
    return action[random(total+1)];
/*    current=me->query("jjf/sanban-axe");
    if (current==total) current=-1;
    me->set("jjf/sanban-axe", current+1);
    return action[current];
*/
}
 
int practice_skill(object me)
{
        object weapon;
 
	if (me->query("betray/count"))
		return notify_fail("你求学之心不专，无缘学宣花三斧。\n");
	if(me->query("family/master_id") != "lao ren")
		return notify_fail("你虽会使用宣花三斧，却不知如何练习。\n");
        if( (string)me->query_skill_mapped("force")!= "lengquan-force")
	return notify_fail("宣花三斧需配合冷泉神功才可发挥威力。\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "axe" )
                return notify_fail("手中无斧，如何练习斧法？\n");
 
        if( (int)me->query("kee") < 50 
        ||    (int)me->query("force") < 30)
                return notify_fail("你的体力不够练宣花三斧，还是先休息休息吧。\n");
        me->receive_damage("kee", 50);
        me->add("force", -30);
        write("你按着所学练了一遍宣花三斧。\n");
        return 1;
}
 
string perform_action_file(string action)
{
        return CLASS_D("fighter") + "/sanban-axe/" + action;
}
void skill_improved(object me)
{
      if( (int)me->query_skill("sanban-axe", 1) % 10 == 0 ) 
        {
	tell_object(me, "\n你练斧过勤，受了点内伤。");
            me->add_maximum_force(-(int)(me->query_skill("sanban-axe",1)/10));
        }
	return;
}

void takeforce()
{
  object me=this_player();
  int reduce=(int)me->query("max_force")/25;

  if (me->query("force")>reduce)
    me->add("force", -reduce);
  else me->set("force", 0);
}
