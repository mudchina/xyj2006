// create by snowcat.c 4/8/1997
// room: /d/westway/shandong.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","山洞里");
  set ("long", @LONG

山洞里有点昏暗，从洞外顶上垂下一些藤条。洞内壁上长了一
层层的绿苔，洞的左角地上铺了一些干草。草上盘腿坐着一位
老人，似乎并没有察觉你的到来。

LONG);

  set("exits", ([
        "out"      : __DIR__"yunti",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);

  set("objects",([
        __DIR__"npc/laoren" : 1,
       ]));

  setup();
}





