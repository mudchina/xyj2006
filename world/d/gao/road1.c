// gate.c

inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG

一条石板小路，刚下过雨，路上看起来还满干净的．一些乡下人
挑着自己种的蔬菜到镇里卖，人不是很多，吆喝声传出很远，在
镇子里回荡．
LONG);
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"zhyuan",
"south" : __DIR__"inn",
"east" : __DIR__"gate",
"west" :__DIR__"road2",
]));
set("objects", ([
                __DIR__"npc/xiaofan": 1]));
        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


