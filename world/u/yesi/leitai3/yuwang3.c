// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "禹王台");
  set ("long", @LONG

高大的禹王台座落在坡上，四周是绿色的树林，苍松翠柏郁郁葱葱气
象非凡。禹王台庄严肃穆，台上铺着大小青石块，西边有一大道通向
台外，南边是一座殿宇。

LONG);

  set("exits", ([
        "westdown" : __DIR__"yuwang2",
        "south" : __DIR__"shuilu",
      ]));
  set("objects", ([
        __DIR__"npc/zu" :  2,
      ]));

  set("outdoors", __DIR__);

  setup();
}


