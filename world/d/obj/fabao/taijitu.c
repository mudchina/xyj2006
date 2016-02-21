
#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
  set_name("太极图", ({"taiji tu", "tu", "fabao"}));
  set_weight(1000);
  if(clonep())
     set_default_object(__FILE__);
  else {
    set("long", @LONG
元始天尊所炼制之太极图。
用法：ji <name> on <direction>
      qi <name>

LONG );
 
  set("unit", "张");
  set("value", 0);
  set("no_put",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);

  set("replace_file", "/obj/money/gold");
        }
  set("is_monitored", 1);
  setup();
}

void init()
{
  add_action("do_ji","ji");
  add_action("do_shou","qi");
  check_owner();

}

int do_ji (string arg)
{
  object me = this_player();
  string fabaoname,dir,dest;
  object fabao;
  object env=environment(me);
//  mapping exits=env->query("exits");

  if( !wizardp(me) && environment(me)->query("no_magic") )
        return notify_fail("这里禁止祭法宝。\n");
  if( !arg ) return notify_fail("你要祭哪样法宝？\n");

  // Check if correct format is followed
  if( sscanf(arg, "%s on %s", fabaoname, dir)!=2 )
        return notify_fail("指令格式 : ji <法宝名称> on <方向>\n");

  fabao=present(fabaoname, me);
  if(fabao!=this_object()) {write("strange...\n");return 0;}
  dest = environment(me)->query("exits/"+dir);
  if (fabao->query("being_used")) {
    write("你已经祭起太极图了。\n");
    return 1;
  }

  if (me->is_busy())
    return notify_fail("你上一个动作还没有完成，无暇分身祭法宝。\n");
  if(!dest) return notify_fail("这个方向没有路径。\n");
        
  if(me->is_fighting())
    return notify_fail("你正忙着打架，没空祭太极图。\n");
  if( (int)me->query("mana") < 500 )
     return notify_fail("你的法力不能控制太极图。\n");
  if( (int)me->query("sen") < 200 )
     return notify_fail("你的精神不足，很难驾驭太极图。\n");

  message_vision(HIC"\n$N微微一笑，手轻轻一抖，展开了太极图。\n"+
      "你觉得眼前一花，仿佛进入了世外桃源。\n\n"NOR,me);

  me->add("mana",-100);
  me->receive_damage("sen", 100);
  
  env->set("altered_dir",dir);
  env->set("old_room",dest);

  env->set("exits/"+dir,__DIR__"taijituroom");
  fabao->set("start",env);
  
  if (me->move(__DIR__"taijituroom")) {
    if (me->ride()) me->ride()->move(environment(me));
    write("\n");
    environment(me)->set("old_room",env);
    env=environment(me);
    env->set("exits",([dir:dest]));
    env->set("host",me);
  }  
  me->start_busy(1+random(3));
  fabao->set("being_used",1);
  return 1;

}

int do_shou(string arg) {
  object me=this_player();
  object bridge,env=environment(me),fabao=this_object();
  object env1;

  if (!arg) return 0;
  if (present(arg,me)!=fabao) {
    write("strange...\n");
    return 1;
  }

  if (!fabao->query("being_used")) {
    write("太极图好好的收着呢。\n"); 
    return 1;
  }
  
  
  if (!bridge=find_object(__DIR__"taijituroom")) {
     write("你收起太极图。\n");
     fabao->delete("being_used");
     return 1;
  }

  if (env=bridge) {
    if (env1=fabao->query("start"))
       env1->set("exits/"+env1->query("altered_dir"),env1->query("old_room"));
    bridge->explode();
    write("你收起太极图。\n");
    fabao->delete("being_used");
    return 1;
  }
  if (bridge->is_clear()) {
    if (env1=fabao->query("start"))
       env1->set("exits/"+env1->query("altered_dir"),env1->query("old_room"));
    write("你收起太极图。\n");
    fabao->delete("being_used");
    destruct(bridge);
    return 1;
  }

  return notify_fail("图中有人，收不得！\n");
}
  
