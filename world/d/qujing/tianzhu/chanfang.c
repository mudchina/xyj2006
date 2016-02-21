// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG

这个禅房已经有一段时间不用了，墙土脱落，地上有一层厚灰，
墙角垫着几张破旧的蒲团，蒲团上盖了一件素布长僧袍。禅房
的西北边有一门，通向后院的菜园小道。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"houyuan",
      ]));
  set("objects", ([
        __DIR__"npc/realgirl"   : 1,
      ]));

  setup();
}


