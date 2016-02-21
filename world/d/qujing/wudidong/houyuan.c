// Room: /d/qujing/wudidong/houyuan
// created 6-18-97 pickle
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "后院");
  set ("long", @LONG

后院里落叶遍地，也没有人打扫。角落里有一口石井，上面长满了青
苔杂草，旁边一根井绳。打水的桶也不知哪去了，看来很久没人用过
了。
LONG);

  set("light_up", 1);
  set("outdoors", "/d/qujing/wudidong");
  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"bedroom",
]));

  setup();
}
void init()
{
  add_action("do_dive", "dive");
}

int do_dive(string arg)
{
  object me, tar;
  me=this_player();
  if ( !arg || ((arg !="well") ))
    return notify_fail("你要往哪儿跳？\n");
  
  if (!tar=present("bishui zhou", me))
    return notify_fail(HIY "你纵身跳下井去，无奈水性欠佳，呛了两口水后，不得不拉着井绳爬了回来。\n" NOR);
  else message_vision(HIW "$N一纵身，跳下井去。\n" NOR, me);
  me->move(__DIR__"well");
  return 1;
}
