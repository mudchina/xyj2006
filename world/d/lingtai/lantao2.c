// Room: some place in 西牛贺洲
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "烂桃山");
  set ("long", @LONG

这里是一片野桃林，山中的桃子无人采摘，密密的桃子挂在枝
头。地下的早已腐烂成泥，不知堆集了几百年。
LONG);
set("exits", ([ /* sizeof() == 4 */
"eastdown" : __DIR__"lantao",

]));

set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/npc/swk": 1]));
  
      set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


