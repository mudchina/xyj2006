//Cracked by Roath
// by snowcat 11/22/1997
#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("剃刀", ({"ti dao", "dao", "blade"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long", "一把剃头用的薄刃刀。\n");
    set("wield_msg", "$N抽出一把薄刃剃刀，捏在手里。\n");
    set("unwield_msg", "$N将剃刀收起，往兜里一装。\n");
  }
  init_blade(2);
  setup();
}

void init()
{
  add_action ("do_cut","cut");
  add_action ("do_cut","ti");
}

int do_cut(string arg)
{
  object me = this_player();
  object ob;

  if (! arg)
    return notify_fail ("你要拿剃刀做什么？\n");

  ob = present (arg,environment(me));
  if (! ob)
    return notify_fail ("你要拿剃刀给谁剃头？\n");
  
  if (! ob->is_character())
    return notify_fail ("你要拿剃刀给谁剃头？\n");
  
  if (me == ob)
    return notify_fail ("你要给自己剃头？\n");

  if (me->is_busy())
    return notify_fail ("你正在忙着呢。\n");

  if (ob->query_temp("no_hair"))
    return notify_fail ("人家头上早没毛了。\n");

  message_vision ("$N操起剃刀，给$n剃起头来。\n",me,ob);
  me->start_busy(5,5);
  call_out ("cutting",5,me,ob);
  return 1;
}

void cutting (object me, object ob)
{
  me->interrupt_me();

  message_vision ("唰唰唰，$N的头发落下一片。\n",ob);
  if (living (ob))
  {
    message_vision ("$N跳将起来，瞪圆双眼大喝一声：你，住手！\n",ob);

    if (environment(ob)->query("no_fight"))
      return;

    if (! interactive(ob) &&
        ! ob->query("can_sleep"))
      return;

    if(!userp(ob)) {
      message_vision ("糟了！看来剃头要剃出人命了！\n",ob);
      ob->kill_ob(me);
    }
    return;
  }
    
//  if (interactive(ob))
//    return;

  if (ob->query("disable_type") != "<睡梦中>" ||
      ! ob->query_temp("disabled"))
    return;

  if (random(7))
    return;
  message_vision ("$N的头发给剃光了。\n",ob);
  ob->set_temp("no_hair",1);
  me->add_temp("obstacle/qinfa_cut_times",1);
  ob->check_hair();
}
 
