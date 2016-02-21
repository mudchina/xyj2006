//vikee
//1/8/2000

inherit ROOM;

void create ()
{
  set ("short", "中堂");
  set ("long", @LONG

御相府的中堂里窗明几净，屋心放着一张大八仙桌，周围放着一些太
师椅以及一些茶几供客人们使用。东边的门通向相府大门，南北各有
一门通往兵器场与盔甲场。

LONG);

  set("exits", ([
        "east" : __DIR__"yuxiang",
        "north" : __DIR__"bingqi",
        "south" : __DIR__"kuijia",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
      ]));

  setup();
}


