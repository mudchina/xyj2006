// by snowcat on 11/5/1997 
inherit NPC;

void create()
{
  set_name("山鸡", ({ "shan ji", "ji" }) );
  set("race", "野兽");
  set("age", 20);
  set("per", 20);
  set("long", "一只成精的母花山鸡。\n");
  set("attitude", "friendly");
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("limbs", ({ "头部", "身体", "尾巴" }) );
  set("verbs", ({ "bite"}) );

  setup();
}


