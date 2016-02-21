#include <ansi.h>
inherit NPC;

void create()
{
  object me=this_object();
  int i = random(5)+10;
  string str;
   set_name("妖怪", ({"yao guai","guai"}));
  set("gender", "男性");
  set("age", 25);
  set("yaoguai","yaoguai");  
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
         "妖怪嘴里嘟嘟囔囔的也不知道在说些什么！\n",
  }));

  setup();
  carry_object("/d/obj/armor/tongjia")->wear();
carry_object("/d/obj/weapon/fork/fork")->wield();
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
    if(!ob->query_temp("obstacle/yaogui_kill"))
     {
    if (ob->query_temp("obstacle/east_from")!=0)
     {
      command("consider "+ob->query("id"));
        message_vision ("$N道：什么人？\n"+HIR+RANK_D->query_rude(ob)+"休走！\n" NOR,this_object(),ob);
     }
    else {
        message_vision("$N道：我要吃了你,嘿嘿!\n",this_object());
         }  
      }
     this_object()->kill_ob(ob);
     ob->set_temp("obstacle/xiaoyao_kill",1);
  } 
}

