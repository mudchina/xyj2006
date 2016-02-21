// created by snowcat on 12/16/1997

inherit NPC;

string *names = ({
  "ºÚÊó¹Ö",
  "»Æáì¹Ö",
  "»Òáõ¹Ö",
  "°×áû¹Ö",
  "³àâ¡¹Ö",
  "ÍÁâ¬¹Ö",
  "Ê¯â¥¹Ö",
  "Ä¾â®¹Ö",
  "Ë®âµ¹Ö",
});

void create()
{
  set_name("Ð¡Í¯", ({"xiao tong", "tong"}));
  set("gender", "ÄÐÐÔ");
  set("age", 13);
  set("combat_exp", 150000+random(30000));
  set("daoxing", 100000);

  set("per", 10);
  set_skill("parry", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("blade", 80);
  set_skill("fork", 80);
  set_skill("rake", 80);
  set_skill("hammer", 80);
  set_skill("sword", 80);
  set_skill("stick", 80);
  set_skill("staff", 80);
  set("max_sen",1100);
  set("max_kee",1100);
  set("max_gin",1100);
  set("force",1100);
  set("max_force",1100);
  set("max_mana",1100);
  set("force_factor",10);
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/shield");
}

void kill_ob (object ob)
{
  object me = this_object();

  if (me->query("id")!="yao guai")
  {
    set("combat_exp",1000000+random(70000));
  set("daoxing", 700000+random(70000));
  set("eff_kee",1100);
  set("kee",1100);
  set("sen",1100);
  set("eff_sen",1100);

    message_vision ("$N¶ÙÊ±±äÁËÑÕÉ«£¬ÏÖÁËÑý¾«µÄ±¾Ïà£¡\n",me);
    me->set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai", "xiao tong", "tong"}));
    command("wear dun");
  }
  ::kill_ob(ob);
}
ÿ
