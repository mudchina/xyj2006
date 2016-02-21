// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yedu.c

inherit ROOM;

void create ()
{
  set ("short", "野渡");
  set ("long", @LONG

这里是城外废弃不用的野渡口，渡口长满野生植物。遍地沼泽，
笼罩着黑雾似的瘴气。散发着腥味的风一阵阵吹来，熏得人头重
脚轻。

LONG);

  set("exits", ([
        "northwest"  : "/d/qujing/baigudong/yelu5",
        "southeast"  : __DIR__"bei1",
      ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if (who->query("combat_exp") < 2000 ||
      random(2))
  {
    if (! who->query_temp("fainted_yedu"))
    {
      message_vision ("一阵腥风吹来，$N顿时头重脚轻。\n",who);
      who->set_temp("fainted_yedu",1);
      remove_call_out ("fall_down");
      call_out ("fall_down",1,who,environment(who));
      who->start_busy(1,1);
      return notify_fail("你禁不住踉跄了几下，两腿突然一软。\n");
    }
  }
  who->set_temp("fainted_yedu",0);
  return 1;
}

void fall_down (object who, object where)
{
  who->move(where);
  who->unconcious();
}
