// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("Å£½Ç´óÍõ", ({ "niujiao dawang", "dawang" }));
  set("long", "Ò»Î»Ñý¹Ö£¬±Ç×ÓÉÏ³¤×ÅÒ»¸ù½Ç¡£");
  set("gender", "ÄÐÐÔ");
  set("age", 50);
  set("attitude", "heroism");
  set("per", 29);
  set("max_kee", 1400);
  set("max_gin", 1400);
  set("max_sen", 1400);
  set("force", 1400);
  set("max_force", 1400);
  set("force_factor", 10);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 80);
  set("combat_exp", 1540000);
  set("daoxing", 1500000);

  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 90);
  set_skill("dragonfight", 85);
  set_skill("dodge", 10);
  set_skill("jindouyun", 70);
  set_skill("sanban-axe", 70);
  set_skill("parry", 85);
  set_skill("force", 70);
  set_skill("wuxiangforce", 70);
  set_skill("axe", 85);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "sanban-axe");
  map_skill("axe", "sanban-axe");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$NÆËµ¹ÔÚµØ£¬»¹Ô­ÎªÒ»Í·Ï¬Å£¡£\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

ÿ
