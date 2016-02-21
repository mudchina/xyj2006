//这种跟环境有关的东西,busy越多,bug越少

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_wayao", "dig");
	//add_action("do_wayao", "wa");
}

void create()
{
	set_name("药锄", ({"yao chu", "chu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop","不要乱丢，这东西打到人会痛的,没打到人,砸到花花草草也不好！\n");
		set("no_put",1);
		set("long", "这是一把很重的药锄，你可以用它来挖药（dig yao）。\n");
		set("value", 5000);
	}
	setup();
}

int do_wayao(string arg)
{       object ob;
        object me=this_player();
        if (me->is_busy()||me->query_temp("pending/exercising")) return notify_fail("你现在正忙着呢。\n");
        if (!arg||arg!="yao") return notify_fail("你要挖什么呢？！\n");
        if (me->is_fighting())	return notify_fail("战斗中还想干什么，找死啊？！\n");
        if (me->query("combat_exp") < 300000) return notify_fail("你的武功修为还不足够拿起这把药锄.\n");
        if ((me->query("sen") < 200)) return notify_fail("你的精力不能集中，挖了也是白挖！\n");
        if (me->query("kee") < 400 ) return notify_fail("你太累了，怎么都拿不动这把药锄！\n");
        if (present("baicao xian", environment(me))) return notify_fail("当人家面偷药,不好吧！\n");
        if (present("zhengui yaocai", environment(this_object()))||present("putong yaocai",environment(this_object()))) return notify_fail("别不知足,你已经挖到药了！\n");
        if(environment(this_object()) != me)  return notify_fail("你是在看别人挖吧？\n");
        if (environment(me)->query_temp("wayao1"))
        {
        me->start_busy(random(3)+1);
        message_vision("$N挥动药锄“呼哧、呼哧”地在地上挖了起来,似乎在找什么东西。\n",me);
        me->add("kee",-100);
        me->add("sen",-50);
            if(random(7)<3)
      {
        message_vision(HIY"空中一声断喝:何方妖孽,敢来神农药圃撒野?百草仙驾着祥云赶来$N面前。\n"NOR,me);
        ob=new(__DIR__"baicaoxian1.c");
        ob->copyskill(ob,me);
        ob->move(environment(me));
        ob->set_leader(me);
        ob->kill_ob(me);
        me->start_busy(1);
      }
      else
      if (random(5)<2||!me->query_temp("killed_zi"))
      {
          message_vision(CYN"一番挖掘，普通药材就是纹丝不动,继续挖吧 :) \n"NOR,me);
      }
      else
      {
        message_vision(YEL"$N挖了半天，终于把那颗药材小心翼翼地掘了出来。\n"NOR,me);
        message_vision(YEL"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me);
        new(__DIR__"putongyaocai")->move(me);
        me->delete_temp("killed_zi");
        environment(me)->add_temp("wayao1",-1);
        destruct(this_object());
        me->start_busy(1);
      }
      return 1;
   }
      else
   	if (environment(me)->query_temp("wayao2"))
        {
        me->start_busy(1+random(4));
        message_vision(CYN"$N挥动药锄开始在地上挖了起来。\n"NOR,me);
        me->add("kee",-150);
        me->add("sen",-70);
             if(random(7)<4)
      {
        tell_room(environment(me),HIY"空中一声断喝:何方妖孽,敢来神农药圃撒野?百草仙驾着祥云赶来.\n"NOR );
        ob=new(__DIR__"baicaoxian2.c");
        ob->copyskill(ob,me);
        ob->move(environment(me));
        ob->set_leader(me);
        ob->kill_ob(me);
        me->start_busy(1);
      }
      else
      if (random(5)<2||!me->query_temp("killed_zi"))
      {
          message_vision(CYN"一番挖掘，珍贵药材就是纹丝不动,继续挖吧 :) \n"NOR,me);
      }
      else
      {
        message_vision(YEL"$N挖了半天，终于把那颗药材小心翼翼地掘了出来。\n"NOR,me);
        message_vision(YEL"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me);
        new(__DIR__"zhenguiyaocai")->move(me);
        me->delete_temp("killed_zi");
        environment(me)->add_temp("wayao2",-1);
        destruct(this_object());
        me->start_busy(1);
      }
       	return 1;
    }
      return notify_fail("这里什么都没有,原来是你看花了眼。\n");
}
