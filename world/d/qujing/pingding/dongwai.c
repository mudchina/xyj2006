// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "洞外");
  set ("long", @LONG

一道山涧从脚下流过，发出潺潺的流水声。山涧的去处有一片
绿色林木，林木的后面有一山洞，洞的上沿有一凿平的石壁，
上面刻着：平顶山莲花洞。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"ping3",
        "southeast"   : __DIR__"dongmen",
      ]));
  set("objects", ([
    __DIR__"npc/chong"   : 1,
    __DIR__"npc/gui"   : 1,
  ]));
  set("outdoors", __DIR__);

  setup();
}



