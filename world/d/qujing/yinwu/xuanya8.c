// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "悬崖");
  set ("long", @LONG

苍山峻岭，峰势崔巍，只见顶上白云飘飘，崖前树影寒寒，林
内松柏千千，峦头翠竹几干。四处怪石嶙嶙，使人心感不安，
难以擅自举步。

LONG);

  set("exits", ([
        "northup"    : __DIR__"xuanya6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N手脚并用奋不顾身地向上爬去。\n",who);
  if (who->query("combat_exp") < 10000 ||
      random(4))
  {
    message_vision ("\n……哗哗一声，$N失手滑了下来。\n",who);
    who->unconcious();    
  }
  else
    who->move(__DIR__"shanmen");
  return 1;
}
