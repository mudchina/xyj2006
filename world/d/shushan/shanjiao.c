//Cracked by Roath
inherit ROOM;

void create()
{
  set ("short", "山脚");
  set ("long", @LONG

山花漫漫，绿野青青，这里是四川蜀山的山脚
远远望去，山上白雪皑皑，山顶一座直耸入云的
宝塔据说关押着传说中的蛇女.
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road1",
"northup" : __DIR__"path1",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
