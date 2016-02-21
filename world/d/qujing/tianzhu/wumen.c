// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "午门");
  set ("long", @LONG

一道长长的琉璃瓦檐石墙将王宫围起，里面可以看见雄伟的宫
殿楼阁。宫门为一巨大的铁钉嵌铜木门，高大的门楼上有两个
烫金大字：午门。

LONG);

  set("exits", ([
        "north"   : __DIR__"zhaoyang",
        "south"   : __DIR__"jiedao45",
      ]));
  set("objects", ([
        __DIR__"npc/bing"   : 2,
        __DIR__"npc/siwei"   : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  object king = present("guo wang",this_object());

  if (king)
    return ::valid_leave (who, dir);
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "north")
    return 0;
  if (interactive (who)  &&
      dir == "north" &&
      ! who->query_temp("obstacle/tianzhu_thrown"))
    return notify_fail ("皇宫伺卫将枪一横，威严地喝了一声：禁行！\n");
  return ::valid_leave (who, dir);
}

