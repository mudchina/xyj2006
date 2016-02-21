// by canoe
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIR"剥皮地狱"NOR);
set("long",@LONG
四周一片漆黑,耳边不时有阴风刮过.隐隐约约的鬼影到处都是.
地上散落很多刑具,这竟然就是传说中的剥皮地狱!
如果你认为肚子饿了，可以用“jinshi”让狱卒给你食物。
如果你认为你的刑期满了，可以用“out”来离开这里。

LONG
);
set("valid_startroom",1);
}
void init ()
{
object me=this_player();
     if(!wizardp(me))
{
 add_action("block_cmd","",1);      
 add_action("do_out","out");      
add_action("do_jinshi","jinshi");      
 me->set("startroom","/d/wiz/dalao.c");
 me->save();
}
}
int block_cmd()
{
        string verb = query_verb();
   
   if (verb=="say") return 0; //allow say
   if (verb=="help") return 0;
   if (verb=="out") return 0;
   if (verb=="look") return 0;
  if (verb=="hp") return 0;
   if (verb=="jinshi") return 0;
   return 1;
}
int do_out()
{
object me=this_player();
//call_other("/daemon/condition/maren.c", "???");
 return 1;
}
int do_jinshi()
{
object me=this_player();
  if((int)me->query("food")<100||(int)me->query("water")<100) 
      { 
      message_vision("狱卒看着$N饥肠辘辘的样子，偷偷塞给$N一个包子和一瓶水。\n"NOR,me);
message_vision("$N感激地送给狱卒一千武学作为报酬。\n"NOR,me);
       me->set("food",1000);
       me->set("water",1000);
if(me->query("combat_exp")>1000) me->add("combat_exp",-1000);
      me->save();
      }
     else message_vision("$N向狱卒要东西吃，可惜狱卒不给。\n"NOR,me);
 return 1;
}
