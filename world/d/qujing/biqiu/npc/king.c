// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "比丘国的国王，身着龙袍，头戴珍珠冠。\n");
  set("title", "比丘国");
  set("gender", "男性");
  set("age", 56);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/biqiu") == "done")
    return;
  if (who->query_temp("obstacle/biqiu_xiaoer") < 2 ||
      who->query_temp("obstacle/biqiu_zuochan") < 17 ||
      who->query_temp("obstacle/biqiu_hou") < 1 ||
      who->query_temp("obstacle/biqiu_guozhang") < 1)
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/biqiu","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"比丘国拯救无辜小童清华洞治服孽畜！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}

