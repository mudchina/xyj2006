// by snowcat 

inherit NPC;

string *names = ({
  "僧人",
  "和尚",
  "道士",
  "道长",
  "祭师",
});

string *ids = ({
  "seng ren",
  "he shang",
  "dao shi",
  "dao zhang",
  "ji shi",
});

string *genders = ({
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
  set("age", 50+random(50));
  set("per", 24+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30+random(50));
  set_skill("dodge", 30+random(50));
  set_skill("parry", 30+random(50));
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
  add_money("silver", random(5));
}


