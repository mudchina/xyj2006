// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "山环路");
  set ("long", @LONG

山环路道险路窄，路外围是悬崖，失足掉下去可能会粉身碎骨，路
的内侧是陡峭的石壁。周围长着稀稀拉拉的一些树林，你已分不太
清东南西北了。

LONG);

  set("exits", ([ 
    "left" : __DIR__"yutai",
    "right" : __DIR__"chenglei",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
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
  who->move(__DIR__"shan22");
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N鼓足勇气往下跳去。\n",who);
  message_vision ("$N砰地重重摔在崖台下。\n",who);
  who->unconcious();
  return 1;
}
