#include <room.h>
inherit ROOM;

int do_dive(string arg);
void reset();

void create ()
{
  set ("short", "山顶");
  set ("long", @LONG

山顶光秃秃的，一棵花草也无，只有一块平坦的巨石。走近一看，大
石正中是一个缸口大小的洞(dong)，已被磨得光滑无比。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "
这就是无底洞了，你凑过去一看，简直就是深不见底。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"shanlu4",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
  add_action("do_dive", "dive");
  add_action("do_dive", "tiao");
}
int do_dive(string arg)
{
  object me;
  me=this_player();
  if ( !arg || ((arg !="dong") ))
    return notify_fail("你要往哪儿跳？ \n");
  message_vision("$N一纵身，跳入洞中，足下彩云生万道，身边瑞气护千层。\n", me);
  me->move(__DIR__"dong1");
  return 1;
}
