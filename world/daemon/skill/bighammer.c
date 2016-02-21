//【大势锤】??

/*
  dodge  5    parry  0    damage  35
威力巨大，命中平平
*/
#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
	([	"action":	"$N挥舞手中$w一招[佛法无边]罩面砸向",
 "dodge":        -10,
 "parry":        0,
		"damage":	30,
		"damage_type":	"砸伤",
	]),
	([	"action":	"$N一声大吼，手中$w一招[河东狮吼]化做一道罡气直袭$1",
		"dodge":	15,
"parry":        5,
"damage":       40,
		"damage_type":	"砸伤",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	([	"action":	"$N将$w高举过肩，对准$n的$l就是一下",
		"dodge":	20,
		"parry":	-10,
		"damage":	35,
		"damage_type":	"砸伤",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	([	"action":	"$N身形一转，$w连砸$n的$1，使的是一招[法轮常转]！",
		"dodge":	-15,
		"parry":	5,
		"damage":	25,
		"damage_type":	"砸伤",
	]),
	([	"action":	"$N一试[当头棒喝]$w只砸$n天灵",
		"dodge":	10,
		"parry":	10,
		"damage":	40,
		"damage_type":	"砸伤",
	]),
	([	"action":	"$N口诵佛号，$w从一个怪异的角度一迅雷不及掩耳之势直撞$n",
		"dodge":	-5,
		"parry":	-10,
		"damage":	40,
		"damage_type":	"砸伤",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
});


void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp;

        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$N只觉得手中" + ob->name() + "把持不定，脱手飞出！\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "只听见「啪」地一声，$N手中的" + ob->name()
                                + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        //ob->set("value", (int)ob->query("value") / 20);
                        ob->set("value", 0);
                        //so can't sell broken weapon.
                        //otherwise may have problem in pawn shop
                        //when the broken weapon disappeared.
                        ob->set("weapon_prop", 0);
                        ob->set("armor_prop", 0);
                        call_out("remove_broken_weapon",random(300)+60,ob);
                        victim->reset_action();
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }
        }
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
    destruct(ob);
  }
}




int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练大势锤。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄大锤才能练大势锤。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 50 )
                return
notify_fail("你的内力或气不够，没有办法练习大势锤。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍大势锤。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/bighammer/" + func;
}
