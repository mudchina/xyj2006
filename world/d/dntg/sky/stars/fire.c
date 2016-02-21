//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("ÁÒ»ð",({"star fire","fire","star"}));
  set("gender", "ÄÐÐÔ");
  set("title", "Òí»ðÐÇ¹Ù");
  set("age", 46);
  set("long", "    \nÒ»ÍÅÐÜÐÜÈ¼ÉÕµÄÁÒ»ð\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 2182331);
  set("daoxing", 2182331);
  set("kee", 1151);
  set("max_kee", 1151);
  set("sen", 1706);
  set("max_sen", 1706);
  set("force", 5083);
  set("max_force", 2542);
  set("mana", 5779);
  set("max_mana", 2890);
  set("force_factor", 136);
  set("mana_factor", 145);
  set("str", 19);
  set("per", 18);


  set_skill("buddhism", 41);
  set_skill("dao", 74);
  set_skill("dodge", 130);
  set_skill("dragonstep", 13);
  set_skill("force", 184);
  set_skill("hellfire-whip", 36);
  set_skill("jindouyun", 251);
  set_skill("jinghun-zhang", 48);
  set_skill("kusang-bang", 22);
  set_skill("literate", 141);
  set_skill("parry", 72);
  set_skill("puti-zhi", 31);
  set_skill("qianjun-bang", 255);
  set_skill("spells", 173);
  set_skill("stick", 200);
  set_skill("tonsillit", 21);
  set_skill("unarmed", 51);
  set_skill("whip", 0);
  set_skill("wuxiangforce", 181);
  set_skill("yaofa", 165);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "puti-zhi");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1;
  string weapon_id="stick";
  string armor1_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"»ðÖ¦"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"»ðÑæ¼×"NOR);
}

