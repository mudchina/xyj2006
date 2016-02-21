
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "铁柱关");
  set ("long", @LONG

从铁柱关往上便是梅山了，铁柱关是上山的唯一道路。路旁有
两座怪石，高达丈许，形如铁柱，是以此地得名铁柱关。当地
人陈此为神人所设，是为二郎真君报迅的天兵。
LONG);


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/meishan/erlangwai",
  "east" : __DIR__"fenglin1",
]));

  setup();
}
int valid_leave(object me, string dir)
{       
	if( wizardp(me)) return 1;

	if (dir == "east") {

        if (!me->query_temp("erlangpass") ){
return notify_fail("好象身后有个人纠住你，你动也动不了！\n");
                }
        return ::valid_leave(me, dir);
        }

        return 1;
}

