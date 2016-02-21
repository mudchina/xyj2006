//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("魂断兰桥",({"star miner","miner","star"}));
  set("gender", "女性");
  set("title", "平天大圣");
  set("age", 29);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 11709356);
  set("daoxing", 11709356);
  set("kee", 1920);
  set("max_kee", 1920);
  set("sen", 3042);
  set("max_sen", 3042);
  set("force", 11105);
  set("max_force", 5553);
  set("mana", 12633);
  set("max_mana", 6317);
  set("force_factor", 278);
  set("mana_factor", 316);
  set("str", 28);
  set("per", 21);


  set_skill("baihua-zhang", 473);
  set_skill("dodge", 229);
  set_skill("force", 372);
  set_skill("jueqingbian", 201);
  set_skill("literate", 144);
  set_skill("moondance", 476);
  set_skill("moonforce", 371);
  set_skill("moonshentong", 388);
  set_skill("parry", 230);
  set_skill("snowsword", 475);
  set_skill("spells", 391);
  set_skill("stealing", 10);
  set_skill("stick", 3);
  set_skill("sword", 196);
  set_skill("unarmed", 184);
  set_skill("whip", 201);


map_skill("force", "moonforce");
map_skill("spells", "moonshentong");
map_skill("dodge", "moondance");
map_skill("parry", "snowsword");
map_skill("unarmed", "baihua-zhang");
map_skill("sword", "snowsword");
  set("inquiry", ([
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/ring")->wear();
carry_object(__DIR__"obj/waist")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="ring",armor2_id="waist";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","断魂剑");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"诱魂腕镯"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"护魂束腰"NOR);
}

