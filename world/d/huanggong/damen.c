inherit ROOM;

void create ()
{
  set ("short", "皇宫大门");
  set ("long", @LONG

皇宫大门庄严肃穆，金壁辉煌，宫墙里面殿阁高大雄伟，层
层叠叠，琉璃瓦白玉掾富丽堂皇。此刻宫门紧闭，门前守卫
着几位金甲武士。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/weishi" : 3,
  __DIR__"npc/xuerengui" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"chaoyangmen",
  "north" : __DIR__"guangchang",
  "northeast" : __DIR__"yhy3b.c",
  "northwest" : __DIR__"yhy3a.c",
]));

  setup();
}

/*int valid_leave(object me, string dir)
{
        if (me->query("quest/reward"))
	return ::valid_leave(me, dir);
	if (dir == "north" ) {
        if (objectp(present("xue rengui", environment(me)))&&!wizardp(me))
	return notify_fail("薛仁贵铁枪一横，喝道：此乃皇宫，禁行！\n");
         if (objectp(present("wei shi", environment(me)))&&!wizardp(me))
        return notify_fail("金甲卫士喊道：我家将军不在，小人不敢放您进去！\n");
        }   
        return ::valid_leave(me, dir);
}*/

 

