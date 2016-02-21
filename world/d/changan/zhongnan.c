// Room: /changan/zhongnan.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "终南山口");
  set ("long", @LONG

终南山又称太乙山，距长安城八十多里，素有“锦秀巨屏拱长
安”之说。据传老子曾在山中讲经。这条大官道穿越终南山口，
两面秀峰入云，却无明显之路可以上山。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"broadway2",
  "north" : __DIR__"broadway1",
]));
  set("outdoors", 2);

  setup();
}






