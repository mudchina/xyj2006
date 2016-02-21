//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("神话世界",({"star lisa","lisa","star"}));
  set("gender", "男性");
  set("title", "室火星官");
  set("age", 30);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1214162);
  set("daoxing", 1214162);
  set("kee", 1058);
  set("max_kee", 1058);
  set("sen", 1817);
  set("max_sen", 1817);
  set("force", 4209);
  set("max_force", 2105);
  set("mana", 6665);
  set("max_mana", 3333);
  set("force_factor", 118);
  set("mana_factor", 167);
  set("str", 19);
  set("per", 10);


  set_skill("baguazhen", 161);
  set_skill("blade", 113);
  set_skill("buddhism", 47);
  set_skill("cuixin-zhang", 94);
  set_skill("dodge", 87);
  set_skill("force", 146);
  set_skill("hammer", 1);
  set_skill("literate", 142);
  set_skill("parry", 160);
  set_skill("qianjun-bang", 160);
  set_skill("spells", 209);
  set_skill("stick", 39);
  set_skill("sword", 2);
  set_skill("taiyi", 42);
  set_skill("unarmed", 67);
  set_skill("whip", 33);
  set_skill("yange-blade", 191);
  set_skill("yaofa", 201);
  set_skill("zhenyuan-force", 164);


map_skill("force", "zhenyuan-force");
map_skill("spells", "taiyi");
map_skill("dodge", "baguazhen");
map_skill("parry", "yange-blade");
map_skill("unarmed", "cuixin-zhang");
map_skill("blade", "yange-blade");
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
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"袖里乾坤"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"苍茫云海间"NOR);
}


