//Cracked by Roath

//inpool.c

inherit ROOM;

void create ()
{
	set ("short", "荷塘中");
	set ("long", @LONG

塘中碧莲相结，荷香扑面而来。你拼命地伸长脖子，想把脑袋从
荷叶底下钻出来。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"up" : __DIR__"southpool",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		//__DIR__"npc/mingyue" : 1,
	]));

	set("outdoors", "wuzhuang");

	setup();
}

void init()
{       
	object me=this_player();

	if( me->query_temp("wzgmaze1") ) me->delete_temp("wzgmaze1");
	if( me->query_temp("wzgmaze2") ) me->delete_temp("wzgmaze2");
	if( me->query_temp("wzgmaze3") ) me->delete_temp("wzgmaze3");
	if( me->query_temp("wzgmaze4") ) me->delete_temp("wzgmaze4");
	if( me->query_temp("wzgmaze5") ) me->delete_temp("wzgmaze5");
	if( me->query_temp("wzgmaze6") ) me->delete_temp("wzgmaze6");
	if( me->query_temp("wzgmaze7") ) me->delete_temp("wzgmaze7");
	if( me->query_temp("wzgmaze8") ) me->delete_temp("wzgmaze8");
}

