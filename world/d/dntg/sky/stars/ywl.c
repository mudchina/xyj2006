//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("业务联系",({"star ywl","ywl","star"}));
  set("gender", "男性");
  set("title", "角木星官");
  set("age", 59);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 1726225);
  set("daoxing", 1726225);
  set("kee", 1205);
  set("max_kee", 1205);
  set("sen", 2001);
  set("max_sen", 2001);
  set("force", 5555);
  set("max_force", 2778);
  set("mana", 7837);
  set("max_mana", 3919);
  set("force_factor", 145);
  set("mana_factor", 196);
  set("str", 30);
  set("per", 10);


  set_skill("buddhism", 40);
  set_skill("dao", 19);
  set_skill("dodge", 164);
  set_skill("force", 200);
  set_skill("jindouyun", 144);
  set_skill("jinghun-zhang", 14);
  set_skill("kusang-bang", 99);
  set_skill("liangyi-sword", 59);
  set_skill("literate", 136);
  set_skill("parry", 170);
  set_skill("qianjun-bang", 250);
  set_skill("spells", 263);
  set_skill("stick", 140);
  set_skill("sword", 87);
  set_skill("tonsillit", 15);
  set_skill("unarmed", 94);
  set_skill("wuxiangforce", 190);
  set_skill("yaofa", 198);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "jinghun-zhang");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/ring")->wear();

}


void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="waist",armor2_id="ring";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"笑柄"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"无情"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"钻石王老五"NOR);
}


