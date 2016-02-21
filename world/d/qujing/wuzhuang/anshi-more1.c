//Cracked by Roath
//anshi-more1.c
#include <room.h>
inherit ROOM;

// mon 6/20/99 
// since this room don't refresh, so need set limit.
int query_max_encumbrance() { return 300000; }
int query_max_items() {return 3;}

void create ()
{
	set ("short", "亭底秘室");
	set ("long", @LONG

这是牡丹亭底下的一间秘室，十分狭小，是五庄观用来储藏重要物
品的地方。秘室的墙壁上镶着几块幽蓝的宝石，淡淡的蓝光虽然不
太明亮，却也足够让人看清秘室的布局了。 
LONG);

	set("exits", 
	([ //sizeof() == 4
		//"southwest" : __DIR__"juyuan",
		//"north" : __DIR__"southpool",
		"out" : __DIR__"anshi",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"obj/huangtong-key" : 1,
	]));

	//set("outdoors", "wuzhuang");


	setup();
}


void init()
{
	//add_action("do_mo", "mo");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate_book", 18010);//5 hours 10 seconds.
	}
}

void generate_book()
{
	object book;

	remove_call_out("generate_book");

	book = new("/d/obj/book/taiyi-book");
	book -> move(this_object());
	
	call_out("generate_book", 18010);//5 hours 10 seconds.
	//since the book will disappear after 5 hours, it's ok to generate repeatedly...

	return;
}

int clean_up()
{
	return 0;
}


