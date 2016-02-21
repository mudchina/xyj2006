#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "潭边小路");
  set ("long", @LONG

小路因为年久无人走动的关系，已被枯黄的树叶覆盖了。路边的
荒草几有人高，阵风吹过，卷起一片片的枯叶。草从中也呼呼做
响，象是猛兽发出的吼声。
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xiaolu3",
  "westup" : __DIR__"shipo1",
]));

  setup();
}

void init()
{       
	object me=this_player();
	if( !present("liushu jing") || interactive(me)) {
		remove_call_out("greeting");
		call_out("greeting",5, me);
	}
}
void greeting(object me)
{	object jing;
	if( !me || environment(me) != this_object() ) return;
	if( present("liushu jing") ) return;
	seteuid(getuid());
	if(jing=new("/d/qujing/bibotan/npc/shujing"))
		jing->move(this_object());
		message("vision", "\n一阵惺风吹来，从树上跳下个妖怪来。\n\n", this_object() );
		message_vision("柳树精看着$N大笑：上门的买卖，哈哈。\n\n", me);
	jing->kill_ob(me);
	me->fight_ob(jing);

}
