// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "通道");
  set ("long", @LONG

通道里面怪石遍地，两边洞壁上爬着无名蔓草。南边有光线射
进，那里是玄英洞的洞口，西北方向有一更大的洞穴，通道向
东边延伸而去。

LONG);

  set("exits", ([
        "south"   : __DIR__"dongkou",
        "northwest"   : __DIR__"dongting",
        "east"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/xiniu"  : 1,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object jing = present ("shoumen niujing", this_object());
  if (! who->query_temp("obstacle/jinping_give_hulu") &&
      jing &&
      dir == "east")
    return notify_fail ("守门牛精一晃两只大牛角抵住你：想溜到哪儿去？\n");
  return ::valid_leave(who, dir);
}

