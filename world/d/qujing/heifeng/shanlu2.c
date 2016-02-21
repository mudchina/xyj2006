//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

到处都是山，路也是弯弯曲曲向前延伸着，你不禁觉得很疲惫，草
裹在脚上，十分的难行，真是取经路上多磨难啊。
LONG);

  set("exits", ([
        "west"  : __DIR__"shanlu3",
        "east"  : __DIR__"shanlu1",
      ]));
  set("outdoors","hf");
  setup();

}
