inherit ROOM;

void create ()
{
  set ("short", "密室");
  set ("long", @LONG

    这里是另外一间石室，此处很安静，很适合仙家来次修炼。
原始天尊为了安静修炼，特让弟子姜子牙在此接待来这里的仙
客们。

LONG);

  set("exits", ([
        "north"   : __DIR__"houtang",
        "southeast"   : __DIR__"dadian",
      ]));
  set("objects", ([
                __DIR__"npc/jiang" : 1,
     ]));

  setup();
  set("valid_startroom", 1);
}
