//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("瓜瓜",({"star ggggg","ggggg","star"}));
  set("gender", "女性");
  set("title", "移山大圣");
  set("age", 29);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 5787884);
  set("daoxing", 5787884);
  set("kee", 1304);
  set("max_kee", 1304);
  set("sen", 3056);
  set("max_sen", 3056);
  set("force", 6819);
  set("max_force", 3410);
  set("mana", 12767);
  set("max_mana", 6384);
  set("force_factor", 161);
  set("mana_factor", 320);
  set("str", 14);
  set("per", 26);


  set_skill("baguazhen", 348);
  set_skill("buddhism", 41);
  set_skill("dodge", 219);
  set_skill("force", 206);
  set_skill("ghost-steps", 180);
  set_skill("literate", 151);
  set_skill("moonforce", 41);
  set_skill("ningxie-force", 43);
  set_skill("parry", 191);
  set_skill("sanqing-jian", 250);
  set_skill("snowsword", 64);
  set_skill("spells", 371);
  set_skill("sword", 219);
  set_skill("taiyi", 51);
  set_skill("unarmed", 140);
  set_skill("wuxing-quan", 52);
  set_skill("xiaofeng-sword", 364);
  set_skill("yaofa", 368);
  set_skill("zhenyuan-force", 220);


map_skill("force", "zhenyuan-force");
map_skill("spells", "yaofa");
map_skill("dodge", "baguazhen");
map_skill("parry", "xiaofeng-sword");
map_skill("unarmed", "wuxing-quan");
map_skill("sword", "xiaofeng-sword");
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
       my_weapon->set("name",GRN"碧海");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIG"绿洲"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIW"苍原"NOR);
}

