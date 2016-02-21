// zhyuan.c

inherit ROOM;

void create()
{
  set ("short", "正院");
  set ("long", @LONG

院中一棵巨大的兰花树，开了无数朵白色的小花，发出淡淡的清香，
令人有几分陶醉．听说是高庄主的爷爷种下的，至今已有一人合抱
粗细．东西是一些仆人住的地方，北边是高家的正庭．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"zhting",
"south" : __DIR__"gate",
"east" : __DIR__"pianfang",
"west" :__DIR__"zhangfang",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


