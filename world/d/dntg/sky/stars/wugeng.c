//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("ÎÞ¸ù",({"star wugeng","wugeng","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "Å£½ðÐÇ¹Ù");
  set("age", 33);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1366541);
  set("daoxing", 1366541);
  set("kee", 1285);
  set("max_kee", 1285);
  set("sen", 2084);
  set("max_sen", 2084);
  set("force", 5899);
  set("max_force", 2950);
  set("mana", 7599);
  set("max_mana", 3800);
  set("force_factor", 123);
  set("mana_factor", 191);
  set("str", 18);
  set("per", 12);


  set_skill("buddhism", 43);
  set_skill("dodge", 203);
  set_skill("force", 172);
  set_skill("jindouyun", 202);
  set_skill("literate", 142);
  set_skill("parry", 170);
  set_skill("qianjun-bang", 201);
  set_skill("spells", 215);
  set_skill("stick", 121);
  set_skill("unarmed", 71);
  set_skill("whip", 23);
  set_skill("wuxiangforce", 161);
  set_skill("yaofa", 210);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "none");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/waist")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="waist";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","Öñ¸Í");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","Ê÷Æ¤");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"²ÝÉþ"NOR);
}


