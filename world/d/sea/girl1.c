// girl1.c

inherit ROOM;

void create()
{
  set ("short", "紫云宫");
  set ("long", @LONG

紫云宫是公主龙女住的地方，当然这里不许男子出入。屋里的装饰
多是人间难得一见的珍宝。正中一块浑玉雕成的香炉苒苒的冒着一
股淡紫色的薄烟，整个屋中漫着香气。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"inside1",
"southeast" : __DIR__"girl2",
]));
set("objects", ([
                __DIR__"npc/qiupo": 1]) );

        set("no_clean_up", 0);
//      
        set("water", 1);
//  
        setup();
}

