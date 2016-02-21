// rewritten by snowcat on 4/11/1997
// Room: wuming4

inherit ROOM;

void create ()
{
  set ("short", "无名小路");
  set ("long", @LONG

前面就是山顶了，隐约可见山那边是一座高山。山上白云如烟，别是
一番天地。

LONG);

  set("objects", ([
      __DIR__"npc/bajiaoq" : 1,
          ]));

  set("exits", ([
        "westup"    : __DIR__"wuming",
        "northdown" : __DIR__"wuming3",
      ]));
  set("outdoors", "firemount");

  setup();
}
