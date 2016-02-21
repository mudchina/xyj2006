// by snowcat

inherit NPC;

#include <quest_kl.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("ºú¾´µÂ", ({"hu jingde", "hu", "jingde"}));
  set("long", "Ò»Î»ÉíÅûÕ½ÅÛ£¬ÃæÈÝ×¯ÖØÑÏËàµÄÓùÁÖ¶¼¶½¡£\n");
  set("title", "°ËÊ®ÍòÓùÁÖ¶¼¶½");
  set("gender", "ÄÐÐÔ");
  set("age", 60);
  set("per", 35);
  set("attitude", "peaceful");
  set("class", "fighter");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 400000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",100);
  set("chat_chance",10);
  set("chat_msg",({
    "¶¼¶½´óÈËÅ­·¢³å¹Ú£¬½«¾ªÌÃÄ¾Å¾µØÒ»ÅÄ£¬ºÈµÀ£ºÉ±£¡\n",
    "¶¼¶½´óÈËÅ­µÀ£ºÉ±¾¡ÌìÏÂÑýÄ§¹í¹Ö£¡\n",
    "¶¼¶½´óÈËÅÄ×Å¾ªÌÃÄ¾ºðµÀ£ºÑýÔô£¡\n",
    "¶¼¶½´óÈËÅ­²»¿É¶ô£ºÕ¶¾¡É±¾ø£¡\n",
    "¶¼¶½´óÈËºßÁËÒ»Éù£ºÉ±£¡\n",
    "¶¼¶½´óÈËËµµÀ£ºÒªÉ¨³ýÒ»ÇÐÅ£¹íÉßÉñ£¡\n",
  }));
  set("inquiry", ([
        "here":   "´ËÄËÓíÍõÌ¨Ò²£¬Ë®Â½´ó»á½«²»ÆÚ¾ÙÐÐ£¬±¾¶¼¶½ÔÚ´ËÔ¤×ö·¨³¡£¬É±¾¡ÑýÄ§¹í¹Ö£¡\n",
        "name":   "°ËÊ®ÍòÓùÁÖ¶¼¶½ºú¾´µÂÒ²£¬ÔÚ´Ë×ö·¨£¬ÒÔÉ±¾¡ÑýÄ§¹í¹Ö£¡\n",
        "kill":   (: test_player() :),
        "ÑýÄ§":   (: test_player() :),
        "ÑýÔô":   (: test_player() :),
        "¹í¹Ö":   (: test_player() :),
        "Å£¹í":   (: test_player() :),
        "ÉßÉñ":   (: test_player() :),
        "É±¾¡":   (: test_player() :),
        "É±":   (: test_player() :),
        "Õ¶":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$NÑ¸ËÙµØÒ»Õ¼ØÔ£¬½«¾ªÌÃÄ¾Å¾µØÒ»ÅÄ¶Ô$nËµµÀ£ºÈ¥½«$w½µ·þÁË£¡\n",
    "$NºßÁËÒ»Éù¶Ô$nËµµÀ£ºÀÏ·ò¸ÕÕ¼ÁËÒ»ØÔ£¬ÒÑÖª$wµÄÑôÊÙÒÑ¾¡£¬È¥È¥£¬½«Ö®Õ¶ÁË£¡\n",
    "$NµÍÍ·Ò»¿´ØÔ£¬¶Ô$nËµµÀ£º$w×ï¸ÃÍòËÀ£¬ÄúÈ¥Ò»Ôâ½«´ËÊÂÁËÖ®¡£\n",
    "$N¿´ÍêØÔ¶Ô$nËµµÀ£ºÀÏ·òÕýÈ±ÈËÈ¥½µ·þ$w£¬Äú¿É·ñ×ßÒ»ÌË£¿\n",
    "$NÅ­·¢³å¹Ú£¬¶Ô$nËµµÀ£º$wÎª·Ç×÷´õ£¬Äú»ðËÙÈ¥½«Ö®ÁË½áµô£¡\n",
    "$N½«ØÔÒ»Õ¼£¬»ØÍ·¶Ô$nËµµÀ£ººÃ£¬ÕýÊÇÊ±ºò£¡ÄúÈ¥½«$w½µ·þµô£¡\n",
    "$NÕ¼ØÔÍê±Ï¶Ô$nËµµÀ£ºÈ¥È¥£¬½«$wÉ±µô£¡\n",
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

  if (who->query("quest/pending/kill"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·ò²»ÊÇÇëÄúÈ¥½µ·þ"+who->query("quest/pending/kill/name")+"Âð£¿\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_kill);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/kill");
  if (i == -1)
  {
    message_vision ("$N¶Ô$nÌ¾ÆøËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "¸Ã×öµÄÊÂ×öÁË²»ÉÙ£¬ÀÏ·ò¿´Äú»¹ÊÇÒÔºóÔÙÀ´°É¡£\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_kill[quest_keys[i]];
  who->set("quest/pending/kill/index", i);
  who->set("quest/pending/kill/daoxing", quest_keys[i]);
  who->set("quest/pending/kill/name", quest[IDX_NAME]);
  who->set("quest/pending/kill/id", quest[IDX_ID]);
  who->set("quest/pending/kill/time", delay);
  str = strs[random(sizeof(strs))];
  str = replace_string (str, "$w", quest[IDX_NAME]);
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

  if (! who->query("quest/pending/kill"))
    return;

  if (! who->query("quest/pending/kill/done"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·ò²»ÊÇÇëÄúÈ¥½µ·þ"+who->query("quest/pending/kill/name")+"Âð£¿\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/kill/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N¶Ô$n¾ªÌ¾µÀ£ºÄúÒÑ¾­»ØÀ´ÁË£¿²»»áÕâÃ´¿ì°É¡£\n",me,who);
    message_vision ("$N¸©ÉíÓÖ¿´ÁËÒ»ÑÛØÔËµµÀ£ºÄú»¹ÊÇ"+chinese_number((t-uptime())/60+1)+
                    "·ÖÖÓºóÔÙÀ´°É¡£\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ÈÃ¶¼¶½´óÈËÖ±½ÓÈÏ¿É¡£\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "³ýÑýÃð¹Ö£¬½µ·þÁË"+who->query("quest/pending/kill/name")+"£¬";
  message_vision ("$N¶Ô$nËµµÀ£º¶àÐ»ÕâÎ»"+RANK_D->query_respect(who)+
                  reason+"ÕæÊÇÆ·ÐÐ¿É¼ÎÒ²¡£\n",me,who);
  reward = quest_reward(who, quests_kill, "kill");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/kill/times",1);
  who->add("quest/kill/reward",reward);
  reporting (who,reason, reward, "½±·Ö");
  who->delete("quest/pending/kill");
  quest_done(who);
}


ÿ
