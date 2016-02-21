// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "寺院");
  set ("long", @LONG

寺院里有石山花亭，香草异花朵朵，亭边流水潺潺，水边垂柳
悠悠如流苏一般。院里一条石路往东铺向一座大殿，院子的北
边通向寺外，西南角有一菜园。

LONG);

  set("exits", ([
        "north"   : __DIR__"simen",
        "southwest"   : __DIR__"caiyuan",
        "east"   : __DIR__"daxiong",
      ]));
  set("objects", ([
         __DIR__"npc/tong"   : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}



