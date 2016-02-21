//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("蜗蜗",({"star vovo","vovo","star"}));
  set("gender", "男性");
  set("title", "房日星官");
  set("age", 0);
  set("long", "    \n蜗蜗浴朝阳，饮晨曦，傲然而立，仰天长吟：\n　　神龟虽寿，猷有竟时。腾蛇乘雾，终为土灰。\n　　老骥伏枥，志在千里；烈士暮年，壮心不已。\n　　盈缩之期，不但在天；养怡之福，可得永年。\n他迎风傲立船首，望滚滚江水东逝，只觉得天下英雄舍我其谁。\n");

  set("attitude", "heroism");
  set("class", "fighter");
  set("combat_exp", 726749);
  set("daoxing", 726749);
  set("kee", 732);
  set("max_kee", 732);
  set("sen", 106);
  set("max_sen", 106);
  set("force", 1239);
  set("max_force", 620);
  set("mana", 3859);
  set("max_mana", 1930);
  set("force_factor", 31);
  set("mana_factor", 97);
  set("str", 21);
  set("per", 28);


  set_skill("baguazhou", 95);
  set_skill("bawang-qiang", 66);
  set_skill("blade", 21);
  set_skill("buddhism", 41);
  set_skill("dodge", 18);
  set_skill("force", 44);
  set_skill("lengquan-force", 40);
  set_skill("literate", 65);
  set_skill("parry", 61);
  set_skill("spear", 61);
  set_skill("spells", 148);
  set_skill("stealing", 17);
  set_skill("sword", 51);
  set_skill("taiyi", 26);
  set_skill("unarmed", 51);
  set_skill("whip", 21);


map_skill("force", "lengquan-force");
map_skill("spells", "baguazhou");
map_skill("dodge", "none");
map_skill("parry", "bawang-qiang");
map_skill("unarmed", "none");
map_skill("spear", "bawang-qiang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/spear")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="spear";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","小白菜∝∝∝");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","大小老婆♀♀");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","铜板⊙⊙⊙⊙");
}
