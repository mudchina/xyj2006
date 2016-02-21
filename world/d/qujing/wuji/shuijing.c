// Room: snowcat 

inherit ROOM;

void create ()
{
  set ("short", "水晶宫");
  set ("long", @LONG

黑暗深处一片光明，一座牌楼在水下恍然隐现，你正行走在水晶宫
里，四周如明镜一般，方向难辨。

LONG);

  set("exits", ([ 
    "up" : __DIR__"well",
    "east" : __DIR__"shuijing",
    "west" : __DIR__"shuijing",
    "south" : __DIR__"shuijing",
    "north" : __DIR__"shuijing",
  ]));

  setup();
}

void init ()
{
  add_action ("do_all","",1);
}

int do_all (string arg)
{
  object where = this_object();
  object who = this_player();
  object longwang = present("jing longwang",where);

  if (longwang)
  {
    who->set_temp("obstacle/wuji_shuijing",0);
    return 0;
  }

  who->add_temp("obstacle/wuji_shuijing",1);

  if (who->query_temp("obstacle/wuji_shuijing")<20)
    return 0;


  who->set_temp("obstacle/wuji_shuijing",0);
  message_vision ("水面缓缓升起，慢慢显出龙王的形体。\n",who);
  longwang = new ("/d/qujing/wuji/npc/longwang");
  longwang->move(where);
  longwang->command_function("hi");
  remove_call_out ("longwang_disappear");
  call_out ("longwang_disappear",10+random(30),where);
  return 0;    
}

void longwang_disappear(object where)
{
  object longwang = present("jing longwang",where);

  if (! longwang)
    return;
  if (longwang->query("id") != "jing longwang")
    return;

  message_vision ("水面缓缓分开，龙王徐徐地沉了下去。\n",longwang);
  destruct (longwang);
}

void set_given ()
{
  object me = this_object();

  me->set("has_given",1);
  remove_call_out("reset_given");
  call_out("reset_given",900);
}

void reset_given ()
{
  object me = this_object();

  me->set("has_given",0);
}
