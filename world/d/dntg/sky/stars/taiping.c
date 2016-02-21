//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("太平世界",({"star taiping","taiping","star"}));
  set("gender", "男性");
  set("title", "箕水星官");
  set("age", 53);
  set("long", "    \n方寸山三星洞第三代弟子  太平世界(Taiping)\n");

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1491193);
  set("daoxing", 1491193);
  set("kee", 1248);
  set("max_kee", 1248);
  set("sen", 1764);
  set("max_sen", 1764);
  set("force", 5345);
  set("max_force", 2673);
  set("mana", 6565);
  set("max_mana", 3283);
  set("force_factor", 140);
  set("mana_factor", 165);
  set("str", 16);
  set("per", 27);


  set_skill("dao", 178);
  set_skill("dodge", 159);
  set_skill("force", 200);
  set_skill("hammer", 111);
  set_skill("jindouyun", 157);
  set_skill("literate", 141);
  set_skill("parry", 168);
  set_skill("puti-zhi", 52);
  set_skill("qianjun-bang", 234);
  set_skill("spells", 226);
  set_skill("stealing", 8);
  set_skill("stick", 50);
  set_skill("unarmed", 111);
  set_skill("wuxiangforce", 180);


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
carry_object(__DIR__"obj/ring")->wear();
carry_object(__DIR__"obj/shoes")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="ring",armor2_id="shoes";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"太平金针"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"太平手表"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"太平飞靴"NOR);
}


