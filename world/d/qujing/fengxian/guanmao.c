// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "冠帽店");
  set ("long", @LONG

冠帽店里红梁白墙，里面有大小货架两对四个。一个大匾上写
着：本店出售各类冠帽首饰针线。但见货架上空空如也，挂了
一个小牌：店主仗义施财祭雨，已尽家产。
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao5",
      ]));
  set("objects", ([
        __DIR__"npc/sg2"    : 1,
      ]));
  setup();
}

