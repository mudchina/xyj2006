// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>

inherit ITEM;

#include "message.h"

void create()
{
  set_name("花籽", ({ "seed"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一颗小小的花籽。\n");
    set("unit", "颗");
  }
  setup();
  call_out("need_water", 3, environment(this_object()));
}

int init ()
{
  add_action ("do_water", "water");
  this_object()->set("water",0);
  return 1;
}

void grow (object where)
{
  object me = this_object();
  object who = environment(me);
  string name = me->query("name");
  string msg;

  if (! living(who))
    return;

  if (me->query("dried"))
    return;

  if (me->query("id") == "seed")
  {
    if (random(6) == 0)
    {
      message_vision ("花籽绽裂开，露出了一颗绿芽。\n",who);
      me->set_name("绿芽", ({ "germ"}));
      //me->set("name","绿芽");
      //me->set("id","germ");
      me->set("long","一颗正在长大的小绿芽。\n");
      me->set("unit", "颗");
    }
    else
      message_vision ("花籽动了一下，胀大了一点点。\n",who);
    return;
  }

  if (me->query("id") == "germ")
  {
    if (random(9) == 0)
    {
      message_vision ("绿芽终于长高了，在风中欢快地摇弋。\n",who);
      me->set_name("绿草", ({ "plant"}));
      //me->set("name","绿草");
      //me->set("id","plant");
      me->set("long","一棵茁壮的绿草，上面有花苞。\n");
      me->set("unit", "棵");
    }
    else
      message_vision ("绿芽咔嚓一声长高了一截。\n",who);
    return;
  }

  if (me->query("id") == "plant")
  {
    if (random(12) == 0)
    {
      object flower;
      message_vision ("绿草上的花苞绽开了！春天来了！\n",who);
      flower = new (__DIR__"flower");
      flower->move(who);
      destruct(me);
    }
    else
    {
      switch (random(3))
      {
        case 0:
          { message_vision ("绿草在风中跳起了舞。\n",who); break; }
        case 1:
          { message_vision ("绿草要开花了。\n",who); break; }
        case 2:
          { message_vision ("绿草微笑着。\n",who); break; }
      }
    }
  }
}

void need_water (object where)
{
  object me = this_object();
  object who = environment(me);
  string name = me->query("name");
  string msg;

  if (!who || !living(who))
    return;

  if (me->query("id") == "seed")
  {
    call_out ("need_water",3,where);
    return;
  }

  switch (me->query("water"))
  {
    case 0:
      { msg = name+"长高了一点。\n"; break; }
    case 1:
      { msg = name+"有点蔫了，快淋一点水吧。\n"; break; }
    case 2:
      { msg = name+"开始发黄了。\n"; break; }
    case 3:
      { msg = name+"已经失去了绿色的光泽。\n"; break; }
    case 4:
      { msg = name+"看上去严重缺水，奄奄一息了。\n"; break; }
    case 5:
      { msg = name+"干枯了。\n";
        me->set("name","干"+name);
        me->set("dried",1);
        break; }
  }
  message_vision (msg,who);
  me->set("water",me->query("water")+1);
  call_out ("need_water",random(10)+10,where);
  remove_call_out ("grow");
  call_out ("grow",random(5)+5,where);
}

int do_water (string arg)
{
  object me = this_object();
  object who = this_player();
  string name = me->query("name");
  string msg;

  if (arg != me->query("id"))
    return 0;

  if (me->query("water") >= 5)
  {
    message_vision ("$N的泪水一滴滴流在"+name+"上。\n",who);
    return 1;
  }

  switch (random(9))
  {
    case 0:
      { msg = "$N口含清水，喷在"+name+"上。\n"; break; }
    case 1:
      { msg = "$N将一点清水洒在"+name+"上。\n"; break; }
    case 2:
      { msg = "$N伸出手抓住细细的小雨，淋在"+name+"上。\n"; break; }
    case 3:
      { msg = "$N小心地捧起一点点露水，滴在"+name+"上。\n"; break; }
    case 4:
      { msg = "$N一阵心痛，泪水流在"+name+"上。\n";break; }
    case 5:
      { msg = "$N双手捧着"+name+"，伸到窗外的小雨中……\n";break; }
    case 6:
      { msg = "$N仔细地拿起一只小杯子，将水滴在"+name+"上。\n";break; }
    case 7:
      { msg = "$N捧起从野外采来的晨露，洒在"+name+"上。\n";break; }
    case 8:
      { msg = "$N用手指蘸着清水，一点点滴在"+name+"上。\n";break; }
  }
  message_vision (msg,who);
  me->set("water",0);
  remove_call_out ("grow");
  call_out ("grow",random(5)+5,who);
  return 1;
}
