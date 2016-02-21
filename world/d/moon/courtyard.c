//Cracked by Roath
#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create()
{
  set ("short", "天井");
  set ("long", @LONG

院中满架蔷薇馥郁，中间有一口井。
LONG);

          set("valid_startroom",1);

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"junkroom.c",
  "west" : __DIR__"huilang1.c", 
         ]));

  set("objects", ([ 
	   __DIR__"npc/fairy5.c" : 1,
 	"/d/obj/flower/rose.c":2, 
	"/d/sea/npc/beast/beast6":1,
        ]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  	"water" : 1,
	]));
  set("outdoors", 1);
      
	setup();     
//	"obj/board/moon_b"->foo();
}


