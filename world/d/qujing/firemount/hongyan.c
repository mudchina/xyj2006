// created by snowcat on 4/11/1997
// room: hongyan

inherit ROOM;

void create ()
{
  set ("short", "红岩潭");
  set ("long", @LONG

一面大大的崖壁将一泓潭水环绕，北面有一个出口通向山外。这里
离火焰山顶已经有一段距离了，又是在潭水边，令人精神特别愉快。
你禁不住深吸一口气，心旷神怡。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"shanwai",
  "west" : "/d/qujing/jilei/shan4",
]));
  set("outdoors", "firemount");
 set("objects",
        ([ //sizeof() == 1
                __DIR__"npc/huoyun" : 1,
        ]));

  setup();
}

int valid_leave (object me, string dir)
{
/*
  if (dir=="northwest" && 
      me->query("obstacle/firemount") != "done")
  {
    tell_object(me,"你抬起脚，却怎么也迈不开步子……\n");
    return notify_fail("火焰山这一关没有过，看样子溜是溜过不去。\n");
  }
*/
  return 1;
}
