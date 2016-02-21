// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/bedroom.c

inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG

休息室布置得简单干净，南边靠窗是一铺红砖大炕，铺着藏蓝
色的棉被。炕上摆了个炕桌，放着一个香炉，袅袅香烟从炉上
升起，弥漫整个房间。

LONG);

  set("exits", ([
        "east"         : __DIR__"chanyuan",
      ]));

  set("objects", ([
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

