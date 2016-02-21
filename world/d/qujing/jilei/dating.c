//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "大厅");
  set ("long", @LONG

一个大如宫殿的大厅，厅的中间摆满了石桌石椅，厅的石壁上
挂着兽油铜灯。大厅的西面传来烤肉的香味，东南有一通向里
面的通道，往东北方向有一石廊。

LONG);

  set("exits", ([
        "west"   : __DIR__"canting",
        "northeast"   : __DIR__"shilang",
        "southeast"   : __DIR__"woshi",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
      ]));

  setup();
}



