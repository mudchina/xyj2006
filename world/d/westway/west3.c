//Cracked by Roath
// create by snowcat.c 4/8/1997
// room: /d/westway/west3.c

inherit ROOM;

void create ()
{
  set ("short", "大官道");
  set ("long", @LONG

这是一条宽阔笔直的大官道，足可容得下十马并驰。往西通向
金城郡，西北地区的重要城镇，往东则直达大唐国都长安城。

LONG);

  set("exits", ([
        "east" : __DIR__"west2",
        "northwest" : __DIR__"jincheng",
      ]));
  set("outdoors", __DIR__);

  set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  setup();
}






