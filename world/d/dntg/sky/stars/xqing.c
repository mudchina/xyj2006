//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("小青",({"star xqing","xqing","star"}));
  set("gender", "女性");
  set("title", "齐天大圣");
  set("age", 39);

  set("attitude", "heroism");
  set("class", "taoist");
  set("combat_exp", 5104540);
  set("daoxing", 5104540);
  set("kee", 1295);
  set("max_kee", 1295);
  set("sen", 2976);
  set("max_sen", 2976);
  set("force", 5853);
  set("max_force", 2927);
  set("mana", 12061);
  set("max_mana", 6031);
  set("force_factor", 164);
  set("mana_factor", 302);
  set("str", 16);
  set("per", 14);


  set_skill("buddhism", 41);
  set_skill("dodge", 222);
  set_skill("force", 205);
  set_skill("hammer", 75);
  set_skill("jindouyun", 241);
  set_skill("liangyi-sword", 1);
  set_skill("literate", 142);
  set_skill("moondance", 47);
  set_skill("moonforce", 22);
  set_skill("parry", 201);
  set_skill("puti-zhi", 104);
  set_skill("qianjun-bang", 347);
  set_skill("snowsword", 1);
  set_skill("spells", 370);
  set_skill("stick", 290);
  set_skill("sword", 173);
  set_skill("tonsillit", 15);
  set_skill("unarmed", 195);
  set_skill("whip", 20);
  set_skill("wuxiangforce", 227);
  set_skill("yaofa", 343);


map_skill("force", "wuxiangforce");
map_skill("spells", "yaofa");
map_skill("dodge", "jindouyun");
map_skill("parry", "qianjun-bang");
map_skill("unarmed", "puti-zhi");
map_skill("stick", "qianjun-bang");
  set("inquiry", ([
]));


setup();

carry_object("/obj/loginload/skirt.c")->wear();
carry_object(__DIR__"obj/stick")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/shoes")->wear();

}


void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="stick";
  string armor1_id="shoes",armor2_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","绣花针");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","绣鞋");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","绣裙");
}

