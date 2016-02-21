
inherit ROOM;

void create ()
{
  set ("short", "大门");
  set ("long", @LONG

你眼前出现了一座汉白玉牌坊，上面龙飞凤舞的写着“瑶池”
两个金色大字。里面就是王母娘娘用来宴客的瑶池了。旁边站
着一个身材魁武，神态伟岸的金甲卫士，两道目光炯炯地审视
着你，看得你一阵心虚。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wmj6",
  "north" : __DIR__"donglang",
]));

  setup();
}

int valid_leave(object me, string dir)
{
    if ( dir == "north" && me->query_temp("yaochi_pass") <= 0 )
            return notify_fail("瑶池重地，闲人免入！\n");
    if (me->query_temp("yaochi_pass") > 0)
    me->set_temp("yaochi_pass",me->query_temp("yaochi_pass")-1);
  return 1;
}
