// edited by mind
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "树洞内");
        set("long", @LONG
树穴周围不过五尺，果然没有可以藏下一个人的地方。
奇怪的是，居然有一股淡淡的红烧鸡的香气。。。
LONG
  );
   set("objects", ([
      
   ]) );  
        set("no_magic",1);
        
        setup();
} 
void init()
{
   add_action("do_smell", "smell");
   add_action("do_step", "step");
}

int do_step(string arg)
{
   object me, room;
   me = this_player();

   if(me->query_temp("marks/smell")) {
      tell_object(me, "你一脚踏在铁八卦印痕上，你站的地方竟突然往下面沉了下去！\n\n");
      message("vision", "地面豁开一个洞，"+me->name(me)+"竟突然沉了下去，不见了。\n", environment(me),me );
      room = find_object(__DIR__"tongzi1");
      if(!objectp(room)) room=load_object(__DIR__"tongzi1");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_smell(string arg)
{
   object me, room;
   me = this_player();

   tell_object(me,HIY"红烧鸡的香气缥缥袅袅，若有若无，你掀掀鼻子，仔细闻闻，这香气象是从下面。。。\n"NOR);
   message("vision",me->name(me)+"脸上露出古怪的神情，似乎在找着什么。\n", environment(me),me);
   tell_object(me, "\n你赶紧低头一看，地上有个奇怪的铁八卦的印痕(step)，不仔细找，还看不出来。\n", me);
   me->set_temp("marks/smell", 1);      

   return 1;
}

