#include <ansi.h>
inherit ITEM;
int do_quit();
void self_destruct();
int is_qimen() {return 1;}
int set_exits(string s) {
  if (!s) return 0;
  set("exits", ([
       "east": s,      
       "west": s,      
       "north": s,      
       "south": s,      
       "northeast": s,      
       "southeast": s,      
       "southwest": s,      
       "northwest": s,      
     ]));
  return 1;
}
void create()
{
     set_name("奇门",({"in qimen","qimen"}));     
     set("short","奇门遁甲阵");
     set("long", @LONG

你突然觉得天旋地转，日月星辰全部消失，再也分不清东西南北。
眼前忽而漆黑一片，忽而亮光四射，忽而金星闪烁，耳边一时万籁
俱寂，一时锣鼓喧天，一股惧意由泥丸升起，直冲天灵，身不由己
地浑身直打颤。

LONG
     );
     set_max_encumbrance(100000000000);
     set_weight(100);
     set("no_get",1);
     seteuid(getuid());
     set_exits("/d/city/center");     
     setup();
}
void init() {
   object host=query("host");
   object old_room=query("old_room");
   string dir,dest;
   object me=this_player();
   add_action("do_quit", "quit");
   add_action("no_halt","surrender");
   //if (!old_room) return;
   if (!host || environment(host)!=this_object()) 
      call_out("self_destruct",1);
   if (me!=host) 
     add_action("block",({"exert","cast","perform"}));
   else add_action("do_finish","finish");
   if (!userp(me)) {
      me->set("chat_chance_combat_bk",
              me->query("chat_chance_combat"));
      me->delete("chat_chance_combat");
   } else me->set_temp("time_in_qimen",time());
}
int block() {
   write("你身陷奇门遁甲阵，早已急得手足无措，哪有心思干这个。\n");
   return 1;
}
int no_halt() {
   if (this_player()==query("host") && this_player()->is_fighting()) {
      write("投降？没门儿！宁死不屈！\n");
      return 1;
   }
   return 0;
}
void self_destruct() {
  string dir,dest;
  object old_room=query("old_room");
  object *inv=all_inventory(this_object());
  object host=query("host");
  if (old_room) {
    dir=old_room->query("altered_dir");
    dest=old_room->query("old_room");
    old_room->set("exits/"+dir,dest);
  } else old_room=load_object(query("exits/east"));
  for (int i=0;i<sizeof(inv);i++) {
     if (userp(inv[i])) 
        tell_object(inv[i],"你突然觉得眼前金光一闪，耳旁一阵轰鸣．．．\n");
     else inv[i]->set("chat_chance_combat", 
               inv[i]->query("chat_chance_combat_bk"));
     inv[i]->move(old_room);
  }
  if (host) host->delete_temp("cast_qimen");  
  destruct(this_object());
}
int do_quit() {      
     write("你心烦意乱，不知道如何才能退出。\n");
     return 1;
 }
int do_finish() {
  object host=query("host");
  object me=this_player();
  if (host!=me) return 0;
  if (me->is_fighting()) {
    write("你正忙着打架，没有闲功夫。\n");
    return 1;
  }
  message_vision(HIB"$N手一挥，收起了奇门遁甲术。\n"NOR,me);
  call_out("self_destruct",1);
  return 1;
}
int valid_leave(object me,string dir) {
  object host=query("host");
  int spells;
  int ap,dp;
  if (!host) return 1;
  if (me==host) 
    if (me->is_fighting()) {
       return notify_fail("临阵脱逃？不合适吧？\n");
    } else return 1;
  spells=host->query_skill("spells");
  ap=host->query("daoxing")+spells*spells*spells/10;
  if (spells>200) spells=200;
  if (userp(me)) {
    me->add("sen",-spells);
    me->add("kee",-spells);
    if (!query_temp("time_in_qimen"))
      set_temp("time_in_qimen",time());
    else 
       if (time()-query_temp("time_in_qimen")>spells)
           return 1;
  }
  spells=me->query_skill("spells");
  dp=me->query("daoxing")+spells*spells*spells/10;
  if (random(ap)<random(dp)) return 1;
  message_vision(HIR"$N象只没头苍蝇般撞来撞去，可就是找不着北。\n"NOR,me);
  if (userp(me)) me->start_busy(3+random(5));
    else me->start_busy(2);
  return 0;
}
