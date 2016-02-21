// Room: /d/qujing/wudidong/lock.c
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "石洞");
  set("long", @LONG
      
踏进门来，已无半点光亮，你只得摸索前进。四下阴冷潮湿，阵阵霉
臭之气扑面而来。远处突然传来微弱的声响，似是有人在低声呻吟，
又似野兽低嗥，令你毛发直竖。
LONG);
  set("exits", ([ /* sizeof() == 2 */
		 "southeast" : __DIR__"houdong",
		 "north" : __DIR__"trap",
		 ]));
  set("no_clean_up", 0);

  setup();
}
int valid_leave(object me, string dir)
{
  int mykar, mycor, factor;

  mycor=(int)me->query_cor();
  mykar=(int)me->query_kar();
  factor=mykar*2-mycor;
  if(factor<1) factor=1;
  if (dir=="southeast")
    {
      me->delete_temp("mark/wudidong_no_hope_of_knowing_trap");
      me->delete_temp("mark/wudidong_aware_of_trap");
    }
  if (me->query_temp("mark/wudidong_no_hope_of_knowing_trap"))
      return ::valid_leave(me, dir);
  if (dir =="north")
  {
      if(random(factor)>=5)
	{
	  tell_object(me, CYN "你隐隐觉得有些不对，也不知为什么。似乎有什么机关需要你去破(disarm)。\n" NOR);
	  me->set_temp("mark/wudidong_aware_of_trap", 1);
	}
      else
        {
	  tell_object(me, CYN "你隐隐觉得有些......\n" NOR);
          me->set_temp("mark/wudidong_no_hope_of_knowing_trap", 1);
	}
    }
  return ::valid_leave(me, dir);
}
