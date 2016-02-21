//tomcat
//mingwang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string avenge();
string ask_chuxian();
string ask_cancel();
void create()
{
  set_name("冥王", ({"ming wang", "wang"}));
  set("long", "他便是地藏王菩萨的师兄，与地藏王势不两立，因不服天庭管束被赶出地府．终日在鬼门关附近游荡。\n");
  set("title",CYN"幽冥之王"NOR);
  set("gender", "男性");
  set("class", "youling");
  set("age", 80);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("str", 30);
  set("int", 30+random(5));
  set("max_kee", 4000);
  set("max_gin", 3500);
  set("max_sen", 3000);
  set("kee", 4000);
  set("gin", 3500);
  set("sen", 3000);

  set("force", 10000);
  set("max_force", 5000);
  set("force_factor", 300);
  set("max_mana", 6000);
  set("mana", 12000);
  set("mana_factor", 300);

  set("combat_exp", 600000);
  set("daoxing",60000000);

   set_skill("unarmed", 300);
   set_skill("whip", 300);
   set_skill("hellfire-whip", 280);
   set_skill("dodge", 250);
   set_skill("parry", 280);
   set_skill("literate", 250);
   set_skill("spells", 280);
   set_skill("force", 280);
set_skill("tonsillit", 300);
   set_skill("ghost-steps", 280);
   set_skill("gouhunshu", 280);
   set_skill("jinghun-zhang", 250);
   set_skill("kusang-bang", 250);
   set_skill("zhuihun-sword", 250);
   set_skill("sword", 290);
   set_skill("stick", 250);

  map_skill("force", "tonsillit");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("spells", "gouhunshu");
  map_skill("parry", "hellfire-whip");
  map_skill("whip", "hellfire-whip");
  map_skill("sword", "zhuihun-sword");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "whip.three" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
        }) );
 
  set_temp("apply/armor", 150);
  set_temp("apply/dodge", 150);
//  set("chat_chance", 40);
//        set("chat_msg", ({
//                (: random_move :)
//        }));
  
  create_family("阎罗地府", 1, "祖师");
  setup();
  carry_object("/d/obj/cloth/baipao")->wear();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

 
void attempt_apprentice(object ob)
{
     object me;
     
      ob->this_player();
   
   if( (int)ob->query("family/generation")==2 )  
  {
        command("say 你是地藏的徒弟？，拿命来吧!");
        message_vision ("$n大喝一声要杀死$N！\n",me,ob);
        kill_ob(ob);
        return ;
   }   

    if (ob->query("obstacle/number") < 26) {
        command("say 这位" + RANK_D->query_respect(ob) + "你还是先出去闯荡一番吧！\n");
        command("sigh");
        return;
        }

    if (((int)ob->query("daoxing") < 1000000 )) {
      command("say " + RANK_D->query_rude(ob) + "这点三脚猫的把式怎么打得过地藏王？回去练练把!");
      return;
    }
    command("grin");
    command("say 很好，" + RANK_D->query_respect(ob) +
       "多加努力，他日帮我报仇，杀了地藏王这个老匹夫。\n");
    command("recruit " + ob->query("id") );
    return;
  }

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
       ob->set("title", HBBLU"九幽鬼圣"NOR);
    ob->set("class", "youling");
}




