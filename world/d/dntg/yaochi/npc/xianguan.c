
#define DONGLANG "/d/dntg/yaochi/donglang"
#include <ansi.h>

inherit NPC;

void create()
{

  set_name("造酒仙官",({ "zaojiu xianguan","xianguan","xian" }) );
  set("can_sleep",1);
  set("gender", "男性" );
  set("long", "一位紫绶金章芙蓉冠的仙长，正在酒缸前忙碌着。\n");
  set("age", 100+random(100));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",40000);
  set("combat_exp",40000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_kee", 4000);
  set("max_sen", 4000);
  set("max_mana", 4000);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",150);
  set_skill("dodge",100);
  set_skill("parry",200);
  set_skill("spear",100);
  set_skill("force",100);
  set("no_get","造酒仙官对你而言太重了。\n");
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}

void heart_beat() {
   object env,me=this_object();       
   set("eff_kee", 4000);
   set("eff_sen", 4000);
   set("kee",4000);
   set("sen",4000);
   set("force",500);
       
   ::heart_beat();
  
  if (!env=environment(me)) return;
  
  if (!living(me)) return;
//  message_vision("$N is a living.\n",me);
  if (!env->query("xianguan")) {
    message_vision("$N匆匆忙忙地离开了。\n",this_object());
    if (this_object()->move(DONGLANG)) 
        message_vision("$N快步走了过来。\n",this_object());
    else destruct(this_object());
  }
}

