// by snowcat on 7/5/1997 
inherit NPC;

void create()
{
  set_name("公鸡", ({ "gong ji", "ji" }) );
  set("race", "野兽");
  set("gender", "雄性");
  set("age", 2);
  set("long", "一只雄赳赳的大公鸡。\n");
  set("attitude", "friendly");
  set_skill("unarmed", 2);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("limbs", ({ "头部", "身体", "尾巴" }) );
  set("verbs", ({ "bite"}) );

  setup();
}

