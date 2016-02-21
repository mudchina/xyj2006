// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "阎罗大堂");
  set ("long", @LONG

这里便是名闻天下，令人提起心惊胆寒的阎罗地府。人死后都会
在这里受到应有的处置。左右分立四名青面獠牙鬼，看起来恐怖
之极．四周还摆着一些刑具，上面都是血。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"walk2",
  "east" : __DIR__"roomout",
  "west" : __DIR__"walk3",
  "north" : __DIR__"zhengtang",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qinggui" : 2,
  __DIR__"npc/liaogui" : 2,
]));

  setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
	if((string)me->query("family/family_name")!="阎罗地府") {

        if (objectp(present("qingmian gui", environment(me)))
		|| objectp(present("liaoya gui", environment(me)))) {
return notify_fail("好象身后有个人抱住了你，你动也动不了！\n");
                }
        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);
        }

        return 1;
}

