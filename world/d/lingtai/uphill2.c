// Room: some place in 西牛贺洲
// uphill2.c

inherit ROOM;

void create()
{
  set ("short", "枯松坪");
  set ("long", @LONG

山路依旧蜿延而上，西边的松林被山风一吹，哗哗地做响。
抬头上望，山高林密，不知还要走多远．向西边望去，林中
太暗，什么也看不清楚。前方一棵大松树(pine)上好象写了
些什么。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "pine" : "小心林中有狼！\n",
]));

set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill3",
"south": __DIR__"uphill1",
"west": __DIR__"forrest"
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{       
	object me;
        me=this_player();

        if ( !arg || ((arg != "pine") ))
                return notify_fail("你要爬什么？\n");
        else
                message_vision("$N抓住伸出的树枝，小心翼翼的爬了上去。\n",me);
                me->move("/d/lingtai/uptree");
		me->receive_damage("kee", 20);
		tell_room( environment(me), "树枝晃了几晃，有个人爬了上来！\n", ({me}));

                return 1;
}

