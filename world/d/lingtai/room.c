// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "瑶台");
  set ("long", @LONG

一座瑶台高高在上，见那菩提祖师端坐在台上，两边有三十个小
仙侍立台下。周围摆设全是仙家器具，有一种说不出的祥和，又
透着庄严。
LONG);
set("exits", ([ /* sizeof() == 4 */
"out": __DIR__"houlang5",
]));
set("objects", ([
                __DIR__"npc/puti": 1 ]) );
        set("no_clean_up", 0);
        setup();
}


