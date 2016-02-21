inherit ROOM;
#include <room.h>
int test_player (object who);

void create ()
{
  set ("short", "三门");
  set ("long", @LONG

这儿是画栋雕梁，明窗彩户。真是别有洞天。
LONG);
 
  set("exits", ([
        "north"  : __DIR__"ermen",
        "south"  : __DIR__"dating",
      ]));
  create_door("north", "石门", "south", DOOR_CLOSED);
  setup();
  "obj/board/shibei_b"->foo();
}
int valid_leave(object me, string dir)
{
	object ob0;
	object yao = new("/d/qujing/guanyin/npc/guai");
        if ( dir == "south" ){
	if (!test_player(me)){
		ob0 = present("yao guai",environment(me));
		if (!ob0)
			yao->move(environment(me));
	        return notify_fail("从门后闪出个小妖喝道：什么人，到处瞎闯，找死啊！\n");
        }
	}
        return ::valid_leave(me, dir);
}

int test_player (object who)
{
  string *names;
  string name;
  names = who->query_temp("apply/name");
  if (! names)
    return 0;
  if (sizeof(names) < 1)
    return 0;
  name = names[0];
  if (name == "凌虚子")
    return 1;
  if (name == "妖怪")
    return 1;
  return 0;
}
