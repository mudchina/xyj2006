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
  set("item_desc", ([ /* sizeof() == 1 */
  "north" : "望北隐约看到堂上杀气森森。\n",
]));

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"new-walk2",
  "north" : __DIR__"zhengtang",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mamian" : 1,
  __DIR__"npc/niutou" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("family/family_name")!="阎罗地府") {
	if (objectp(present("niutou gui", environment(me))))
        return notify_fail("牛头鬼暴喝几声：擅闯阎罗殿，这不是找死吗？\n");
        if (objectp(present("mamian gui", environment(me))))
        return  notify_fail("马面鬼抡起手中铜锤，对着你说：先问问它答应不！\n");

	}

	return ::valid_leave(me, dir);
	}
	return ::valid_leave(me, dir);

}

