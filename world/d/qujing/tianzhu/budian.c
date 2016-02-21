// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "布店");
  set ("long", @LONG

布店里搭起了两排木架子，架子上摆着一些布匹，有素色布染
花布织花布粗布细布绸缎锦棉等等。屋子的东面是半人高的黄
木柜台。

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao97",
      ]));
  set("objects", ([
        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}


