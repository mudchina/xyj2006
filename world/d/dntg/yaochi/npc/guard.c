
#include <ansi.h>
inherit NPC;

void create()
{
  string name, id;

  set_name("金甲卫士", ({ "jinjia weishi", "guard", "weishi" }) );
  set("gender", "男性" );
  set("long", "

一名威风凛凛的天将，奉王母之命，看守瑶池。
尽忠职守，不会将任何没有请柬的人私放入内。
");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 80);
  set("int", 25);
  set("per",21);
  set("combat_exp",100000);
  set("daoxing",100000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 50);
  set("max_kee", 900);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",99);
  set_skill("dodge",99);
  set_skill("parry",99);
  set_skill("spear",99);
  set_skill("stick",99);
  set_skill("sword",99);
  set_skill("axe",99);
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  switch(random(4)) {
     case 0:
            carry_object("/d/obj/weapon/stick/bintiegun")->wield();
            break;
     case 1:
            carry_object("/d/obj/weapon/sword/tiejian")->wield();
            break;
     case 2:
            carry_object("/d/obj/weapon/spear/tieqiang")->wield();
            break;
     default :
            carry_object("/d/obj/weapon/axe/bigaxe")->wield();
            break;
  }
}

void unconcious() {die();}

int accept_object(object me, object ob)
{

   if ((string)ob->query("id")!="invitation letter") return 0;
   call_out("verify",1,me);  
   return 1;
}      

void verify(object me) {

  if (me->name()!="赤脚大仙") {
    tell_object(me,"你一抬头，发现金甲卫士正把一道锐利的目光向你投来。\n");
    command("hmm");
    command("say 这张请柬明明是给赤脚大仙的，怎么到了你的手里？！");
    message_vision(CYN"$N吓得魂不附体，颤身说道：“我捡的，我地上捡的，我。。”\n"+
        "话没说完，就一溜烟地躲进了角落。\n"NOR,me);
    return;
  }

  command("say 原来是赤脚大仙驾到。");
  command("bow daxian");
  command("say 快里边请。。。");
  me->set_temp("yaochi_pass",2);
}
