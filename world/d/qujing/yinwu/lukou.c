// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "路口");
  set ("long", @LONG

这里险象众生，路势奇恶，上通两岸犬牙一般巨石悬崖，下连
三路阴森森草坡。路口边一圈摆开大小岩石，尤如天然的石桌
石椅一般。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"xuanya5",
        "northeast"    : __DIR__"xuanya3",
        "west"    : __DIR__"caopo1",
        "southwest"    : __DIR__"caopo3",
        "southeast"    : __DIR__"caopo2",
      ]));
  set("objects", ([
        __DIR__"npc/shanyao" : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  object shanyao = present("shan yao", this_object());

  if (dir == "west" || dir == "southwest" || dir == "southeast")
    return ::valid_leave(who,dir);

  if (! who->query("env/invisibility") &&
      shanyao &&
      ! shanyao->is_busy() &&
      ! shanyao->query_temp("no_move"))
    return notify_fail("山妖呲牙咧嘴地死活不让你过！\n");
  return ::valid_leave(who,dir);
}
