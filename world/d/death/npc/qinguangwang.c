//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
  set_name("ÇØ¹ãÍõ", ({"qinguang wang", "wang", "qinguang"}));
  set("title", "Òõ¼äÊ®ÍõÖ®");
  set("gender", "ÄÐÐÔ");
  set("age", 60);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 850);
  set("max_force", 800);
  set("force_factor", 60);
  set("max_mana", 800);
  set("mana", 1000);
  set("mana_factor", 30);
  set("combat_exp", 800000);
  set("daoxing", 700000);

  set_skill("unarmed", 140);
  set_skill("jinghun-zhang", 120);
  set_skill("dodge", 140);
  set_skill("parry", 140);
  set_skill("gouhunshu", 100);
  set_skill("tonsillit", 100);
  set_skill("spells", 120);
  set_skill("force", 120);
  set_skill("ghost-steps", 100);
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  create_family("ÑÖÂÞµØ¸®", 2, "ÄãºÃ");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  //        carry_object("/d/lingtai/obj/shoe")->wear();
  //        carry_object("/d/lingtai/obj/putibang")->wield();
}
void attempt_apprentice(object ob, object me)
{
  if (((int)ob->query("combat_exp") < 50000 )) {
    command("say " + RANK_D->query_rude(ob) + "¹¦µ×Èç´ËÖ®²î£¬²»Åä×öÎÒÍ½µÜ£¡");
    return;
  }
  command("haha");
  command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
	  "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
  command("recruit " + ob->query("id") );
  return;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "youling");
}

ÿ
