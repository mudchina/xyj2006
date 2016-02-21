//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "普渡场");
  set ("long", @LONG

普渡场里香烟缭绕，正中是一大紫木香案，两边各有一个兽脚铜鼎。
场内木鱼声清脆地敲着，唱经声也此起彼伏。普渡场的东北方向是出
口，东边有一门通往祭贤场。

LONG);

  set("exits", ([
        "northeast" : __DIR__"shuilu",
        "east" : __DIR__"jixian",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
        __DIR__"npc/yin" :  1,
      ]));

  setup();
}


