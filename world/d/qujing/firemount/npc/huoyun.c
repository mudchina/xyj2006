// tomcat
 
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
// inherit SKILL;

void create()
{
  set_name("祝融氏", ({"zhurong shi", "zhurong", "shi"}));
   
  set("title", HIR"火魔"NOR);
  set("gender", "男性");
  set("age", 43);
  set("str", 45);
  set("per", 35);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
  set("combat_exp", 9000000);
  set_skill("spear", 300);
  set_skill("force", 280);
  set_skill("dodge", 250);
  set_skill("parry", 250);
  set_skill("unarmed", 250);
  set_skill("huoyun-qiang", 280);
  set_skill("literate", 290);
  set_skill("stick", 300);
  set_skill("dali-bang", 290);
  set_skill("spells", 300);
  set_skill("pingtian-dafa", 300);
  set_skill("moshenbu", 280);
  set_skill("huomoforce", 300);
  set_skill("moyun-shou", 250);
  map_skill("force", "huomoforce");
  map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("spear", "huoyun-qiang");
  map_skill("parry", "huoyun-qiang");
  map_skill("dodge", "moshenbu");
  set("max_sen", 6000);
  set("max_kee", 8000);
set("force", 10000);
set("max_force", 6000);
set("mana",2000);
set("max_mana",1000);
set("daoxing",50000);
set("force_factor", 200);
set("force_mana", 100);
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
		(: perform_action, "spear", "huohun" :),
		(: perform_action, "unarmed", "zhangxinlei" :),
		(: perform_action, "spear", "lihuo" :),
		(: perform_action, "spear", "ji" :),
  }) );
 
  create_family("火云洞", 1, "蓝");
  setup();
 
  carry_object("d/obj/weapon/spear/huomoqiang")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}
 
void attempt_apprentice(object ob)
{  
    
    ob=this_player();
   
   if( (string)ob->query("family/family_name")!="火云洞") {
        command("say  我不认识你。\n");
       return;
      }
    
      if ((int)ob->query("daoxing") < 1000000 ) {
       command("say 你道行太低了。\n");
       return;
      }

  if (ob->query("obstacle/number") < 25) {
        command("say 这位" + RANK_D->query_respect(ob) + "拜我为师，要先先历尽取
经劫难！\n");
        command("sigh");
        return;
        }

        if( (int)ob->query_skill("huomoforce", 1) < 180 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "想做我火魔的传人，你的火魔心法还不够！\n");
        command("sigh");
        return;
        }

  command("recruit " + ob->query("id") );
  return ;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
    ob->set("title",HBRED"火云邪神"NOR);
}
