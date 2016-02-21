// created by smile 12/10/1998
//巡山小妖，route in baigushan
#include <ansi.h>
inherit NPC;

void create()
{
  object me=this_object();
  int i = random(5)+1;
  string str;
  set_name("巡山小妖", ({"xiao yao","yao"}));
  set("gender", "男性");
  set("age", 25);
  set("xiaoyao","xiaoyao");  
  set("combat_exp", 18000*i);
  set("attitude","aggressive");
  set("per", 8);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_sen",80*i);
  set("max_gee",80*i);
  set("max_gin",80*i);
  set("force",80*i);
  set("max_force",80*i);
  set("max_mana",80*i);
  set("force_factor",8*i);
 
  set("chat_chance",10);
  set("chat_msg",({
       "巡山小妖馋的口水都流出来了,嘿嘿，今天又有一顿美餐了。！\n",
       "巡山小妖大叫到，大王要我们拿人，今日你休想跑！\n",
       (: random_move :),
       "巡山小妖打了个响指，哈哈，今天福气了。！\n",
       "巡山小妖嘿嘿冷笑两声，今天叫你来得去不得！\n",
       (: random_move :),
  }));
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baigudong/obj/armor")->wear();
  str = "/d/qujing/baigudong/obj/weapon0";
  str[strlen(str)-1] = '0'+random(10);
  carry_object(str)->wield();
}

void init()
{
  object ob=this_player();
  call_out("greeting",1,ob);
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if(!ob->query_temp("obstacle/xiaoyao_kill"))
     {
    if (ob->query_temp("obstacle/east_from")!=0)
     {
      command("consider "+ob->query("id"));
      message_vision ("
$N道：前几天大王说有东土大唐取经的人路过，吃了可以长生不老,看来就是你!\n"+
             HIR+RANK_D->query_rude(ob)+"休走！\n" NOR,this_object(),ob);
     }
    else {
      message_vision("$N大喜道：又有一顿美餐送上门来了!\n",this_object());
         }  
      }
     this_object()->kill_ob(ob);
     ob->set_temp("obstacle/xiaoyao_kill",1);
  } 
}