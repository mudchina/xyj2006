// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "门前");
  set ("long", @LONG

一座楼阁在山腰里静卧，只见山环庭院，溪绕亭台，柳间栖白
鹭，桃内啭黄莺，好一个庵观寺院。门上嵌着一个石匾，上有
“黄花观”三个大字。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"qiaolin6",
        "east"    : __DIR__"yuannei",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

