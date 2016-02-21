// Room: /d/changan/kezhan  snowcat moved to /d/qujing/wuji
inherit ROOM;

int block_cmd(string);
void create ()
{
  set ("short", "坤元客栈");
  set ("long", @LONG

这家客栈位与乌鸡国最繁华的坤元街中段，所以生意非常兴隆。南
来北往的客人多在此歇脚。几个跑堂的小二来来回回招待着四方来
客。楼上是客房。

LONG);

//  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoer" : 1,
  ]));
  set("resource", ([ /* sizeof() == 1 */
      "water" : 1,
    ]));
  set("exits", ([ /* sizeof() == 5 */
    "up" : __DIR__"up",
    "north" : __DIR__"estreet2",
  ]));
  set("no_magic", 1);
  set("valid_startroom", 1);
  setup();
}

void init()
{
}

int valid_leave(object me, string dir)
{
  object mbox;

  if ( !me->query_temp("rent_paid") && dir == "up" )
    return notify_fail("店小二满脸堆笑地挡住了你：对不起，客房不便打扰。\n");

  return ::valid_leave(me, dir);
}

