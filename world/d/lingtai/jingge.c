// Room: some place in 西牛贺洲
// jingge.c

inherit ROOM;

void create()
{
  set ("short", "经阁");
  set ("long", @LONG

这里便是三星洞藏经阁，但里面并没有多少书。只是一些基本功
夫和一些道教经典供弟子们平时研读。一排排的书架整齐的摆在
屋中。
LONG);
set("item_desc",(["shelf": 
"远处的看不清楚，最近的一个上好象有些千字文，道德经之类．\n"]));
set("exits", ([ /* sizeof() == 4 */
"south": __DIR__"houyuan",
"up": __DIR__"lou",
]));
set("objects", ([
                __DIR__"npc/guangxi": 1 ]) );
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" ) {
        if (objectp(present("guang xizi", environment(me)))) {
        if((string)me->query("family/family_name")=="方寸山三星洞") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("广羲子对你说到：上面是我道家弟子清修之地，请勿乱闯！\n");
        }
        }
        return ::valid_leave(me, dir);
}



