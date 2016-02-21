// rewritten by snowcat on 12.12.1997

inherit NPC;

void create()
{
  set_name("³Â³¤ÀÏ", ({"chen zhanglao", "chen", "zhanglao"}));
  set("gender", "ÄÐÐÔ");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 50000);
  set("daoxing", 50000);

  set("per", 35);
  set_skill("dodge", 30);
  set_skill("force", 30);
  set_skill("parry", 30);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",500);
  set("max_force",500);
  set("max_mana",500);
  set("force_factor",5);
  setup();

  carry_object("/d/obj/cloth/choupao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tongtian") == "done")
    return;
  if (! who->query_temp("obstacle/tongtian_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/tongtian","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"Í¨ÌìºÓ¾ÈÍ¯ÄÐÅ®£¬Ë®Õ¬½µÓã¾«£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}
ÿ
