// tianmojian.c 	天魔茧

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;

void create()
{
	set_name("天魔茧", ({"tianmojian", "tianmo jian", "jian"}));
	set_weight(7000);
//  	set_max_encumbrance(50000);
//  	set("max_items",10);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "蒸笼老人的天魔茧,专门用来收取经人\n");
		set("unit", "个");
		set("max_liquid", 15);
	}

	set("value",1);
  	set("unique", 1);
  	set("no_sell", "你找死啊。\n");
  	set("is_monitored",1);
  	setup();

}



void init()
{
  object me = this_object();
  object where = environment();

  if (interactive(where))
  {
     if (where->query("obstacle/qujing")=="ren" 
		|| where->query("combat_exp")<500000)
	{
	   call_out("destruct_me",1,where,me);
   	}
  }

  add_action("do_shou","收");
  add_action("do_shou","shou");
  add_action("do_shou","zhua");
}


void destruct_me(object where, object me)
{
    object env=environment(where);
    message("sound","空中一声大吼,无用的家伙,还我天魔茧来\n",env);
    destruct(me);
    OBSTACLE_D->delete("last_jie_id")	;
}


int do_shou()
{
   	object me,who,qjr,where,laoren,husongren;
	string husong 		;
	
	me=this_object()	;
	who=this_player()	;
        where=environment(who)	;
	if (!(qjr=present("qujing ren",where)))
 	  return notify_fail("取经人不在这里\n");
	husong=OBSTACLE_D->query("husong");
	husongren=find_player(husong);  	    	
        if (husongren)
 	  {  
   	     if (where==environment(husongren))
	     return notify_fail("有人在保护着呢\n");
  	  }

	message_vision("$N祭起天魔茧,只见那茧射出万缕轻丝将取经人团团捆住\n",who);
	write("你耳边仿佛听到蒸笼老人的叫好声,那茧便消失了\n");

	OBSTACLE_D->set("cated_qjr",1);
	OBSTACLE_D->set("cated_id",who->query("id"));
	OBSTACLE_D->set("cated_type","player");
		//取经人已经被抓.而且是玩家抓的
	OBSTACLE_D->set("last_env",base_name(where));
	OBSTACLE_D->set("where_qujingren","/d/qujing/qujingren/tianmo/zlf");
	OBSTACLE_D->save();	
        OBSTACLE_D->qujing_fail();
	OBSTACLE_D->open_door();

	laoren= find_living("zhenglong laoren");
	if (laoren)destruct(laoren);
  	if (qjr)destruct(qjr);
	destruct(me);
	return 1;

}



