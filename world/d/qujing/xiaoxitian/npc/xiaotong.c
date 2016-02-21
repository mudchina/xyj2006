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
  string str;
  set_name("Ð¡Í¯", ({"xiao tong", "tong"}));
  set("gender", "ÄÐÐÔ");
  set("age", 13);
  set("combat_exp", 150000+random(70000));
  set("daoxing", 100000);

  set("per", 10);
  set_skill("parry", 70);
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("blade", 70);
  set_skill("fork", 70);
  set_skill("rake", 70);
  set_skill("hammer", 70);
  set_skill("sword", 70);
  set_skill("stick", 70);
  set_skill("staff", 70);
  set("max_sen",700);
  set("max_gee",700);
  set("max_gin",700);
  set("force",700);
  set("max_force",700);
  set("max_mana",700);
  set("force_factor",10);
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
  str = "/d/qujing/xiaoxitian/obj/weapon0";
  str[strlen(str)-1] = '0'+random(7);
  carry_object(str); 
  carry_object("/d/qujing/xiaoxitian/obj/shield");
}

void kill_ob (object ob)
{
  object me = this_object();

  if (me->query("id")!="yao guai")
  {
    message_vision ("$N¶ÙÊ±±äÁËÑÕÉ«£¬ÏÖÁËÑý¾«µÄ±¾Ïà£¡\n",me);
    me->set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai", "xiao tong", "tong"}));
    command("wear dun");
    command("wield all");
  }
  ::kill_ob(ob);
}
ÿ