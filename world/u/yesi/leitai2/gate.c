// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "五彩门");
  set ("long", @LONG

一座由雕花香檀木建立起来的大门高高立地而起，门柱上镶着
无数五彩透明的翡翠宝石。门里面是大会会场，瑞气笼罩气象
万千。这里在没有举行水陆大会时，凡人不得擅自入内。

LONG);

  set("exits", ([
        "northdown"   : __DIR__"shuilu",
        "south"   : __DIR__"north",
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (wizardp(who))
    return ::valid_leave(who, dir);
  if (dir == "south")
    //return notify_fail ("对不起，请让巫师护送您进去。\n");
    return ::valid_leave(who, dir);
  return ::valid_leave(who, dir);
}



