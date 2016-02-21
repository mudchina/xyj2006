inherit NPC;
void create()
{
  set_name("ñ´Ê¥Õæ¾ı",({"yisheng zhenjun","zhenjun","jun"}));
  set("gender", "ÄĞĞÔ");
  set("age", 45);
  set("long", "    \nÓñµÛµÄÌùÉíÊÌÎÀ£¬ÔÚÁéÏö±¦µîÇ°ÊØÎÀ×Å¡£\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 800000);
  set("daoxing", 1000000);
  set("kee", 1500);
  set("max_kee", 1500);
  set("sen", 1700);
  set("max_sen", 1700);
  set("force", 1400);
  set("max_force", 1400);
  set("mana", 1500);
  set("max_mana", 1500);
  set("force_factor", 20);
  set("mana_factor", 40);


  set_skill("dodge", 100);
  set_skill("baguazhen", 50);
  set_skill("force", 100);
  set_skill("zhenyuan-force", 50);
  set_skill("spells", 100);
  set_skill("taiyi", 100);
  set_skill("unarmed", 120);
  set_skill("wuxing-quan", 40);
  set_skill("parry", 140);


map_skill("dodge", "baguazhen");
map_skill("force", "zhenyuan-force");
map_skill("spells", "taiyi");
map_skill("unarmed", "wuxing-quan");
map_skill("parry", "wuxing-quan");

  set("inquiry", ([
]));


setup();

carry_object("/d/obj/cloth/jinpao")->wear();
add_money("silver", 80);

}
