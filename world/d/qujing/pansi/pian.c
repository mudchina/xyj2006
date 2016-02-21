// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "偏房");
  set ("long", @LONG

偏房白墙红梁，有一窗户朝北开设，窗棂上挂有丹药葫芦，窗
台上放有几个火罐。房里设有四方桌斜背椅，两扇门大开，通
向东面的殿堂。

LONG);

  set("exits", ([
        "east"    : __DIR__"zheng",
      ]));
  set("objects", ([
        __DIR__"npc/dao"    : 1,
      ]));
  setup();
}

