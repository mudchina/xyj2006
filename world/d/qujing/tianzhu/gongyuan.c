// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "宫院");
  set ("long", @LONG

宫院里鲜花百草丛丛，院心里铺着六色碎石子，一条彩廊自东
向西弯弯曲曲通过。彩廊的东边通向华夷阁，彩廊的西边通向
昭阳宫。

LONG);

  set("exits", ([
        "east"   : __DIR__"huayi",
        "west"   : __DIR__"zhaoyang",
      ]));
  set("outdoors", __DIR__);

  setup();
}


