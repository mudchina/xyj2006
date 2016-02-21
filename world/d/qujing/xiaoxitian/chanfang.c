// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG

一个半新半旧的禅房，已不再使用，现被用来当作仓库，墙角
堆着一些粮袋。南边原有两扇窗子，已被用木板封死。北面是
通向菜园的门。

LONG);

  set("exits", ([
        "north"   : __DIR__"caiyuan",
      ]));
  set("objects", ([
        __DIR__"obj/jinnao"   : 1,
        __DIR__"npc/tong"   : 3,
      ]));

  setup();
}



