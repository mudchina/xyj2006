// Room: /d/jjf/gate.c

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG

这里是当朝大将秦叔宝的官邸，慕名来拜师的人也很多。大门两侧
有两头高大的石狮子。东边是一棵槐树，郁郁葱葱，遮盖了大半个
院子，整个院子里阴阴凉凉的。南边是个空场，大概是秦将军演武
之地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"front_yard.c",
  "north" : "/d/city/qinglong-e2",
]));
	set("out_doors", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinan" : 1,
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "south" ) {
	if (((string)me->query("family/family_name")=="将军府") 
	||	wizardp(me)
	||	me->query_temp("pending/jiangjun_answer")) {
		return ::valid_leave(me, dir);
        	}
		if(objectp(present("qin an", environment(me)))) {
            	return
notify_fail("秦安喝道：将军府岂是你乱闯之地！有何贵干(answer)？\n");
    		}
		return 1;
	}
    	return 1;
	}

