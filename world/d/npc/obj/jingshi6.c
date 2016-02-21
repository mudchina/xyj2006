# include <skill.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG"绿晶石"NOR, ({"lvjing shi", "lvjing", "shi"}));
	set_weight(1);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","颗");
		set("long","七彩水晶之一。\n");
	}
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
	add_action("do_combine","combine");
}
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/npc/obj/jingshi"))
        	pearl->move(where);
	message_vision("$N手中的$n突炸裂开来，一道霞光过后便失去了颜色。\n",where,me);
	destruct(me);
}
int do_combine()
{
	object me,a,b,c,d,e,f,g,real;
	me=this_player();
	a=this_object();

	if( (int)me->query("force") < 2000)
		return notify_fail("你的内力不足，很难发挥七彩水晶的威力。\n");
	if( (int)me->query("mana") < 2000)
		return notify_fail("你的法力不足，不能洞悉七彩水晶的动向。\n");

	 if ( !(c=present("huangjing shi",me)))
                return notify_fail("你将手中水晶石摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(d=present("hongjing shi",me)))
                return notify_fail("你将手中水晶石摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(e=present("chengjing shi",me)))
                return notify_fail("你将手中水晶石摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(f=present("lanjing shi",me)))
                return notify_fail("你将手中水晶石摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(g=present("zijing shi",me)))
                return notify_fail("你将手中水晶石摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(b=present("baijing shi",me)))
                return notify_fail("你将手中水晶石摆弄了几下，却一无所获，大概还没有收集够。\n");

	if( real=new("/d/npc/obj/jingshireal")){
		destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
                destruct(f);
                destruct(g);
	real->move(me);
	message_vision("$N将手中水晶石按天罡之阵摆好，只见几道霞光掠过，7颗水晶石居然合为一体。\n",me);
	destruct(a);
	}
	return 1;
}


