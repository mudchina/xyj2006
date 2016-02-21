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
  "southwest" : __DIR__"gudu",
  "northeast" : __DIR__"xiaolu2",
]));

  setup();
}

void init()
{       
        object me=this_player();
	if( query("done") ) return;
        if( !present("laohu jing") || interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",5, me);
        }
}
void greeting(object me)
{       object jing;
        if( !me || environment(me) != this_object() ) return;
        if( present("laohu jing") ) return;
        seteuid(getuid());
        if(jing=new("/d/qujing/bibotan/npc/laohujing"))
                jing->move(this_object());
                message("vision", "\n一阵腥风吹来，从草从中钻出个妖怪来。\n\n", this_object());
                message("vision","老虎精大叫到：大王我要拿你去下酒，乖乖投降吧，免得大王动手，你多吃苦头！\n\n",
this_object());
        jing->kill_ob(me);
        me->fight_ob(jing);

}
