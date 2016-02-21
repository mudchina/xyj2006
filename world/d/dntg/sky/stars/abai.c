//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("º«°Ø",({"star abai","abai","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "Î¸ÍÁÐÇ¹Ù");
  set("age", 51);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 1267587);
  set("daoxing", 1267587);
  set("kee", 1259);
  set("max_kee", 1259);
  set("sen", 1774);
  set("max_sen", 1774);
  set("force", 5435);
  set("max_force", 2718);
  set("mana", 6245);
  set("max_mana", 3123);
  set("force_factor", 114);
  set("mana_factor", 157);
  set("str", 29);
  set("per", 13);


  set_skill("blade", 21);
  set_skill("dodge", 142);
  set_skill("force", 187);
  set_skill("ghost-steps", 236);
  set_skill("gouhunshu", 155);
  set_skill("hellfire-whip", 236);
  set_skill("huntian-qigong", 0);
  set_skill("jinghun-zhang", 173);
  set_skill("kugu-blade", 122);
  set_skill("kusang-bang", 90);
  set_skill("literate", 142);
  set_skill("ningxie-force", 45);
  set_skill("parry", 148);
  set_skill("spells", 185);
  set_skill("tonsillit", 136);
  set_skill("unarmed", 140);
  set_skill("whip", 201);
  set_skill("yaofa", 5);


map_skill("force", "tonsillit");
map_skill("spells", "gouhunshu");
map_skill("dodge", "ghost-steps");
map_skill("parry", "hellfire-whip");
map_skill("unarmed", "jinghun-zhang");
map_skill("whip", "hellfire-whip");
  set("inquiry", ([
]));


setup();
carry_object(__DIR__"obj/whip")->wield();
carry_object(__DIR__"obj/armor")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="whip";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"Æ¤±Þ"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"°×ÂÞÅÛ"NOR);
}

