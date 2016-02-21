inherit ROOM;

void create ()
{
  set ("short", "石阶");
  set ("long", @LONG
    一条石阶小路蜿蜒而上，四处风吹草动，聆听空谷回音。四处见
山峦，路在这里显得宽畅一些，地面较平坦。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shijie2",
  "southdown" : __DIR__"gate",
]));

  setup();
}
