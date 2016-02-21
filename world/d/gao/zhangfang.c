// zhangfang.c

inherit ROOM;

void create()
{
  set ("short", "帐房");
  set ("long", @LONG

这儿是高家的帐房，里面摆了一排柜子．高家有好几百亩良田，大
多租给附近的农家．管家每月会去收租一次．柜子里就是全部的帐
簿．由余柜子经常开关，木把已变的油亮．
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"zhyuan",
]));
set("objects", ([
                __DIR__"npc/guanjia": 1,
		__DIR__"npc/huoji": 1 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


