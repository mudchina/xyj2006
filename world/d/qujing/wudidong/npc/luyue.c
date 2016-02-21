//lestat 瘟癀之昊天大帝 吕岳

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

/************************************************************/
void create()
{
  set_name("吕岳", ({"lu yue","luyue", "lu", "monster"}));
    set_weight(10000000);
  set("gender", "男性" );
  set("class", "yaomo" );
  set("age", 23);
  set("long", 
"吕岳原为九龙岛炼气士。后拜入碧游宫通天教主座下，万仙阵之后，\n"
"被封为瘟癀之昊天大帝之职，率领瘟部六位正神。\n");
  set("title", HIY"瘟癀之昊天大帝"NOR);
  set("combat_exp", 5000000);
  set("daoxing", 5000000);
  set("attitude", "heroic");
  create_family("陷空山无底洞", 1, "弟子");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set_skill("unarmed", 250);
  set_skill("dodge", 250);
  set_skill("parry", 280);
  set_skill("literate", 270);
  set_skill("spells", 300); 
  set_skill("yaofa", 250);
  set_skill("sword",280);
  set_skill("qixiu-jian",290);
  set_skill("blade", 300);
  set_skill("kugu-blade", 300);
  set_skill("lingfu-steps", 250);
  set_skill("yinfeng-zhua", 250);
  set_skill("force", 250);   
  set_skill("huntian-qigong", 250);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
  set("per", 50);
  set("max_kee", 5500);
  set("max_sen", 5500);
  set("force", 5800);
  set("max_force", 5000);
  set("force_factor", 500);
  set("mana",3000);
  set("max_mana", 3000);
  set("mana_factor", 500);

  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
     (: exert_function, "zhangqi" :),
    (: perform_action, "blade.diyu" :)
   }) );
  setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/npc/obj/armor")->wear();
}
/**************************************************************/

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="陷空山无底洞") {
 
 if (ob->query("obstacle/number") < 26) {
        command("say 这位" + RANK_D->query_respect(ob) + "你还是先出去闯荡一番吧！\n");
        command("sigh");
        return;
        }
  if (((int)ob->query("daoxing") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，看在地涌夫人的面子上，我就收下你了。\n");
        command("recruit " + ob->query("id") );
        return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"我不认识你吧。\n");
        return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
    ob->set("title",HIR"血饮狂刀"NOR);
}


