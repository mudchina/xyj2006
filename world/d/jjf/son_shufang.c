// Room: /d/jjf/son_shufang.c

inherit ROOM;

void create ()
{
  set ("short", "书房");
  set ("long", @LONG
秦将军请来的教书先生就住在这里。除了一张床和几张桌椅之
外，屋子里就只有几个大书架了。仔细看看，书架上净是兵法、武
功的书。看来秦公子是要子承父业了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"son_cabinet",
]));

  setup();
}
