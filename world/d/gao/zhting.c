// zhting.c

inherit ROOM;

void create()
{
  set ("short", "正厅");
  set ("long", @LONG

正前方是一张八仙桌，左右是两张带皮垫的太师椅。高老爷正坐在椅
上正喝着茶水。左右墙上挂着几幅字画，仔细看看好象并没有什么名
气。东西是两间偏厅。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"houyuan",
"south": __DIR__"zhyuan",
"west" : __DIR__"pianting",
"east" :__DIR__"fanting",
]));
set("objects", ([
                __DIR__"npc/gao": 1,
		__DIR__"npc/yahuan2": 2 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


