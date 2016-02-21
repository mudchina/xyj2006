// rewritten by snowcat on 4/11/1997
// Room: wuming1

inherit ROOM;

void create ()
{
  set ("short", "无名小路");
  set ("long", @LONG

无名小路蜿蜒曲折，前面可看到一座小光秃秃的山丘，四周不见一点
生机，只有红色的砂石。

LONG);

  set("exits", ([
        "northeast" : __DIR__"shalu",
        "southwest" : __DIR__"wuming2",
      ]));
  set("outdoors", "firemount");

  setup();
}
