// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "翠云宫");
  set ("long", @LONG

这里便是主管阴曹地府，天下鬼魂的地藏王菩萨的行宫。堂上并没有
什么华贵的装饰，奇怪的是左右各放了八个白色的石环，每个都有半
扇门板那么大。正中一个铁桌，桌上摆着文具，一个青竹小筒内装着
法牌令箭。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"walk6",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizhang" : 1,
]));

  setup();
}
