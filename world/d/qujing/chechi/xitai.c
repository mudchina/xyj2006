// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xitai.c

inherit ROOM;

void create ()
{
  set ("short", "戏台");
  set ("long", @LONG

这里屋深幽暗，屋子西端搭有一座精巧但已有点退色的戏台。戏
台两边挂有数盏明亮的灯笼。前几排有些矮凳，后面是一些红油
茶桌和宽背扶手椅。

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi8",
      ]));
  set("objects", ([
        __DIR__"npc/xizi"  : 1,
      ]));

  setup();
}

