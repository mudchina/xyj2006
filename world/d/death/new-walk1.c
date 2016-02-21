// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "幽司");
  set ("long", @LONG

这里便是阴曹地府之中，偶尔看到几个索命鬼，勾司人牵着些套着
枷锁的人走来走去。周围是一座座的楼阁宫殿，看起来也相当的富
丽堂皇，奇怪的是都有一扇钉着金钉的红木门和一条白玉门槛。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"new-walk2",
  "east":  __DIR__"new-zhaopo",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/genggui" : 1,
]));

  setup();
}

