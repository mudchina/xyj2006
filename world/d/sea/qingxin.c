inherit ROOM;

void create ()
{
  set ("short", "清心堂");
  set ("long", @LONG

这里是东海龙宫的南侧殿，一架大屏风将殿分成两半，屏风后放着
一些大大小小的漆红嵌金箱子彩盒，里面是宫内的文书符篆，每到
行雨时都少不了它们。几个文官模样的鱼怪来回出入。
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zitaiwei" : 1,
  __DIR__"npc/qingdusi" : 1,
]));


  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"mulang1.c",
  "north" : __DIR__"inside5",
  "southwest" : __DIR__"xizhen.c",
]));
//      
        set("water", 1);
//  
  setup();
}

