// Room: /u/mimi/zhuziguo/street2  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "官道");
  set ("long", @LONG

平西望去有一座城池，隐隐被一层黑云罩着。两边的草虫里时
有小动物窜出来。东边是一座山，山势巍峨挺拔。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"street1",
    "west" : __DIR__"eastgate",
  ]));
  set("outdoors", __DIR__"");                   
  set("light_up", 1);

  setup();
}

