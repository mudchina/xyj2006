// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void leave_here(object me) {
   if(me) me->move("/d/12gong/szchoose");
}

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向双子宫的路上，只见前面可以看到美丽的双子宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的金牛宫。
LONG);


        set("exits", ([
        "eastup"    :       __DIR__"shuangzi",
            "southdown"  :       __DIR__"jn2sz1",
        ]));

        set("outdoors", "12gong");
        setup();
}


int valid_leave(object me, string dir)
{
        if (dir == "eastup" && me->query_temp("12gong/cike") != "done")
	       {
			 
         call_out("leave_here",1,me);
      return notify_fail("你一阵迷茫。\n");
		   }
return ::valid_leave(me, dir);
}

void init()
{
    add_action("block_cmd", "", 1);
}


int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
