//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("单身贵族",({"star liz","liz","star"}));
  set("gender", "女性");
  set("title", "尾火星官");
  set("age", 29);
  set("long", "    \n本人以为天地皆空，人生皆幻，\n世情嗜欲，悉伐性之斧斤；富贵功名，皆迷心之鸩毒。\n欲寻清幽之谷，依深穴之岩，垒石为门，拔茅为席，澄心净虑。\n吾愿足以！！！\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1224175);
  set("daoxing", 1224175);
  set("kee", 936);
  set("max_kee", 936);
  set("sen", 1895);
  set("max_sen", 1895);
  set("force", 3107);
  set("max_force", 1554);
  set("mana", 6779);
  set("max_mana", 3390);
  set("force_factor", 123);
  set("mana_factor", 170);
  set("str", 15);
  set("per", 13);


  set_skill("axe", 22);
  set_skill("baihua-zhang", 94);
  set_skill("blade", 17);
  set_skill("dagger", 23);
  set_skill("dodge", 135);
  set_skill("force", 161);
  set_skill("jueqingbian", 180);
  set_skill("kusang-bang", 17);
  set_skill("literate", 141);
  set_skill("moondance", 175);
  set_skill("moonforce", 167);
  set_skill("moonshentong", 179);
  set_skill("parry", 201);
  set_skill("snowsword", 214);
  set_skill("spear", 61);
  set_skill("spells", 180);
  set_skill("stealing", 9);
  set_skill("stick", 31);
  set_skill("sword", 120);
  set_skill("taiyi", 51);
  set_skill("throwing", 21);
  set_skill("tonsillit", 21);
  set_skill("unarmed", 106);
  set_skill("whip", 138);
  set_skill("xiaofeng-sword", 16);
  set_skill("yaofa", 15);
  set_skill("zhuihun-sword", 11);


map_skill("force", "moonforce");
map_skill("spells", "moonshentong");
map_skill("dodge", "moondance");
map_skill("parry", "snowsword");
map_skill("unarmed", "baihua-zhang");
map_skill("sword", "snowsword");
  set("inquiry", ([
      "name" : "俗名单身贵族。",
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
       my_weapon->set("name",HIY"流水"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"清风"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"浮云"NOR);
}

