//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
        set("short", "后山");
        set("long", @LONG
        一条小路通往后山禁地。
LONG
        );

        set("exits", ([
                "north" : __DIR__"bamboo",
                "southwest" : __DIR__"houdian",
                "eastup" : __DIR__"feipu",
        ]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{

   if (dir == "north" ) {
        if (me->query("family/family_name") == "蜀山剑派")
        {
        if (me->query("shushan/ask_zuidao_go"))
        return ::valid_leave(me, dir);
        return notify_fail("你忽然听到剑圣的话：“本派禁地，不怕被重罚吗！？”\n");
        }
        if (objectp(present("jian tong", environment(me))))
   return notify_fail("守山剑童客气地说：“后山乃本派禁地，还是请回吧！”\n");
        }   
        return ::valid_leave(me, dir);
}

