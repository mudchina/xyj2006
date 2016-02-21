//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("Áé",({"star lwq","lwq","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "±ÏÔÂÐÇ¹Ù");
  set("age", 65);
  set("long", "    \n$NºÍ$n\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1006693);
  set("daoxing", 1006693);
  set("kee", 1152);
  set("max_kee", 1152);
  set("sen", 1695);
  set("max_sen", 1695);
  set("force", 5599);
  set("max_force", 2800);
  set("mana", 6759);
  set("max_mana", 3380);
  set("force_factor", 140);
  set("mana_factor", 170);
  set("str", 15);
  set("per", 25);


  set_skill("dao", 178);
  set_skill("dodge", 123);
  set_skill("force", 201);
  set_skill("jindouyun", 178);
  set_skill("literate", 127);
  set_skill("moonforce", 14);
  set_skill("ningxie-force", 21);
  set_skill("parry", 143);
  set_skill("puti-zhi", 148);
  set_skill("qianjun-bang", 197);
  set_skill("snowsword", 124);
  set_skill("spells", 190);
  set_skill("stick", 101);
  set_skill("sword", 48);
  set_skill("taiyi", 49);
  set_skill("unarmed", 137);
  set_skill("wuxiangforce", 180);
  set_skill("zhuihun-sword", 35);


map_skill("force", "wuxiangforce");
map_skill("spells", "dao");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "puti-zhi");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
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
       my_weapon->set("name","µ¶½£");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","µ¶");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","½£");
}

