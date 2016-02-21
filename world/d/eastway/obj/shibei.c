// create by snowcat.c 7/18/1997

inherit ITEM;

void create ()
{
  set_name("石碑", ({ "shi bei", "bei" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一块刻满碑文的巨大石碑。\n");
    set("unit","块");
  }
  setup();
}

int init ()
{
  add_action ("do_examine","examine");
  return 1;
}

int do_examine (string arg)
{
  string *msgs = ({
    "$N屏住呼吸仔细地观察着石碑。\n",
    "$N全神贯注地阅读碑文。\n",
    "$N细心地察看碑文。\n",
    "$N一边研究碑文，一边思考。\n",
  });
  string *actions = ({
    "你从中得到一些启发。\n",
    "你对碑文中有了进一步的理解。\n",
    "你觉得对碑文似乎有了更深的理解。\n",
    "你顿时感到有了一些新的收获。\n",
    "你从碑文中获得了一些知识。\n",
  });
  object me = this_player();
  object bei = this_object();

  if (arg != "bei" &&
      arg != "shi bei")
  {
    tell_object(me,"你要研究什么？\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"你再也没有精力去研究碑文了！\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"你正在忙着呢！\n");
    return 1;
  }
  bei->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("literate",1+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (bei->query("times")>200)
  {
    message_vision ("只见$N晃了一下，"+
                    "往后一翻倒进乱石丛中。\n",bei);
    destruct (bei);
  }
  return 1;
}

