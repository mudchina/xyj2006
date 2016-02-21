// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "会同馆");
  set ("long", @LONG

会同馆为天阳街最大的聚集地，远道而来的客人受到邀请可以在这
里休息，整个会同馆舒适安静。贵宾到此，会有专门的人夫迎接安
排住宿饭食。

LONG);

  set("exits", ([ 
    "east" : __DIR__"chu",
    "south" : __DIR__"xiang",
    "north" : __DIR__"tian2",
  ]));
  set("valid_startroom", 1);
  setup();
}
