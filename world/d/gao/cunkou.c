// shanlu.c

inherit ROOM;

void create()
{
  set ("short", "村口");
  set ("long", @LONG

到了村口，向村中望去，稀稀落落也有百十来间瓦房。村里人都
忙忙碌碌的，顾不上搭理你，只有几个小童在村旁的池塘中无忧
无虑的玩着。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"tulu",
"east" : __DIR__"house",
"southwest" : __DIR__"xuetang",
]));
set("objects", ([
            "/d/gao/npc/cunzhang": 1,
]));


        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


