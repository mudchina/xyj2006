
inherit ROOM;

void create ()
{
        set ("short", "罗汉塔");
        set ("long", @LONG


                        佛


LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"eastdown" : __DIR__"tar4",
		"southup" : __DIR__"tar6",
                
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/lr5" : 1,
     
        ]));
   set("no_clean_up", 0);
        setup();
   
}



int valid_leave(object me, string dir)
{
if (me->query("family/family_name") != "南海普陀山" && dir == "southup")
if(objectp(present("luo han", environment(me))))
return notify_fail("罗汉伸手挡住了你的去路。\n");   
return ::valid_leave(me, dir);
}
