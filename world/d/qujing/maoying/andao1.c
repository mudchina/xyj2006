// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "暗道");
  set ("long", @LONG

……你似乎什么也看不清楚，只觉得暗道里湿气飕飕，但难以
探到前方的出路……

LONG);

  set("exits", ([
      ]));

  setup();
}

void init ()
{
  add_action ("do_go", "go");
}

int do_go (string dir)
{
  object who = this_player();

  if (! dir)
    return 0;

  if (dir == "east" ||
      dir == "west" ||
      dir == "south" ||
      dir == "north")
  {
    if (random(5))
    {
      message_vision ("$N在黑暗中梆地撞到了石墙上。\n",who);
    }
    else
    {
      message_vision ("$N在黑暗中找到一出口，挤了出去。\n",who);
      who->move(__DIR__"shanpo3");
    }
    return 1;
  }
  return 0;
}


