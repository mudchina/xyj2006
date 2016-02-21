//【三界散仙】lestat 2001/8
// 鬼谷子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("鬼谷子", ({ "gui guzi", "guzi", "gui" }));
//        set("title","");
        set("long", 
"传说中的神仙，满头白发的老人，两眼炯炯有神。\n");

        set("gender", "男性");
        set("age", 665);
        set("attitude", "peaceful");
        set("str", 100);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","sanxian");
        
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 15000);
        set("max_force", 8000);
        set("max_mana",8000);
        set("mana",12000);
        set("force_factor", 500);
        set("mana_factor", 500);
        set("combat_exp", 50000000);
        set("daoxing", 50000000);

        set_skill("spells",300);
        set_skill("force", 290);
        set_skill("dodge", 290);
        set_skill("parry", 300);
        set_skill("sword", 290);   
        set_skill("binfen-steps", 280);        
        set_skill("literate", 280);
        set_skill("ice_fire_zhang", 280);
        set_skill("unarmed", 280);
        set_skill("whip", 280);
        set_skill("butian-force", 280);
        set_skill("mysticism", 280);
        set_skill("wuwei-fuchen", 280);
        set_skill("spysword", 280);        
        map_skill("dodge", "binfen-steps");        
        map_skill("parry", "spysword");
        map_skill("sword", "spysword");
        map_skill("force", "spysword");
        map_skill("spells", "mysticism");
         map_skill("unarmed", "ice_fire_zhang");
        


        create_family("三界散仙", 1, " 白");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword","dunnoname" :),
                              
        }) );
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);
   add_temp("apply/armor_vs_force",250);
   add_temp("apply/armor_vs_spells",250);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
int is_ghost() { return 1; }

void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="三界散仙") {
if (ob->query("obstacle/number") < 26) {
command("say 这位" + RANK_D->query_respect(ob) + "拜我为师，要先先历尽取经劫难！\n");
 command("sigh");
 return;
}
  if (((int)ob->query("daoxing") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
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
   ob->set("class", "sanxian");
   ob->set("title",HIB"鬼谷子传人"NOR);
   }




