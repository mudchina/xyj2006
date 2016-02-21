// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/luochi2.c

inherit ROOM;

void create ()
{
  set ("short", "漯池");
  set ("long", @LONG

这里淤积着一片一片被阳光晒得半干的沼泽地。走在硬硬的泥壳
上面，感觉脚下的地面软软地往下陷。路不成行，歪歪斜斜地长
着一丛丛无名杂草。

LONG);

  set("exits", ([
        "west"       : __DIR__"luochi1",
        "east"       : __DIR__"chaoxing",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int init ()
{
  add_action ("do_down", "down");
}

int do_down(string arg)
{
  object who = this_player();

  if (arg)
    return 0;

  tell_object (who,"你脚下一陷！\n");
  who->move(__DIR__"shanb");
  return 1;
}
