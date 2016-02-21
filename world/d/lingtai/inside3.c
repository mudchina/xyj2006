// Room: some place in 西牛贺洲
// inside3.c

inherit ROOM;

void create()
{
  set ("short", "厢房");
  set ("long", @LONG

这里是一间布置得相当雅致的厢房，从窗子可以看到院中的海棠．
正中墙上挂着太极八卦．左边一个木榻，一个道士正在打坐练功．
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"gate1",
]));
set("objects", ([
                __DIR__"npc/yunjing": 1 ]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}



