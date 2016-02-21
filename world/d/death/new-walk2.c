// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "奉祭场");
  set ("long", @LONG

奉祭场中有一四方高台，台上刻有日月星辰，山川大河的图腾。台
上的铜鼎里偶有青烟生起，四周但见磷火阵阵，闪冒银光。四周有
一座座的楼阁宫殿，看起来也相当的富丽堂皇，间有几个索命鬼，
勾司人走来走去。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk3",
  "west" : __DIR__"new-walk4",
  "north" : __DIR__"new-walk5",
  "south": __DIR__"new-zhaopo",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/zhangmen" : 1,
]));
  set("valid_startroom", 1);

  setup();
}

