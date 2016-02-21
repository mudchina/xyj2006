//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("野风信子",({"star windf","windf","star"}));
  set("gender", "女性");
  set("title", "娄金星官");
  set("age", 38);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 2143726);
  set("daoxing", 2143726);
  set("kee", 1346);
  set("max_kee", 1346);
  set("sen", 2472);
  set("max_sen", 2472);
  set("force", 6641);
  set("max_force", 3321);
  set("mana", 10099);
  set("max_mana", 5050);
  set("force_factor", 168);
  set("mana_factor", 253);
  set("str", 14);
  set("per", 19);


  set_skill("baihua-zhang", 241);
  set_skill("buddhism", 41);
  set_skill("dodge", 203);
  set_skill("force", 204);
  set_skill("jueqingbian", 184);
  set_skill("literate", 142);
  set_skill("moondance", 279);
  set_skill("moonforce", 235);
  set_skill("moonshentong", 50);
  set_skill("parry", 184);
  set_skill("rake", 100);
  set_skill("snowsword", 139);
  set_skill("spells", 280);
  set_skill("sword", 206);
  set_skill("unarmed", 181);
  set_skill("yaofa", 280);
  set_skill("zhuihun-sword", 51);


map_skill("force", "moonforce");
map_skill("spells", "moonshentong");
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
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();

}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","杏花枝");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","绿叶");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","花瓣");
}


