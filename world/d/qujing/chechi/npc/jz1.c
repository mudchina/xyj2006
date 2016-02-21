// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("¼àÕ¶¹Ù", ({"jianzhan guan", "guan"}));
  set("gender", "ÄÐÐÔ");
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
  object chantai1;
  object chantai2;

  if (! who)
    return 0;
  if (! where)
    return 0;
  if (where->query("short") != "¼ÀË®³¡")
    return 0;  

  yangli = present("yangli daxian",where);  
  huli = present("huli daxian",where);  
  luli = present("luli daxian",where);  
  king = present("guo wang",where);  
  chantai1 = present("yun chantai 1",where);
  chantai2 = present("yun chantai 2",where);

  if (! yangli || ! huli || ! luli || ! king || ! chantai1 || ! chantai2)
    return 1;
  if (who->query_temp("obstacle/chechi") != "seen_king")
    return 1;
  if (who->query("obstacle/chechi") != "eaten")
    return 1;
  return 2;
}
void init ()
{
  call_out("greet_player",1,this_player());
  add_action ("do_climb","climb");
}

void greet_player (object who)
{
  object me = this_object();

  if (check_valid_player(who) == 2 &&
      ! who->query_temp("obstacle/chechi_greeted"))
  {
    who->set_temp("obstacle/chechi_greeted",1);
    me->command_function("hi "+who->query("id"));
    message_vision ("$N¶Ô$nËµµÀ£º¡°ÇëÉÏÔÆÌÝ£¬ÓÚÌ¨¶¥×øìøÏÔÊ¥¡£¡±\n",me,who);
  }
}

int do_climb (string arg)
{
  object who = this_player();
  object me = this_object();
  object where = environment (me);
  object chantai1;
  object chantai2;
  object huli;
  int status;

  if (! arg)
    return 0;
  if (! who)
    return 0;
  if (! where)
    return 0;
  chantai1 = present("yun chantai 1",where);
  if (chantai1->query("id") != "yun chantai")
    return 0;
  chantai2 = present("yun chantai 2",where);
  if (chantai2->query("id") != "yun chantai")
    return 0;
  if (present(arg,where) != chantai1)
    return 0;
  status = check_valid_player(who);
  huli = present("huli daxian",where);  
  if (huli && huli->query("id") != "huli daxian")
    huli = 0;
  if (status == 0)
    return 0;
  if (status == 1 || ! huli)
    call_out ("failing_climb",1,me,who,where,chantai1,chantai2,huli);
  else if (who->query_temp("obstacle/chechi_chantai_times") == 0)
  {
    who->set_temp("obstacle/chechi_chantai_times",1);
    call_out ("failing_climb",1,me,who,where,chantai1,chantai2,huli);    
  }
  else if (random(3))
  {
    call_out ("failing_climb",1,me,who,where,chantai1,chantai2,huli);    
  }
  else
    call_out ("success_climb",1,me,who,where,chantai1,chantai2,huli);
  return 1;
}

void display_climb (object me, object who,
                    object chantai1, object chantai2, object huli)
{
  if (! me)
    return;
  if (! who)
    return;
  if (huli)
  {
    message_vision ("$NË³ÊÖÒ»Ö¸¡£\n",me);
    message_vision ("$NÕÐÀ´Ò»Ï¯²ÊÔÆ£¬ÂýÂý·ÉÉÏìøÌ¨¶¥×ùÅÌ¶¨£¬¿ªÊ¼´ò×ø¡£\n\n",
                    huli);
    huli->move(chantai1);
  }
  message_vision ("$NË³ÊÖÒ»Ö¸¡£\n",me);
  message_vision ("$NÕÐÀ´Ò»Ï¯²ÊÔÆ£¬ÂýÂý·ÉÉÏìøÌ¨¶¥×ùÅÌ¶¨£¬¿ªÊ¼´ò×ø¡£\n\n",
                  who);
  who->move(chantai2);
}
 
void failing_climb (object me,object who, object where,
                    object chantai1, object chantai2, object huli)
{
  display_climb (me,who,chantai1,chantai2,huli);
  call_out ("failing",30+random(10),me,who,where,huli);
}

void failing (object me,object who, object where, object huli)
{
  int i;
  if (! me)
    return;
  if (! who)
    return;
  if (environment(who)->query("name")!="ÔÆìøÌ¨")
    return;
  who->move(where);
  message_vision ("Ö»¼û$Nµ¹ÔÔ´ÐÒ»°ãË¤½«ÏÂÀ´£¬°ðµØÔÒÔÚµØÉÏ¡£\n",who);
  i = who->query_skill("dodge",1);
  if (((i>0) && (i<75)) || (wizardp(who) && i>0))
  {
    tell_object(who,"ÄãµÄ»ù±¾Çá¹¦¸ø»î»îµØË¤µôÁËÒ»¼¶£¡\n");
    who->set_skill("dodge",i-1);
  }
  i = who->query_skill("parry",1);
  if (((i>0) && (i<75)) || (wizardp(who) && i>0))
  {
    tell_object(who,"ÄãµÄ²ðÕÐÐ¶Á¦Ö®·¨¸ø»î»îµØË¤µôÁËÒ»¼¶£¡\n");
    who->set_skill("parry",i-1);
  }
  who->unconcious();
  if (! huli)
    return;
  huli->move(where);
  message_vision ("$NÌ¤×ÅÔÆ²Ê£¬ÇáÉíÎÈÎÈÂäµØ¡£\n",huli);
}

void success_climb (object me,object who, object where,
                    object chantai1, object chantai2, object huli)
{
  display_climb (me,who,chantai1,chantai2,huli);
  call_out ("success",40+random(10),me,who,where,huli);
}

void success (object me,object who, object where, object huli)
{
  if (! me)
    return;
  if (! who)
    return;

  if (environment(who)->query("name")!="ÔÆìøÌ¨")
    return;
  who->move(where);
  if (huli)
  {
    huli->move(where);
    message_vision ("$NÏñ³ÓíÈÒ»Ñù°ÈµØÔÒÔÚµØÉÏ£¬Ë¤µÃ±ÇÇàÁ³Ö×¡£\n\n",huli);
  }
  message_vision ("Ö»¼û$NÐ¯ÔÆ×ÝÉí£¬½¡²½·ÉÔ¾Ö±ÏÂ£¬ÎÈÎÈµØÂäÔÚµØÉÏ¡£\n",who);
  who->set("obstacle/chechi","chantai");
  who->save();
  message_vision ("$NÐË·ÜµØµãµãÍ·£¬Ïò$n°ÝµÀ£º¡°Çë£¡¡±\n",me,who);
}
ÿ