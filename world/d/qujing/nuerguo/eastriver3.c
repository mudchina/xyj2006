// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/eastriver3.c

inherit ROOM;

void create ()
{
  set ("short", "子母河东岸");
  set ("long", @LONG

这里河面很宽很浅，河对岸有柳荫垂碧，微露出茅屋几檐。
河岸这边地踩得很踏实，好像曾经有不少人在这里走过。河
面很宽很浅，看样子徒步涉水也可以走过去。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eastriver2",
]));
  set("outdoors", __DIR__"");

  setup();
}

void init()
{
  add_action("do_cross", "cross");
}

void in_river(object me, object room);

void walk_in()
{
  object room;
  object me;

  me = this_player();

  if (!(room = find_object(__DIR__"river")))
    room = load_object(__DIR__"river");
  if (room = find_object(__DIR__"river"))
  {
    message_vision ("$N踮起脚，小心地走进水里……\n",me);
    in_river(me, room);
  }
}

void in_river(object me, object room)
{
  me->move(room);
  tell_object(me,"\n走进河里你才发现河面的确很宽。\n");
  call_out("in_danger", 15, me);
}

void in_danger(object me, object room)
{
  if(!me) return;
  me->move(room);

  if (me->query("combat_exp")<2000)
  {
    me->move(__DIR__"eastriver3");
    message_vision ("水突然急了，$N拼命地挣扎，结果还是给冲回了岸！\n",me);
    tell_object(me,"\n大概你的道行不够成熟。\n");
    return;
  }

  if (random(3)==0 &&
      me->query("obstacle/nuerguo")==0 &&
      me->query("water") < me->max_food_capacity())
  {
    message_vision ("$N脚下一滑，摔进河里，呛了满肚子的河水！\n",me);
    me->set("obstacle/nuerguo","stomachache");
    me->set("water", me->max_water_capacity()+50);
    tell_object(me,"\n糟了，喝了河水要怀孕的！\n");
    call_out("stomach_pain",1,me);
  }
  else if (random(2)==0)
  {
    message_vision ("$N一脚没踩稳，摔进河里，呛了几口水！\n",me);
    me->set("water", me->max_water_capacity()+50);
  }
  call_out("arrive", 5, me);
}

void stomach_pain(object me)
{
  int m,n;

  if(!me) return;

  if (me->query("obstacle/nuerguo")=="stomachache")
  {
    m = me->query("max_kee") * (70+random(15)) / 100;
    n = me->query("kee");
    if (me->query("eff_kee") > m)
      me->set("eff_kee", m);
    if (n > m)
      me->set("kee", m);
    message_vision ("$N捂着肚子呻吟了几声。\n",me);
    call_out("stomach_pain", 30, me);
  }
}

void arrive(object me)
{
  me->move(__DIR__"westriver");
  message_vision ("$N淋漓漓地爬上了岸。\n",me);
}

int do_cross(string arg)
{
  object me;
    me=this_player();
  if( !arg || arg=="" )
    return 0;

  if( arg=="river" )
  {
         if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_nuerguo")!="done"))
	{
		 me->add_temp("wzg_rulaifo",1);
		 me->set_temp("set_nuerguo","done");
	}
	walk_in();
    return 1;
  }
  return 0;
}

void reset()
{
    object room;

    ::reset();
}
