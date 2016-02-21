#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "寒玉堂");
  set ("long", @LONG

殿堂乃是用寒玉沏成，深绿色的寒玉皆取于那北冥雪山之中，玉
中透出淡淡荧光，整个大堂内渗着透骨的寒气。宫中的鱼蟹都惧
怕寒冷，是以堂中冷冷清清，与大殿形成鲜明的对比。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  "/d/sea/npc/gonge" : 1,
]));
	set("cold", 1);
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shuijg",
]));
//      
        set("water", 1);
//  
  setup();
}

