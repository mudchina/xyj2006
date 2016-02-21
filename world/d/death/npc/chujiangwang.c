//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
  set_name("³þ½­Íõ", ({"chujiang wang", "wang", "chujiang"}));
  set("title", "Òõ¼äÊ®ÍõÖ®");
  set("gender", "ÄÐÐÔ");
  set("age", 80);
  set("class", "youling");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 900);
  set("max_gin", 900);
  set("max_sen", 900);
  set("force", 1150);
  set("max_force", 1000);
  set("force_factor", 50);
  set("max_mana", 1000);
  set("mana", 1000);
  set("mana_factor", 40);
  set("combat_exp", 720000);
  set("daoxing", 600000);

  set_skill("unarmed", 150);
  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("spells", 150);
  set_skill("force", 150);
  set_skill("gouhunshu", 100);
  set_skill("tonsillit", 100);
  set_skill("ghost-steps", 100);
  set_skill("jinghun-zhang", 120);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  
  create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

ÿ
