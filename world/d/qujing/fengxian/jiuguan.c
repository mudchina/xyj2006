// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "酒馆");
  set ("long", @LONG

酒馆为一双檐小木楼，馆门口的酒字招牌已摘掉。里面木桌和
木椅擦得干干净净，柜台上竖着一牌子，上有：“戒酒祭雨，
免费供茶”八个大字。
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao4",
      ]));
  set("objects", ([
        __DIR__"npc/sg3" : 1,
        __DIR__"obj/tea" : 2,
      ]));
  setup();
}

