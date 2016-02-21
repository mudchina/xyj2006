// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("弥勒佛祖", ({"mile fozu", "mile", "fozu"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("daoxing", 5000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);
  set_skill("spells",180);
  set_skill("staff",180);
  set_skill("buddhism", 180);
  set_skill("jienan-zhi", 180);
  set_skill("lotusmove", 180);
  set_skill("lunhui-zhang", 180);
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("spells", "buddhism");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  set("max_sen",1800);
  set("max_gee",1800);
  set("max_gin",1800);
  set("force",1800);
  set("max_force",1800);
  set("max_mana",1800);
  set("force_factor",125);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (! who)
    return;
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/xiaoxitian") == "done")
    return;
  if (! who->query_temp("obstacle/xiaoxitian_killed"))
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/xiaoxitian","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"小西天金铙脱险，小雷音寺战胜黄眉老佛！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}

