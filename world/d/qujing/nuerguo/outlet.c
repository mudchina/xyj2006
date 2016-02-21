// created by snowcat.c 4/4/1997
// room: /d/nuerguo/outlet.c

inherit ROOM;

void create ()
{
  set ("short", "迷宫出口");
  set ("long", @LONG

突然无数棵绿树丛中出现了一个豁口，外面似乎是一条大路。
你心中一喜，总算从迷宫里走出来了。

LONG);

  set("exits", ([
        "westup" : __DIR__"shanpo",
      ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave (object me, string dir)
{
  // once get into here, reset all greenyard temps, to prevent abuse
  me->set("startroom","/d/city/kezhan");
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}






