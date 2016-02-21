// pianfang.c

inherit ROOM;

void create()
{
  set ("short", "偏房");
  set ("long", @LONG

一间小小的偏房，摆设很简单．只有一张桌子和几张椅子而已．高
家养了几个庄丁护院．其实都是些三脚猫功夫，只能吓吓人罢了．
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" :__DIR__"zhyuan",
]));
set("objects", ([
                __DIR__"npc/jiading": 2 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


