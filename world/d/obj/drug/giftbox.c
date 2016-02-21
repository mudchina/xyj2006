
// renshen-guo.c 人参果
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

int do_open(string);

void init()
{
	check_owner();
      if(this_player()==environment())
	add_action("do_open", "open");
	return ::init();
}

void create()
{
	set_name(HIW "礼品盒" NOR, ({"lipin box", "lipin", "box"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个装饰精美的礼品盒,不妨打开(open)来看看。\n");
		set("value", 0);
		set("drug_type", "补品");
                set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_put",1);
		set("unique",1);
		set("no_give",1);
		set("time_available", 4);

	}
  
	set("is_monitored",1);
	setup();
}

int do_open(string arg)
{
	string msg;
	object me = this_player();
  
	if (!id(arg)) return notify_fail("你要打开什么？\n");
	if (me->query("wizgift/newbiegift"))
	{  
	   tell_object(me,"你为什么这么贪心呢?\n");
	   destruct(this_object()); 
	   return 1;
	}
	me->set("wizgift/newbiegift",1);
	me->save();
// me->add("combat_exp",10000);
 me->add("combat_exp",50000);
//me->add("daoxing",10000);
me->add("daoxing",20000);
me->add("potential",50000);
	me->save();
	msg=HIY"$N小心翼翼地把盒子打开来，突然盒中射出一片金光，晃得$N"+
		"睁不开眼。\n"NOR;
        message_vision(msg,me);
        write("你的道行，武学，潜能都增加了!\n");
        log_file("static/NEWBIEGIFTopen","["+ctime(time())+"] "+
	sprintf("%s(%s)打开了%O\n",
         this_player()->query("name"),this_player()->query("id"),
         this_object()));

	destruct(this_object());
	return 1;

}

