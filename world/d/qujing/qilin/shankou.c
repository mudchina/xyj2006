// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "山口");
  set ("long", @LONG

好一个麒麟山顶！冲天处尖峰耸立，占地处远脉迢迢。这里是麒麟
山口，南边呈谷状，长满山草山花。西北边则光秃秃赭红色一片似
火烧过一般。

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"yading",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  object who = this_player();

  message_vision ("$N鼓足勇气往下跳去。\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 50)
  {
    message_vision ("$N砰地重重摔在崖台下。\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-50);
  who->move(__DIR__"shan23");
  return 1;
}
