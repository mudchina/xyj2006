// create by snowcat.c 4/8/1997
// room: /d/westway/shizhen.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","石栈道");
  set ("long", @LONG

这是一条极长的用大石块铺成的栈道，远处栈道伸进石坡，不
得不在有的地方凿石辟路架路。据说西面再远一点就是著名的
嘉峪关了，往东是去酒泉的方向。

LONG);

  set("exits", ([
        "east" : __DIR__"jiuquan",
        "west" : __DIR__"jiayu",
      ]));
  set("outdoors", __DIR__);

  setup();
}


void init()
{       
        object me=this_player();
        if( query("done") ) return;
        if( interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",25, me);
        }
}
	
int greeting(object me)
{
	object *list, ob;
	int i;
	if( !me || environment(me) != this_object() ) return 1;
	tell_room(this_object(), "你忽然觉得脚下的石板松动了………\n");

	list=all_inventory(this_object());
	i=sizeof(list);
	while (i--)
	{
		ob=list[i];
		ob->move("/d/westway/tielong");
		message_vision("「咚」的一声，$N从机关掉到了铁笼中………\n", ob);
	}
	this_object()->set("done");
	call_out("reg", 300);
	return 1;
}
int reg()
{
	this_object()->delete("done");
	return 1;
}

