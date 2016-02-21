// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

这里是三岔路口的小街，由青石板条铺成，令人觉得悠闲宁静，
街头有炊烟袅袅飘来青柴的香味。不远处传来家家户户舂米的
声音，还有大户人家榨香油的醇香味。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie6",
        "north"   : __DIR__"xiaojie3",
        "southeast"   : __DIR__"cunlu3",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "southeast")
    return 0;

  return ::valid_leave (who, dir);
}

