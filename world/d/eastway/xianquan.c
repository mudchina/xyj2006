// create by snowcat.c 4/20/1997
// room: /d/eastway/xianquan.c

inherit ROOM;

void create ()
{
  set ("short", "仙泉");
  set ("long", @LONG

一股热气腾腾的白雾将你团团围住，你已经来到了仙泉边。泉中
清水碧波荡漾，水面雾气缭绕，有许多人正在里面闭目坐浴。
LONG);

  set("exits", ([
        "out"     : __DIR__"huaqing",
      ]));
  set("objects", ([ /* sizeof() == 1 */
      __DIR__"npc/girl" : 2,
      ]));
  set("resource", ([ /* sizeof() == 1 */
    "spring" : 1,
      ]));

  set("outdoors", __DIR__);

  setup();
}

int init ()
{
  add_action ("do_bath","bath");
  add_action ("do_cure","cure");
  return 1;
}

int do_bath (string arg)
{
  string *msgs = ({
    "$N在泉中洗了起来。\n",
    "$N用泉水洗了洗自己。\n",
    "$N在泉中热气腾腾地洗了起来。\n",
    "$N用热热的泉水洗了洗自己。\n",
  });
  string *actions = ({
    "你感觉到泉水有一种说不出来的的神力。\n",
    "你仿佛觉得泉水有一种神秘的法力慢慢渗进你的体内。\n",
    "你似乎感觉到有一种神力渗进体内。\n",
    "你恍惚觉得有一种神秘的法力将你笼罩。\n",
    "似乎有一种神秘的法力渗进你的体内。\n",
  });
  object me = this_player();

  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"你太虚弱了，洗热水浴有危险！\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
    return notify_fail ("你正在热泉中忙着呢！\n");
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("spells",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  return 1;
}

int do_cure (string arg)
{
  string *msgs = ({
    "$N捧起泉水往身上慢慢地浇下来。\n",
    "$N用热泉水往自己身上一浇。\n",
    "$N舀起热热的泉水，往身上浇下来。\n",
    "$N躺在热泉水中，泡着自己的身体。\n",
    "$N坐进热气腾腾的泉水。\n",
    "$N泡在热泉水中，慢慢地坐浴。\n",
  });
  object me = this_player();

  if (me->is_busy())
    return notify_fail ("你正在热泉中忙着呢！\n");
  message_vision (msgs[random(sizeof(msgs))],me);
  me->start_busy(1,1);
  if ((me->query("kar")+me->query_temp("spring/cure_times")) > 20)
  {
    if (! me->update_condition())
      return 1;
    message_vision ("$N红光满面地站了起来，走到泉边。\n",me);
    me->clear_condition();
    me->unconcious();
  }
  me->add_temp("spring/cure_times",1);
  return 1;
}

int valid_leave(object me, string dir)
{
  me->delete_temp("spring/cure_times",1);
  return ::valid_leave(me, dir);
}
