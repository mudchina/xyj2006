// created by snowcat.c 5/27/1997
// room: /d/pantao/pan3b.c

inherit ROOM;
inherit "/d/dntg/pantao/climbtree.c";

void create ()
{
  set ("short", "三千年蟠桃园");
  set ("long", @LONG

蟠桃园内花红叶绿，夭夭灼灼花盈树，颗颗枝枝果压枝。只见
是：时开时结千年熟，无夏无冬万载迟，先熟的，酡颜醉脸，
还生的，带蒂青皮。好个凝脂肌带绿，映日显丹姿。

LONG);

  set("exits", ([
        "west"       : __DIR__"pan3a",
        "east"       : __DIR__"pan3c",
        "north"      : __DIR__"pan2b",  
//         "south"      : __DIR__"fenga",  
      ]));
  set("up","tree3");
  set("objects", ([
         __DIR__"npc/lishi6"  : 1,
         __DIR__"npc/lishi7"  : 1,
      ]));

  set("outdoors",1);
  setup();
}

