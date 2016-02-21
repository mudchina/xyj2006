// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "山石路");
  set ("long", @LONG

    这段山路终于要走过去了，不由让人长吁一口气。
    路旁可见一间茅屋，静静的立在那里，不知道主人在不
在，口渴的行人真想去讨一杯水喝。
。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shanshipo",
  "eastdown" :__DIR__"sroad6",
  "west" :__DIR__"maowu",
]));

  setup();
}






