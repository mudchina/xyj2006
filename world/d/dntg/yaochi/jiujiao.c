
#include <ansi.h>

inherit ROOM;
void drunk();
int effect();
void create ()
{
  set ("short", "酒窖");
  set ("long", @LONG

一间密不透风的地窖，放着了一排排酒坛，里面装的就是
令天上诸神思之垂涎不已的王母仙酒了。你一走进来，就
觉得酒香扑鼻，果然是好酒。
LONG);

  set("exits", ([
        "up"  : __DIR__"donglang",
      ]));

   set("objects",([
    __DIR__"npc/obj/jiutan" :4,
  ]));

//  set(no_magic,1)
  set("no_clean_up", 1);
  setup();
//  drunk();
}

void drunk() {
  object *user;
  user=all_inventory(this_object());
  for (int i=0;i<sizeof(user);i++)
    if(living(user[i])) {
       user[i]->apply_condition("drunk",
            (int)user[i]->query_condition("drunk")+50); 
       tell_object(user[i],"酒香醇厚，你不禁飘然欲醉。\n");
     }
  remove_call_out("drunk");
  if (sizeof(user))  call_out("drunk",60);
}

void init() {
  add_action("do_fill","fill");
  this_player()->delete_temp("yaochi_fill");

  if (this_player()->query_temp("yaochi_open") && 
      this_player()->query("dntg/yaochi")!="done") 
     call_out("announce",2,this_player());
  drunk();
}

void announce(object me) {
  
  if (me->query("dntg/yaochi")=="done") return;
  tell_object(me,HIC"你闻到仙酒的香味，全身上下说不出的舒泰，觉得根骨有所进步！\n"NOR);
  message("channel:rumor", HIM + "【谣言】某人：听说"+
     me->query("name")+"溜进瑶池，偷喝了王母娘娘的仙酒。\n"NOR,users());
//  me->add("gift_modify/con",2);

  me->set("dntg/yaochi","done");
}

int do_fill(string arg)
{
   string liquid_name;
   string liquid_type;
   object me=this_player();
   object jiudai;

   if( !living(this_player()))  return 1;
   if (!arg || !jiudai=present(arg,me)) return notify_fail("装满什么？\n");

   if( this_player()->is_busy() )
         return notify_fail("你上一个动作还没有完成。\n");
  if (!inherits(F_LIQUID,jiudai)) return notify_fail(jiudai->query("name")+"不能用来装酒！\n");
   if(me->query_temp("yaochi_fill")) 
      return notify_fail("人心不足蛇吞象，还是见好就收吧。\n");
   me->set_temp("yaochi_fill",1);

   liquid_name = YEL"仙酒"NOR;
   liquid_type = "alcohol";

   if(jiudai->query("liquid/remaining") )
      message_vision("$N将"+jiudai->name()+"里剩下的"+
        jiudai->query("liquid/name")+"倒掉。",me);
   message_vision("$N将"+jiudai->name()+"装满"+liquid_name+"。\n",me);

   if( this_player()->is_fighting() ) this_player()->start_busy(2);

   jiudai->set("liquid/type", liquid_type);
   jiudai->set("liquid/name", liquid_name);
   jiudai->set("liquid/remaining", query("max_liquid"));
   jiudai->set("liquid/drink_func", (:effect:));

   return 1;
}

int effect() {
  object me=this_player();
  int max=(int)me->query("max_force")*2;
  this_player()->apply_condition("drunk",
     (int)this_player()->query_condition("drunk")+5);
  message_vision(HIG"$N感到体内生出缕缕内力，源源不绝。\n"NOR,me);
  
  me->add("force",200+random(100));
  if (me->query("force")>max) me->set("force",max);

  return 1;
}




