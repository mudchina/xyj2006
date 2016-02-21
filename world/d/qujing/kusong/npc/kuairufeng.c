//Cracked by Roath
inherit NPC;

void create()
{
  set_name("¿ìÈç·ç", ({"kuairu feng","feng"}));
  set("gender", "ÄÐÐÔ");
  set("age", 10);
  set("title", "»ðÔÆ¶´½¡½«");
  set("long","Ò»¸öÔôÃ¼ÊóÑÛµÄÐ¡Ñý¾«¡£\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);

  set("per", 15);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  set("max_sen",800);
  set("max_gee",800);
  set("max_gin",800);

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

ÿ