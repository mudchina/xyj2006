// zijinbo.c	紫金钵

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;

void create()
{
	set_name("紫金钵", ({"zijinbo", "zijin bo", "bo"}));
	set_weight(7000);
//  	set_max_encumbrance(50000);
//  	set("max_items",10);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "御赐紫金钵,这可是无价之宝,可讨万方斋菜\n");
		set("unit", "个");
		set("value", 1000000);
		set("max_liquid", 15);
	}

  	set("unique", 1);
  	set("no_sell", "这可是无价之宝,恐怕没人买得起吧。\n");
  	set("no_drop", "吃饭的家伙,可是不能轻易丢弃\n");
  	set("no_give", "大唐天子御赐宝物,给人你可真大方\n");
  	set("is_monitored",1);
  	setup();

}


void destruct_me(object where, object me)
{
  object who;
  who=find_player(me->query("owned"))	;
  message_vision("$n飞升到空中,发出耀眼的光芒向运方飘去……\n",where,me);

  if (!who)destruct(me);
  me->move(who)				;
  tell_object(who,"你觉得身上一紧,好象多了什么东西");
    
}

void init()
{
  object me = this_object();
  object where = environment();
  add_action("do_huayuan","huayuan");

  if (interactive(where))
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
}


int do_huayuan(string arg)
{
   object me,who,target,where;
   me=this_object();
   who=this_player();
   where=environment(who);
 
   if (!arg)return notify_fail("你要向谁化缘\n");
   if (target=present(arg,where))
     {
	if (me->query("have_food"))
		return notify_fail("紫金钵里已经有东西了\n");
	if (who->is_busy())return notify_fail("你好象忙不过来\n");
	if (who->is_fight())return notify_fail("不会吧.\n");
	if (target->query("id")=="qujing ren")
		return notify_fail("他估计比你还穷\n");
	if (target->query("attitude")!="friendly")
		return notify_fail(target->query("name")+"看起来不太友好\n");
	if (target->query_temp("give_beg")) 
		return notify_fail(target->query("name")
			+"看起来没什么可以给你的\n");	  
/*	if (!target->query("vendor_goods"))
		return notify_fail(target->query("name")
			+"看起来没什么可以给你的.\n");	  
	//仅能在商店化缘.
*/

	if (random(2)!=0) 
	  {
 	    target->set_temp("give_beg",1);//要求一次成功
	    return notify_fail(target->query("name")
		+"看起来没什么可以给你的\n");
	  }

	target->command_function("say 我这里还有些饭菜,你就将就用吧\n");
        message_vision("$N给了你些饭菜\n",target);
	target->set_temp("give_beg",1);
	me->set("have_food",1);
     }
   else
     {
	return notify_fail("你要向谁化缘\n");
     }
  
   return 1;
}




 

