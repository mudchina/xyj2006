// Room: /luohanta/tal8.c

inherit ROOM;

void create()
{
	set("short", "罗汉塔");
	set("long", @LONG


                        佛


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"tal7",
  "eastup" : __DIR__"tal9",
]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/ll8" : 1,
     
        ]));
   set("no_clean_up", 0);
        setup();
   
}



int valid_leave(object me, string dir)
{
if (me->query("family/family_name") != "南海普陀山" && dir == "eastup")
if(objectp(present("luo han", environment(me))))
return notify_fail("罗汉伸手挡住了你的去路。\n");   
return ::valid_leave(me, dir);
}
