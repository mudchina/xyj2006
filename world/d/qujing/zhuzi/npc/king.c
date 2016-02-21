// by snowcat 11/6/1997

inherit NPC;

int test_player (object me);
object copy_yao(object ob);

void create()
{
  set_name("¹úÍõ", ({"guo wang", "wang", "king"}));
  set("long", "Öì×Ï¹úµÄ¹úÍõ£¬Í·´÷Öì½ğ¹Ú£¬ÊÖÖ´×Ï½ğÕÈ¡£\n");
  set("title", "Öì×Ï¹ú");
  set("gender", "ÄĞĞÔ");
  set("rank_info/respect", "±İÏÂ");
  set("age", 46);
  set("per", 30);
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
        "name":   "ëŞÄËÖì×Ï¹ú¹úÍõÒ²£¬½üÀ´ÉíÌå²»ÊÊ£¬¾ÃÒ½ÄÑÓú¡£",
        "Íõºó":   "ëŞÖ®ºó£¬Î¨½ğÊ¥¹¬ºóÒÑ±ğÈıÄêÒÓ¡£",
        "½ğÊ¥¹¬": "½ğÊ¥¹¬²»ÔÚÒÑÈıÄêÒÓ¡£",
        "²»ÊÊ":   (: test_player :),
        "²¡":     (: test_player :),
        "Ò½":     (: test_player :),
        "Ò½ÖÎ":   (: test_player :),
        "Ò½ÁÆ":   (: test_player :),
        "Ò©":     (: test_player :),
        "³ÔÒ©":   (: test_player :),
      ]));

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void throw_player (object who)
{
  object me = this_object();

  message_vision ("$NºÈÁËÒ»Éù£ºËÍ¿Í£¡\n", me, who);
  message_vision ("¼¸Î»Ì«¼à×ßÀ´¶ş»°²»Ëµ¼ÜÆğ$N¾Í×ß¡£\n", who);
  who->move("/d/qujing/zhuzi/hugong1");
  call_out ("in_river",1,who);
  me->start_busy(1,1);
}

void in_river (object who)
{
  message_vision ("$N»º¹ıÉñÀ´£¬·¢ÏÖ×Ô¼º±»ÈÓÔÚ±ùÀäµÄ»¤¹¬ºÓË®Àï¡£\n", who);
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$NËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<10000)
  {
    inform_player (msg+"µÀĞĞ²»¹»£¬ÅÂÊÇÓ¹Ò½Ò²£¡\n",who);
    call_out("throw_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/zhuzi") == "done" ||
      who->query_temp("obstacle/zhuzi_cured"))
  {
    inform_player (msg+"£¬¶àĞ»¶àĞ»£¬ëŞÔÙ°İ¶ÙÊ×£¡\n",who);
    return 1;
  }  

  if (this_object()->query_temp("cured"))
  {
    inform_player (msg+"²»±Ø¶àÂÇ£¬ëŞÒÑ¿µ¸´£¡\n",who);
    return 1;
  }  

  inform_player (msg+"£¬¿É·ñÎªëŞÑ°µÃÎÚ½ğµ¤£¿\n",who);
  who->set_temp("obstacle/zhuzi_asked",1);
  call_out ("wait_player",300,who);
  return 1;
}

void wait_player (object who)
{
  if (who)
    who->set_temp("obstacle/zhuzi_waited",1);
}

int accept_object (object who, object ob)
{
  object me = this_object();
  object ob2;
  string msg = "$NËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who);

  if (ob->query("id") != "yao")
  {
    inform_player (msg+"£¬ëŞÒÑÓµÓĞ½­É½Éçğ¢£¬Æñ¿ÉÓÃÕâĞ¡¶÷»İ´ò¶¯ëŞĞÄ£¡\n",who);
    call_out("throw_player",1,who);
    call_out("destroy_object",1,ob);
    return 1;    
  }

  if (who->query("combat_exp")<10000)
  {
    inform_player (msg+"µÀĞĞ²»¹»£¬ÅÂÊÇ¼ÙÒ©Ò²£¡\n",who);
    call_out("throw_player",1,who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (who->query("obstacle/zhuzi") == "done" ||
      who->query_temp("obstacle/zhuzi_cured"))
  {
    inform_player (msg+"£¬¶àĞ»¶àĞ»£¬ëŞÔÙ°İ¶ÙÊ×£¡\n",who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (this_object()->query_temp("cured"))
  {
    inform_player (msg+"²»±Ø¶àÂÇ£¬ëŞÒÑ¿µ¸´£¡\n",who);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  if (! who->query_temp("obstacle/zhuzi_waited"))
  {
    inform_player (msg+"£¬ÎÚ½ğµ¤ÄË¹óÖØÖ®Ò©£¬¾ÃÑ°²Å¿ÉµÃ£¬ÕâÒ©ÅÂÊÇÓĞ¼Ù£¡\n",who);
    call_out("delayed_vision",1,"$N½«Ò©ÍùÅÔ±ßÓñÍ°ÀïÒ»ÈÓ¡£\n",me);
    call_out("destroy_object",1,ob);
    return 1;
  }  

  message_vision ("$N½ÓÏÂÒ©£¬¶Ô$nÁ¬ÉùµÀĞ»¡£\n",me,who);
  call_out("delayed_vision",3,
           "ÔçÓĞ¼¸Î»¹¬Å®½øÀ´£¬ËÅºò×Å$N½«Ò©ÓÃÎŞ¸ùË®·şÏÂ¡£\n",me); 
  ob2 = copy_yao(ob);
  call_out("eat_drug",1,me,ob2,who);
  return 1;
}

void delayed_vision (string msg, object me)
{
  message_vision (msg,me);  
}

void destroy_object (object ob)
{
  destruct (ob);
}

void eat_drug (object me, object ob, object who)
{
  int i = who->query_temp("obstacle/zhuzi_given");

  if (! ob->query_temp("is_ready"))
  {
    message_vision ("$NÍ»È»Ò»Õó×Ó¸¹Í´£¬²»½û´óÉùÉëÒ÷ÆğÀ´¡£\n",me,who);
    message_vision ("$NËµµÀ£º¼ÙÒ©£¬¼ÙÒ©Ò²£¡\n",me,who);
    call_out("throw_player",1,who);
    destruct (ob);
    return;
  }
  if (i < 2)
  {
    message_vision ("ÉÙÇê£¬$N½¥¾õĞÄĞØ¿íÌ©£¬ÆøÑªµ÷ºÍÒ»Ğ©ÁË¡£\n",me);
    me->command_function("thank "+who->query("id"));
  }
  else
  {
    message_vision ("$NÖÕÓÚÍÂ³öÒ»Ğ©»àÎï£¬¾«Éñ¶¶ËÓÆğÀ´£¬Á³É«Ò²»Ö¸´ÁË¡£\n",me);
    message_vision ("\n$N¶Ô$nËµµÀ£º¶÷ÈËÇéÖØÈçÉ½£¬¹ÑÈË³êĞ»²»¾¡£¡\n",me,who);
    me->set_temp("cured",1);
    who->set_temp("obstacle/zhuzi_cured",1);
    call_out("say_more",5,me,who);
  }
  who->set_temp("obstacle/zhuzi_given",i+1);
  destruct (ob);
}

void say_more (object me, object who)
{
  message_vision ("\n$NËµµÀ£º·½²ÅÍÂ³öµÄ»àÎï£¬ÄËÈıÄêÖ®»ıÖÍÒ²¡£\n",me);
  message_vision ("$NÓÖËµµÀ£ºÈıÄêÁË£¬ëŞÎŞÖçÎŞÒ¹µØË¼Äî½ğÊ¥¹¬¡£\n",me);
  call_out("say_more2",3,me,who);
}

void say_more2 (object me, object who)
{
  message_vision ("\n$NÏëÏë¶Ô$nËµµÀ£º¶÷ÈË¿É·ñÌæëŞ¾È½ğÊ¥Íõºó»Ø¹¬£¿\n",me,who);
}

// by wuliao.
// since the give command destruct the object quickly, we need get a new object
// with the same attributes
object copy_yao ( object me )
{
	object who = new ( "/d/qujing/zhuzi/obj/yao.c");

	who -> set("name", me->query("name"));
	who -> set_temp("is_ready", me->query_temp("is_ready") );
	who -> move(this_object());
	
	return who;
}ÿ
