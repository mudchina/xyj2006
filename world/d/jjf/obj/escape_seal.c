#include <skill.h>
#include <ansi.h>

//inherit ITEM;
inherit COMBINED_ITEM;
void create()
{
        set_name("逃命符", ({"escape seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸，中央有个大大的“逃”字。
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

	if(!arg || (arg!="escape seal"
                        && arg!="seal"
                        && arg!="paper") )
		return notify_fail("你要祭什么？\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不能控制逃命符。\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，很难驾驭逃命符。\n");


	tell_room(environment(me),
me->name()+"大喊一声“着”，手一挥，祭出了一张逃命符。。。\n\n");
	tell_room(environment(me),"周围呼的一下闪出一片火光。\n");



	if( random( (int)me->query_kar()+ (int)me->query_cps()) > 10 )	{
		tell_room(environment(me),"\n"+me->name()+"趁着火影逃跑了。\n");
		me->move("/d/jjf/se_garden");

	} else {
		tell_room(environment(me), "\n谁知火势太猛，"+me->name()+"没跑掉。\n");

	}
	me->add("mana",-50);
        
        me->start_busy(1+random(2));


        add_amount(-1);
	//destruct(seal);
	return 1;
}
