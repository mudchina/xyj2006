//sgzl

inherit NPC;

void create()
{
  set_name("ÅóÓÑ",({"star matthew","matthew","star"}));
  set("gender", "ÄĞĞÔ");
  set("title", "ØµÍÁĞÇ¹Ù");
  set("age", 53);
  set("long", "    \nÊÀÊÂÈçÆå  Ç¬À¤Äª²â  Ğ¦¾¡Ó¢ĞÛ\n");

  set("attitude", "heroism");
  set("class", "dragon");
  set("combat_exp", 954340);
  set("daoxing", 954340);
  set("kee", 1059);
  set("max_kee", 1059);
  set("sen", 1955);
  set("max_sen", 1955);
  set("force", 4599);
  set("max_force", 2300);
  set("mana", 7359);
  set("max_mana", 3680);
  set("force_factor", 115);
  set("mana_factor", 185);
  set("str", 21);
  set("per", 23);


  set_skill("archery", 17);
  set_skill("dodge", 162);
  set_skill("dragonfight", 199);
  set_skill("dragonforce", 150);
  set_skill("dragonstep", 183);
  set_skill("fengbo-cha", 202);
  set_skill("force", 161);
  set_skill("fork", 202);
  set_skill("hammer", 62);
  set_skill("huntian-hammer", 161);
  set_skill("literate", 142);
  set_skill("moonforce", 22);
  set_skill("parry", 161);
  set_skill("seashentong", 141);
  set_skill("snowsword", 161);
  set_skill("spells", 218);
  set_skill("stealing", 22);
  set_skill("sword", 72);
  set_skill("unarmed", 159);
  set_skill("whip", 38);
  set_skill("yaofa", 218);
  set_skill("zhuihun-sword", 12);


map_skill("force", "dragonforce");
map_skill("spells", "seashentong");
map_skill("dodge", "dragonstep");
map_skill("parry", "fengbo-cha");
map_skill("unarmed", "dragonstep");
map_skill("fork", "fengbo-cha");
  set("inquiry", ([
]));


setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/fork")->wield();
carry_object(__DIR__"obj/head")->wear();
carry_object(__DIR__"obj/armor")->wear();

}


void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="fork";
  string armor1_id="head",armor2_id="armor";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","ßÕßÕßÕ»ú¹ØÇ¹");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","·Àµ¯¿ø");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","·Àµ¯ÒÂ");
}

