//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("爱天",({"star lovesky","lovesky","star"}));
  set("gender", "男性");
  set("title", "轸水星官");
  set("age", 51);
  set("long", "    \n此三天,乃取自子曰:三人行必有我师之意.\n");

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 1546018);
  set("daoxing", 1546018);
  set("kee", 1043);
  set("max_kee", 1043);
  set("sen", 1785);
  set("max_sen", 1785);
  set("force", 3959);
  set("max_force", 1980);
  set("mana", 7179);
  set("max_mana", 3590);
  set("force_factor", 98);
  set("mana_factor", 180);
  set("str", 31);
  set("per", 11);


  set_skill("baguazhou", 11);
  set_skill("blade", 201);
  set_skill("buddhism", 42);
  set_skill("dodge", 108);
  set_skill("force", 163);
  set_skill("gouhunshu", 13);
  set_skill("hellfire-whip", 78);
  set_skill("huntian-qigong", 51);
  set_skill("huoyun-qiang", 0);
  set_skill("jinghun-zhang", 49);
  set_skill("kugu-blade", 201);
  set_skill("kusang-bang", 49);
  set_skill("literate", 141);
  set_skill("lotusforce", 116);
  set_skill("ningxie-force", 21);
  set_skill("parry", 162);
  set_skill("qianjun-bang", 23);
  set_skill("qixiu-jian", 36);
  set_skill("spells", 223);
  set_skill("stealing", 48);
  set_skill("stick", 4);
  set_skill("throwing", 55);
  set_skill("unarmed", 140);
  set_skill("whip", 67);
  set_skill("yaofa", 222);
  set_skill("yinfeng-zhua", 122);


map_skill("force", "lotusforce");
map_skill("spells", "yaofa");
map_skill("dodge", "kugu-blade");
map_skill("parry", "kugu-blade");
map_skill("unarmed", "yinfeng-zhua");
map_skill("blade", "kugu-blade");
  set("inquiry", ([
]));


setup();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"屠龙刀"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"屠龙甲"NOR);
}

