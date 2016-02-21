//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("风间准",({"star fjz","fjz","star"}));
  set("gender", "男性");
  set("title", "驱神大圣");
  set("age", 29);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 5108691);
  set("daoxing", 5108691);
  set("kee", 1123);
  set("max_kee", 1123);
  set("sen", 2340);
  set("max_sen", 2340);
  set("force", 4599);
  set("max_force", 2300);
  set("mana", 9441);
  set("max_mana", 4721);
  set("force_factor", 144);
  set("mana_factor", 237);
  set("str", 16);
  set("per", 22);


  set_skill("buddhism", 41);
  set_skill("cuixin-zhang", 142);
  set_skill("dao", 48);
  set_skill("dodge", 221);
  set_skill("force", 200);
  set_skill("ghost-steps", 153);
  set_skill("hellfire-whip", 185);
  set_skill("jindouyun", 249);
  set_skill("kusang-bang", 160);
  set_skill("literate", 142);
  set_skill("parry", 201);
  set_skill("qianjun-bang", 255);
  set_skill("spells", 370);
  set_skill("stick", 202);
  set_skill("sword", 204);
  set_skill("tonsillit", 1);
  set_skill("unarmed", 190);
  set_skill("whip", 91);
  set_skill("wuxiangforce", 188);
  set_skill("yaofa", 258);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "ghost-steps");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "cuixin-zhang");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"红"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"风"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"雨"NOR);
}

