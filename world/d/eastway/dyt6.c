// create by snowcat.c 4/20/1997
// room: /d/eastway/dyt6.c

inherit ROOM;

void create ()
{
  set ("short", "大雁塔内");
  set ("long", @LONG

大雁塔内结构精洁宽敞，塔内布置精美，给人以清静肃穆
之感。四周开有龛窗，塔内有楼梯直通上下。这里似乎是
非同寻常的场所。

LONG);

  set("exits", ([
        "down"    : __DIR__"dyt5",
        "up"      : __DIR__"dyt7",
      ]));

  setup();
}






