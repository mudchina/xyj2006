// by snowcat 12/9/1997

inherit NPC;

int test_player ();

void create()
{
  set_name("¹úÍõ", ({"guo wang", "wang", "king"}));
  set("long", "ÌìóÃ¹ú¹úÍõ£¬ÉíÅûÁúÅÛ£¬ÉñÌ¬×¯ÑÏ¡£\n");
  set("title", "ÌìóÃ¹ú");
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
    "name" : "ëÞÄËÌìóÃÒ»¹úÖ®¾ýÒ²£¬¹ÑÈËÓÐÒ»¹«Ö÷¡£",
    "here" : "ÌìóÃ¹úÒ²¡£",
    "ÌìóÃ" : "ÌìóÃ¹úÒ²¡£",
    "ÌìóÃ¹ú" : "ÌìóÃ¹úÒ²¡£",
    "¹«Ö÷" : (: test_player :),
    "æâÂí" : (: test_player :),
    "ÕÐÇ×" : (: test_player :),
    "princess" : (: test_player :),
  ]));
  setup();
  set_temp("no_return",1);
  carry_object("/d/obj/cloth/longpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
}

int test_player ()
{
  object me = this_object();
  object who = this_player();

  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$N¶Ô$nËµµÀ£º¼ÙæâÂíµÀÐÐ²»×ã£¬ºÎÒÔ»ìÈë½û¹¬£¿\n",me,who);
    message_vision ("\n$N¶Ô×óÓÒ·Ô¸ÀÁË¼¸¾ä¡£\n",me);
    message_vision ("¼¸Î»ËÅÎÀ¹Ù¼«ÓÐÀñÃ²µØ¶Ô$NÒ»µãÍ·£¬Óµ×Å$N×ß³ö´óµî¡£\n",who);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
    message_vision ("ËÅÎÀ¹Ù×ß½øÎçÃÅ¡£\n",who);
    return 1;
  }
  if (who->query("obstacle/tianzhu")=="done")
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÅ¶£¬æâÂíºÎÀ´£¿ÎªºÎ²»Ô¸Î÷ÐÐÈ¡¾­£¿\n",me,who);
    return 1;
  }
  if (! who->query_temp("obstacle/tianzhu_thrown"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ººÎÐíÈËÒ²¾ÓÈ»¶·µ¨»ìÈë½û¹¬£¿\n",me,who);
    message_vision ("\n$N¶Ô×óÓÒ·Ô¸ÀÁË¼¸¾ä¡£\n",me);
    message_vision ("¼¸Î»ËÅÎ»¹Ù¼«ÓÐÀñÃ²µØ¶Ô$NÒ»µãÍ·£¬Óµ×Å$N×ß³ö´óµî¡£\n",who);
    who->move("/d/qujing/tianzhu/zhaoyang");
    who->move("/d/qujing/tianzhu/wumen");
    message_vision ("ËÅÎÀ¹Ù×ß½øÎçÃÅ¡£\n",who);
    return 1;
  }
  if (who->query_temp("obstacle/tianzhu_killed"))
  {
    object junji = present ("jun ji",environment(me));

    message_vision ("$N¶Ô$nËµµÀ£ºëÞÕæºýÍ¿Ò²£¬Îó½«Ñý¾«µ±°®Å®£¡\n",me,who);
    if (! junji)
    {
      message_vision ("\n$NÆæ¹ÖµÀ£º¾ü»ú´ó³¼ºÎÔÚ£¿\n",me);
      return 1;
    }
    message_vision ("\n$N¶Ô$n·Ô¸ÀÁË¼¸¾ä¡£\n",me,junji);
    remove_call_out ("following");
    call_out ("following",5,me,junji,who);
    return 1;
  }
  message_vision ("$N¶Ô$nËµµÀ£ºæâÂíºÎ²»ºó¹¬°Ý¼û¹«Ö÷£¿\n",me,who);
  return 1;
}

void following (object me, object junji, object who)
{
  object taijian1 = present ("tai jian 1",environment(me));
  object taijian2 = present ("tai jian 2",environment(me));

  message_vision ("\n$NµãÁËµãÍ·¡£\n",junji);
  message_vision ("$N¶Ô$nËµµÀ£º¿É·ñ´ø±ÝÏÂÈ¥Ñ°¹«Ö÷£¿\n",junji,who);
  junji->command_function ("follow "+who->query("id"));
  me->command_function ("follow "+who->query("id"));
  me->set("my_saver",who);
  if (taijian1)
    taijian1->command_function ("follow "+who->query("id"));
  if (taijian2)
    taijian2->command_function ("follow "+who->query("id"));
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/tianzhu") == "done")
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/tianzhu","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"ÌìóÃ¹ú´óÕ½ÍÃÑý£¬¾È»ØÌìóÃ¹«Ö÷£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
              chinese_number(i/4)+"Ìì"+
              chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}

ÿ
