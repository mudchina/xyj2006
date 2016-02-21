// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/fang.c

inherit ROOM;

void create ()
{
  set ("short", "方丈楼");
  set ("long", @LONG

方丈楼里简朴干净，只有一方木桌，上面有几本佛经，几个木鱼
和木鱼锤。边上有一张长长的木床，叠有几方棉布薄被。南边是
木梯，往下通向后殿。

LONG);

  set("exits", ([
        "southdown"     : __DIR__"hou",
      ]));

  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

