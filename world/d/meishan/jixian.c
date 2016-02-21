
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "集仙坡");
  set ("long", @LONG

山势陡转于此，堆成半亩大小的一片平地。从此仰望山颠，尖秀
玲珑，悚拔瘦削，似有锋芒不可逼视。地下有土格分划，方者甚
方，圆者浑圆，似非天力所及。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "northup" : "望上隐约看到山颠。\n",
]));

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/zhi" : 1,
  __DIR__"npc/guo" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"cuiping",
  "southeast" : __DIR__"zhaoyun",
]));

  setup();
}


int valid_leave(object me, string dir)
{
        if (dir == "northup" ) {
        if (objectp(present("guo shen", environment(me))))
        return notify_fail("郭申一横手中青锋剑，喝道：此为我梅山要地，闲杂人等闪开！\n");
        if (objectp(present("zhi jian", environment(me))))
        return notify_fail("直健将黄铜禅杖提了起来，对着你说：先问问它答应不！\n");
        }   
        return ::valid_leave(me, dir);
}

