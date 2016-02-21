//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short", "树上");
  set ("long", @LONG

这是一棵大桃树，上面接了很多的大桃子，你的口水不禁从树上滴
了下去，仿似下雨一般。

LONG);

  set("exits", ([
        "down"     : __DIR__"shanding",
      ]));
  setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object ob = this_player();
        object tao = new(__DIR__"obj/tao");
        
        if( !arg || arg != "tao zi")
          {
          tell_object(ob,"你要摘什么？\n");
          return 1;
          }
        if( present("tao",ob) )
           {
           tell_object(ob,RED"你怎么这么贪心。\n"NOR);
           return 1;
           }
        tao->move(ob);
        message_vision("$N从树上摘了一棵又大又红的桃子。\n",ob);
        return 1;
}        
