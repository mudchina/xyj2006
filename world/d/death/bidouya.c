inherit ROOM;

void create ()
{
  set ("short", "壁斗崖");
  set ("long", @LONG

北面是奈何桥，桥后一座险峰，吹来阵阵腥风。南边是建在山
中一座孤城，传来凄凄哭声。左右俱是深涧万丈，略有闪乎就
会沦如万劫不复之地而永无超生之时。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pingyang",
  "north" : __DIR__"naiheqiao",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/duanzhu" : 1,
]));

  setup();
}
