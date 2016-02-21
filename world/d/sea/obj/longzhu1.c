# include <skill.h>

inherit ITEM;

void create()
{
        set_name("金龙珠", ({"jin longzhu", "zhu", "pearl"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","颗");
		set("long",
"一颗斗大圆润的珍珠，传说只有得道的真龙才会有。
内有光影游动，似乎触摸(touch)之下会发出异彩。
这颗龙珠似乎上有八宫之相，也许能合并(combine)其它的龙珠。\n");
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
	add_action("do_study","touch");
	add_action("do_combine","combine");
}
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/sea/obj/pearl"))
        	pearl->move(where);
	message_vision("$N手中的$n突发七彩之光，一道霞光过后便失去了颜色。\n",where,me);
	destruct(me);
}
int do_combine()
{
	object me,a,b,c,d,e,f,g,h,i,real;
	me=this_player();
	a=this_object();

	if( (int)me->query("force") < 1500)
		return notify_fail("你的内力不足，很难将龙珠合并。\n");
	if( (int)me->query("mana") < 1000)
		return notify_fail("你的法力不足，不能支配龙珠的动向。\n");

	if ( !(b=present("yin longzhu",me))) 
		return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(c=present("chi longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(d=present("cheng longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(e=present("huang longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(f=present("lu longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(g=present("qing longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(h=present("lan longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
        if ( !(i=present("zi longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");

	if( real=new("/d/sea/obj/longzhureal")){
		destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
                destruct(f);
                destruct(g);
                destruct(h);
                destruct(i);
	real->move(me);
	message_vision("$N将手中龙珠按八宫之位摆在金龙珠周围，只见几道霞光掠过，九颗龙珠居然合为一体。\n",me);
	destruct(a);
	}
	return 1;
}


int do_study(string arg)
{
	object me,pearl;

	me=this_player();

	if( !arg || (arg!="jin longzhu"
			&& arg!="longzhu"
			&& arg!="pearl") )
		return notify_fail("你要摸什么？\n");

	if( (int)me->query_skill("force",1) < 100)
		return notify_fail("你的内功心法不够，还感受不到龙珠内的魔力。\n");
	if( (int)me->query_skill("force",1) >= 150)
		return notify_fail("你的内功心法过高，龙珠内的魔力以对你毫无作用了。\n");
	if( (int)me->query_skill("spells",1) < 50)
		return notify_fail("你的法术休养不够，还领悟不到龙珠内的魔力。\n");
	if( (int)me->query("kee") < 50)
		return notify_fail("你的气血不足，再练会晕倒过去。\n");
	if( (int)me->query("sen") < 50)
		return notify_fail("你的精神不济，再练会昏迷过去。\n");
	if( (int)me->query("force") <50)
		return notify_fail("你的内力不足，再练有害无益。\n");

	if( (int)this_object()->query("learned") >= (int)me->query("spi")) {
		message_vision("$N手中的$n突发七彩之光，一道霞光过后便失去了颜色。\n",me,this_object());
		if( pearl=new("/d/sea/obj/pearl")){
			pearl->move(me);
		}
		destruct(this_object());
		return 1;
	}

	message_vision("$N双手轻握$n，只见一丝淡淡霞光流入掌中。\n",me,this_object());
	me->improve_skill("force", random((int)me->query_int()/2 + (int)me->query_spi()/2)+1+random(3));
	me->receive_damage("kee",30);
	me->receive_damage("sen",30);
	me->add("force",-10);
	this_object()->add("learned",1+random(2));
	write("你对内功心法的领悟似乎又深了一层。\n");
	return 1;
}
