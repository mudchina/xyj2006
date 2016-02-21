#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "云楼宫门");
  set ("long", @LONG

云楼宫乃是托塔李天王的住宅，未近宫门已觉兵气森森。门楼上
高悬一龙吞漆金匾，上书“托塔天王府”五个大字。门旁兵将盔
明铠亮，警惕有神的护卫着府门。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"yongdao",
    "west" : __DIR__"yun1",
  ]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/yaocha" : 1,
  __DIR__"npc/yushi" : 1,
]));

  set("outdoors", 1);
  setup();
}


int valid_leave(object me, string dir)
{

        if( wizardp(me)) return 1;


        if (dir == "east" ) {
	  if(me->query("combat_exp") < 100000) {
	        if (objectp(present("yushi jiang", environment(me))))
       		  return notify_fail("鱼师将伸手将你拦住，说：此乃天王府，闲杂人等闪开！\n");
       		if (objectp(present("yaocha jiang", environment(me))))
       		  return notify_fail("药叉将伸手将你拦住，说：此乃天王府，闲杂人等闪开！\n");
	  }
        }   
        return ::valid_leave(me, dir);
}

