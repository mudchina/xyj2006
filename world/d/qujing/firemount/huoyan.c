// rewritten by snowcat on 4/11/1997
// room: huoyan

inherit ROOM;

void create ()
{
  set ("short", "火焰山");
  set ("long", @LONG

火，火，火！！！

大火绵延八百里，四周寸草不生。据说当年太上老君的炼丹炉被蹬
翻，几块炉砖掉在此处，即化为火焰山。人一走进去既成烟灰，更
勿提东南西北。

LONG);

  set("exits", ([
        "westdown" : __DIR__"huoyan",
        "eastdown" : __DIR__"huoyan",
        "northup"  : __DIR__"huoyan",
        "southup"  : __DIR__"huoyan",
      ]));
  set("outdoors", "firemount");
  set("burning_mount",1);
  setup();
}

void init()
{
  add_action("do_all", "");
  add_action("do_fly", "fly");
  add_action("do_extinguish", "extinguish");
  add_action("do_extinguish", "fan");
  add_action("do_extinguish", "shan");
}

int do_fly (string arg)
{
  object me = this_player();

  if (! this_object()->query("burning_mount"))
    return 0;

  message_vision("只见$N向上一飞，又被一个热浪重重地打了下来。\n", me);
  return 1;
}

void burnt (object me)
{
  if (! me)
    return;

  if (environment(me) != this_object())
  {
    me->set_temp("burnt_in_mount",1);
    return;
  }

  if (! this_object()->query("burning_mount"))
    return;

  if (random(8) == 0)
  {
    message_vision("一股热浪袭来，将$N往上一抛，$N飞了出去！\n",me);
    me->move(__DIR__"shanbian");
    message_vision("$N冒着浓烟从山上滚了下来！\n",me);
    me->set_temp("burnt_in_mount",0);
    me->set_temp("fanned_in_mount",0);
    me->set_temp("fan_times_in_mount",0);
    me->set_temp("fainted_in_mount",1);
 me->unconcious();
    return;
  }
  else if (random(2) == 0)
  {
    object ob;
    object *inv = all_inventory(me);
    if (sizeof(inv) == 0)
      return;
    ob = inv[random(sizeof(inv))];
    if (ob->query("id") != "tie shan")
    {
      if (ob->move(this_object()))
      {
        message_vision("只见火焰一舔，$N的$n顿时化为灰烬！\n",me,ob);
        destruct(ob);
      }
    }
  }
  else 
  {
    switch (random(4))
    {
      case 0:
        { message_vision("$N的头发冒起一股青烟！\n",me); break; }
      case 1:
        { message_vision("$N身上滋滋作响！\n",me); break; }
      case 2:
        { message_vision("$N的脸上膨起几个大水疱！\n",me); break; }
      case 3:
        { message_vision("$N发出一股焦味！\n",me); break; }
    }
  }
  if(me->query("kee") > 15)
    me->add("kee",-5-random(10));
  if(me->query("sen") > 15)
    me->add("sen",-5-random(10));
  call_out ("burnt",random(5)+15,me);
}

void get_burnt (object me)
{
  if (!me || me->query_temp("burnt_in_mount"))
    return;

  if (! this_object()->query("burning_mount"))
    return;

  call_out ("burnt",1,me);
}

int do_all ()
{
  object me;
  me = this_player();

  call_out ("get_burnt",random(2)+10,me);
  return 0; // return 0 to invoke normal commands
}

void announce_success (object me)
{
  object princess = new (__DIR__"npc/princess");

  princess->announce_success(me);
  destruct(princess);
}

void success_quest (object me)
{
  object where = this_object();
  message_vision("\n刹那间天昏地暗，轰隆隆几声剧响之后，一切都平静了！\n", me);
  message_vision("$N抑制住砰砰心跳，定睛一看：大火已经被扑灭了！\n", me);
  where->set ("long", @LONG

大火已经被人扑灭了，四处还冒着一丝丝的残烟。

曾几何时这里的大火绵延八百里，四周寸草不生。据说当年太上老
君的炼丹炉被蹬翻，几块炉砖掉在此处，即化为火焰山。人一走进
去既成烟灰，更勿提东南西北。

现在一切都很平静了，你走在这里，感叹不已。

LONG);

  where->set("exits", ([
               "northwest" : __DIR__"shanwai",
               "eastdown"  : __DIR__"shanbian",
             ]));
  where->set("burning_mount",0);
  call_out ("announce_success",1,me);
  call_out ("creat",1800);
}

void test_result (object me)
{
  if (random(5) == 0 &&
      me->query_temp("fainted_in_mount") &&
      me->query_temp("fan_times_in_mount") >= 4)
  {
    success_quest(me);
    return;
  }
  message_vision("\n哗啦啦，山上的火焰退去一大片，又慢慢蔓延回到脚边。\n", me);
}

void can_fan (object me)
{
  me->set_temp("fanned_in_mount",0);
}

int do_extinguish (string arg)
{
  object me = this_player();

  if (wizardp(me) && me->query("env/override"))
  {
    success_quest(me);
    return 1;
  }
  if (! present("tie shan",me))
    return 0;

  if (! this_object()->query("burning_mount"))
  {
    message_vision("见到山上已没有火了，$N扇了扇自己的冷汗。\n", me);
    return 1;
  }

  call_out ("get_burnt",random(2)+10,me);

  message_vision("只见$N拼命地抡起大铁扇只一扇。\n", me);
  if (me->query_temp("fanned_in_mount"))
  {
    message_vision("可惜风力不足，什么奇迹都没发生。\n", me);
    return 1;
  }

  me->set_temp("fanned_in_mount",1);
  me->set_temp("fan_times_in_mount",me->query_temp("fan_times_in_mount")+1);
  message_vision("一股狂飙席地而起，排山倒海般地卷向漫山遍野的火焰！\n", me);
  call_out ("test_result",1,me);
  call_out ("can_fan",random(2)+3,me);
  return 1;
}
