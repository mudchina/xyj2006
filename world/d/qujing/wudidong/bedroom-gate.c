// Room: /d/qujing/wudidong/bedroom-gate.c

inherit ROOM;

void create ()
{
  set ("short", "彩楼");
  set ("long", @LONG

好一间齐楚阁儿！白墙灰瓦，爬满了种种奇花，一扇紧闭的小小朱门，
也是藤萝掩映，更显得郁郁葱葱。门口站了两个小妖，打扮得倒也齐
整，看来这里正是洞主的绣房。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kanmen" : 2,
  __DIR__"npc/luyue" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"houdong",
  "east" : __DIR__"inner-bedroom",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "east" && 
      me->query("family/master_id") != "yu shu" &&
      member_array("tian shu",me->parse_command_id_list())==-1 &&
      member_array("yu shu",me->parse_command_id_list())==-1)
    return notify_fail("那里只有洞主的亲信才能随意出入。\n");
  return ::valid_leave(me, dir);
}
