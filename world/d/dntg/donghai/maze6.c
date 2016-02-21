//sgzl

#include <room.h>
inherit ROOM;

string *ways = ({
  "/d/dntg/donghai/mazea",
  "/d/dntg/donghai/maze3",
  "/d/dntg/donghai/maze2",
  "/d/dntg/donghai/mazed",
  "/d/dntg/donghai/maze3",
});

void create()
{
set("short", "海底迷宫");
set("long", @LONG
海水又变的清澈了，但你已经很难找到方向了。    
四周的景物好象都一样，要是没人引路的话看来
很难出去了。
LONG );


set("exits", ([
  "south"   : __DIR__"mazeend",
  "east"   : ways[random(sizeof(ways))],
  "north"   : ways[random(sizeof(ways))],
  "west"   : ways[random(sizeof(ways))],
]));


set("objects", ([
     __DIR__"npc/xiaoyu"  : 1,
]));




setup();
}


void init()
{
      if(this_player()->query("id")=="xiao hong yu"
      || this_player()->query("id")=="xiao qing yu"
      || this_player()->query("id")=="xiao lan yu"
      || this_player()->query("id")=="xiao bai yu"
      || this_player()->query("id")=="xiao hua yu"
      || this_player()->query("id")=="xiao jin yu"
        )
        message_vision("$N游了过来。\n",this_player());
}

int valid_leave(object me, string dir)
{
      if(this_player()->query("id")=="xiao hong yu"
      || this_player()->query("id")=="xiao qing yu"
      || this_player()->query("id")=="xiao lan yu"
      || this_player()->query("id")=="xiao bai yu"
      || this_player()->query("id")=="xiao hua yu"
      || this_player()->query("id")=="xiao jin yu"
        )
       message_vision("$N摆着尾巴游走了。\n", this_player());
       return ::valid_leave(me, dir);
}

