// Room: /shulin/lin4.c
inherit ROOM;
void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片茂密的树林，好象被人设计了一种阵，一走进来，你仿佛迷失了方向。
LONG );
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"lin5",
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __DIR__"lin3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
