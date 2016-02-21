// Room: /luohanta/tal9.c

inherit ROOM;

void create()
{
	set("short", "罗汉塔");
	set("long", @LONG


                        佛


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"talup",
  "westdown" : __DIR__"tal8",
]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/ll9" : 1,
     
        ]));
   set("no_clean_up", 0);
        setup();
   
}



int valid_leave(object me, string dir)
{
if (me->query("family/family_name") != "南海普陀山" && dir == "up")
if(objectp(present("luo han", environment(me))))
return notify_fail("罗汉伸手挡住了你的去路。\n");   
return ::valid_leave(me, dir);
}
