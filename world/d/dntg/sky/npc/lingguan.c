inherit NPC;

void create()
{
  set_name("Áé¹Ù",({"ling guan","guan"}));
  set("gender", "ÄÐÐÔ");
  set("age", 25);
  set("long", "ÓÓÊ¥Õæ¾ýÊÖÏÂÁé¹Ù£¬ÖÒÐÄ³àµ¨£¬æçÓÂÎÞ±È¡£\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 800000);
  set("daoxing", 1000000);
  set("kee", 3500);
  set("max_kee", 3500);
  set("sen", 2700);
  set("max_sen", 2700);
  set("force", 1800);
  set("max_force", 1800);
  set("mana", 1700);
  set("max_mana", 1700);
  set("force_factor", 100);
  set("mana_factor", 80);

  set_skill("dodge", 150);
  set_skill("baguazhen", 150);
  set_skill("force", 150);
  set_skill("tonsillit", 150);
  set_skill("spells", 150);
  set_skill("taiyi", 150);
  set_skill("unarmed", 200);
  set_skill("wuxing-quan", 200);
  set_skill("parry", 240);
  set_skill("whip", 240);
  set_skill("hellfire-whip", 240);

map_skill("dodge", "baguazhen");
map_skill("force", "tonsillit");
map_skill("spells", "taiyi");
map_skill("unarmed", "wuxing-quan");
map_skill("parry", "hellfire-whip");
map_skill("whip", "hellfire-whip");
set("chat_chance_combat", 60);
set("chat_msg_combat", ({
      (: perform_action, "whip", "lunhui" :),
  }) );

setup();
carry_object("/d/obj/armor/tongjia")->wear();
carry_object("/d/obj/weapon/whip/pibian")->wield();
}
