// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/tangchi.c

inherit ROOM;

void create ()
{
  set ("short", "汤池");
  set ("long", @LONG

屋子里散着热腾腾的蒸气，夹杂有柴烟的味道。四周的石墙已被
熏得有点发黑，墙角架有一排大铁锅，锅边有木架子供人上下进
出，上面搭着一些毛边干浴巾。

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi2",
      ]));

  set("objects", ([ 
        __DIR__"obj/yujin" : 1,
      ]));

  setup();
}

