// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "石门");
  set ("long", @LONG

山岩的下面，有一突出的巨石，宛若门檐一般。石门的一侧竖
着刻有一列文字，上面写着：压龙山压龙洞。石门的东南方有
一入口通向洞里面。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"yalong2",
        "southeast"   : __DIR__"shilang1",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 2,
      ]));

  setup();
}



