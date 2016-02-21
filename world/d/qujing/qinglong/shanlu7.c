// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山上一望无边的绿色森林，狂风吹过，林涛怒吼，远处的兽吼
声阵阵传来。山路盘山而绕，岩崖看上去十分陡峭，路面崎岖
且极为狭窄。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanlu6",
        "south"   : "/d/qujing/jinping/cunlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



