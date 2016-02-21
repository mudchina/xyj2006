//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/xiaolu1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "尽头");
  set ("long", @LONG

这里是洞的尽头了，可以看到这个地方经常有人来往，有一
块石头(stone)特别光滑，你不禁想去摸摸。
LONG);

  set("exits", ([
        "west"  : __DIR__"xiaolu2",
      ]));
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("pig_appear");        
        call_out("pig_appear",5,ob);
        add_action("do_push","push");
}

int do_push(string arg)
{

        object ob = this_player();
      
        if ( ! arg || arg != "stone" )
                return notify_fail("你要推什么？\n");

        if( ob->query("max_force") < 500
          &&ob->query("force") < 700 )
                return notify_fail("你推了半天，但是什么也没有发现。\n");

        message_vision(HIR"$N发力于掌上，大喝一声：开，就见石头慢慢的移动开，你看到一束光线照了进来。\n"NOR,ob);
                set("exits/out", __DIR__"shulin1");
                ob->set("force",0);
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
}
void close(object room)
{
        message("vision","只听咯吱一声，石头又移了回来。\n", room);
        room->delete("exits/out");
}       
                
void pig_appear(object ob)
{
        
        object pig=new(__DIR__"npc/pig");
        object where=environment(ob);

      if( objectp(present("zhu guai") ) ) return ;
      if( query_temp("done") ) return ;
        message_vision(HIC"忽然一阵阴风吹来，一个头大猪向$N冲来。\n",ob);
        message_vision("似乎猪还向$N呵呵得笑着。\n"NOR,ob);
        pig->move(where);
        ob->set_temp("see_pig",1);
       where->set_temp("done",1);
        return;
}
