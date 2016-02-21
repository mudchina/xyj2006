// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山坡");
  set ("long", @LONG

山坡上长着古树青藤，路上枯枝落叶遍地，坡边高高低低长着
灌木蒿草，夹杂着一些大大小小的岩石。坡下幽幽深深，不时
可见沟渠洞穴。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanpo8",
        "southwest"   : __DIR__"shanpo12",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  add_action ("do_enter", "enter");
}

int do_enter ()
{
  object who = this_player();
  string location = "/d/qujing/maoying/tuxue1";

  location[strlen(location)-1] = '1'+random(3);

  message_vision ("$N在蒿草石缝中扒开一个洞，钻了进去。\n",who);
  who->move(location);
  return 1;
}


