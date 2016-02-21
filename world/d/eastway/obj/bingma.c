// create by snowcat.c 7/18/1997

inherit ITEM;

void create ()
{
  if (random(4))
    set_name("兵俑", ({ "bingma yong", "yong" }) );
  else
    set_name("马俑", ({ "bingma yong", "yong" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一尊栩栩如生的兵马俑。\n");
    set("unit","尊");
  }
  setup();
}

int init ()
{
  add_action ("do_act","act");
  return 1;
}

int do_act (string arg)
{
  string *msgs = ({
    "$N按照兵马俑的姿态比划了一下。\n",
    "$N学着兵马俑的形态用力比划了一下。\n",
    "$N对着兵马俑，全神贯注地比划了一下。\n",
    "$N一边看着兵马俑，一边试着比划了一下。\n",
  });
  string *actions = ({
    "你感觉到自己的格斗能力有了进步。\n",
    "你的扑击技巧有一点提高。\n",
    "你的扑击格斗能力有了新的提高。\n",
    "你感到你的扑击格斗之技有了进步。\n",
    "你的扑击格斗之技提高了。\n",
  });
  object me = this_player();
  object yong = this_object();

  if (arg != "yong" &&
      arg != "bingma yong")
  {
    tell_object(me,"你想怎样比划呢？\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"你已经太疲劳了！\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"你正在忙着呢！\n");
    return 1;
  }
  if (me->query_temp("weapon") ||
      me->query_temp("secondary_weapon"))
  {
    tell_object (me,"你拿着武器无法比划。\n");
    return 1;
  }
  yong->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("unarmed",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (yong->query("times")>100)
  {
    message_vision ("只见$N摇摇晃晃，轰地一下倒在地上碎了。\n",yong);
    destruct (yong);
  }
  return 1;
}

