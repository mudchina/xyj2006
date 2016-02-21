//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

走到山路上，看着远方的丛山，你觉得此山真是个险啊，山峰迭障
不断，山路起浮崎岖，路旁尽是些奇石怪木。
LONG);

  set("exits", ([
        "westup"  : __DIR__"shanlu3",
        "east"  : __DIR__"shanpo",
      ]));
  set("outdoors","hfd");
  setup();
}

void init()
{
	object me=this_player();
	if (me->disable_player("<睡梦中>"))
	return;
	if (me->query_temp("need_sleep")=="yes")
	{
	message_vision("$N疑惑的看看四周，和昨天遇到的情景完全不同。\n",me);
	tell_object(me,"你发现身上好像多了些东西。\n");
	me->delete_temp("need_sleep");
	return;
	}
}






