// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei1.c

inherit ROOM;

void create ()
{
  set ("short", "北城门");
  set ("long", @LONG

宝象国的北城门，因多次发生妖祸，城门外大道已被堵塞。向西
北方向看去可以见到山峦，向南极目看去，远远能看见宝象国的
王宫大门。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"yedu",
        "south"      : __DIR__"bei2",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
        __DIR__"npc/bing" : 2,
        __DIR__"npc/shanyao" : 1,
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

