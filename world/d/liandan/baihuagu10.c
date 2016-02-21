//By Canoe
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
 set ("short", "神农药圃");
  set ("long", @LONG

乱花渐欲迷人眼,潜草才能没马蹄.这里万花鲜妍,草药
品种很多,说不定就藏了什么奇珍异草.

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baihuagu12",
  "south" : __DIR__"road3",
  "east" : __DIR__"baihuagu32",
  "west" : __DIR__"baihuagu22",
]));
  if(!random(6)) set("outdoors",1);
  setup();
}

void init() {
  object me=this_player();
  if (present("baicao shen",this_object())) return;
  if (!present("yao chu",me)) return;
   me->start_busy(random(2)+1);
  tell_object(me,GRN"四周草木丛生,你举步维艰。\n"NOR);
 
  if (random(10)) return;
  else {
  remove_call_out("greeting");
  call_out("greeting",1,me,this_object());
      }
}

void greeting(object me,object env) {
  if (!me || environment(me)!=env) return;
   me->start_busy(2);
  tell_object(me,MAG"你看到草丛中似乎有些异样，不由停住脚步，想看个仔细。\n"NOR);
  call_out("greeting1",2,me,env);
}


void greeting1(object me,object env) {
  if (!me || environment(me)!=env) return;
  
  if (random(4)) 
     {
      environment(me)->set_temp("wayao1",1);
      environment(me)->delete_temp("wayao2");
      tell_object(me,MAG"你的眼前一亮，看到一颗"HIY"普通药材"NOR MAG"藏在草丛中。\n\n"NOR);
     }
  else {
      environment(me)->set_temp("wayao2",1);
      environment(me)->delete_temp("wayao1");
      tell_object(me,MAG"你的眼前一亮，看到一颗"HIR"珍贵药材"NOR MAG"藏在草丛中。\n\n"NOR);
     }      
}

