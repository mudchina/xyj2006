inherit ROOM;
void create ()
{
  set ("short", "山门");
  set ("long", @LONG

站在山门往里看，层层殿阁，迭迭廊房。两路松篁。又
见那钟鼓楼高，浮屠塔峻。山门上的横匾写着“观音院”
三个大字。传说这儿是观音菩萨的云下院。
LONG);
 
 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 2,
                __DIR__"npc/guai1" : 4,
        ]));
  set("exits", ([
        "eastdown"  : __DIR__"lin7", 
        "enter" : __DIR__"langdao1",
      ])); 
  set("outdoors", __DIR__);
  setup();
}

