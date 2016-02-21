// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "冰道");
  set ("long", @LONG

河面冻得结结实实，厚厚的一层冰已经被人走出一条长长的冰
道，也有大冰撬滑过留下的痕迹。风呼呼地打在脸上，刺骨地
寒冷。

LONG);

  set("exits", ([
        "west"   : __DIR__"hexi4",
        "east"   : __DIR__"bing4",
        "north"   : __DIR__"bing1",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(3)+1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  object where = this_object ();
  object who = this_player ();

  call_out ("cracking",random(20)+5,where);
  call_out ("testing",random(30)+30,who,where);
}

void cracking (object where)
{
  tell_room (where, "冰发出咔地一声轻响。\n");
}

int test_player (object who)
{
  string *names;
  string name;

  if (! who)
    return 0;

  names = who->query_temp("apply/name");
  if (! names)
    return 0;

  if (sizeof(names) < 1)
    return 0;

  name = names[0];

  if (name != "小童")
    return 0;

  if (present ("bishui zhou",who))
    return 2;
  return 1;    
}

void testing (object who, object where)
{
  int status = test_player(who);

  if (status==0)
  {
    tell_room (where, "冰咔咔作响。\n");
    return;
  }

  if (environment (who) != where)
    return;

  message_vision ("冰面上裂开一道裂缝，$N一个趔趄不由自主地摔进水中！\n",who);
  if (status == 1)
  {
    message_vision ("众人赶来，连忙将$N冰棍一般拖出冰水。\n",who);
    who->unconcious();
    return;
  }
  who->move(__DIR__"hedi");
}

