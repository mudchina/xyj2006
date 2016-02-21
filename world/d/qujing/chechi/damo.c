// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/damo.c

inherit ROOM;

void create ()
{
  set ("short", "达摩殿");
  set ("long", @LONG

达摩殿里空空如也，几张供桌零乱地堆在屋角。墙面龟裂，门窗
无存。地上胡乱地铺着干草，上面放着一些破旧蒲团。西北方向
有一通道。

LONG);

  set("exits", ([
        "northwest"     : __DIR__"jingang",
      ]));

  set("objects", ([
        __DIR__"npc/heshang"    : 3,
      ]));
  setup();
}

