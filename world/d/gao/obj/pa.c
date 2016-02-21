// rake.c

#include <weapon.h>
#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;
//inherit RAKE;

void create()
{
  set_name("小钉钯", ({ "ding pa", "pa","rake" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 100);
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
    set("time", 3);
    set("material", "iron");
    set("long", "一柄金光灿灿的小钉耙，据说能大能小。\n");
    set("wield_msg", "$N抡起一柄$n，叫了声“大”,钉耙果然变的十分称手。\n");
  }
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
	object zhu;

        if(me->is_busy())
                return notify_fail("你正忙着呢，无法祭出小钉耙。\n");
        if( !victim)
                return notify_fail("你想祭的人不在这里。\n");
        if( where->query("no_magic"))
                return notify_fail("这里不能祭小钉耙。\n");
        if( !me->is_fighting())
                return notify_fail("只有战斗中才能祭小钉耙。\n");
        if( (int)me->query("mana") < 1000 )
                return notify_fail("你的法力不能控制小钉耙。\n");
        if( (int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，很难驾驭小钉耙。\n");


        message_vision(HIC"\n$N大喊一声“摄”，手一挥，祭出了$n。。。\n"NOR, me, seal);
message_vision(HIC"$n「呼」地一下飞到半空，只见红光一闪，又稳稳的落到了$N手中。\n"NOR,me,seal);

	seteuid(getuid());
        zhu = new("/d/gao/npc/bajie");
        zhu->move(environment(me));
        zhu->invocation(me);
	zhu->set_temp("invoker",me);
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