// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "承雷石");
  set ("long", @LONG

山环路低洼出耸立一座高大的石崖，如石碑一般。崖顶曾被山雷劈
开，缺口处长了一棵矮松，云在崖顶缓缓飘过。这里似乎可以听见
远远的禽咽兽吼之声从林涛中传来。

LONG);

  set("exits", ([ 
    "left" : __DIR__"shan12",
    "right" : __DIR__"shan13",
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
  message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
  who->unconcious();
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N鼓足勇气往下跳去。\n",who);
  message_vision ("$N砰地重重摔在台下。\n",who);
  who->unconcious();
  return 1;
}
