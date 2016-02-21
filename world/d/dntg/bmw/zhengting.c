//sgzl
#include <room.h>
inherit ROOM;
 
void create()
{
   set("short", "正厅");
   set("long", @LONG

小小的正厅中大大小小的官员都在繁忙的工作着，
中间一张大大的公案。
LONG );
set("item_desc",(["book":"
御马监共上等成年战马千匹，随时听候调用。\n"
]));
 
   set("exits", ([
   "east"  : __DIR__"zoulang",
   "north" : __DIR__"majiu1",
   "south" : __DIR__"yinyanting",
  ]));
 
  set("objects", ([
    __DIR__"npc/jiancheng" : 1,
    __DIR__"npc/dianbu" : 1,
    __DIR__"obj/table" : 1,
  ]));
 

  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}

int valid_leave(object me, string dir)
{
  if (dir == "north" && objectp(present("jian cheng", environment(me)))) 
    {
    if ( me->query("dntg/bmw") !="allow" ) 
         return notify_fail("监丞伸手拦住你道：后面是御马监重地，"+ RANK_D->query_respect(me) +"没事还是不要进去了吧。\n");
    else  return  ::valid_leave(me, dir); 
    }
  return 1;
}

