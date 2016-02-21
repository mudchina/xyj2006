// Room: /u/hkgroup/workroom

#include <room.h>
inherit ROOM;
//#include "honglou.h"

void init();
void do_close2();
int do_push(string);
int valid_leave();
string look_door2();
int do_knock2(string);

void create ()
{
  set ("short", "红楼旧址");
  set ("long", @LONG

　　正门之上有一匾(bian)。正门却不开，只有角门(door)供人出入。

LONG);

  set("light_up", 1);
  set("no_magic", 1);
//  set("outdoors", "/u/hkgroup");
 // set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"path1",
 // "lobby"  : "/d/changan/playerhomes/h_none.c",
]));
 // set("no_fight", 1);

  set("item_desc", ([ /* sizeof() == 2 */
  "door" 	: 	(: look_door2, "door" :),
  "bian": "
　　　　红楼旧址

",
]));
  setup();
}


void init()
{
        add_action("do_push", "push");
	add_action("do_close", "close");
	add_action("do_knock2", "knock");
}

void close_door2()
{
        object room;

        if(( room = find_object(__DIR__"path1")) ) {
                delete("exits/enter");
                        message("vision", "咯吱一声, 角门慢慢地合上了。\n",
			this_object());
                room->delete("exits/out");
                message("vision", "咯吱一声, 角门从外面慢慢地合上了。\n", room);
        }
        else message("vision","ERROR: door not found(close).\n", room);

}

int do_knock2(string arg)
{
        object mbox;

        if (!arg || arg!="door")
                return notify_fail("你要敲什么？\n");

        if (query("exits/enter"))
                return notify_fail("角门是开着的。\n");
	else {
        if( !this_player()->query_temp("mbox_ob") )
		{
       		seteuid(getuid());
        	mbox = new(MAILBOX_OB);
        	mbox->move(this_player());
		message_vision("$N轻轻敲了敲门，只听哧的一声，"
				"一个破旧的信箱钩住了$N的衣角，吓了$N一跳。\n",
				this_player());
		}
	else message_vision("$N轻轻敲了敲门，门上的信箱晃了几晃。\n",
				this_player()); 
	return 1;
	}
}

int do_close(string arg)
{
        object room;

        if (!query("exits/enter"))
                return notify_fail("角门已经是关着的了。\n");

        if (!arg || (arg != "door" && arg != "enter"))
                return notify_fail("你要关什么？\n");

        remove_call_out("close_door2");
        call_out("close_door2", 2);

        return 1;
}

int do_push(string arg)
{
        object room, mbox;

        if (query("exits/enter"))
                return notify_fail("角门已经是开着了。\n");

        if (!arg || arg!="door")
                return notify_fail("你要推什么？\n");

        if( room = find_object(__DIR__"path1") ) {
                set("exits/enter", __DIR__"path1");
                message_vision("$N轻轻地推了推门，只听吱地一声，角门慢慢地开了一条缝。\n",
                        this_player());
                room->set("exits/out", __FILE__);
                message("vision", "外面有人推门，只听吱地一声，角门慢慢地开了一条缝。\n",
                        room);
                remove_call_out("close_door2");
                call_out("close_door2", 10);

        }
        else message("vision", "ERROR: door not found(push).\n",this_player());

        return 1;
}

int valid_leave(object me, string dir)
{
        object mbox;

        	if( mbox = me->query_temp("mbox_ob") ) {
               		message_vision("$N把信箱挂回原处。\n", me);
                	destruct(mbox);
       		}
 		return 1;
}

string look_door2()
{
	return("一道供人出入的角门。门上挂着一个破旧的信箱。\n"
		"你试着敲了敲门，又轻轻推了推。\n");
}
