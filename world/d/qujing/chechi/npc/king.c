// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("¹úÍõ", ({"guo wang", "king" }));
  set("title","³µ³Ù¹ú");
  set("gender", "ÄÐÐÔ");
  set("rank_info/respect", "±ÝÏÂ");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 50);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 260000);
  set("daoxing", 100000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("seashentong", 50);
  set_skill("dragonforce", 50);
  set_skill("dragonstep", 50);
  set_skill("dragonfight", 50);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("spells", "seashentong");
  set("eff_dx",30000);
  set("nkgain",180);
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init()
{
  call_out("follow_player",2,this_object(),this_player());
}

int follow_player (object me, object who)
{
  object where = environment (me);
  object yangli = present("yangli",where);
  object huli = present("huli",where);
  object luli = present("luli",where);

  me->set_temp("no_return",1);
  if (where->query("short") != "½ðöÇµî")
    return 1;
  if (! yangli || ! huli || ! luli)
    return 1;
  if (! who)
    return 1;
  if (who->query("obstacle/chechi")=="done")
    return 1;
  if (who->query_temp("obstacle/chechi")!="eaten")
    return 1;
  if (environment(who) != where)
    return 1;
  if (me->query_temp("follow")==who->query("id"))
    return 1;
  message_vision ("\n¹úÍõµÀÉù£º¡°ÈýÎ»¹úÊ¦ÇëÁË£¡¡±\n",who);
  yangli->set_leader(me);
  huli->set_leader(me);
  luli->set_leader(me);
  message_vision ("\nÈý´óÏÉ´ÕÉÏÇ°È¥£¬¹òÔÚ¹úÍõ½ÅÏÂ£¬µÍÉùËµ×ÅÊ²Ã´¡£\n\n",me);

  remove_call_out("continue_follow");
  call_out("continue_follow",4,me,who);
  remove_call_out("continue_following");
  call_out("continue_following",8,me,who);
  remove_call_out("following_player");
  call_out("following_player",12,me,who);
  return 1;
}

int continue_follow (object me, object who)
{
  message_vision ("$N³Ô¾ªµØ°¡ÁËÒ»Éù¡£\n",me);
  message_vision ("$NÅ­µÀ£º¡°´óµ¨ÍýÍ½£¬¾¹¸ÒÆÛÆ­¹úÊ¦£¡¡±\n\n",me);
  if (who && environment(me)==environment(who))
  {
    message_vision ("$N²»½û¡°°È¡±µØÒ»Éù¹òÏÂ¡£\n\n",who);
    who->start_busy (9,10);
  }
  return 1;
}

int continue_following (object me, object who)
{
  object where = environment (me);
  object taijian = present ("tai jian",where);

  if (taijian)
    message_vision ("Ì«¼à´ÕÉÏÈ¥£¬µÍÉùÃÜÓï¡£\n",me);
  message_vision ("$NÏëÁËÒ»Ïë£¬Î¢Î¢µãÁËµãÍ·¡£\n\n",me);
  return 1;
}

int following_player (object me, object who)
{
  object where = environment (me);
  object taijian = present ("tai jian",where);

  if (where->query("short") != "½ðöÇµî")
    return 1;
  if (! who)
    return 1;
  if (who->query("obstacle/chechi")=="done")
    return 1;
  if (who->query_temp("obstacle/chechi")!="eaten")
    return 1;
  if (environment(who) != where)
    return 1;
  if (me->query_temp("follow")==who->query("id"))
    return 1;

  if (taijian)
  {
    message_vision ("$N×ßÉÏÇ°À´£¬¾ö¶¨¸úËæ$nÒ»ÆðÐÐ¶¯¡£\n\n",taijian,who);
    taijian->set_temp("no_return",1);
    taijian->set_leader(who);
  }
  message_vision ("$N¸©ÊÓ×Å$nËµµÀ£ºÈôÕæÊÇÔ¶µÀÏÉ¿Í£¬ÇÒ²»·ÁÓëÈý¹úÊ¦Ò»±È¡£\n",
                  me,who);
  message_vision ("\n$NÓÖµÀ£º¡°ÊÇËÀÊÇ»î£¬¼àÕ¶¹ÙÇ°¼û·ÖÏþ£¡¡±\n",me);
  message_vision ("$N¾ö¶¨¿ªÊ¼¸úËæ$nÒ»ÆðÐÐ¶¯¡£\n",me,who);
  who->interrupt_me(who,"");
  me->set_temp("follow",who->query("id"));
  me->set_leader(who);
  who->set_temp("obstacle/chechi","seen_king");
  return 1;
}

void announce_success(object who)
{//disabled announce and reward...
  int i;

  if (who->query("obstacle/chechi") == "done")
  {
    tell_object (who,"ÄãÒÑ¾­¹ýÁËÕâÒ»¹Ø£¬Ê²Ã´¶¼µÃ²»µ½ÁË£¡\n");
    return;
  }  

  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/chechi","done");
  who->add("daoxing",i+5000);
  command("chat "+who->query("name")+"³µ³Ù¹úÊ©Õ¹Ê¥ÊÖ£¬´óÆÆÑýµÀ£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ýÎ÷ÐÐÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(5)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
  command("follow none");
}
ÿ
