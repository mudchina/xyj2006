// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "长史馆");
  set ("long", @LONG

长史馆门口放着两青铜狮，馆里为一大堂，堂中放有一仙桌上
有一套细瓷茶具。左手边有一案桌，上面堆了许多本厚厚的公
书文本。

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie5",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));

  setup();
}



