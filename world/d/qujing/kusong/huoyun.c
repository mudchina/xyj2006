//Cracked by bear
inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "火云堂");
  set ("long", @LONG

这里就是火云洞的中心－火云堂。正前方一把黑虎皮的软椅高高
在上，椅后一把玄色大锦旗，上面绣着“圣婴大王”四个金子。
两旁小妖林立，头顶几十把松油灯把堂上照的雪亮。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao7",
  "west" : __DIR__"jin",
  "east" : __DIR__"tu",
  "northeast" : __DIR__"huo",
  "northwest" : __DIR__"mu",
  "north" : __DIR__"shui", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/honghaier" : 1,
  __DIR__"obj/che1" : 1,
  __DIR__"obj/che2" : 1,  
  __DIR__"obj/che3" : 1,  
  __DIR__"obj/che4" : 1,  
  __DIR__"obj/che5" : 1,  
]));


  setup();
  
//   call_other("/obj/board/kusong_b", "???")
}
void init()
{
   object where=this_object();

    remove_call_out("check_time");
   check_time(where);
   add_action("do_hear","hear");
}
void check_time(object where)
{

   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   if(phase==0&&(!query("jiangjing"))) jiang_jing(where);
if(phase==7&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:es",CYN+"◇"YEL"枯松涧火云洞"CYN"◇"YEL"红孩儿[Honghai er]"CYN"：现在开始传授我们枯松涧火云洞的魔法。\n"+NOR,users());
tell_object(where,"红孩儿说道：我乃枯松涧火云洞的洞主也。\n");
tell_object(where,"火魔心法修炼后，体内三昧真火纵是大罗神仙也难逃一劫，\n");
tell_object(where,"修炼本门魔法目的是希望能参透天地间永恒的奥秘，以达到天人合一的境界。\n");

   tell_object(where,"注意：山外有山，天外有天。\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"红孩儿说道：回去试试你的心法进展如何。\n");
   set("jiangjing",0);
     set ("long", @LONG
   火云洞弟子安静的坐着 ，他们在听红孩儿传授本门心法。
LONG);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("红孩儿还没开始传授本门心法呢。\n");

 if((string)me->query("family/family_name")!="火云洞")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("你的本门心法已经颇有所造诣了。\n");

    tell_object(me,"你在旁边听着，听着。不禁对本门心法有所领悟。\n");
   me->start_busy(5);
   me->improve_skill("huomoforce",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("pingtian-dafa",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}

