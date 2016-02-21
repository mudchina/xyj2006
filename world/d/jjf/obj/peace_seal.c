#include <skill.h>
#include <ansi.h>

//inherit ITEM;
inherit COMBINED_ITEM;
void create()
{
        set_name("休战符", ({"peace seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸，中央有个大大的“休战”字。
可以在战斗中祭(burn)之。\n");
        set("base_unit","张");
        set("unit", "张");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	set_amount(1);
	setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
	add_action("do_burn", "burn");
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N手中的$n突发红光，符咒渐渐淡去不见了。\n",where,me);
        destruct(me);
}

int do_burn(string arg)
{
	object seal=this_object();
	object me=this_player();

	if(!arg || (arg!="peace seal"
                        && arg!="seal"
                        && arg!="paper") )
		return notify_fail("你要祭什么？\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢，无法祭休战符。\n");
	if(!me->is_fighting())
		return notify_fail("你只有在战斗中才能用休战符。\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不能控制休战符。\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，很难驾驭休战符。\n");


	tell_room(environment(me),
me->name()+"大喊一声“着”，手一挥，祭出了一张休战符。。。\n\n");
	tell_room(environment(me),
"休战符「呼」地一下飞到半空，天上隐隐传来“因果循环，报应不爽，众位还是得饶人处且饶人吧！”的声音。\n");



	if( random( (int)me->query_kar()+ (int)me->query_cps()) > 20 )	{

		tell_room(environment(me),"\n众人听到，都渐渐把手停了下来。\n");
		me->remove_all_killer();

	} else {
		tell_room(environment(me), "\n谁知没人听从，继续厮杀！\n");

	}
	me->add("mana",-50);
        add_amount(-1);
        me->start_busy(2+random(2));
	return 1;
}
