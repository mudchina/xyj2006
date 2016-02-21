// created 11/6/1997 by snowcat

inherit NPC;

void create()
{
  string dir;
  set_name("½ðÊ¥¹¬", ({"jinsheng gong", "gong", "queen"}));
  set("title", "Öì×Ï¹ú");
  set("gender", "Å®ÐÔ");
  set("age", 28);
  set("per", 26);
  set("rank_info/respect", "ÄïÄï");
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("snowsword", 30);
  set_skill("sword", 30);
  set_skill("dragonfight", 30);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set_skill("spells", 30);
  set_skill("dragonstep", 30);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_gin", 500);
  set("max_kee", 500);
  set("max_sen", 500);
  set("force", 500);
  set("max_force", 500);
  set("mana", 500);
  set("max_mana", 500);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void test_player (object who);

void init()
{
  test_player (this_player());
  ::init();
}

void test_player (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/zhuzi") == "done")
    return;
  if (! who->query_temp("obstacle/zhuzi_cured"))
    return;
  if (! who->query_temp("obstacle/zhuzi_killed"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/zhuzi","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"Öì×Ï¹úÊ©ÉñÁ¦ÖÎÓúÍòËê£¬½â¾È½ðÊ¥¹¬ÓÚÈýÄê¾Ã»ö£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
               chinese_number(i/4)+"Ìì"+
              chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
  command ("thank");
  call_out ("leaving",2);
}

void leaving ()
{
  object me = this_object();

  command("bow");
  command("southeast");
  destruct (me);
}
ÿ
