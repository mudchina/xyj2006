// rewritten by snowcat on 4/11/1997
// Room: wuming2

inherit ROOM;

void create ()
{
  set ("short", "无名小路");
  set ("long", @LONG

无名小路蜿蜒曲折，前面可看到一座小光秃秃的山丘，四周不见一点
生机，只有红色的砂石。

LONG);

  set("objects", ([
    __DIR__"npc/bajiao" : 1,
    ]));

  set("exits", ([
        "northeast" : __DIR__"wuming1",
        "southup"   : __DIR__"wuming3",
      ]));
  set("outdoors", "firemount");

  setup();
}
