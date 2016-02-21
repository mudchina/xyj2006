// created by snowcat.c 4/4/1997
// room: /d/nuerguo/greenyard.c

inherit ROOM;

void leave_here(object me);

void create ()
{
  set ("short", "绿迷宫");
  set ("long", @LONG

一座用无数棵绿树修剪成的大迷宫，前后左右都是一片绿色
的密树丛，很难辨别方向，也看不到任何出口。

LONG);

  set("exits", ([
        "east"      : __DIR__"greenyard",
        "west"      : __DIR__"greenyard",
        "south"     : __DIR__"greenyard",
        "north"     : __DIR__"greenyard",
        "northwest" : __DIR__"greenyard",
        "southwest" : __DIR__"greenyard",
      ]));
  set("valid_startroom",1);
  setup();
}

void init()
{
  add_action("do_fly", "fly");
  add_action("do_quit", "quit");
}

int do_quit ()
{
  object me;
  me = this_player();

  me->set("startroom",base_name(environment(me)));
  tell_object(me,"暂时离开迷宫……\n");
  return 0; // return 0 to invoke normal quit
}

int do_fly (string arg)
{
  object me;
  me = this_player();

  message_vision("只见$N向上一飞，重重地摔了下来，头上粘着几片枯树叶。\n", me);
  tell_object(me,"看样子在迷宫里真是插翅难飞……\n");
  return 1;
}

int valid_leave (object me, string dir)
{
  object icedew;
  int i;

  me->set("startroom",base_name(environment(me)));
  if (i = me->query_temp("out_of_greenyard"))
  {
    i++;
    me->set_temp("out_of_greenyard",i);
    if (i > 5)
    {
      me->set_temp("lost_in_greenyard",0);
      me->set_temp("out_of_greenyard",0);
      
      call_out("leave_here",1,me);

      return 1;
    }
  }
  else if (! me->query_temp("lost_in_greenyard"))
  {
    me->set_temp("lost_in_greenyard",1);
    call_out("found_outlet",240+random(240),me);
  }
  return 1;
}

// mon move this out of the valid_leave function
// to prevent an Illegal move error.
// 4/11/98
void leave_here(object me)
{
      object icedew;

      me->move(__DIR__"outlet");
      if (! present("icedew",environment(me)))
      {
        icedew = new(__DIR__"obj/icedew");
        icedew->move(environment(me));
      }
      tell_object(me,"绿草地上有一个亮闪闪的东西！\n");
}

void found_outlet(object me)
{
  if(!me) return;
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",1);
}
