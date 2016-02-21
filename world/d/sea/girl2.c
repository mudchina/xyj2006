// hill.c

inherit ROOM;

void create()
{
  set ("short", "花园");
  set ("long", @LONG

花园虽不大，花儿却极多。五颜六色，姹紫嫣红。看一看却都不
认的．几只彩色的小鱼游来游去。向东是公主的寝宫，南边是公
主平时练武的地方。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"girl1",
"east" : __DIR__"girl3",
"south" : __DIR__"girl4",
"north" : __DIR__"wolongrest",
]));
set("objects", ([
                __DIR__"npc/gongnu": 1]) );

        set("no_clean_up", 0);
	set("outdoors", 1);
//      
        set("water", 1);
//  
        setup();
}

int valid_leave(object me, string dir)
{
    if((string)me->query("family/family_name")=="龙宫") return 1;
   if((string)me->query("family/family_name")=="东海龙宫") return 1;


    if (dir == "north" ) {

        return notify_fail("那里只有龙宫的弟子才能进去．\n");
    }

return 1;
}

