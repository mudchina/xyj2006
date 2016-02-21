// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "兔穴");
  set ("long", @LONG

一个深深的山洞，洞里雾汽缈缈，洞的角落铺满了松软的干草。
洞的里面似乎有暗道。人说：狡兔有三穴。这是第几穴呢？洞
里的暗道又通向什么穴呢？

LONG);

  set("exits", ([
        "northeast"   : __DIR__"andao3",
        "northwest"   : __DIR__"andao2",
      ]));

  setup();
}



