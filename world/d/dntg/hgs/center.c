// Room: /d/4world/center.c
inherit ROOM;

void create ()
{
  set ("short", "傲来台");
  set ("long", @LONG

这里便是傲来国的城中心傲云广场，几条宽广的大路由此延伸向
四面八方。可看到四周有各地的行人来来往往，一派繁华景象。
地上是青砖铺就，后有一个高台，台上竖着根旗杆(qigan)。时常
有艺人在场间空地上表演。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "qigan" : "一根紫桐木做的旗杆，高有数丈。

",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yiren" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"north1",
  "west" : __DIR__"west1",
  "east" : __DIR__"east1",
]));

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

        if ( !arg || ((arg != "qigan") ))
                return notify_fail("你要爬什么？\n");
	
	message_vision("$N搓了搓手，腾地就顺着旗杆向上爬去。\n",me);

	if((int)me->query_skill("dodge",1) < 20) {
		me->improve_skill("dodge", 5);
		me->receive_damage("kee", 10);

	}	
	else {
		message_vision("$N奋力爬到最顶，博得周围一阵喝采！\n", me);
	}
   return 1;
}

