// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "杨树");
  set ("long", @LONG

杨树林里，树木茂盛高大，枝叶青绿斑白。许多树(tree)的根
根叉叉交缠在一起，看上去十分奇特。风吹在树上，发出有一
点异样的声响。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"yang1",
        "northeast"    : __DIR__"yang2",
        "east"    : __DIR__"yang4",
      ]));
  set("item_desc", ([
       "tree" : "树的枝条绞在一起，长在同一个根上。\n",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  add_action ("do_turn","turn");
  add_action ("do_push","push");
}

int do_turn (string arg)
{
  object who = this_player();
  int times = who->query_temp("obstacle/biqiu_turns");

  if (! arg ||
      (arg != "left" &&
      arg != "right"))
    return notify_fail ("你象无头苍蝇一样围着树转了起来。\n");
 
  if (arg == "left")
  {
    message_vision ("$N围着树往左转了一圈。\n",who);
  }  
  if (arg == "right")
  {
    message_vision ("$N围着树往右转了一圈。\n",who);
  }  
  who->set_temp("obstacle/biqiu_turns",0);
  return 1;
}

int do_push (string arg)
{
  object who = this_player();

  if (! arg ||
      arg != "tree")
    return notify_fail ("你伸出手想推什么。\n");
 
  message_vision ("$N伸出手将树用力一推。\n",who);
  who->set_temp("obstacle/biqiu_turns",0);
  return 1;
}
