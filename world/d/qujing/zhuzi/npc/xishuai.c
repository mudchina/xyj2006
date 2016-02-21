// by snowcat on 11/5/1997 
inherit NPC;

void create()
{
  set_name("蟋蟀", ({ "xishuai" }) );
  set("race", "野兽");
  set("age", 5);
  set("per", 30);
  set("long", "一只雄赳赳地弹着翅膀的大蟋蟀。\n");
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("limbs", ({ "大头", "背部", "左翅", "右翅", "左大腿", "右大腿", "大隆肚" }) );
  set("verbs", ({ "bite" }) );

  setup();
}

