// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "华夷阁");
  set ("long", @LONG

华夷阁有十来丈之高，以精雕木建就，四周绘着彩色图案，西
边的阁门通向一条彩廊。阁内色彩鲜艳装璜华丽，风吹过来，
有无数檐铃叮咚作响。

LONG);

  set("exits", ([
        "west"   : __DIR__"gongyuan",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 1,
      ]));

  setup();
}


