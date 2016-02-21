// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("¼àÕ¶¹Ù", ({"jianzhan guan", "guan"}));
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",100);
  set("max_gin",1000);
  set("max_kee",1000);
  set("max_sen",1000);
  set("max_force",1200);
  set("max_mana",1200);
  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("force", 90);
  set_skill("spells", 90);
  setup();
  carry_object("/d/qujing/chechi/obj/gongpao")->wear();
  carry_object("/d/qujing/chechi/obj/dao")->wield();
}

// 0: invalid place; 1: invalid condition; 2: valid
int check_valid_player (object who)
{
  object me = this_object();
  object where = environment (me);
  object yangli;
  object huli;
  object luli;
  object king;
  object guizi;

  if (! who)
    return 0;
  if (! where)
    return 0;
  if (where->query("short") != "Ì³³¡")
    return 0;  

  yangli = present("yangli daxian",where);  
  huli = present("huli daxian",where);  
  luli = present("luli daxian",where);  
  king = present("guo wang",where);  
  guizi = present("zhuhong guizi",where);

  if (! yangli || ! huli || ! luli || ! king || ! guizi)
    return 1;
  if (who->query_temp("obstacle/chechi") != "seen_king")
    return 1;
  if (who->query("obstacle/chechi") != "chantai")
    return 1;
  return 2;
}

void init ()
{
  call_out("greet_player",1,this_player());
  add_action ("do_guess","guess");
}

void greet_player (object who)
{
  object me = this_object();

  if (check_valid_player(who) == 2 &&
      ! who->query_temp("obstacle/chechi_greeted2"))
  {
    who->set_temp("obstacle/chechi_greeted2",1);
    message_vision ("¼¸Î»ÄÚ¹ÙÌ§×ÅÒ»Ğ©¶«Î÷×ßÀ´£¬½«Öìºì¹ñ×Ó²¼ÖÃÒ»·¬¡£\n",me);
    message_vision ("ÄÚ¹ÙÏò±±ÀëÈ¥¡£\n\n",me);
    me->command_function("hi "+who->query("id"));
    message_vision ("$N¶Ô$nËµµÀ£º¡°¸ô°å²ÂÃ¶£¬ÇëµÀ³öÖìºì¹ñ×ÓÀïÎªºÎÎï¡£¡±\n",
                    me,who);
  }
}

void display_guess (object me, object who, object guizi,
                    string arg, object luli)
{
  if (! me)
    return;
  if (! who)
    return;

  message_vision ("$NÖ¸×Å¹ñ×ÓËµ£¬ÕâÀïÃæÊÇ"+arg+"°É¡£\n",who);
}
 
void failing_guess (object me,object who, object where,
                    object guizi, string arg, object luli)
{
  display_guess (me,who,guizi,arg,luli);
  who->start_budy(4,5);
  call_out ("failing",5,me,who,where,guizi,arg,luli);
}

void failing (object me, object who, object where,
              object guizi, string arg, object luli)
{
  string str;
  if (! me)
    return;
  if (! who)
    return;
  if (arg == "¹¬ÒÂ")
  {
    if (random(2))
      str = "ÌÒ×Ó";
    else
      str = "µÀÍ¯";
  }
  else if (arg == "ÌÒ×Ó")
  {
    if (random(2))
      str = "¹¬ÒÂ";
    else
      str = "µÀÍ¯";
  }
  else if (arg == "µÀÍ¯")
  {
    if (random(2))
      str = "ÌÒ×Ó";
    else
      str = "ÏÉÒÂ";
  }
  else
  {
    switch (random(3))
    {
      case 0:
      {
        str = "¹¬ÒÂ";
        break;
      }
      case 1:
      {
        str = "ÌÒ×Ó";
        break;
      }
      case 2:
      {
        str = "µÀÍ¯";
        break;
      }
    }
  }
  who->start_budy(3,4);
  call_out ("put_player_in",3,me,who,guizi);
  call_out ("get_player_out",120,me,who,guizi);
  if (luli)
  {
    message_vision ("Ö»¼û$N¿àË¼Ú¤Ïë£¬ËµµÀ£º¡°ÊÇ"+str+"¡±¡£\n\n",luli);
    message_vision ("»°ÒôÎ´Âä£¬$N´ò¿ªÖìºì¹ñ×Ó£¬È´¹ûÈ»ÊÇ"+str+"¡£\n\n",me);
  }
  else   
    message_vision ("$NºßµØÒ»Éù´ò¿ªÖìºì¹ñ×Ó£¬ÀïÃæÊÇ"+str+"¡£\n\n",me);
}

void put_player_in (object me, object who, object guizi)
{
  message_vision ("$N¶Ô$nÒ»ÉùÀäĞ¦£¬º°µÀ£º¡°À´ÈË£¡¡±\n",me,who);
  message_vision ("´Ó¹¬ÀïÔçÒÑ×ß³öÁ½¸öÄÚ¹Ù£¬½«$N×óÓÒ¼ĞÆğÍù¹ñ×ÓÀïÒ»ÈÓ¡£\n",who);
  me->set_temp("obstacle/chechi","player_in");
  who->move(guizi);
}

void get_player_out (object me, object who, object guizi)
{
  me->set_temp("obstacle/chechi",0);
me->move(environment(guizi));
  message_vision ("¹¬Àï×ß³öÁ½¸öÄÚ¹Ù£¬½«$N´Ó¹ñ×ÓÀïÈíÃàÃàµØÍÏÁË³öÀ´¡£\n\n",who);
  message_vision ("ÄÚ¹ÙÖØĞÂ½«Öìºì¹ñ×Ó²¼ÖÃÒ»·¬£¬Ïò±±Àë¿ª¡£\n",me);
  message_vision ("$N¶Ô$nËµµÀ£º¡°Ë¡ÄãÒ»»Ø£¬ËÙ²Â£¡¡±\n",me,who);
}

void success_guess (object me,object who, object where,
                    object guizi, string arg, object luli)
{
  display_guess (me,who,guizi,arg,luli);
  who->start_budy(2,3);
  call_out ("success",2,me,who,where,arg,luli);
}

void success (object me,object who, object where, string arg, object luli)
{
  if (! me)
    return;
  if (! who)
    return;

  message_vision ("$NËµµÀ£º¡°¿ª¹ñ£¡¡±\n\n",me);
  message_vision ("Öìºì¹ñ×Ó´ò¿ª£¬¹ûÈ»ÊÇ"+arg+"£¡\n\n",me);
  who->set("obstacle/chechi","guizi");
  who->save();
  me->set_temp("obstacle/chechi",0);
  message_vision ("$NÃæÂ¶Ï²É«£¬Á¬ÉùÏò$n°İµÀ£º¡°Çë£¡¡±\n",me,who);
}

int do_guess (string arg)
{
  object who = this_player();
  object me = this_object();
  object where = environment (me);
  object guizi;
  object luli;
  int status;

  if (! arg)
    return 0;
  if (! who)
    return 0;
  if (! where)
    return 0;
  guizi = present("zhuhong guizi",where);
  if (guizi->query("id") != "zhuhong guizi")
    return 0;
  status = check_valid_player(who);
  if (status == 0)
    return 0;
  luli = present("luli daxian",where);  
  if (luli && luli->query("id") != "luli daxian")
    luli = 0;
  if (me->query_temp("obstacle/chechi")=="busy")
  {
    message_vision ("$NÃ°Ã°Ê§Ê§µØº°ÁËÒ»Éù£¬ÕâÀïÃæÊÇ"+arg+"£¡\n",who);
    message_vision ("$N½ĞµÀ£º¡°×¡¿Ú£¬Õâ²»Õı²Â×ÅÂğ£¿¡±\n",me);
    return 1;
  }
  if (me->query_temp("obstacle/chechi")=="player_in")
  {
    message_vision ("$Nñ²ñ²µØº°ÁËÒ»Éù£¬ÕâÀïÃæÊÇ"+arg+"£¡\n",who);
    message_vision ("$NËµµÀ£º¡°×¡¿Ú£¬ÕâÀïÃæ²»»¹¹Ø×ÅÈËÂğ£¿¡±\n",me);
    return 1;
  }
  me->set_temp("obstacle/chechi","busy");
  if (status == 1 || ! luli)
  {
    failing_guess(me,who,where,guizi,arg,luli);    
  }
  else if (who->query_temp("obstacle/chechi_guizi_times") == 0)
  {
    who->set_temp("obstacle/chechi_guizi_times",1);
    failing_guess(me,who,where,guizi,arg,luli);    
  }
  else if (random(3))
    failing_guess(me,who,where,guizi,arg,luli);    
  else if (arg != "¹¬ÒÂ" && arg != "ÌÒ×Ó" && arg != "µÀÍ¯")
    failing_guess(me,who,where,guizi,arg,luli);    
  else
    success_guess(me,who,where,guizi,arg,luli);
  return 1;
}

ÿ
