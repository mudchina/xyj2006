// shanlu.c

inherit ROOM;

void create()
{
  set ("short", "山路");
  set ("long", @LONG

好不容易走出了小林，迈上了一条山间小路。越走树林越密，树缝
中洒下来的阳光也变得斑斑点点。茅草渐厚，灌木丛生。从东北方
吹来阵阵的冷风，令人毛骨耸然。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"xiaolin1",
"northup" : __DIR__"room",
"southdown": __DIR__"shanlu1",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


