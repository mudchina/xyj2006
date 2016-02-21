// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "山石路");
  set ("long", @LONG

    烈阳当头熊熊,山路颠簸不平，偶闻惊鸟声，恐有多事端。
    近观路有零星白骨，远望难见人烟，让人越走越心慌，
只想快快走出这片地方。
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "eastdown": __DIR__"sroad4",
  "southwest" :    __DIR__"sroad6",
]));

  setup();
}






