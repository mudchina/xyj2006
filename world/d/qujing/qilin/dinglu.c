// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "鼎炉厅");
  set ("long", @LONG

大厅里放着一长条石桌，厅堂后是一巨型铜鼎，下面火光闪闪。石
桌上放着各色果菜，又摆着獐狸鹿兔之类的野味。大厅的里门通向
帅府宫，东边通向偏宫。

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"shuaifu",
    "east" : __DIR__"piangong",
    "southeast" : __DIR__"dongnei",
  ]));
  set("objects", ([
    __DIR__"obj/rou" : 5,
    __DIR__"npc/nanyao" : 2,
  ]));
  setup();
}
