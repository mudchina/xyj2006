// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "坡路");
  set ("long", @LONG

坡路渐陡渐窄，山色茫茫云雾渺渺，东南方向的巅峰冲天占地，挡
住雾角，岭头松郁郁。路旁岩崖石磷磷高耸，往南是一道绝壁将道
路封死。

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"polu3",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N奋力向上爬去。\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 50)
  {
    message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-50);
  who->move(__DIR__"shan11");
  return 1;
}
