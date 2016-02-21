// Room: /d/jjf/gate.c

inherit ROOM;


void create()
{
set("short", "演武场入口");
set("long", @LONG
在傲来国演武场的入口，站立着几个威武的禁军教头，
守卫着这里。里面不时传来雄壮的号角声。
LONG
	);

set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fight_room",
  "west"  : __DIR__"northgate",
]));
set("out_doors", 1);
set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/jiaotou" : 2,
]));

setup();
}



int valid_leave(object me, string dir)
{
    if (dir == "south" && objectp(present("jinjun jiaotou", environment(me)))) 
      {
      if ( me->query_temp("donghai") !=1 ) 
         {
         return
         notify_fail("禁军教头喝道：我国兵马正在里面训练！你来这干什么(answer)？\n"
                    +"(０．比武　１．看热闹　２．捣乱　３．从军)\n");
         }
      }
      else 
         { 
         return 
         ::valid_leave(me, dir); 
         }
      return 1;
}

