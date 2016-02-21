// Room: /changan/xiaoqiu.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "小土丘");
  set ("long", @LONG

泾水河边的一座小土丘，不知因何垒成。微风掠过，坡上垂
柳沙沙而动。绿荫中有一小亭，亭上牌匾“品棋亭”三个大
字写得是意兴盎然。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"eside2",
  "enter" : __DIR__"pinqiting",
]));
  set("outdoors", 1);

  setup();
}






