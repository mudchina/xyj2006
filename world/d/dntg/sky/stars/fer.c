//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("Ììô¥",({"star fer","fer","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "ÐéÈÕÐÇ¹Ù");
  set("age", 36);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 2414774);
  set("daoxing", 2414774);
  set("kee", 1312);
  set("max_kee", 1312);
  set("sen", 2211);
  set("max_sen", 2211);
  set("force", 5859);
  set("max_force", 2930);
  set("mana", 8157);
  set("max_mana", 4079);
  set("force_factor", 142);
  set("mana_factor", 204);
  set("str", 20);
  set("per", 20);


  set_skill("blade", 275);
  set_skill("buddhism", 41);
  set_skill("dodge", 222);
  set_skill("force", 210);
  set_skill("huntian-qigong", 180);
  set_skill("jienan-zhi", 210);
  set_skill("kugu-blade", 248);
  set_skill("liangyi-sword", 20);
  set_skill("literate", 141);
  set_skill("moyun-shou", 211);
  set_skill("parry", 200);
  set_skill("qixiu-jian", 212);
  set_skill("snowsword", 40);
  set_skill("spells", 278);
  set_skill("stealing", 210);
  set_skill("sword", 216);
  set_skill("throwing", 100);
  set_skill("tonsillit", 11);
  set_skill("unarmed", 211);
  set_skill("yange-blade", 245);
  set_skill("yaofa", 200);
  set_skill("yinfeng-zhua", 210);


map_skill("force", "huntian-qigong");
map_skill("spells", "yaofa");
map_skill("dodge", "kugu-blade");
map_skill("parry", "kugu-blade");
map_skill("unarmed", "jienan-zhi");
map_skill("blade", "kugu-blade");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"¿ÝÊ÷¸ù"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"¿ÝÊ÷Æ¤"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"¿ÝÊ÷Ò¶"NOR);
}

