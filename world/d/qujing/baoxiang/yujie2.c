// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yujie2.c
inherit ROOM;

void create ()
{
  set ("short", "白玉阶");
  set ("long", @LONG

由白玉铺成的台阶，级级缓缓向上铺去。每一级台阶都精工细雕
而成，镶嵌有金丝银线。两边各通向一宫一殿，左为大明宫，右
为太极殿。

LONG);

  set("exits", ([
        "northdown"  : __DIR__"yujie1",
        "southup"    : __DIR__"yujie3",
        "west"       : __DIR__"gong2",
        "east"       : __DIR__"dian2",
      ]));
  set("objects", ([
        __DIR__"npc/girl" : 2,
    ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

/*
int valid_leave (object who, string dir)
{
  if (dir == "west")
  {
    message_vision ("$N将头往宫里一探，里面两个威武的护宫武弁将$N架出。\n",
                    who);
    return notify_fail("");
  }
  if (dir == "east")
  {
    message_vision ("$N将头往殿里一探，里面两个威武的护殿武弁将$N架出。\n",
                    who);
    return notify_fail("");
  }
  return 1;
}

*/
