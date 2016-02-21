// by snowcat 

inherit NPC;

#include <quest_ak.c>
#include <reporting.c>

string *strs = ({
    "$NÈ¼ÆðÒ»¸ùÏã¼ÀìëÒ»·¬£¬¶Ô$nËµµÀ£º×æÁéÔÚÌì£¬ÇëÄúÈ¥°Ý¼û$w²¢Ñ¯ÎÊÓÐ¹Ø$oÒ»ÊÂ¡£\n",
    "$N½«ÊÖÖÐÏãµãÈ¼¶Ô$nËµµÀ£ºÀÏ·ò¼À±Ï×æ×Ú£¬µÃÖªÓÐ$wÖªµÀ$oÖ®ÊÂ£¬Äú¿É·ñÈ¥Çë¼û£¿\n",
    "$NÄéÏãÏò×æ×ÚÒ»°Ý£¬×ªÉí¶Ô$nËµµÀ£º¿É·ñÈ¥°Ý¼û$w£¬²¢¸æÖª$oÒ»ÊÂ£¿\n",
    "$N½«ÏãµãÈ¼£¬¶Ô$nËµµÀ£ºÔÚÌì×æÁéÈÃÄú¾Í$oÒ»ÊÂ°Ý·Ã$w£¬Çë¾¡Ôç¶¯ÉíÒ²¡£\n",
    "$N¶Ô$nËµµÀ£ºÀÏ·ò°ÝÁË×æ×Ú£¬ÕýÈ±ÈËÈ¥°Ý·Ã$w£¬¸æÖª$oÖ®ÊÂ¡£\n",
    "$NÈ¼ÏãÍê±Ï£¬»ØÍ·¶Ô$nËµµÀ£º²»Öª¿É·ñÈ¥°Ý¼û$w£¬Ì½ÎÊ$oÒ»ÊÂ¡£\n",
    "$NÔÚÏã»ðÖÐ»º»ºÏò×æ×ÚÒ»°Ý£¬ÔÙ¶Ô$nËµµÀ£º×æÁéÔÚÌìÇëÄúÈ¥°Ý¼û$w²¢¸æÖª$oÖ®ÊÂ¡£\n",
  });  

// mon 3/22/99
string get_message(string str1, string str2)
{
    string str;
    string *msg1=({"$NÈ¼ÆðÒ»¸ùÏã¼ÀìëÒ»·¬£¬¶Ô$nËµµÀ£º×æÁéÔÚÌì£¬ÇëÄúÈ¥"});
    string *msg2=({"°Ý¼û","³¯ÎÊ","ÎÊºò","°Ý·Ã","Çó¼û","¿´Íû","·ÃÎÊ","ÖÂÒâ",
	    "ÎÊºòÒ»ÏÂ","°Ý·ÃÒ»´Î","°Ý¼ûÒ»´Î","ÎÊºòÒ»»Ø","¿´ÍûÒ»ÏÂ","Çó¼ûÒ»´Î",
	    "·ÃÎÊÒ»´Î","·ÃÎÊÒ»»Ø","°Ý·ÃÒ»»Ø","ÖÂÒâÒ»´Î","°Ý·ÃÒ»ÏÂ","¿´ÍûÒ»ÏÂ",
	    "°Ý¼û°Ý¼û","ÎÊºòÎÊºò","°Ý·Ã°Ý·Ã","¿´Íû¿´Íû"});
    string *msg3=({"£¬Ë³Â·","£¬²¢","£¬²¢ÇÒ","£¬Ò»¶¨","£¬¾¡Á¦",
	    "²¢","²¢ÇÒ",});
    string *msg4=({"Ì½Ìý","Ë÷ÎÊ","ÇëÎÊ","´òÌý","Ì½ÎÊ","²éÑ¯","Ì½Öª","Ñ°²é",
	           "Ì½·Ã","µ÷²é","²éÖª","Ì½·Ã","µ÷²é","¹ýÎÊ","´òÌ½","²éÃ÷",
	    "Ì½·ÃÌ½·Ã","Ñ°²éÑ°²é","´òÌ½´òÌ½","Îñ±ØÌ½Ã÷","Ò»¶¨Ì½Öª","µ÷²éµ÷²é",
	    "Ì½ÌýÓÐ¹Ø","´òÌ½ÓÐ¹Ø","´òÌýÓÐ¹Ø","²éÑ¯ÓÐ¹Ø","Ì½ÖªÓÐ¹Ø","Ì½ÎÊÓÐ¹Ø",
            "Ì½Ìý¹ØÓÚ","´òÌ½¹ØÓÚ","´òÌý¹ØÓÚ","²éÑ¯¹ØÓÚ","Ì½Öª¹ØÓÚ","Ì½ÎÊ¹ØÓÚ",
	    "²éÎÊÓÐ¹Ø","²éÎÊ¹ØÓÚ","µ÷²éÓÐ¹Ø","µ÷²é¹ØÓÚ","ÇëÎÊÓÐ¹Ø","ÇëÎÊ¹ØÓÚ",
	    "Ì½ÌýÌ½Ìý","´òÌý´òÌý","Ì½ÎÊÌ½ÎÊ","²éÃ÷ÓÐ¹Ø","¹ýÎÊÓÐ¹Ø"});
    string *msg5=({"Ò»ÊÂ","Ö®ÊÂ","µÄÏûÏ¢","µÄÇé¿ö","µÄÎÊÌâ",});
    string *msg6=({"£¡","¡£","¡£¡£¡£",});
    
    if(random(10)<3)
      str = strs[random(sizeof(strs))];
    else {
	str=msg1[random(sizeof(msg1))]+
	    msg2[random(sizeof(msg2))]+"$w"+
	    msg3[random(sizeof(msg3))]+
	    msg4[random(sizeof(msg4))]+"$o"+
	    msg5[random(sizeof(msg5))]+
	    msg6[random(sizeof(msg6))]+"\n";
    }
    str = replace_string (str, "$w", str1);
    str = replace_string (str, "$o", str2);
    return str;
}

void show_message(object who)
{
    string str;

    if(!who) return;
    if (! who->query("quest/pending/ask"))
	return;
    str=who->query("quest/pending/ask/message");
    if(!str) 
      message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·ò²»ÊÇÇëÄúÈ¥¼û"+who->query("quest/pending/ask/name")+
                    "Ñ¯ÎÊ"+who->query("quest/pending/ask/topic")+"Ò»ÊÂÂð£¿\n",
		    this_object(),who);
    else
      message_vision(str,this_object(),who);
}

int test_player();

void create()
{
  set_name("³Â¹âÈï", ({"chen guangrui", "chen", "guangrui"}));
  set("long", "³Â¹âÈïÄËÐþÞÊÖ®¸¸£¬µ±³¯´ó²û¶¼¸ÙÓù´Í×´Ôª¡£\n");
  set("title", "´ó²û¶¼¸Ù");
  set("gender", "ÄÐÐÔ");
  set("age", 50);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "scholar");
  set("shen_type", 1);
  set("combat_exp", 40000);
  set("daoxing", 100000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("literate", 180);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "¹âÈï´óÊ¦ËµµÀ£ºÉÆÔÕÉÆÔÕÄÄ¡£\n",
    "¹âÈï´óÊ¦×ÔÓïµÀ£ºÊÀÉÏÏÍÈË£¬ÓÐÇó±ØÓ¦ÄÄ¡£\n",
    "¹âÈï´óÊ¦ËµµÀ£º¼À×æÇóÏÍ£¬ÄËË®Â½´ó»áÇ°Ö®±ØÐèÒ²¡£\n",
    "¹âÈï´óÊ¦Ì¾ÑÔµÀ£ºÌìÏÂÕÐÏÍ£¬Àû¹úÀûÃñÖ®´ó²ßÒ²¡£\n",
    "¹âÈï´óÊ¦ËµµÀ£º°Ë·½ÇóÏÍÒ²¡£\n",
    "¹âÈï´óÊ¦ËµµÀ£º·ÙÏã¼À×æ£¬ÒÔÕÐÌìÏÂÕÐÏÍÊ¿¡£\n",
  }));
  set("inquiry", ([
        "here":   "´ËÄËÓíÍõÌ¨Ò²£¬Ë®Â½´ó»á½«²»ÆÚ¾ÙÐÐ£¬±¾×´ÔªÔÚ´ËÔ¤×ö·¨³¡ÒÔ¼À×æÇóÏÍ¡£\n",
        "name":   "ÐþÞÊÖ®¸¸³Â¹âÈïÒ²£¬ÔÚ´Ë×ö·¨¼À×æÇóÏÍ¡£\n",
        "ask":   (: test_player() :),
        "¼À×æ":   (: test_player() :),
        "ÇóÏÍ":   (: test_player() :),
        "ÕÐÏÍ":   (: test_player() :),
        "ÏÍÈË":   (: test_player() :),
        "ÏÍÊ¿":   (: test_player() :),
        "ÉÆÔÕ":   (: test_player() :),
        "ÕÐ":   (: test_player() :),
        "Çó":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *acks = ({
    "ÖªµÀÁË¡£\n",
    "ÎÒÕâ¾Í»á¶¯Éí£¬ÄúÇëÏÈ»Ø°É¡£\n",
    "ºÃµÄ¡£\n",
    "¶àÐ»À´·Ã£¬ÎÒÕâ¾ÍÈ¥°ì¡£\n",
    "ºÃ£¬ÎÒÂíÉÏ¾ÍÈ¥×¼±¸¡£\n",
  });
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  string str;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·ò¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/ask"))
  {
      call_out("show_message",1,who);

//    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
//                    "£¬ÀÏ·ò²»ÊÇÇëÄúÈ¥¼û"+who->query("quest/pending/ask/name")+
//                    "Ñ¯ÎÊ"+who->query("quest/pending/ask/topic")+"Ò»ÊÂÂð£¿\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_ask);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/ask");
  if (i == -1)
  {
    message_vision ("$N¶Ô$nÌ¾ÆøËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "¸Ã×öµÄÊÂ×öÁË²»ÉÙ£¬ÀÏ·ò¿´Äú»¹ÊÇÒÔºóÔÙÀ´°É¡£\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_ask[quest_keys[i]];
  who->set("quest/pending/ask/index", i);
  who->set("quest/pending/ask/daoxing", quest_keys[i]);
  who->set("quest/pending/ask/name", quest[IDX_NAME]);
  who->set("quest/pending/ask/id", quest[IDX_ID]);
  who->set("quest/pending/ask/topic", quest[IDX_OBJ]);
  who->set("quest/pending/ask/acknowledge", acks[random(sizeof(acks))]);
  who->set("quest/pending/ask/time", delay);
  
  str=get_message(quest[IDX_NAME], quest[IDX_OBJ]);
  who->set("quest/pending/ask/message",str);

//  str = strs[random(sizeof(strs))];
//  str = replace_string (str, "$w", quest[IDX_NAME]);
//  str = replace_string (str, "$o", quest[IDX_OBJ]);
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  int t;

  if (!who || !visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "ÉíÉÏÏéÔÆ»·ÈÆ£¬ÇëËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¡\n",me,who);
    return;
  }

  if (! who->query("quest/pending/ask"))
    return;

  if (! who->query("quest/pending/ask/done"))
  {
      call_out("show_message",1,who);
//    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
//                    "£¬ÀÏ·ò²»ÊÇËµ¹ýÇëÈ¥°Ý¼û"+who->query("quest/pending/ask/name")+
//                    "²¢¸æÖ®"+who->query("quest/pending/ask/topic")+"Ò»ÊÂÂð£¿\n",me,who);
    return;
  }

  t = who->query("quest/pending/ask/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N¶Ô$n¾ªÌ¾µÀ£ºÄúÒÑ¾­»ØÀ´ÁË£¿²»»áÕâÃ´¿ì°É¡£\n",me,who);
    message_vision ("$N¿´ÁËÒ»ÑÛÏãËµµÀ£ºÕâÏã»¹Ðè"+chinese_number((t-uptime())/60+1)+
                    "·ÖÖÓ²ÅÈ¼¾¡£¬µ½Ê±ÄúÔÙÀ´°É¡£\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ÈÃ³Â¹âÈïÖ±½ÓÈÏ¿É¡£\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "¼À×æ°ÝÏÍ£¬¾Í"+who->query("quest/pending/ask/topic")+
           "Ò»ÊÂ°Ý¼ûÁË"+who->query("quest/pending/ask/name")+"£¬";
  message_vision ("$N¶Ô$nËµµÀ£º¶àÐ»ÕâÎ»"+RANK_D->query_respect(who)+
                  reason+"ÕæÊÇÆ·ÐÐ¿É¼ÎÒ²¡£\n",me,who);
  reward = quest_reward(who, quests_ask, "ask");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/ask/times",1);
  who->add("quest/ask/reward",reward);
  reporting (who,reason, reward, "½±·Ö");
  who->delete("quest/pending/ask");
  quest_done(who);
}


ÿ
