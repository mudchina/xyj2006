inherit ROOM;

void create()
{
  set ("short", "书堂");
  set ("long", @LONG

一间小小的房子。正中墙上挂着一幅孔子的画像。一个老先生
正教着一群孩子念之乎者也。。。
LONG);

set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"cunkou",
]));

 set("objects", ([ /* sizeof() == 2 */
"/d/gao/npc/teacher" : 1,
"/d/gao/npc/kid" : 2,
]));


        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

