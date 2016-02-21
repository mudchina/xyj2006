
// by canoe
#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIR"拔舌地狱"NOR);
set("long",@LONG
四周一片漆黑,耳边不时有阴风刮过.隐隐约约的鬼影到处都是.
地上散落很多刑具,这竟然就是传说中的拔舌地狱!
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
 me->set("startroom","/d/city/prison.c");
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
   return 1;
}
int do_out()
{
object me=this_player();
call_other("/daemon/condition/maren.c", "???");
if(!me->query_condition("maren")) 
      { message_vision("$N刑满释放！$N被转移到客栈。\n"NOR,me);
                me->move("/d/city/kezhan");
                      me->set("startroom","/d/city/kezhan");
                      me->save();
              }
     else message_vision("$N试图离开这里，可惜刑期没满。\n"NOR,me);
 return 1;
}
