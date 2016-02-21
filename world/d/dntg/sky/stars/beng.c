//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("文十五",({"star beng","beng","star"}));
  set("gender", "男性");
  set("title", "壁水星官");
  set("age", 39);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1579579);
  set("daoxing", 1579579);
  set("kee", 1133);
  set("max_kee", 1133);
  set("sen", 1674);
  set("max_sen", 1674);
  set("force", 4617);
  set("max_force", 2309);
  set("mana", 5793);
  set("max_mana", 2897);
  set("force_factor", 162);
  set("mana_factor", 145);
  set("str", 23);
  set("per", 14);


  set_skill("baguazhen", 146);
  set_skill("buddhism", 38);
  set_skill("dao", 136);
  set_skill("dodge", 165);
  set_skill("force", 212);
  set_skill("fork", 0);
  set_skill("hellfire-whip", 11);
  set_skill("jindouyun", 216);
  set_skill("jinghun-zhang", 197);
  set_skill("kusang-bang", 75);
  set_skill("literate", 139);
  set_skill("ningxie-force", 18);
  set_skill("parry", 247);
  set_skill("qianjun-bang", 203);
  set_skill("snowsword", 11);
  set_skill("spells", 200);
  set_skill("stealing", 3);
  set_skill("stick", 99);
  set_skill("sword", 100);
  set_skill("tonsillit", 84);
  set_skill("unarmed", 157);
  set_skill("whip", 34);
  set_skill("wuxiangforce", 218);
  set_skill("xiaofeng-sword", 107);


map_skill("force", "wuxiangforce");
map_skill("spells", "dao");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "jinghun-zhang");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object("/d/obj/weapon/standard/stick")->wield();
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
       my_weapon->set("name","木棒");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"布衣"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"披风"NOR);
}

