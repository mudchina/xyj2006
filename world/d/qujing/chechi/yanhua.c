// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/yanhua.c

inherit ROOM;

void create ()
{
  set ("short", "烟花院");
  set ("long", @LONG

烟花院已有些年头了，院门漆成大彩红色，里面香气扑鼻，各种
摆设琳琅满目，桌上放有丝琴竹箫。从关闭的里屋门后隐隐传来
女人笑唱的声音。

LONG);

  set("exits", ([
        "north"         : __DIR__"jieshi8",
      ]));
  set("objects", ([
        __DIR__"npc/jinchai"   : 1,
      ]));

  setup();
}

