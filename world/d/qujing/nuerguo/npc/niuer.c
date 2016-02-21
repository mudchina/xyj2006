// rewritten by snowcat.c 4/4/1997
// niuer.c
#define NAME "Å£¶þÏÈÉú"

inherit NPC;

int is_busy;
int is_empty;

void create()
{
  set_name(NAME, ({"niuer","xiansheng","daoshi"}));
  set("gender", "ÄÐÐÔ" );
  set("age", 53);
  set("title", "ÈçÒâÕæÏÉ");
  set("long", "Å£¶þÏÈÉúÊÇÅ£Ä§ÍõµÄµÜµÜ¡£²»¹ýËûÒ»Ïò²»Ï²»¶±ðÈË½ÐËû\nÅ£¶þÏÈÉú£¬¶øÏ²»¶±»½Ð×÷ÈçÒâÏÈÉú¡£");
  set("class","taoist");
  set("combat_exp", 500000);
  set("daoxing", 800000);

  set("attitude", "peaceful");
  set_skill("unarmed", 90);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("spells",80);
  set("per", 25);
  set("max_kee", 600);
  set("max_gin", 200);
  set("max_sen", 400);
  set("force", 500);
  set("max_force", 500);
  set("inquiry", ([
        "name": "ÎÒÊÇÅ£Ä§ÍõµÄµÜµÜ£¬±ðÈË½ÐÎÒÈçÒâÏÈÉú¡£\n",
        "ÈçÒâÏÈÉú": "ÈçÒâ£¬ÈçÒâ£¬ÎÒÓÐÊ±ºò³£³£ÖÎÒ»Ð©¶Ç×Ó²»Êæ·þµÄÃ«²¡¡£\n",
        "¶Ç×Ó": "¶Ç×ÓÕÍ£¬¶Ç×Ó´ó£¬¶Ç×ÓÍ´ÎÒ¶¼¿ÉÒÔÊÔÒ»ÊÔ¡£\n",
      ]));
  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  is_busy = 0;
  is_empty = 0;
}

void return_object (object who, object ob, string id, int amount)
{
  if (! ob)
  { // money is normally destroyed when given to NPC!
    if (id == "thousand-cash")
    {
      ob = new("/obj/money/thousand-cash");
      ob->set_amount(amount/100000);
    }
    else if (id == "gold")
    {
      ob = new("/obj/money/gold");
      ob->set_amount(amount/10000);
    } 
    else if (id == "silver")
    {
      ob = new("/obj/money/silver");
      ob->set_amount(amount/100);
    } 
    else if (id == "coin")
    {
      ob = new("/obj/money/coin");
      ob->set_amount(amount);
    } 
    
    if (ob)
    {
      ob->move(who);
      tell_object(who,NAME+"½«Ò»Ð©"+ob->query("name")+"»¹¸øÄã¡£\n");
    }
  }
  else
    command("give "+who->query("id")+" "+id);  
}

int accept_object (object who, object ob)
{
  object queen;
  string msg, id;
  int amount;
  msg = NAME+"¹°ÊÖµÀ£ºÕâÎ»"+RANK_D->query_respect(who);

  amount = ob->value(); 
  id = ob->query("money_id");
  if (! id)
  {
    id = ob->query("id");
    amount = 1;
    say(msg+"Õæ¿ÍÆø¡£¶àÐ»¶àÐ»£¬²»±Ø²»±ØÀ²¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }

  if (who->query("obstacle/nuerguo") == "done")
  {
    queen = new (__DIR__"queen");
    queen->refuse_player (who);
    destruct (queen);
    say(msg+"£¬¿È¡­¡­ËµµÄÒ²ÊÇ¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "marriage")
  {
    say(msg+"»¹ÊÇÏÈÈ¥¼û¹«Ö÷°É¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "company")
  {
    say(msg+"»¹ÊÇÏÈÈ¥¼û¹«Ö÷°É¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") != "stomachache")
  {
    say(msg+"¿´À´Ã»Ê²Ã´Ã«²¡¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }
  
  if ( ob->value() < 30000) 
  {
    say(msg+"£¬¿È¡­¡­Õâ¸ö¡­¡­ÅÂÊÇ²»Í×°É¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  if (is_busy)
  {
    say(msg+"£¬Õæ¶Ô²»Æð£¬ÎÒ²»ÕýÔÚÃ¦×ÅÖÎ²¡Âð£¿\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  
  if (is_empty)
  {
    say(msg+"£¬¶Ô²»Æð£¬ÖÎ²¡µÄÈªË®ÓÃÍêÁË£¬µÈÒ»»á¶ùÔÙÀ´°É¡£\n");
    call_out ("return_object",1,who,ob,id,amount);
    return 1;
  }  

  say(msg+"ÕæÊÇÌ«¿ÍÆøÁË£¬ÎÒÕâ¾Í¸øÄúÖÎ²¡¡£\n");
  is_busy = 1;
  is_empty = 1;
  call_out("get_water",1,who);
  call_out("get_water",15,who);
  call_out("heal_stomach",30,who);
  who->start_busy(30,30); // will be reset when heal
  remove_call_out("reset_busy");
  call_out("reset_busy",30);
  remove_call_out("reset_empty");
  call_out("reset_empty",180);
  return 1;
}

void get_water (object who)
{
  if (who)
  {
    say ("\n"+NAME+"ÂýÓÆÓÆµØ×ß¹ýÈ¥£¬Ö¨Ö¨¸Â¸ÂµØÒ¡ÉÏÒ»Í°ÈªË®¡£\n\n");
    call_out("pour_water",1,who);
  }
}

void pour_water (object who)
{
  if (who)
  {
    say (NAME+"ÄÃÆðÒ»Ö»½ðÒ©ÖÑ£¬¿ÚÖÐÄîÄîÓÐ´Ê¡£\n");
    say ("Ö»¼ûÂúÂúÒ»´óÍ°Ë®¾ÓÈ»È«²¿¶¼µ¹½øÐ¡Ò©ÖÑÀï£¡\n\n");
    call_out("feed_water",1,who);
    call_out("feed_water",2,who);
    call_out("feed_water",3,who);
  }
}

void feed_water (object who)
{
  if (who)
  {
    message_vision (NAME+"ÅõÆð½ðÒ©ÖÑ£¬½«ÈªË®ÂýÂý¹à½ø$NµÄ×ìÀï¡£\n",who);
    message_vision ("Ò»¹ÉÁ¹ÒâÁ÷½ø$NµÄÌåÄÚ£¬$NµÄ¶Ç×ÓÀï¶¯ÁËÒ»ÏÂ¡£\n",who);
  }
}

void heal_stomach (object who)
{
  int res;

  if (! who)
    return;

  if (random(10)==0)
  {
    message_vision ("\n$NÃÍ¿ÈÁË¼¸ÏÂ£¬×ìÀïÇº³öÒ»Ð©µ­»ÆÉ«µÄË®£¡\n",who);
    res = 1;
  }
  else
  {
    message_vision ("\n$N·ÜÁ¦ÕÅÁËÕÅ×ì£¬Ïë¿È³öÊ²Ã´£¬¿ÉÊ²Ã´¶¼Ã»¿È³öÀ´¡£\n",who);
    res = 0;
  }
  call_out("check_result",1,who,res);
}

void check_result (object who, int res)
{
  object queen;

  if (! who)
    return;

  if (res)
  {
    say (NAME+"Á³ÉÏÂ¶³öÁËÎ¢Ð¦£º¿´Ñù×ÓÒ©ÐÔ¼«¼Ñ£¬ÖÎºÃÁË¡£\n");
    queen = new (__DIR__"queen");
    queen->announce_success (who,"ÖÎºÃÁË¸¹Ë®ÔÐ");
    destruct (queen);
  }
  else
  {
    say (NAME+"Ì¾ÁËÒ»¿ÚÆø£ºàÅ£¬Ã»ÓÐÖÎºÃ£¬»¹µÃÔÙÀ´¿´Ò»´Î¡£\n");
  }
  who->interrupt_me();
}

void reset_busy ()
{
  is_busy = 0;
}

void reset_empty ()
{
  is_empty = 0;
}
ÿ