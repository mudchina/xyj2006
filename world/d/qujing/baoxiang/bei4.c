// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei4.c

inherit ROOM;

void create ()
{
  set ("short", "北街");
  set ("long", @LONG

这里离城市中心很近，路面宽敞，异国情调的人们走来走去，非常
热闹。东面有一马栈，不时有人挑担或牵马进去休息歇脚。往南就
是王宫的大门。

LONG);

  set("exits", ([
        "north"      : __DIR__"bei3",
        "east"       : __DIR__"mazhan",
        "south"      : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

