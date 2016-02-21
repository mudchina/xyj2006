// by snowcat  11/22/1997

inherit NPC;

string *names = ({
  "贩子",
  "官人",
  "女仆",
  "男仆",
  "路人",
  "道人",
  "市民",
  "艺人",
});

string *ids = ({
  "fan zi",
  "guan ren",
  "nu pu",
  "nan pu",
  "lu ren",
  "dao ren",
  "shi min",
  "yi ren",
});

string *genders = ({
  "男性",
  "男性",
  "女性",
  "男性",
  "男性",
  "男性",
  "男性",
  "男性",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", genders[i]);
  set("combat_exp", 1000+random(1000));
  set("age", 20+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",300);
  set("max_mana",300);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("silver", random(3));
}


