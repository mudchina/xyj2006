//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("ÇçÈá",({"star finesoft","finesoft","star"}));
  set("gender", "Å®ĞÔ");
  set("title", "Å®ÍÁĞÇ¹Ù");
  set("age", 29);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 988164);
  set("daoxing", 988164);
  set("kee", 1152);
  set("max_kee", 1152);
  set("sen", 1744);
  set("max_sen", 1744);
  set("force", 4720);
  set("max_force", 2360);
  set("mana", 7100);
  set("max_mana", 3550);
  set("force_factor", 118);
  set("mana_factor", 178);
  set("str", 18);
  set("per", 28);


  set_skill("baihua-zhang", 55);
  set_skill("buddhism", 44);
  set_skill("dodge", 88);
  set_skill("force", 201);
  set_skill("literate", 143);
  set_skill("moondance", 88);
  set_skill("moonforce", 136);
  set_skill("parry", 163);
  set_skill("snowsword", 162);
  set_skill("spells", 210);
  set_skill("stealing", 21);
  set_skill("sword", 53);
  set_skill("unarmed", 142);
  set_skill("yaofa", 210);


map_skill("force", "moonforce");
map_skill("spells", "yaofa");
map_skill("dodge", "moondance");
map_skill("parry", "snowsword");
map_skill("unarmed", "baihua-zhang");
map_skill("sword", "snowsword");
  set("inquiry", ([
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/armor")->wear();

}


void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","Ççºç½£");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","ÈáÔÆ¼×");
}

