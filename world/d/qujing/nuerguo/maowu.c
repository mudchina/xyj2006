// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/maowu.c

inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG

这是一间简陋的小茅屋。四壁以芦杆搭成。屋内只有一些简
单的生活用具。一位老婆婆倚门而坐。以年龄看来似是摆渡
老妇人的姐姐。
LONG);

  set("exits", ([ 
        "south" : __DIR__"westriver",
      ]));

  set("objects",([
        __DIR__"npc/oldwoman" : 1,
       ]));

  setup();
}






