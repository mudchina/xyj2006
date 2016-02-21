inherit ROOM;
void create ()
{
  set ("short", "大厅");
  set ("long", @LONG

这儿中间坐着一个黑汉，两旁有小妖站着，还有小妖在
走动。真是一个好地方。
LONG);
 
        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/heihan" : 1,
        ]));
  set("exits", ([
        "north"  : __DIR__"sanmen",
      ]));
  setup();
}
