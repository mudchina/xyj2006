
#include <ansi.h>
#define ONEDAY 86400

inherit ITEM;

void create()
{
  set_name( HIY"九转金丹"NOR , ({"jiuzhuan jindan", "jindan","dan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long","一颗金光闪闪的仙丹，乃是太上老君为玉帝的丹元大会特别炼制而成，服之延年益寿。\n");
    set("value", 800000);
    set("no_sell", 1);
    set("no_drop","你舍得？\n");
    set("no_give","你舍得？\n");
    set("drug_type", "补品");
  }
  setup();
  call_out("self_dest",600);
}

void self_dest()
{
    object env;
    if(this_object()) {
        if(env=environment(this_object()))
            tell_object(env,name()+"掉在地上不见了。\n");
        destruct(this_object());
    }
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int food,water;
  object me = this_player();
  int r=me->query_kar();
  if (arg!="jindan" && arg!="dan") 
    return 0;
  
  if (environment()!=me) {
     write("你身上没有金丹。\n");
     return 1;
  }
  if (r<30) r=30;

  message_vision(HIG "$N捏起金丹送进嘴里，如嚼炒豆般吃了。\n" NOR, me);
  me->set("dntg/laojun","done");
  if (time()-me->query("jindan_last_eaten")<ONEDAY) return 1;
  if (random(r)>28) {
    tell_object(me, HIG"你顿时觉得身轻体健，飘飘欲仙！\n"NOR);
    me->add("life/life_time",1);
    MONITOR_D->report_system_object_msg(me," eats jindan and gets 1 year life time.\n" );
  me->set("jindan_last_eaten",time());
  } else {
      tell_object(me,HIR"你突然觉得头晕眼花，四肢乏力，烦闷欲呕，原来你无福消受仙丹，铅汞中毒了。\n"NOR);
  me->add("bad_jindan",1);
  if (me->query("bad_jindan")>40) {
    me->delete("bad_jindan");
    me->set_temp("death_msg","服食金石仙丹过量，中毒而死。\n");
    me->die();
    me->delete_temp("death_msg");
    return 1;
  }
      if (!random(3)) {
        tell_object(me,HIR"你猛地想起汉武帝因误服丹药而一命呜呼的往事，不由吓得心胆俱裂，魂飞魄散。\n"NOR);
        me->unconcious();
      }
  }
  destruct(this_object());
  return 1;
}
