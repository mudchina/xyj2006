// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

一个不高的山坡上，建着一个寺庙，云雾淡淡，悠哉闲哉。坡
边有几只小羊远远地吃着草。寺庙的门口打扫得干干净净，门
上有一牌匾：慈云寺。

LONG);

  set("exits", ([
        "westdown"   : __DIR__"cunlu6",
        "east"   : __DIR__"qian",
      ]));
  set("outdoors", __DIR__);

  setup();
}



