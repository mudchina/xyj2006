// Room: some place in 西牛贺洲
// hill.c

inherit ROOM;

void create()
{
  set ("short", "方寸山下");
  set ("long", @LONG

抬头望去，到了一座山下。山虽不高，望去却气象万千，婀娜多
姿。一朵白云斜斜的靠在山腰，为山平增几分灵气。隐隐约约能
听到山中樵夫唱的山歌，几只小鸟也随之一唱一和。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill1",
"southeast" : "/d/gao/road4",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

