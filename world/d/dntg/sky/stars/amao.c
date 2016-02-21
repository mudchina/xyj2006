//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("ÆßÈÐ",({"star wxyz","wxyz","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "¹í½ðÐÇ¹Ù");
  set("age", 59);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 2197634);
  set("daoxing", 2197634);
  set("kee", 1307);
  set("max_kee", 1307);
  set("sen", 2409);
  set("max_sen", 2409);
  set("force", 5815);
  set("max_force", 2908);
  set("mana", 9859);
  set("max_mana", 4930);
  set("force_factor", 144);
  set("mana_factor", 247);
  set("str", 29);
  set("per", 11);


  set_skill("blade", 199);
  set_skill("buddhism", 42);
  set_skill("dodge", 116);
  set_skill("force", 201);
  set_skill("hellfire-whip", 3);
  set_skill("huntian-qigong", 189);
  set_skill("kugu-blade", 263);
  set_skill("lingfu-steps", 1);
  set_skill("literate", 141);
  set_skill("moonforce", 11);
  set_skill("parry", 108);
  set_skill("qixiu-jian", 197);
  set_skill("snowsword", 4);
  set_skill("spells", 278);
  set_skill("stealing", 9);
  set_skill("sword", 161);
  set_skill("tonsillit", 7);
  set_skill("unarmed", 51);
  set_skill("xiaofeng-sword", 153);
  set_skill("yaofa", 270);
  set_skill("yinfeng-zhua", 38);


map_skill("force", "huntian-qigong");
map_skill("spells", "yaofa");
map_skill("dodge", "kugu-blade");
map_skill("parry", "kugu-blade");
map_skill("unarmed", "yinfeng-zhua");
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
       my_weapon->set("name",HIY"ÑªÁÜÁÜµÄ¿Ý¹Ç"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","ÈËÆ¤");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"Í·¸Ç¹Ç"NOR);
}

