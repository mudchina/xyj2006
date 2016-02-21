// create by snowcat.c 4/8/1997
// room: /d/westway/yinma.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","饮马峪");
  set ("long", @LONG

走进饮马峪，光线一下子暗了起来。你隐隐约约看见这是一个
两端小中间大的葫芦峪，峪谷底传来潺潺的流水声。西北边出
了峪口就能去酒泉，东边的峪口外通向平阳道。风乎乎地吹着
你，呜呜作响，你又仿佛觉得听见身后总有点什么动静。

LONG);

  set("exits", ([
        "east"      : __DIR__"pingyang",
        "northwest" : __DIR__"madao",
      ]));
  set("resource/water", 1);
  set("outdoors", __DIR__);

  set("objects",([
        __DIR__"npc/madao" : 1,
       ]));

  setup();
}

int valid_leave (object me, string dir)
{
  object madao;
  madao = present("ma dao",environment(me)); 
  if (madao &&
      living(madao) &&
      (string)me->query("family/family_name")!="五庄观" &&
      (me->query_temp("has_paid") <= 0) &&
      (me->query("obstacle/number") < 2) &&
      dir == "northwest")
  {
    if (random(3) == 0)
      message_vision ("$N恶狠狠地劈胸一把揪住$n：往哪儿跑！给钱！\n",madao,me);
    return notify_fail("马盗喊叫着：不给钱我要杀人啦！\n");
  }
  if (me->query_temp("has_paid") > 0)
    me->set_temp("has_paid",me->query_temp("has_paid")-1);
  return 1;
}



