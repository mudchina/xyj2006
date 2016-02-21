// Room: /4world/entrance
inherit ROOM;

// int do_push(string);

void create ()
{
  set ("short", "仙石");
  set ("long", @LONG

这里是花果山腰的一块平地。一道瀑布从山顶飞流直下，
泻入一眼深潭，当真是：“一派白虹起，千寻雪浪飞”。
瀑布边上有一块大石头，相传为天地灵气所化。不知是谁在
上面刻了一首诗：

　　　　混沌未分天地乱，茫茫渺渺无人见。
　　　　自从盘古破鸿蒙，开辟从兹清浊辨。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/ourhome/npc/longear" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"houshan1",
  "southdown" : __DIR__"up2",
]));

  setup();
}


int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回给邮差。\n");
		destruct(mbox);
	}
	return 1;
}

