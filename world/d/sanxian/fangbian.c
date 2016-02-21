#include <room.h>
inherit ROOM;
void create()
{
        set("short", "方便之处");
        set("long", @LONG
这里就是方便之处，有一个臭烘烘的粪坑，散发着恶心的味道。
LONG
  );
  set("exits",([
        "northwest" : __DIR__"guodao",
      ]));  
   set("objects", ([
      
     ]) );  
        set("no_magic",1);
        create_door("northwest", "木门", "southeast", DOOR_CLOSED);
        setup();
} 

void init()
{
   add_action("do_search", "search");
   add_action("do_look", "look");
   add_action("getting", "zuan");
}

int do_look(string arg)
{
   object me;

   me = this_player();
   if (!arg || (arg != "粪坑" && arg != "cesspit"))
      return 0;
   if(me->query_temp("marks/foundcesspit"))
      tell_object(me, "一个粪坑，好象太干净了点。肯定有古怪！果然有个小洞(hole)。。。\n");
        me->set_temp("marks/foundhole", 1);
   return 1;
}

int do_search(string arg)
{
   object me;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if (!arg) {
      if(random(100) < llvl) {
         tell_object(me, "你发现粪坑(cesspit)里有些碎石，想仔细看看。\n");
         me->set_temp("marks/foundcesspit", 1);
         return 1;
      }
      message_vision("$N捂住鼻子，抑制住恶心，耐心地查看着粪坑。。。。\n", me);
      tell_object(me, "这么臭的地方，别找啦，太臭了！！！\n");
      return 1;
   }
   return 0;
}



int getting(string arg)
{
        object obj;
        object me;
                
        if(!arg || arg=="")
        {
                write("你要钻什么？\n");
                return 1;
        }
        if( arg == "洞" || arg == "hole" || arg == "小洞")
        {
        me = this_player();
        if(me->query_temp("marks/foundhole")){
        message_vision("$N捏住鼻子，缩紧身子，从粪坑里的小洞钻了进去。\n", me);
        me->start_busy(2);
        call_out("zuaning",2,me);
        me->stop_busy();
        message("vision","爬了一段，变成了一个小道，"+me->name() + "赶紧钻了出来。\n", environment(me),me);
        return 1;
        }
        }

        else
        {
                write("这"+arg+"有啥好钻的，以为你是老鼠啊？\n");
                return 1;
        }

}
int zuaning(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"xiaodao");
        message_vision("爬了一段，变成了一个小道，$N赶紧钻了出来。\n", me);
        }
        return 1;
}
