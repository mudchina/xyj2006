//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("法徐",({"star ziling","ziling","star"}));
  set("gender", "男性");
  set("title", "斗木星官");
  set("age", 51);

  set("attitude", "heroism");
  set("class", "bonze");
  set("combat_exp", 1524566);
  set("daoxing", 1524566);
  set("kee", 1204);
  set("max_kee", 1204);
  set("sen", 2149);
  set("max_sen", 2149);
  set("force", 5761);
  set("max_force", 2881);
  set("mana", 8439);
  set("max_mana", 4220);
  set("force_factor", 142);
  set("mana_factor", 212);
  set("str", 23);
  set("per", 28);


  set_skill("baguazhen", 99);
  set_skill("bawang-qiang", 46);
  set_skill("buddhism", 200);
  set_skill("dodge", 151);
  set_skill("force", 180);
  set_skill("fumo-zhang", 78);
  set_skill("huoyun-qiang", 127);
  set_skill("jienan-zhi", 106);
  set_skill("kusang-bang", 11);
  set_skill("literate", 121);
  set_skill("lotusforce", 195);
  set_skill("lotusmove", 243);
  set_skill("lunhui-zhang", 256);
  set_skill("parry", 135);
  set_skill("spear", 62);
  set_skill("spells", 204);
  set_skill("staff", 201);
  set_skill("taiyi", 50);
  set_skill("tonsillit", 10);
  set_skill("unarmed", 109);
  set_skill("yaofa", 13);


map_skill("force", "lotusforce");
map_skill("spells", "buddhism");
map_skill("dodge", "lotusmove");
map_skill("parry", "lunhui-zhang");
map_skill("unarmed", "jienan-zhi");
map_skill("staff", "lunhui-zhang");
map_skill("spear", "huoyun-qiang");
  set("inquiry", ([
      "name" : "老纳俗家名字徐子陵，法号法徐。",
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/staff")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/shoes")->wear();

}


void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="staff";
  string armor1_id="shoes",armor2_id="waist";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"天天的大腿骨"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"青青的脚掌骨"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"青青血骷髅"NOR);
}

