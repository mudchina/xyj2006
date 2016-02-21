
#include <ansi.h>

inherit ITEM;

void create() {
  set_name("黄粱枕", ({"huangliang zhen","pillow","zhen"}));
  set("long","一只绣花枕头，相传当年卢生枕其而眠，做了个好梦。\n");
  set_weight(3000);
  if( clonep() )
          set_default_object(__FILE__);
  else {
          set("unit", "只");
          set("value", 0);
          set("material", "cloth");
  }
  setup();
}

int goto_dream(object me)
{
    object env;
    
    if(!me) return 0;
    
    if(env=environment(me))
      tell_object(env,"\n"+HIY+me->name()+"拥着"+name()+
	      "，进入了梦的世界．．．\n\n"NOR);
    return 1;
}


void pillow_destruct()
{
    destruct(this_object());
}

/*
void init() {
  add_action("do_sleep","sleep");
}

int do_sleep(string arg)
{
  object ob=this_object(),me=this_player();
  object env = environment(me);
        
  if (arg!="pillow" && arg!="zhen" && arg!="zhen tou") return 0;
  if( !env->query("sleep_room") &&
      !me->query_temp("force_sleep") )
          return notify_fail("这里不是睡觉的地方。\n");
  if (me->is_busy())
          return notify_fail("你正忙着呢！\n");
  if( me->is_fighting() )
          return notify_fail("战斗中不能睡觉！\n");
  if ((time()-me->query("last_sleep"))<90)
          return notify_fail("你刚睡过一觉, 先活动活动吧。 \n");
  message_vision(HIY"$N拥着枕头，进入了梦的世界．．．\n"NOR,me);
  me->move("/d/ourhome/honglou/kat");
  me->set("dream_place",(string)env);
  return 1;
}
*/
