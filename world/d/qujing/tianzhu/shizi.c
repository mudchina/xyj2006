// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "十字街彩楼");
  set ("long", @LONG

这里是天竺国的城中心十字街口，街上熙熙攘攘十分热闹，街
心有一绘红画绿的琉璃彩楼，一大群人挤在彩楼四周，交头接
耳兴奋地议论着什么。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao56",
        "west"   : __DIR__"jiedao53",
        "north"   : __DIR__"jiedao45",
        "south"   : __DIR__"jiedao65",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 5,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  object who = this_player();
  object king = present("guo wang",this_object());

  if (! who)
    return;

  if (! interactive (who))
    return;

  if (king)
    return;

  if (who->query("combat_exp")<10000)
    return;
//  if (who->query("obstacle/tianzhu")=="done")
//    return;

  message_vision ("人们交头接耳，低声议论着什么。\n",who);
  remove_call_out ("noicing");
  call_out ("noicing",random(10)+5,who);
}

void noicing (object who)
{
  object where = this_object ();
  object king = present("guo wang",this_object());

  if (king)
    return;

  if (! who ||
      environment (who) != where)
    return;
  if (where->query("has_thrown"))
  {
    message_vision ("人群中叽叽喳喳议论：听说绣球打中了一路客。\n",who);
    message_vision ("又有人说道：也不知打中了何许人也。\n",who);
    return;
  }
  message_vision ("彩楼上有人高喊：公主拈香完毕，正祝告天地。\n",who);
  remove_call_out ("preparing");
  call_out ("preparing",random(10)+10,who);
}

void preparing (object who)
{
  object where = this_object ();
  object king = present("guo wang",this_object());

  if (king)
    return;

  if (! who ||
      environment (who) != where)
    return;
  if (where->query("has_thrown"))
  {
    return;
  }
  message_vision ("彩楼上有人又高喊：公主临窗，伺女备球！\n",who);
  message_vision ("底下无数看客高声呐喊：抢绣球也！抢绣球也！\n",who);
  remove_call_out ("throwing");
  call_out ("throwing",random(10)+10,who);
}

void throwing (object who)
{
  object where = this_object ();
  object king = present("guo wang",this_object());

  if (king)
    return;

  if (! who &&
      environment (who) != where)
    return;
  if (where->query("has_thrown"))
  {
    return;
  }
  message_vision ("一只绣球飞来，啪地砸在$N的头上！\n",who);
  if (who->query("gender") == "女性")
    message_vision ("看客们高喊：女驸马！女驸马！\n",who);
  else
    message_vision ("看客们高喊：打着了！打着了！\n",who);

  where->set("has_thrown",1);
  call_out ("reset_thrown",1200);
  remove_call_out ("leaving");
  call_out ("leaving",random(10)+10,who);
}

void reset_thrown ()
{
  this_object()->set("has_thrown",0);
}

void leaving (object who)
{
  object where = this_object ();

  if (! who &&
      environment (who) != where)
    return;
  message_vision ("一片吆喝声中，人群闪开一条道，公主走了过来。\n",who);
  message_vision ("公主对$N婉尔一笑，轻声说：去见父王也。\n",who);
  message_vision ("一群伺官宫女簇拥着晕晕乎乎的$N向北走去。\n",who);
  who->move(__DIR__"jiedao45");
  who->move(__DIR__"wumen");
  who->move(__DIR__"zhaoyang");
  who->move(__DIR__"jinluan");
  message_vision ("$N晕晕乎乎地清醒了过来。\n",who);
  message_vision ("公主对国王撒了个娇，红着脸向后宫走去。\n",who);
  who->set_temp("obstacle/tianzhu_thrown",1);
}
