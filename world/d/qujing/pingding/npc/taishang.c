// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("Ì«ÉÏÀÏ¾ý", ({"taishang laojun", "taishang", "laojun"}));
  set("gender", "ÄÐÐÔ");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("daoxing", 10000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);
  set_skill("spells",180);
  set_skill("dao", 180);
  set_skill("puti-zhi", 180);
  set_skill("jindouyun", 180);
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("spells", "dao");
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

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/pingding") == "done")
    return;
  if (! who->query_temp("obstacle/pingding_huaqi_killed"))
    return;
  if (! who->query_temp("obstacle/pingding_laonai_killed"))
    return;
  if (! who->query_temp("obstacle/pingding_jinjiao_killed"))
    return;
  if (! who->query_temp("obstacle/pingding_yinjiao_killed"))
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/pingding","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"Æ½¶¥É½Ñ¹ÁúÉ½Ê©Íþ£¬ÌæÀÏ·òÊÕ»Ø½ðÒøÍ¯×Ó£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}

ÿ
