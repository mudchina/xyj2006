// yahuan1.c

inherit NPC;

void create()
{
  set_name("丫环", ({"ya huan"}));
  set("long","一个美丽的丫环。\n");
  set("gender", "女性");
  set("age", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("combat_exp",600);
  setup();
  carry_object("/d/obj/cloth/pink_cloth")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}


