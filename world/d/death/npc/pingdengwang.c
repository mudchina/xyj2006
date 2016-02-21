//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
  set_name("Æ½µÈÍõ", ({"pingdeng wang", "wang", "pingdeng"}));
  set("title", "Òõ¼äÊ®ÍõÖ®");
  set("gender", "ÄÐÐÔ");
  set("age", 70);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 900);
  set("max_gin", 600);
  set("max_sen", 600);
  set("force", 650);
  set("max_force", 1000);
  set("force_factor", 35);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 700000);
  set("daoxing", 600000);

  set_skill("unarmed", 130);
  set_skill("dodge", 130);
  set_skill("parry", 130);
  set_skill("spells", 130);
  set_skill("jinghun-zhang", 120);
  set_skill("ghost-steps", 100);
  set_skill("force", 130);
  set_skill("gouhunshu", 100);
  set_skill("tonsillit", 100);
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  
  create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

ÿ
