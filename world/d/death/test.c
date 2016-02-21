inherit ROOM;

void create()
{
  set ("short", "超生贵道门");
  set ("long", @LONG

这里边是阴间通往阳间的唯一出口－贵道门。若是有冤死鬼投
胎，就由此出阴间。南方有一座大牌坊耸立，牌坊的另一面什
么也看不到。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "out" : "牌坊的另一面什么也看不到。\n",
]));

set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"pingyang",
]));
	set("hell", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_out", "out");
}

int do_out()
{//	string owner;
        object me, zhenshen;
	me=this_player();

	if( me->query_temp("in_hell")) {
		if( zhenshen=me->query_temp("zhenshen")) {
			me->move(environment(zhenshen));
			destruct(zhenshen);
			me->delete_temp("in_hell");
			message_vision("$N揉揉眼睛，似乎清醒了过来。\n", me);
			return 1;
		}
	}
        me->move("/d/death/out");
        me->delete_temp("in_hell");
        return 1;
}

