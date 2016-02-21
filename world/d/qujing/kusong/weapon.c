//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "兵器盔甲室");
  set ("long", @LONG

屋内有几个兵器甲，上面分门别类的放着些常用的兵器，兵器都
擦的很亮，看来有人经常保管。墙上挂着写盔甲鞋帽之类。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao8", 
]));



  setup();
}

