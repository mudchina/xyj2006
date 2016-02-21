// create by snowcat.c 7/18/1997

inherit ITEM;

void create ()
{
  set_name("石龟", ({ "shi gui", "gui" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一只用于驼石碑的千年石龟。\n");
    set("unit","只");
  }
  setup();
}

int init ()
{
  add_action ("do_touch","touch");
  return 1;
}

int do_touch (string arg)
{
  string *msgs = ({
    "$N伸出手抚摸石龟。\n",
    "$N静静地将手放在石龟上。\n",
    "$N仔细地用手缓缓抚摸石龟。\n",
    "$N沉默地抚摸着石龟。\n",
  });
  string *actions = ({
    "你感觉石龟隐隐约约传给你一种力量。\n",
    "你仿佛觉得石龟散发出一种无形的力量。\n",
    "你似乎感觉到石龟将某一种说不出的力量传给你。\n",
    "你恍惚地感受到石龟的力量。\n",
    "似乎有一种古老神秘的力量渗进你的体内。\n",
  });
  object me = this_player();
  object gui = this_object();

  if (arg != "gui" &&
      arg != "shi gui")
  {
    tell_object(me,"你要抚摸什么？\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"你已经没有力气了！\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"你正在忙着呢！\n");
    return 1;
  }
  gui->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("force",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (gui->query("times")>300)
  {
    message_vision ("只见$N发出几声嘎吧的杂音，"+
                    "突然破裂成无数碎石块散落在地。\n",gui);
    destruct (gui);
  }
  return 1;
}

