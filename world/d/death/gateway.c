// Room: /d/death/gateway.c

inherit ROOM;

void create ()
{
  set ("short", "酆都城门");
  set ("long", @LONG

你现在来到一座黑色城楼之前，城楼上刻着三个大字：酆都城。往
北走进城楼只见一片黑漆漆的，只有少许暗红色的火光若隐若现地
闪烁着。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gate",
  "north" : __DIR__"walk1",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bgargoyle" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{	me=this_player();

	if( wizardp(me)) return 1;

	if (dir == "north") {
		if((string)me->query("family/family_name")!="阎罗地府") {
			if (objectp(present("black gargoyle", environment(me))))
				return notify_fail("黑无常对你喝道：不许乱闯！\n");
			if(me->is_ghost()){
				me->reincarnate();
			}
		return 1;				
		}
		if(me->is_ghost()){
			me->reincarnate();
		}
	return 1;
	}
	else return 1;
}


