// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei1.c

inherit ROOM;

void create ()
{
  set ("short", "西城门");
  set ("long", @LONG

城楼高筑，旌旗飘扬。城门西北有条长河弯曲地流过，远远可
以看见河上架了座浮桥。往东看是城里闹市区，许多路人正忙
着进出城。西边一条小路通到山边。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"qiao2",
        "east"       : __DIR__"xi2",
      ]));

  set("objects", ([
      __DIR__"npc/people" : 2,
      __DIR__"npc/bing" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) && 
      dir == "northwest" && 
      who->query("id")!="huangjia bing")
    return 0;
  return 1;
}
