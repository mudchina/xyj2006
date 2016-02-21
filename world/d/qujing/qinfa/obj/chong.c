// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "瞌睡虫" , ({"keshui chong", "chong"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("long", "一只灵巧的瞌睡虫，正闪着两只眼睛奇怪地盯着你。\n");
 set("value", 60000);
  }
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_apply", "apply");
  add_action("do_apply", "fang");
}

int do_apply(string arg)
{
  object me = this_player();
  object where = environment(me);
  object ob;

if( me->query("faith") <= 500 )
    return notify_fail ("年轻人还不会使用瞌睡虫？\n");
  if (! arg)
    return notify_fail ("你要拿瞌睡虫做什么？\n");

  ob = present (arg,where);
  if (! ob)
    return notify_fail ("你要拿瞌睡虫往谁身上放？\n");
  
  if (! living(ob))
    return notify_fail ("你要拿瞌睡虫往谁身上放？\n");
  
  if (me == ob)
    return notify_fail ("你要拿瞌睡虫往自己身上放？\n");

  // mon 4/11/98
  if(where->query("no_fight") && where->query("no_magic"))
      return notify_fail ("在安全区用瞌睡虫可不太好吧！\n");

  if (this_object()->query("is_climbing"))
    return notify_fail ("瞌睡虫正在爬呢。\n");

  message_vision ("$N静悄悄地拿出一只瞌睡虫，往$n身上一放。\n",me,ob);
  message_vision ("瞌睡虫迅速地爬进$N的鼻孔里。\n",ob);
  this_object()->move(ob);  
  this_object()->set("is_climbing",1);
  call_out("applying",1+random(10),ob);  
  return 1;
}

void applying (object ob)
{
  if (! ob)
    return;

//  message_vision ("$n迅速地爬进$N的鼻孔里。\n",ob,this_object());
  message_vision ("$N忍不住打了一个哈欠，满脸睡意。\n",ob);

  if ((userp(ob) || ob->query("can_sleep")) && random (2)==0) {
//    ob->set_temp("force_sleep",1);
    if(!wizardp(ob)) ob->command_function("sleep");    
    ob->delete_temp("force_sleep");
  }
  destruct (this_object());
}
 
