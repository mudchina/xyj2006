// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/da.c

inherit ROOM;

void create ()
{
  set ("short", "大相府");
  set ("long", @LONG

大相府由青垣石砌成。府外灯笼高挂，府内宽敞明亮富丽堂皇。
一看就知是朝廷官人的住宅，朝西有两扇包铜厚门紧闭，大概是
通向相府的内院。

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi3",
      ]));
  set("objects", ([
        __DIR__"npc/daguan"  : 1,
      ]));

  setup();
}

