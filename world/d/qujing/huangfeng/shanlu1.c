//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

就要走出树林了，只见前面有座高山，十分险峻，有诗写道：

   高的是山，峻的是岭；陡的是崖，深的是壑；响的是泉，鲜的是花；
   那山高不高，顶上接青霄；这涧深不深，地下见地府。

LONG);

  set("exits", ([
        "west"  : __DIR__"shanpo",
        "east"  : __DIR__"road4",
      ]));
  set("outdoors","hfd");
  setup();
}
