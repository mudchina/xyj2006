// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/houdian.c

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里香烟缭绕，笙竽声不绝，殿内设有一台，上放有铜壶玉
简若干。此刻烛光闪闪，灯火通明。向南是三清殿，西北方向
是藏经楼。

LONG);

  set("exits", ([
        "south"        : __DIR__"sanqing",
        "northwest"    : __DIR__"cangjing",
      ]));
  set("objects", ([
         __DIR__"npc/daotong"    : 2,
      ]));
  setup();
}

