// created by snowcat.c 4/4/1997
// room: /d/nuerguo/entry.c

inherit ROOM;

void create ()
{
  set ("short", "王宫大门");
  set ("long", @LONG

这是西梁王宫高高的大门。门台下挤着一群爱看热闹的女人
们伸着脖子探着头看来看去，压低着嗓子在叽叽咕咕小声议
论着什么。北边是前宫入口，南边是安乐巷。

LONG);

  set("exits", ([
        "north"     : __DIR__"fronthall",
        "southdown" : __DIR__"towna2",
      ]));

  set("objects", ([
         __DIR__"npc/lady" : 1,
     ]));
  setup();
}

int valid_leave (object me, string dir)
{
  if ((string)me->query("id")=="woman" && dir=="north") 
    return 0;
  return 1;
}

