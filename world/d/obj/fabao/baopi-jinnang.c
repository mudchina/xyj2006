// Rainy
// 07/09/98
// require: 	mana 1000
// can use 3 times.

#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name("豹皮锦囊", ({"baopi jinnang", "jinnang", "fabao"}));
        set_weight(10000);
        if(clonep())
                set_default_object(__FILE__);
        else {
	set("long", "一个裹着豹皮的绣囊，入手沉甸甸的。\n");
        set("unit", "个");
        set("value", 0);
        set("no_put",1);
        set("no_sell",1);
	set("replace_file", "/obj/money/gold");
	set("time", 3);
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
	object dog;

        if(me->is_busy())
                return notify_fail("你正忙着呢，无法祭出豹皮锦囊。\n");
        if( !victim)
                return notify_fail("你想祭的人不在这里。\n");
        if( where->query("no_magic"))
                return notify_fail("这里不能祭豹皮锦囊。\n");
        if( !me->is_fighting())
                return notify_fail("只有战斗中才能祭豹皮锦囊。\n");
        if( (int)me->query("mana") < 1000 )
                return notify_fail("你的法力不能控制豹皮锦囊。\n");
        if( (int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，很难驾驭豹皮锦囊。\n");


        message_vision(HIC"\n$N大喊一声“摄”，手一挥，祭出了$n。。。\n"NOR, me, seal);
message_vision(HIC"$n「呼」地一下飞到半空，只见黑光一闪，一只小兽猛冲向了$N。\n"NOR,victim,seal);

	seteuid(getuid());
	dog=new("/obj/npc/xiaotian-quan");
	dog->move(environment(victim));
	dog->invocation(victim);


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

        me->start_busy(3+random(3));

	add("time", -1);
	
	if( (int)seal->query("time") < 1) {
        destruct(seal);
	}
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

