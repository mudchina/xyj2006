// created 4/4/1997 by snowcat

inherit NPC;

void create()
{
  set_name("¹¬Å®", ({"girl", "gongnu"}));
  set("gender", "Å®ÐÔ");
  set("age", 15);
  set("combat_exp", 2500);
  set_skill("unarmed", 5);
  set_skill("dodge", 5);
  set_skill("parry", 5);
  set("force", 10);
  set("max_force", 10);

  setup();
}

void init()
{
  ::init();
}

