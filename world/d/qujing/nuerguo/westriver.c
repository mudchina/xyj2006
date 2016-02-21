// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/westriver.c

inherit ROOM;

void create ()
{
  set ("short", "子母河西岸");
  set ("long", @LONG

河边柳荫垂碧，水面很宽很浅，北面有一座小茅屋。风吹过
后，一个小招牌轻轻地晃来晃去。河岸踩得很踏实，有不少
人从这里徒步涉水过河。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sanchalu",
  "north" : __DIR__"maowu",
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
  me->move(room);
  tell_object(me,"\n一个浪打过来你差一点跌进水里！\n");
  call_out("arrive", 5, me);
}

void arrive(object me)
{
  me->move(__DIR__"eastriver3");
  message_vision ("$N淋漓漓地爬上了岸。\n",me);
}

int do_cross(string arg)
{
  if( !arg || arg=="" )
    return 0;

  if( arg=="river" )
  {
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
