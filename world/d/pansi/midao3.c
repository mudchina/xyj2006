// midao3.c
// by lestat

inherit ROOM;

void create()
{
        set("short", "秘密通道");
        set("long", @LONG
这是一段又长又黑的秘密通道，隐约可以感觉到四周是冰冷而坚硬的石
壁，你什么了看不清楚，只可以靠摸索着前进。
LONG );
	set("exits", ([
		"south" : __DIR__"midao2",
		"out" : "/d/city/center",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out") 
	 tell_object(me,"你走出了秘密通道，神秘地出现在长安城十字街头。\n");
	 return ::valid_leave(me,dir);
}

