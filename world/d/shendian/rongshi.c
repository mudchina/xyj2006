#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short", HIC"荣室"NOR);
  set ("long", @LONG

这里是天神台上的其中一个房间。是众神修行的地方。

LONG);
  set("exits", ([ /* sizeof() == 1 */
                 "west" : __DIR__"tianshentai",
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
  add_action("do_xiuxing", "xiuxing");
}
 int do_xiuxing()
{
  int myspells, myspi, learned, sencost;
    object me = this_player();
   int num;
   num = 0;
   if((int)me->query("combat_exp") < 2000000)
   num = 150;
    else {if((int)me->query("combat_exp") < 3500000)
    num = 250;
    else num = 350;}
        if((int)me->query_skill("spells",1) < num)
    {
    if(me->query("babu/shendian") == "done")
    {
    myspells = me->query_skill("spells");
      myspi=(int)me->query_spi();
  learned=(myspells+myspi)/6;

   if( myspells < 100 )
       sencost = 30+(myspells/10);
  else  
        sencost = 30+(myspells/5);

  if ((int)me->query("sen")<=sencost)
      return notify_fail("你神智不清，再这样下去会有危险的！\n");
  if(me->query("mana")<=(sencost/2))
    return notify_fail("你的法力不足，难以领会高深的法术。\n");
  me->receive_damage("sen", sencost);
  me->add("mana", -(sencost/2));
   tell_object (me, "你的「基本法术」略有进展。\n");
  me->improve_skill("spells",learned);
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
