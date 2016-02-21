//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("青青",({"star ivan","ivan","star"}));
  set("gender", "女性");
  set("title", "通风大圣");
  set("age", 43);
  set("long", "    \n爱,认真就好\n别急着实现那些别人说的\n天荒地老\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 4342951);
  set("daoxing", 4342951);
  set("kee", 1360);
  set("max_kee", 1360);
  set("sen", 2725);
  set("max_sen", 2725);
  set("force", 6499);
  set("max_force", 3250);
  set("mana", 10959);
  set("max_mana", 5480);
  set("force_factor", 150);
  set("mana_factor", 275);
  set("str", 16);
  set("per", 23);


  set_skill("baihua-zhang", 176);
  set_skill("buddhism", 41);
  set_skill("dodge", 225);
  set_skill("force", 200);
  set_skill("ghost-steps", 153);
  set_skill("jueqingbian", 155);
  set_skill("literate", 125);
  set_skill("moondance", 352);
  set_skill("moonforce", 200);
  set_skill("ningxie-force", 21);
  set_skill("parry", 154);
  set_skill("snowsword", 352);
  set_skill("spells", 309);
  set_skill("sword", 206);
  set_skill("tonsillit", 7);
  set_skill("unarmed", 140);
  set_skill("whip", 59);
  set_skill("yaofa", 309);
  set_skill("zhuihun-sword", 1);


map_skill("force", "moonforce");
map_skill("spells", "yaofa");
map_skill("dodge", "moondance");
map_skill("parry", "snowsword");
map_skill("unarmed", "baihua-zhang");
map_skill("sword", "snowsword");
  set("inquiry", ([
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"青女剑"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"吹笳明月带"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"倚剑白云衣"NOR);
}

