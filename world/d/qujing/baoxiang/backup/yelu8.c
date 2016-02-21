// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu8.c

inherit ROOM;

void create ()
{
  set ("short", "野路");
  set ("long", @LONG

野路道路细长崎岖，起伏不停。四周远远都是大小山峦，低洼处
是一片湿湿的沼泽地带，看不见人间烟火。走在山路上静悄悄，
雾气浓郁，不由得让人小心加快步伐。

LONG);

  set("exits", ([
        "east"       : "/d/qujing/huangfeng/huangfeng8",
        "southwest"  : __DIR__"yelu7",
      ]));
  set("objects", ([
        __DIR__"npc/nuzi"   : 1,
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  object where = this_object ();

  if (who->query("obstacle/number") > 2 &&
      ! wizardp (who))
    return ::valid_leave (who, dir);

  if (dir == "east")
    return ::valid_leave (who, dir);

  if (random(20)==0)
    return ::valid_leave (who, dir);

  if (who->query_temp("obstacle/baoxiang_killed_nuzi") == 0)
  {
    if (! present ("nu zi",where))
    {
      object ob = new (__DIR__"npc/nuzi");
      ob->move(where);
    }
    return notify_fail("你眼前身影一晃，似乎有谁挡住了你的路。\n");
  }
  if (who->query_temp("obstacle/baoxiang_killed_furen") == 0)
  {
    if (! present ("fu ren",where))
    {
      object ob = new (__DIR__"npc/furen");
      ob->move(where);
    }
    if (present ("fu ren",where))
    return notify_fail("你眼前身影一晃，似乎有谁挡住了你的路。\n");
  }
  if (who->query_temp("obstacle/baoxiang_killed_gonggong") == 0)
  {
    if (! present ("gong gong",where))
    {
      object ob = new (__DIR__"npc/gonggong");
      ob->move(where);
    }
    return notify_fail("你眼前身影一晃，似乎有谁挡住了你的路。\n");
  }
  return ::valid_leave (who, dir);
}
