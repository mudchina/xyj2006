//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("九流人",({"star near","near","star"}));
  set("gender", "男性");
  set("title", "觜火星官");
  set("age", 54);
  set("long", "    \n小道士(Xiao dao)\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1492484);
  set("daoxing", 1492484);
  set("kee", 1179);
  set("max_kee", 1179);
  set("sen", 1690);
  set("max_sen", 1690);
  set("force", 4793);
  set("max_force", 2397);
  set("mana", 6143);
  set("max_mana", 3072);
  set("force_factor", 140);
  set("mana_factor", 154);
  set("str", 15);
  set("per", 14);


  set_skill("blade", 3);
  set_skill("dao", 180);
  set_skill("dodge", 152);
  set_skill("force", 200);
  set_skill("hammer", 117);
  set_skill("jindouyun", 147);
  set_skill("jinghun-zhang", 93);
  set_skill("literate", 141);
  set_skill("parry", 166);
  set_skill("puti-zhi", 36);
  set_skill("qianjun-bang", 196);
  set_skill("spells", 220);
  set_skill("stealing", 10);
  set_skill("stick", 33);
  set_skill("sword", 6);
  set_skill("throwing", 1);
  set_skill("tonsillit", 20);
  set_skill("unarmed", 116);
  set_skill("wuxiangforce", 180);
  set_skill("yaofa", 21);


map_skill("force", "wuxiangforce");
map_skill("spells", "dao");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "jinghun-zhang");
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
       my_weapon->set("name",HIY"桂树枝"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"粗布衣"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"太极道袍"NOR);
}

