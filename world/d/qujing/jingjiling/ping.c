#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "萝藤坪");
  set ("long", @LONG

这里独有方圆近丈的一片空地，四处结着不少藤萝，箩根在地下
盘结勾连，就好象一张大网般笼在石崖上。远望山坡上遍地的荆
棘，将道路团团围住。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jingji8",
  "southup" : __DIR__"shiya",
]));

  setup();
}


int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "southup") {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
                return
notify_fail("赤身鬼使一挺手中钢叉，挡住了你的去路。\n");
        }

        return 1;
}

