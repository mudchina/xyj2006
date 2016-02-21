// created by snowcat

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

#include "message.h"

void create()
{
  set_name("镇妖锤", ({ "mallet" }) );
  set_weight(350);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把镇妖锤。\n");
    set("unit", "把");
  }
  set("value",100000);
  set("no_get",1);
  init_hammer(1);
  setup();
}

int init ()  
{   
  add_action ("do_hammer", "za");
  add_action ("do_faint", "yun");
  add_action ("do_maxfaint", "zayun");
  return 1;
}

object is_present (string arg, object room)
{
  object *list = all_inventory (room);
  object ob;
  int i;

  if (! arg)
    return 0;
  for (i=0; i<sizeof(list); i++)
  {
    if (list[i]->query("id")==arg)
    {
      ob = list[i];
      break;
    }
  }
  ob = present(arg,room);
  if (ob && !ob->is_character())
    ob = 0;
  return ob;
}

int do_hammer (string arg)
{
  string *hits = ({
    "\n$N伸出手抓了抓空气，然后倒下。\n\n",
    "\n$N翻翻白眼，慢慢地扶着空气倒下。\n\n",
    "\n$N拼命地想扶住空气，然后，烂泥一般瘫在地。\n\n",
    "\n$N象醉鬼一样竭力想搂住空气，然后颤抖着缓缓倒在地上。\n\n",
  });

  object me = this_player();
  object ob;
  string name = this_object()->query("name");

  if (!arg) {
    return notify_fail ("要砸哪一位妖精？\n"); 
  }
  ob = is_present (arg,environment(me));
  if (! ob) {
    return notify_fail ("这位妖精不在这里。\n");
  }

  set("value",0);
  if (me->query("sen")>50)
  {
    me->add("sen",-50);
  }
  else
  {
    me->unconcious();
    return 1;
  }

  if (ob->query("env/invisibility") > 0)
    message_vision ("$N高高举起一把巨大的镇妖锤，对$n大喝一声：臭妖精，哪里藏！\n",me,ob);
  else
    message_vision ("$N高高举起一把巨大的镇妖锤，对$n大喝一声：臭妖精，看招！\n",me,ob);
  message_vision ("\n只听：轰！轰！轰！\n\n几声惊天动地的巨响……\n",ob);
  message_vision (hits[random(sizeof(hits))],ob);
  ob->set("env/immortal",0);
  ob->set("env/invisibility",0);
  return 1;
}

int do_faint (string arg)
{
  if (!do_hammer(arg))
    return 0;
  if (!wizardp(this_player()))
    return 1; 
  set("value",0);
  if (this_player()->query("sen")>50)
  {
    this_player()->add("sen",-50);
  }
  else
  {
    this_player()->unconcious();
    return 1;
  }
  call_out ("get_fainted",2,is_present (arg,environment(this_player())));
  return 1;
}

void get_fainted (object ob)
{
  //ob->unconcious();
}

int do_maxfaint (string arg)
{
  if (!do_hammer(arg))
    return 0;
  if (!wizardp(this_player()))
    return 1; 
  set("value",0);
  if (this_player()->query("sen")>50)
  {
    this_player()->add("sen",-50);
  }
  else
  {
    this_player()->unconcious();
    return 1;
  }
  call_out ("get_maxfainted",2,is_present (arg,environment(this_player())));
  return 1;
}

void get_maxfainted (object ob)
{
  string short = ob->query("name")+"("+capitalize(ob->query("id"))+")";
  if (ob->query("nickname"))
    short = "「"+ob->query("nickname")+"」"+short;
  if (ob->query("title"))
    short = ob->query("title")+short;
  message_vision(HIR "\n$N眼冒金星，一个踉跄扑倒在地....\n\n" NOR,
          ob);
  // ob->set_temp("no_move",1);
  // //ob->disable_player(" <砸晕了>");
  //ob->set_temp("block_msg/all", 1);
  ob->set_temp("apply/short",({short+" <砸晕了>"}));
  //ob->set("gin", 0);
  //ob->set("kee", 0);
  //ob->set("sen", 0);
  ob->set_temp("mallet_fainted", 1);
  call_out("get_revived", random(100 - query("con")) + 50, ob,short);
  call_out("display_fainted", random(5), ob);
}

void get_revived (object ob, string short)
{
  if (! ob->query_temp("mallet_fainted"))
    return;

  message_vision(HIR "\n$N东倒西歪地慢慢站起来。\n" NOR,
          ob);
  // ob->delete_temp("no_move");
  // //ob->revive();
  ob->delete_temp("apply/short");
  //ob->set_temp("block_msg/all", 0);
  ob->set_temp("mallet_fainted", 0);
}

void display_fainted (object ob)
{
  string *msgs = ({
    "$N晃晃悠悠爬起来腿一软又瘫下去。\n",
    "$N躺在地上翻翻白眼。\n",
    "$N慢慢坐起来，身子一歪又倒下去。\n",
    "$N睁开眼，头一歪又晕了过去。\n",
    "$N努力张了张嘴，什么也说不出来。\n",
    "$N挣扎了一下。\n",
    "$N哼了一声。\n",
    "$N无力地伸出手，在空中抓了一下。\n",
  });

  if (! ob->query_temp("mallet_fainted"))
    return;

  message_vision(msgs[random(sizeof(msgs))],ob);
  call_out("display_fainted", random(20), ob);
  
}

