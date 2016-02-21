// by snowcat 11/6/1997

inherit NPC;

int test_player (object who);

void create()
{
  set_name("上官郡主", ({"shangguan junzhu", "junzhu", "zhu"}));
  set("title", "凤仙郡");
  set("long", "天竺国凤仙郡的一郡之侯。\n");
  set("gender", "男性");
  set("age", 50);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
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
  set("inquiry", ([
    "name" : "老夫乃凤仙郡侯，上官乃本郡之官姓。",
    "上官" : "老夫乃凤仙郡侯，上官乃本郡之官姓。",
    "here" : "此乃天竺国凤仙郡，因久旱无雨急寻法师以祭雨求雨祈雨救吾军民也。",
    "rain" : (: test_player :),
    "雨" : (: test_player :),
    "祭雨"   : (: test_player :),
    "求雨" : (: test_player :),
    "祈雨" : (: test_player :),
  ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  carry_object("/d/obj/weapon/blade/fengdao")->wield();
}

int test_player (object who)
{
  object me = this_object();
  who = this_player();

  if (who->query("obstacle/fengxian")=="done")
  {
    message_vision ("$N连忙对$n翻身一拜：多谢！\n",me,who);  
    return 1;
  }

  message_vision ("$N说道：多少大师前来凤仙郡救济灾民，"+
                  "去各个庙宇道场祭坛，都尚未有果。\n",me);
  message_vision ("$N轻叹了一口气。\n",me);
  return 1;
}

void init ()
{
  object who = this_player();

  call_out ("check_player",3,who);
}

void check_player (object who)
{
  object me = this_object();
  if (!who)
    return;
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/fengxian") == "done")
    return;
  if (who->query_temp("obstacle/fengxian_donated") < 1)
    return;
  if (who->query_temp("obstacle/fengxian_ketou") < 9)
    return;
  if (who->query_temp("obstacle/fengxian_zhanbai") < 9)
    return;
  if (who->query_temp("obstacle/fengxian_nianxiang") < 9)
    return;
  if (environment(who) != environment(this_object()))
    return;
  message_vision ("门外走来一官人，看了$N一眼。\n",who);
  message_vision ("官人对$N一拜说道：方才天上狂风大作，电闪雷鸣，"+
                  "果然一场好雨。\n",me);
  message_vision ("\n官人退下。\n",me);
  command ("ah");
  command ("thank "+who->query("id"));
  call_out ("announce_success",3,who);
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/fengxian") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/fengxian","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"凤仙郡劝善施霖，救得饥民千千万万！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
