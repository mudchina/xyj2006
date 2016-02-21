//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("√˜œ√",({"star feixiao","feixiao","star"}));
  set("gender", "ƒ––‘");
  set("title", "¡¯Õ¡–«Àﬁ");
  set("age", 60);
  set("long", "    \n$n$r\n");

  set("attitude", "heroism");
  set("class", "bonze");
  set("combat_exp", 1236121);
  set("daoxing", 1236121);
  set("kee", 1141);
  set("max_kee", 1141);
  set("sen", 1660);
  set("max_sen", 1660);
  set("force", 5389);
  set("max_force", 2695);
  set("mana", 6623);
  set("max_mana", 3312);
  set("force_factor", 140);
  set("mana_factor", 166);
  set("str", 18);
  set("per", 10);


  set_skill("bawang-qiang", 213);
  set_skill("buddhism", 184);
  set_skill("changquan", 26);
  set_skill("dodge", 138);
  set_skill("force", 201);
  set_skill("lengquan-force", 180);
  set_skill("literate", 141);
  set_skill("lotusmove", 138);
  set_skill("mace", 113);
  set_skill("parry", 181);
  set_skill("spear", 158);
  set_skill("spells", 176);
  set_skill("tonsillit", 5);
  set_skill("unarmed", 51);
  set_skill("whip", 64);
  set_skill("wusi-mace", 132);
  set_skill("yanxing-steps", 127);
  set_skill("yaofa", 12);


map_skill("force", "lengquan-force");
map_skill("spells", "buddhism");
map_skill("dodge", "lotusmove");
map_skill("parry", "bawang-qiang");
map_skill("unarmed", "changquan");
map_skill("spear", "bawang-qiang");
  set("inquiry", ([
]));


setup();
carry_object(__DIR__"obj/spear")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="spear";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"±Ã”Ò–∞—˝"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"±Ã”Òª∑"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"±Ã”Ò»¶"NOR);
}

