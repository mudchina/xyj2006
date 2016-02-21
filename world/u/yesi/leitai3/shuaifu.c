// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "帅府");
  set ("long", @LONG

帅府内灯笼高悬，正中放着一把肥大的特号躺椅。屋后有一个案台，
上面放着一个澡盆大的金饭盆，边上有一水桶大小的银酒壶。西边有
一门，通向帅府外。

LONG);

  set("exits", ([
        "west" : __DIR__"tianpeng",
      ]));
  set("objects", ([
        __DIR__"npc/zhubajie" :  1,
      ]));

  setup();
}


