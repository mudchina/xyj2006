//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("雪星",({"star xuexing","xuexing","star"}));
  set("gender", "男性");
  set("title", "覆海大圣");
  set("age", 27);

  set("attitude", "heroism");
  set("class", "youling");
  set("combat_exp", 2844814);
  set("daoxing", 2844814);
  set("kee", 1657);
  set("max_kee", 1657);
  set("sen", 2304);
  set("max_sen", 2304);
  set("force", 8999);
  set("max_force", 4500);
  set("mana", 8779);
  set("max_mana", 4390);
  set("force_factor", 202);
  set("mana_factor", 220);
  set("str", 23);
  set("per", 20);


  set_skill("baguazhen", 160);
  set_skill("buddhism", 44);
  set_skill("cuixin-zhang", 200);
  set_skill("dodge", 208);
  set_skill("force", 201);
  set_skill("ghost-steps", 306);
  set_skill("gouhunshu", 26);
  set_skill("hellfire-whip", 291);
  set_skill("jinghun-zhang", 304);
  set_skill("kusang-bang", 175);
  set_skill("literate", 142);
  set_skill("ningxie-force", 43);
  set_skill("parry", 172);
  set_skill("spells", 240);
  set_skill("stick", 166);
  set_skill("sword", 150);
  set_skill("tonsillit", 305);
  set_skill("unarmed", 200);
  set_skill("whip", 185);
  set_skill("yaofa", 236);
  set_skill("zhuihun-sword", 41);


map_skill("force", "tonsillit");
map_skill("spells", "yaofa");
map_skill("dodge", "ghost-steps");
map_skill("parry", "jinghun-zhang");
map_skill("unarmed", "jinghun-zhang");
map_skill("whip", "hellfire-whip");
  set("inquiry", ([
]));


setup();
carry_object("/d/obj/cloth/jinpao.c")->wear();
carry_object(__DIR__"obj/whip");
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="whip";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIC"神鞭"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIW"雪色"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",BLK"铁衣"NOR);
}

