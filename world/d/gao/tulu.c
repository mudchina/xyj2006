// shanlu.c

inherit ROOM;

void create()
{
  set ("short", "土路");
  set ("long", @LONG

一条湿漉漉的小路，路边开着许多野花．路边小渠里溪水缓缓的
流着．水田中也偶尔传来青蛙＂呱呱＂的叫声．远远望去，稻田
中绿油油的．北边可望到高家镇，南边就到了村里．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"daotian2",
"south" : __DIR__"cunkou",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


