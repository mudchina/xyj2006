// gate.c

inherit ROOM;

void create()
{
  set ("short", "土路");
  set ("long", @LONG

周围是一片蹈田，一些农夫在田里赶着牲口耕种．还有一些孩子在
田地里玩耍．远处的村落隐约而见，炊烟饶饶，一幅天下太平的景
象．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"daotian1",
"south" : __DIR__"daotian2",
"east" : __DIR__"road3",
"west" : "/d/shushan/road1",
"northwest" : "/d/lingtai/hill",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


