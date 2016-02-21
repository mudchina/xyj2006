// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/daoren.c

inherit NPC;

void create()
{
  set_name("µÀÈË", ({"dao ren", "dao", "daoren"}));
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 20000);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",5);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);
  set_skill("unarmed", 40+random(90));
  set_skill("dodge", 40+random(90));
  set_skill("parry", 40+random(90));
  set_skill("force", 40+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


