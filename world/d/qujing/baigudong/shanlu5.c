// Room: writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

  只见山石陡峭，路径弯曲，雾气浓郁，前不见来路，后
难觅出路，伸手不见五指，对面难见面颜。模模糊糊能看
到山顶有一个巨大的洞口，突突的冒着黑烟。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "eastdown"      : __DIR__"shanlu4",
  "west" : __DIR__"shanlu6",
]));

  setup();
}






