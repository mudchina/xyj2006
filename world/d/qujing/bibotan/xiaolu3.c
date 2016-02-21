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
  "east" : __DIR__"gudu",
  "northwest" : __DIR__"xiaolu4",
]));

  setup();
}

void init()
{       
        object me=this_player();
        if( !present("shuishe guai") || interactive(me)) {
                remove_call_out("greeting");
                call_out("greeting",5, me);
        }
}
void greeting(object me)
{       object jing, guai;
        if( !me || environment(me) != this_object() ) return;
        if( present("shuishe guai") ) return;
        seteuid(getuid());
        if(guai=new("/d/qujing/bibotan/npc/shuiguai"))
                guai->move(this_object());

        seteuid(getuid());
        if(jing=new("/d/qujing/bibotan/npc/shuiguai"))
                jing->move(this_object());

                message("vision", "\n潭中的水动了动，钻出两个妖怪来。\n\n", this_object() );
                message_vision("水蛇怪看着$N大笑：好多天没开荤了，哈哈。\n\n", me);
        jing->kill_ob(me);
        me->fight_ob(jing);
	guai->kill_ob(me);
        me->fight_ob(guai);

}

