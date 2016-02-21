//这种跟环境有关的东西,busy越多,bug越少
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  int north=(POS/10+4)%5*10+POS%10,south=(POS/10+1)%5*10+POS%10,
      east=POS/10*10+(POS%10+1)%5,west=POS/10*10+(POS%10+4)%5;
  set ("short", "神农药圃");
  set ("long", @LONG

乱花渐欲迷人眼,潜草才能没马蹄.这里万花鲜妍,草药
品种很多,说不定就藏了什么奇珍异草.

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baihuagu"+north,
  "south" : __DIR__"baihuagu"+south,
  "east" : __DIR__"baihuagu"+east,
  "west" : __DIR__"baihuagu"+west,
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
 
add_action("do_cast", "cast");
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
int do_cast(string arg)
{
object me=this_player();
if ( arg !="qiankun on baicao xian"||arg!="qiankun") return 0;
     else {write("用乾坤对付百草仙？不好吧？\n"); return 1;}
}

