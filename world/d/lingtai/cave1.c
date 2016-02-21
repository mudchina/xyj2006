// Room: some place in 西牛贺洲
// cave1.c

inherit ROOM;

void create()
{
  set ("short", "洞口");
  set ("long", @LONG

好不容易从密林中走了出来，眼前一下亮了起来．前方一个小
山洞，洞口还有不少血迹．一阵山风吹过，带来股令人欲呕的
腥气．．．啊！！？难道有野兽？
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"forrest",
"west": __DIR__"cave2",
]));
set("objects", ([
                __DIR__"npc/oldwolf.c": 1 ]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( dir == "west" && objectp(present("wolf", environment(me)))) 
        return notify_fail("老狼猛的跳到你前面拦住你！\n");

        return ::valid_leave(me, dir);
}

