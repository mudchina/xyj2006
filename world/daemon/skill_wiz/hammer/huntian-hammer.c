//【混天锤】??

/*
  dodge  15    parry  -15    damage  30
其锤法直来直去，招招为实，势大力猛，招架抵挡
甚为不易，一但碰上则伤害极大。但不足是不够轻
盈。
*/
#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
	([	"action":	"$N手中$w一转，卷着一股强劲的风力挥向$n的$l，
这一下又急又猛，势大力狠，眼见就到了$n身前",
		"dodge":	10,
		"parry":	-10,
		"damage":	30,
		"damage_type":	"砸伤",
	]),
	([	"action":	"$N双手一震，手中$w夹带着闷雷般的响声，劈头盖脸地就向$n砸了过去",
		"dodge":	15,
		"parry":	-15,
		"damage":	30,
		"damage_type":	"砸伤",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	([	"action":	"$N将$w高举过肩，蓄紧力发，对准$n的$l发出雷霆一击",
		"dodge":	20,
		"parry":	-20,
		"damage":	35,
		"damage_type":	"砸伤",
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
	]),
	([	"action":	"$N身走轻灵，手中$w忽上忽下，令人捉摸不清去路，
就在$n一恍惚间，“唰”地砸向$n的$l",
		"dodge":	0,
		"parry":	-10,
		"damage":	25,
		"damage_type":	"砸伤",
	]),
	([	"action":	"$N趁与$n错身之机，倒转$w，锤把戳向了$n，
这一下如白蛇吐芯，悄无声息的点上了$n的$l",
		"dodge":	10,
		"parry":	-10,
		"damage":	20,
		"damage_type":	"戳伤",
	]),
	([	"action":	"$N紧握$w猛挥了个大圆，卷的周身长内沙土尘扬，
趁$n不能辨物之记，手中$w斜斜地砸向$n的$l",
		"dodge":	20,
		"parry":	-25,
		"damage":	30,
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
                return notify_fail("你的内力不够，没有办法练混天锤。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一柄大锤才能练混天锤。\n");

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
notify_fail("你的内力或气不够，没有办法练习混天锤。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍混天锤。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("dragon") + "/huntian-hammer/" + func;
}
