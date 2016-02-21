//Cracked by bear
// Room: /d/nanhai/chanfang
inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
void create ()
{
  set ("short", "禅房");
  set ("long", @LONG

这是普陀山门人弟子们练功打坐的地方。只见几个僧人正在
一边吆喝着舞拳弄脚，另外几个在练习兵器。屋角摆着几把
铁杖铁枪。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang",
]));
 set("no_clean_up", 1);
set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangchan" : 1,
]));

  setup();
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
message("channel:es",CYN+"◇"RED"南海普陀山"CYN"◇"CYN"掌禅僧[Zhangchan seng]"CYN"：现在开始讲授我佛如来之无边佛法。\n"+NOR,users());
tell_object(where,"万机歇罢结禅坛，无字拈来着力参。\n");
tell_object(where,"参到水穷山尽处，自然透得祖师关。\n");
tell_object(where,"古德云：参禅要透祖师关，妙悟要穷心路绝。祖关不透，心路不绝，尽是依草附木精灵。\n");
tell_object(where,"且道如何是祖师关？只这一个“无”字，便是一关，禅门目之为“无门关”。\n");

   tell_object(where,"如果透得这一关，不仅能够亲见赵州，而且能够与历代祖师把手共行，眉毛撕结，同一眼见，同一耳闻，岂不庆快！\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"掌禅僧说道：我讲的，也都是历代祖师、诸大善知识讲过的，并不是从我自心里边悟出来的，所以都是拾人牙慧而已。\n");
   set("jiangjing",0);
     set ("long", @LONG
    弟子们若有所悟。
LONG);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("掌禅僧还没开始传授佛法呢。\n");

 if((string)me->query("family/family_name")!="南海普陀山")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("你对佛法的理解已经自成一脉了。\n");

    tell_object(me,"你在旁边听着，听着。禅心更加稳固了。\n");
   me->start_busy(5);
   me->improve_skill("lotusforce",random((int)(me->query("spi")+me->query("int"))/2));
 //  me->improve_skill("buddhism",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}

