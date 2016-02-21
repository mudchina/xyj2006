// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "酒铺");
  set ("long", @LONG

酒铺外撑着一长棚，几张桌子从屋外一直铺到屋里，上面零乱
地放着酒罐子，粗酒碗和点心碟子，地上扔有一些花生皮壳。
几位酒客在摇头晃脑地猜着酒拳。

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao3",
      ]));
  set("objects", ([
        __DIR__"npc/zhou"    : 1,
      ]));
  setup();
}

