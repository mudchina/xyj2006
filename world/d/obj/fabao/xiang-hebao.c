// Rainy
// 07/09/98

#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name("香荷包", ({"xiang hebao", "hebao", "bao", "fabao"}));
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "一个红色的小香荷包，上面用金银丝线绣了些咒文。\n");
        set("unit", "个");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
	set("replace_file", "/obj/money/gold");
        }
	set("is_monitored", 1);
        setup();
}

void init()
{
  check_owner();
}

int ji_ob(object victim)
{
        object seal=this_object();
        object me=this_player();
        object where=environment(me);

        int limitmana, vicmana;
	int limitdx, vicdx;
	int limitkar, vickar;
	int limit, vic;


        if(me->is_busy())
                return notify_fail("你正忙着呢，无法祭出香荷包。\n");
        if( !victim)
                return notify_fail("你想祭的人不在这里。\n");
        if( where->query("no_magic"))
                return notify_fail("这里不能祭香荷包。\n");
        if( !me->is_fighting())
                return notify_fail("只有战斗中才能祭香荷包。\n");
        if( (int)me->query("mana") < 500 )
                return notify_fail("你的法力不能控制香荷包。\n");
        if( (int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，很难驾驭香荷包。\n");


        message_vision(HIC"\n$N大喊一声“摄”，手一挥，祭出了$n。。。\n"NOR, me, seal);
message_vision(HIC"$n「呼」地一下飞到半空，只见红光一闪，一股红雾喷向了$N。\n"NOR,victim,seal);

	limitmana = 500+random(300);
	limitdx = 200000+random(100000);
	limitkar = (int)me->query_kar();

	limit = (limitdx/1000 + limitmana) * limitkar;

	vicmana = (int)victim->query("max_mana");
	vicdx = (int)victim->query("daoxing");
	vickar = (int)victim->query_kar();

	vic = (vicdx/1000 + vicmana) + vickar;

                if( random(limit+vic) > vic ){
        message_vision(HIC"\n$N躲闪不及，把红雾吸到了鼻子里。\n"NOR,victim);
			victim->apply_condition("xiang_air", 5);
                } else {
                        message_vision(HIC"\n$N猛退几步，躲了过去。\n"NOR,victim);
                }

                if( !victim->is_fighting(me) ) {
                if( living(victim) ) {
                        if( userp(victim) ) victim->fight_ob(me);
                        else
                                victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }
        me->add("mana",-100);
	me->receive_damage("sen", 100);

        me->start_busy(3+random(5));
        destruct(seal);
        return 1;
}

int ji (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+name+"？\n");

  victim=present(target,environment(me));
  return seal->ji_ob(victim);
}

