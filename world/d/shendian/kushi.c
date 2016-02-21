#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short", HIC"枯室"NOR);
  set ("long", @LONG

这里是天神台上的其中一个房间。是众神坐禅的地方。

LONG);
  set("exits", ([ /* sizeof() == 1 */
                 "east" : __DIR__"tianshentai",
                 ]));
  set("no_clean_up", 1);
  set("no_fight", 1);
   set("no_magic", 1);
  set("alternative_die",1);
  set("sleep_room", 1);
  set("outdoors", 0);
  setup();
}       
void init()
{
  add_action("do_zuochan", "zuochan");
}
 int do_zuochan()
{
  int myforce, myspi, learned, sencost;
    object me = this_player();
   int num;
   num = 0;
   if((int)me->query("combat_exp") < 2000000)
   num = 150;
    else {if((int)me->query("combat_exp") < 3500000)
    num = 250;
    else num = 350;}
   if((int)me->query_skill("force",1) < num)
   {
    if(me->query("babu/shendian") == "done")
    {
    myforce = me->query_skill("force");
      myspi=(int)me->query_spi();
  learned=(myforce+myspi)/6;

  if( myforce < 100 )
       sencost = 30+(myforce/10);
  else  
        sencost = 30+(myforce/5);

  if ((int)me->query("sen")<=sencost)
      return notify_fail("你神智不清，再这样下去会有危险的！\n");
  if(me->query("force")<=(sencost/2))
    return notify_fail("你的内力不足，难以领会高深的内功。\n");
  me->receive_damage("sen", sencost);
  me->add("force", -(sencost/2));
   tell_object (me, "你的「基本内功」略有进展。\n");
  me->improve_skill("force",learned);
   return 1;
    }
    else
    {
    message_vision(HIY"$N怎么进来的，回去吧！\n"NOR,this_player());
   message_vision(HIY"$N被一只无行的手抓回了南城客栈！\n"NOR,this_player());
   this_player()->move("/d/city/kezhan");
    return 1;
    }
   }
   else
   {
   message_vision(HIW"$N的修为已经够高了！\n"NOR,this_player());
       return 1;
   }
}
