// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/fengyun.c

inherit ROOM;

void create ()
{
  set ("short", "风云殿");
  set ("long", @LONG

殿里云霞缭绕，烟雾层叠，仙气十足。殿壁上绘满各种风神云神
的画像，神态各异。殿心有一八角香桌，上面燃着九柱麝香，香
气扑鼻。

LONG);

  set("exits", ([
        "south"        : __DIR__"jishui",
        "east"         : __DIR__"jinluan",
      ]));

  set("objects",([
         __DIR__"npc/taijian" : 1,
      ]));
  setup();
}

