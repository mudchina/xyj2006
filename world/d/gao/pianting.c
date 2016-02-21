// pianting.c

inherit ROOM;

void create()
{
  set ("short", "偏厅");
  set ("long", @LONG

靠窗是张火炕，上面垫着皮褥子．整个房子暖洋洋的．高老太太
正盘着腿坐在炕上，低头查着旧帐．旁边一个丫环伺候着．
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"zhting",
]));
set("objects", ([
                __DIR__"npc/gaopo": 1,
                __DIR__"npc/yahuan1": 1,
]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


