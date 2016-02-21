// Room: /d/jjf/front_yard.c

inherit ROOM;

void create ()
{
  set ("short", "练武场");
  set ("long", @LONG
空阔的场地上铺满了细细的黄土，正好适合演武。四面有几个
秦府家将正在练武。树荫里，一位管家打扮的人正在背着手观看，
还不时走上前去指点一二。场地边上挂着几个大沙袋(sandbags)，
不知有什么用处。西面有间破败的小屋，门窗都封死了，与将军府
里其它的房舍格格不入。
LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "window" : "门窗都被封死了，墙上好象有些锤砸的痕迹．\n",
  "door" : "
门窗都被封死了，墙上好象有些锤砸的痕迹．\n",
  "sandbags" : "
几个沉重的沙袋，可以试着打打(da)看。\n",
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gate",
  "south" : __DIR__"front_yard2",
  "east" : __DIR__"majuan",
  "southwest" : __DIR__"guest_bedroom",
]));

  set("objects", ([
                   __DIR__"npc/qinfu": 1,
		   __DIR__"npc/xiaotong": 2,
                   ]));

  setup();
}

void init()
{
  add_action("do_hammer", "hammer");
  add_action("do_da", "da");
}

int do_da(string arg)
{
  object me=this_player();
  int unarmedskll=(int)(me->query_skill("unarmed", 1)/2);
  int maxlevel, exp=(int)me->query("combat_exp");
 
  if( !arg || !((arg == "sandbags") || (arg == "沙袋")))
    return notify_fail("你要打什么？\n");
  if( me->query("kee") < (int)(me->query("max_kee")/5))
    return notify_fail("再打下去你会累死的！\n");
  if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
    return notify_fail("用兵器会把沙袋打坏的！\n");
  if (!((string)me->query("family/family_name")=="将军府"))
    {
      message_vision("$N一拳向沙袋打去，可是沙袋一动不动。\n", me);
    }
  else
    {
      message_vision("$N用尽力气向沙袋打去，打得沙袋直晃。\n", me);
      if (exp*10 <= (unarmedskll*unarmedskll*unarmedskll))
	{
	  me->receive_damage("kee", (int)me->query("max_kee")/10);
	  return notify_fail("你的道行不够高，不能从打沙袋中学到新知。\n");
	}
      if (unarmedskll*2<((int)me->query("con")+(int)me->query("str"))/2)
	{
	  me->improve_skill("unarmed", random((int)(me->query("con")+me->query("str"))/2));
	  tell_object(me, "你领悟出一些基本拳脚方面的窍门。\n");
	}
      else
	{
	  tell_object(me, "你在沙袋上费了半天劲，可是什么也没有学到。\n");
	}
    }
  me->receive_damage("kee", (int)me->query("max_kee")/10);
  return 1;
}

int do_hammer(string arg)
{       
  object me;
  me=this_player();
  if ( !present("hammer", me) || (arg != "door"))
    return notify_fail("你挥起拳头往墙上砸去，呃．．．．好象挺疼！\n");
  else
    message_vision("$N挥舞大锤，往墙上砸去．\n", me);
  if((int)me->query_temp("mark/将军") < 1)
    {
    me->set_temp("mark/将军", 1);
  }
  me->add_temp("mark/将军", 1);
  me->receive_damage("kee", 40);
  if((int)me->query_temp("mark/将军") > 5)
    {
    message_vision("$N把墙砸开了一个洞，连忙钻了进去．\n", me);
    me->set_temp("mark/将军", 1);
    me->set_temp("mark/将军禁地", 1);
    me->move("/d/jjf/mishi");
    return 1;
  }
  return 1;
}

