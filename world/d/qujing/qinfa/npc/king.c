// by snowcat 11/6/1997

inherit NPC;

int test_player (object who);

void create()
{
  set_name("¹úÍõ", ({"guo wang", "wang", "king"}));
  set("long", "ÇÕ·¨¹ú¹úÍõ£¬ÉíÅûÁúÅÛ£¬ÉñÌ¬×¯ÑÏ¡£\n");
  set("title", "ÇÕ·¨¹ú");
  set("gender", "ÄÐÐÔ");
  set("age", 50);
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
  set("inquiry", ([
    "buddhism" : (: test_player :),
    "monk" : (: test_player :),
    "·ð"   : (: test_player :),
    "·ð½Ì" : (: test_player :),
    "ºÍÉÐ" : (: test_player :),
    "°Ý·ð" : (: test_player :),
    "Èë·ð" : (: test_player :),
    "Èë·ðÃÅ" : (: test_player :),
  ]));
  set("can_sleep",1);
  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void check_hair ()
{
  object me = this_object();

  if (me->query("disable_type") == "<Ë¯ÃÎÖÐ>" &&
      me->query_temp("disabled"))
  {
    call_out("check_hair",1);
    return;
  }

  if (me->query_temp("has_said"))
    return;

  message_vision ("$NÍ»È»ÏÂÒâÊ¶µØÃþÁËÃþÍ·£ºÌìÄÅ£¬ÄÔ´üÈ«Ìê¹âÁË£¡\n",me);
  message_vision ("$NÒ»ÕóÑ£ÔÎ£¬²îµãË¤µ¹ÔÚµØ£¡\n",me);
  me->set_temp("has_said",1);
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "jingang")
  {
    message_vision ("$NËµµÀ£ºÊ²Ã´ÍæÒâ£¬ëÞ½­É½ÒÑÓÐ£¬ÆñÈ±´ËÀÃ»õ£¡\n",me);
    return 0;
  }
  if (! query_temp("has_said"))
  {
    message_vision ("$NËµµÀ£ºÕýºÃ£¬ëÞÒªÉ±¾¡Ò»ÍòºÍÉÐ£¡\n",me);
    me->kill_ob(who);
    return 1;
  }
  if (who->query_temp("obstacle/qinfa_cut_times")<4)
  {
    message_vision ("$NËµµÀ£ºÄã¸ö³ô·ð¶ù£¡ëÞÒªÉ±¾¡Ò»ÍòºÍÉÐ£¡\n",me);
    me->kill_ob(who);
    return 1;
  }
  command ("thank "+who->query("id"));
  me->set_temp("has_book",ob->query("name"));
  remove_call_out ("reading");
  call_out ("reading",3);
  return 1;
}

void reading ()
{
  object me = this_object();
  string book = me->query_temp("has_book");

  if (! living (me))
  {
    message_vision ("$N·­ÁË·­°×ÑÛ¡£\n",me);  
    return;
  }
  if (! book)
  {
    message_vision ("$N³ÁË¼Æ¬¿Ì¡£\n",me);  
    return;
  }

  message_vision ("$NÅõÆð"+book+"£¬¾Û¾«»áÉñµØ¶ÁÁËÆðÀ´¡£\n",
                  me);  
  me->set_temp("can_believe",1);
  if (random(4))
  {
    remove_call_out ("reading");
    call_out ("reading",3);
  }
}

int test_player (object who)
{
  object me = this_object();
  who = this_player();
  if (! me->query_temp("can_believe")) 
  {
    message_vision ("$NËµµÀ£ºëÞÒªÉ±¾¡Ò»ÍòºÍÉÐ£¡\n",me);
    return 1;
  }    
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$NËµµÀ£ºÄã£¬µÀÐÐ²»×ã£¬Æñ¿É¶à×ì£¡\n",me);
    return 1;
  }    
  if (who->query_temp("obstacle/qinfa_cut_times")<4)
  {
    message_vision ("$NËµµÀ£ºëÞÔø±»É®Ëù°ùÒ²¡£\n",me);
    return 1;
  }    
  if (who->query("obstacle/qinfa") == "done")
  {
    message_vision ("$NËµµÀ£º¾ÃÑö¾ÃÑö£¡\n",me);
    return 1;
  }    
  message_vision ("$N³ÁÄ¬¼¸Ðí£¬µãÁËÒ»ÏÂÍ·¡£\n\n",me);
  remove_call_out ("saying1");
  call_out ("saying1",3,who);  
  return 1;
}

void saying1 (object who)
{
  object me = this_object();
  message_vision ("$NËµµÀ£ºëÞÔøÒòÉ®°ùÁËëÞ£¬ÐíÌìÔ¸ÒªÉ±Ò»ÍòºÍÉÐ×öÔ²Âú¡£\n\n",me);
  remove_call_out ("saying2");
  call_out ("saying2",3,who);  
}

void saying2 (object who)
{
  object me = this_object();
  message_vision ("$NËµµÀ£º²»ÆÚ½ñÒ¹¹éÒÀ£¬½ÌëÞµÈÎªÉ®¡£\n\n",me);
  remove_call_out ("saying3");
  call_out ("saying3",5,who);  
}

void saying3 (object who)
{
  object me = this_object();
  message_vision ("$NËµµÀ£ºÈç½ñ·¢¶¼ÌêÂäÁË£¬ëÞÔ¸Èë·ðÃÅ¡£\n\n",me);
  remove_call_out ("saying4");
  call_out ("saying4",5,who);  
}

void saying4 (object who)
{
  object me = this_object();
  message_vision ("$NÓÖËµµÀ£º´ËÄËÌìÒâÒ²¡£\n\n",me);
  remove_call_out ("announce_success");
  call_out ("announce_success",5,who);  
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/qinfa") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/qinfa","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"Ãð·¨¹úÈ°ëÞ¹éÒÀ·ðÃÅ£¬ëÞ¸Ä¹úºÅÎªÇÕ·¨¹ú£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}
ÿ
