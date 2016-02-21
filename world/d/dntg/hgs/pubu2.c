//sgzl

inherit ROOM;

void create ()
{
  set ("short", "瀑布中");
  set ("long", @LONG

……你似乎什么也看不清楚，只觉得四周涧水奔流，难以
探到前方的出路……

LONG);

  set("exits", ([
      ]));

  set("objects", ([
          __DIR__"npc/jing" : 2,
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
    string *names = ({
    "west",
    "east",
    "south",
    "north",
    });


    if (! dir)
      return 0;

    if (who->query("kee")>50)  who->add("kee",-50); 
    else
      {
      who->unconcious();
      return 1;
      }


    if (random(5))
      {
      message_vision ("$N迷迷糊糊踏出一步，一不小心摔倒在地。\n",who);
      }
    else
    {
      if (dir != names[random(sizeof(names))])
        {
        message_vision ("$N在瀑布中找到一丝细缝，挤了出去。\n",who);
        who->move(__DIR__"pubu3");
        return 1;
        }
      else
        {
        message_vision ("$N在瀑布中找到一丝细缝，挤了出去。\n",who);
        who->move(__DIR__"pubu1");
        return 1;
        }
    }



  return 0;
}


