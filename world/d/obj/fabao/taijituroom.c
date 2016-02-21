
#include <ansi.h>
inherit ROOM;

void create() {

  set("short","小桥流水");
  set("long", @LONG

一座古色古香的小石桥，桥墩上刻着“太极”两个篆体字。
桥下小河流水叮咚，河水晶莹透澈，桥上坐着位蓑衣渔翁，
仙风道骨，正吟诗作歌。一片宁静安详的气氛，你几乎忘了
尘世间的烦恼。

LONG);

  setup();
}

void init() {
   object host=query("host");
   object old_room=query("old_room");
   string dir,dest;

   if (!old_room) return;
   if (!host || environment(host)!=this_object()) {
      dir=old_room->query("altered_dir");
      dest=old_room->query("old_room");

      old_room->set("exits/"+dir,dest);
      this_player()->move(dest,1);
      destruct(this_object());
    }
}
       
int is_clear() {
  object *inv=all_inventory();

  for (int i=0;i<sizeof(inv);i++)
    if (userp(inv[i])) return 0;
  return 1;
}   
  
void explode() {
  object *inv=all_inventory();
  object me=query("host");
  string msg=HIW"顿时将";
  int flag=0;

  message_vision(HIW"$N手一扬，太极图应手而起，卷拢起来。\n"NOR,me);
  for (int i=0;i<sizeof(inv);i++)
     if (inv[i]!=me) {
        flag=1;
        msg=msg+inv[i]->name()+"，";
        inv[i]->receive_wound("kee",inv[i]->query("max_kee")*2,me);
     }
  msg+="化做齑粉！\n"NOR;
  if (flag) message_vision(msg,me);

  me->move(query("old_room"));
  destruct(this_object());

}
  

