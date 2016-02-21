//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("游客",({"star youke","youke","star"}));
  set("gender", "男性");
  set("title", "井木星官");
  set("age", 73);
  set("long", "    \n持国天王  掌紫金龙花狐貂　职顺\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1451258);
  set("daoxing", 1451258);
  set("kee", 1395);
  set("max_kee", 1395);
  set("sen", 1851);
  set("max_sen", 1851);
  set("force", 6519);
  set("max_force", 3260);
  set("mana", 7501);
  set("max_mana", 3751);
  set("force_factor", 140);
  set("mana_factor", 188);
  set("str", 21);
  set("per", 10);


  set_skill("blade", 201);
  set_skill("dao", 180);
  set_skill("dodge", 161);
  set_skill("force", 202);
  set_skill("jienan-zhi", 167);
  set_skill("jindouyun", 181);
  set_skill("liangyi-sword", 64);
  set_skill("literate", 150);
  set_skill("ningxie-force", 40);
  set_skill("parry", 208);
  set_skill("qianjun-bang", 201);
  set_skill("spells", 235);
  set_skill("stick", 150);
  set_skill("unarmed", 193);
  set_skill("wuxiangforce", 180);
  set_skill("yange-blade", 201);
  set_skill("zhuihun-sword", 42);


map_skill("force", "wuxiangforce");
map_skill("spells", "dao");
map_skill("dodge", "jindouyun");
map_skill("parry", "yange-blade");
map_skill("unarmed", "jienan-zhi");
map_skill("stick", "qianjun-bang");
map_skill("blade", "yange-blade");
  set("inquiry", ([
]));


setup();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/ring")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="armor",armor2_id="ring";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","木棒");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"布衣"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"戒指"NOR);
}

