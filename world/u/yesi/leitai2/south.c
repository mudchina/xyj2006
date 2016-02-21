// create by snowcat.c 2/8/1997

inherit ROOM;

#include <guanli.h>

void create ()
{
  set ("short", "南观礼台");
  set ("long", @LONG

观礼台由平坦宽适的红木一级级搭成，地下铺着花纹虎皮和金
钱豹皮。台上放着一排排猩红绒面太师椅，可以让贵宾们比较
舒适地观看比赛。

LONG);

  set("exits", ([
        "south"   : __DIR__"drug",
        "west"   : __DIR__"winter",
        "east"   : __DIR__"autumn",
        "northdown"   : __DIR__"ground",
      ]));

  set("objects", ([
        __DIR__"npc/siguan"  : 2,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (wizardp(who))
    return ::valid_leave(who, dir);
  if (dir == "northdown")
    //return notify_fail ("对不起，您不能擅自闯入赛场。\n");
    return can_enter (who);
  return ::valid_leave(who, dir);
}



