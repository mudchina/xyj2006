// Room: /d/4world/cuixiang.c
inherit ROOM;

void create ()
{
  set ("short", "翠香楼");
  set ("long", @LONG

这里就是傲来国最有名的饭馆，是早年一大唐来的富商所开，出
售的都是长安府口味的佳肴。传说当时宰相尝后赞不绝口，乃赠
翠香二字。在这可看到各处来的游人，也可打听到天下发生的大
事。二楼雅座里正大摆宴席，不知是那家有了喜事。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"north1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,

]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
call_other("/obj/board/aolai_b", "???");
}
