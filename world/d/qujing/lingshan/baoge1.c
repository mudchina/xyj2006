// create by snowcat.c 12/8/1997
// edit by canoe ，修改没取完经的不能进去

inherit ROOM;
#include <obstacle.h>

void create ()
{
  set ("short", "宝阁");
  set ("long", @LONG

阁内有香案无数，每个香案上有金银香炉数只，仙香袅袅，缭
缭绕绕，阁北有一玉座落地金莲灯。西边有一殿门通向大雄宝
殿，楼上为宝阁藏经处。

LONG);

  set("exits", ([
        "up"   : __DIR__"baoge2",
        "west"   : __DIR__"daxiong",
  "1"   : __DIR__"chanfang1",
 "2"   : __DIR__"chanfang2",
 "3"   : __DIR__"chanfang3",
"4"    : __DIR__"chanfang4",
 "5"    : __DIR__"chanfang5",
              ]));
  set("objects", ([
        __DIR__"npc/randeng" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

int valid_leave(object who, string dir)
{
        if(dir=="west"||dir=="up")
         	return ::valid_leave(who, dir);
        else 
        {
        if (who->query("obstacle/number") < sizeof(obstacles) && !wizardp(who))
        return notify_fail("燃灯古佛拦着你：里面是修道之人清修之地，请勿打扰！\n");
        else 
              return ::valid_leave(who, dir);
        }
}

