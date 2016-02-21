// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("¹úÍõ", ({"guo wang", "king" }));
  set("title","±¦Ïó¹ú");
  set("gender", "ÄĞĞÔ");
  set("rank_info/respect", "±İÏÂ");
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
  set("combat_exp", 220000);
  set("daoxing", 150000);

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
  set("eff_dx",15000);
  set("nkgain",110);
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void check_princess(object me);

void init()
{
  ::init();
  check_princess(this_object());
}

int accept_object (object who, object ob)
{
  object me = this_object();
  object room = environment(me);

  if (room->query("short")!="ÌìµØ¸ó")
    return 0;

  if (ob->query("id")=="mi xin" &&
      who->query_temp("obstacle/baoxiang")=="got_letter")
  {
    remove_call_out("read_letter");
    call_out("read_letter",3,me,who,ob);
    return 1;
  }
  return 0;
}

void read_letter (object me, object who, object ob)
{
  destruct (ob);
  reset_eval_cost();
  // first time get letter from player
  if (who->query("obstacle/baoxiang")=="got_letter")
  {
    message_vision("$N¶Á°ÕÃØĞÅ£¬²»½ûÌéÀá¾ãÏÂ¡£\n",me);
    message_vision("$NµÀ£ºÎá¶ù²»ĞÒ£¬±»ÑıÒĞÇ¿°ÕÕ¼ÎªÆŞ£¬ÒÑÓĞÊ®ÈıÄêÖ®¾Ã£¡\n\n",me);
    message_vision("´Ë¿ÌÈı¹¬µÎÀá£¬ÎÄÎäÉËÇé£¬¹¬ÖĞÒ»Æ¬¿ŞÉù¡£\n",me);
  }
  // already given letter before
  else
  {
    message_vision("$N¶Ô$nµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                   "£¬ÓÖÀ´ÏàÖú£¬½Ì¹ÑÈË½ñÉúÈçºÎÏà±¨¡£\n",me,who);
  }
  remove_call_out("send_to_fight");
  call_out("send_to_fight",3,me,who);
}

void send_to_fight (object me, object who)
{
  object ling = new ("/d/qujing/baoxiang/obj/ling");
  ling->move(who);
  message_vision("$N´óÉùËµµÀ£ºÁî$nĞË±øÁì½«£¬Óë¹ÑÈË×½É±ÑıÄ§£¬¾ÈÎÒ°Ù»¨¹«Ö÷£¡\n\n",
                 me,who);
  message_vision("ÅÔ±ßÔçÓĞ¾ü»ú´ó³¼ÉÏÇ°µİ¸ø$nÒ»Ö§¾üÁîÅÆ¡£\n",me,who);
  who->set("obstacle/baoxiang","given_letter");
  who->set_temp("obstacle/baoxiang","given_letter");
  who->save();
}

void check_princess(object me)
{
  object room = environment(me);
  object baihua = present("baihua xiu",room);
  object who;
  object ling;

  reset_eval_cost();
  if (room->query("short")!="ÌìµØ¸ó")
    return;
  if (baihua == 0)
    return;

  if (baihua->query("leader")==0)
    return;
  who = present(baihua->query("leader"),room);
  if (who == 0)
    return;
  if (who->query_temp("obstacle/baoxiang")!="given_letter")
    return;
  ling = present ("junling pai",who);
  if (ling == 0)
    return;
  
  baihua->set_leader(0);
  baihua->set_temp("no_return",0);
  remove_call_out ("cry_princess");
  call_out ("cry_princess",2,me,baihua);
  remove_call_out ("announce_success");
  call_out ("announce_success",4,me,who);
}

void cry_princess (object me, object baihua)
{
  message_vision("$N¼ûÁË$nÒ»ã¶£¬È»ºóÀÏÀá×İºáµØ½«$nÀ­¹ıÈ¥¡£\n",me,baihua);
}

void announce_success (object me, object who)
{//disabled announce and reward...
  int i;
  who->add("obstacle/number",1);
  who->set("obstacle/baoxiang","done");
  who->set_temp("obstacle/baoxiang","done");
  i = random(800);
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"ĞË±øÁì½«£¬Ìæ±¦Ïó´ó¹ú×½É±ÑıÄ§£¬½â¾È°Ù»¨¹«Ö÷£¡");
  command("chat "+who->query("name")+"Ë³Àû´³¹ıÎ÷ĞĞÓÖÒ»¹Ø£¡");
  tell_object (who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");
  who->save();
}

ÿ
