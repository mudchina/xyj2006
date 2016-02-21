// create by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("ÑıÍõ", ({"yao wang", "wang" }));
  set("title","»ÆÊ¨¾«");
  set("gender", "ÄĞĞÔ");
  set("age", 40);
  set("attitude", "aggressive");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 1000);
  set("max_gin", 1000);
  set("max_sen", 1000);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 70);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 560000);
  set("daoxing", 600000);

  set_skill("unarmed", 70);
  set_skill("dodge", 100);
  set_skill("parry", 130);
  set_skill("spells", 70);
  set_skill("force", 70);
  set_skill("staff",130);
  set_skill("gouhunshu", 70);
  set_skill("tonsillit", 70);
  set_skill("ghost-steps", 100);
  set_skill("jinghun-zhang", 70);
  set_skill("lunhui-zhang", 130);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-80000);
  set("nkgain",100);
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baotou/obj/siming")->wield();
  
}

void die()
{
  object me = this_object();
  object where = environment();

  message_vision("Ö»¼û$NË¤µ¹ÔÚµØ£¬ÏÖÁË±¾ĞÎ¡£Ô­À´ÊÇÖ»½ğÃ«Ê¨×Ó£¡\n",me);
  set_name("½ğÃ«Ê¨×Ó", ({"yao wang", "wang" }));
  delete("title");
  ::die();
}

void unconcious()
{
  die();
}
ÿ