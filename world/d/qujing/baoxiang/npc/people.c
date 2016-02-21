// by snowcat oct 15 1997

inherit NPC;

string *names = ({
  "渔夫",
  "樵夫",
  "妇女",
  "街头小商人",
  "官人",
  "乞丐",
  "艺人",
  "路人",
});

string *ids = ({
  "yu fu",
  "qiao fu",
  "fu nu",
  "shang ren",
  "guan ren",
  "qi gai",
  "yi ren",
  "lu ren",
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
  set("combat_exp", 100+random(1000));
  set("age", 20+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  set("chat_chance", 8);
  set("chat_msg", ({ (: random_move :) }));
  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", random(5));
}


