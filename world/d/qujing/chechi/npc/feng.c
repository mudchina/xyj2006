// by snowcat oct 24 1997

inherit NPC;

string *names = ({
  "大姑奶",
  "二姑奶",
  "小姑奶",
  "大嫂子",
  "小嫂子",
  "小妾",
  "二妾",
  "大小姐",
  "二小姐",
  "花姐儿",
  "小姐",
});

string *ids = ({
  "da gunai",
  "er gunai",
  "xiao gunai",
  "da saozi",
  "xiao saozi",
  "xiao qie",
  "er qie",
  "da xiaojie",
  "er xiaojie",
  "hua jieer",
  "xiaojie",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "女性");
  set("combat_exp", 1000+random(9000));
  set("age", 18+random(9));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",1);
  set("max_gin",100);
  set("max_kee",100);
  set("max_sen",100);
  set("max_force",200);
  set("max_mana",200);
  set_skill("unarmed", 10+random(40));
  set_skill("unarmed", 10+random(40));
  set_skill("unarmed", 10+random(90));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  add_money("silver", random(5));
}
