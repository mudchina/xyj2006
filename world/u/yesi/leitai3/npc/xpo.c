// by snowcat 

inherit NPC;

#include <quest_am.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("ÏàÆÅ", ({"xiang po", "xiang", "po"}));
  set("gender", "Å®ÐÔ");
  set("title", "Óù´Í");
  set("age", 75);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 15000);
  set("daoxing", 50000);

  set_skill("unarmed", 10);
  set_skill("dodge", 25);
  set_skill("parry", 25);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("chat_msg",({
    "ÏàÆÅ¸ßÐËµØËµ£ºÏà¹«Ò²ËµÀ²£¬Ææ»õÕ÷¼¯ÁË²»ÉÙ£¬¿É½üÆÚÅÉÈË½«¿ø¼×»¤¾ßËÍµ½¾©³Ç¡£\n",
    "ÏàÆÅËµµÀ£º»Ê¹¬ÀïÈËËµÎÒÃÇÏà¸®ÊÕ¼¯ÁË²»ÉÙºÃ¿ø¼×»¤¾ß¡£\n",
    "ÏàÆÅÓÖËµµÀ£ºÎº´óÈËÒ²ËµÉÏ´ÎËÍµÄ¿ø¼×»¤¾ßÀï²»ÉÙÉÏ³ËÆ·¡£\n",
    "ÏàÆÅËµ£ºÓÐÐ©¿ø¼×»¤¾ß¿ÉÒÔ¼ÓÒÔ¸ÄÁ¼¡£\n",
    "ÏàÆÅËµµÀ£ºÏà¸®Õ÷¼¯¿ø¼×»¤¾ß£¬ÕæÊÇ×öÁËºÃÊÂÒ²¡£\n",
    "ÏàÆÅ×ÔÑÔµÀ£º¸ö±ðÕ÷À´µÄ¿ø¼×²ÐÈ±²»È«£¬»¹ÐèÅ¬Á¦Õ÷¼¯¡£\n",
  }));
  set("inquiry", ([
        "here":   "´ËÄËÓù´ÍÏà¸®Ò²£¬æªÉíÔÚ´Ë×¨ÃÅÊÕ¼¯¿ø¼×¡£\n",
        "name":   "ÏàÁ¼Ö®ÆÞÒ²¡£\n",
        "armor":   (: test_player() :),
        "¿ø¼×»¤¾ß":   (: test_player() :),
        "¿ø¼×":   (: test_player() :),
        "»¤¾ß":   (: test_player() :),
        "ÊÕ¼¯":   (: test_player() :),
        "Õ÷¼¯":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$NÏëÏë¶Ô$nËµµÀ£º½ñÌìæªÉíÕý×¼±¸ÇëÈËÈ¥ÕÒ",
    "$NÏ¸ÏëÁËÒ»ÏÂ¶Ô$nËµµÀ£ºÎº´óÈËÍÐ»°£¬ËµÊÇ¾©³ÇÓÐÈËÏëÒªÊ²Ã´",
    "$N¶Ô$nËµµÀ£ºÌýËµ³¤°²ÓÐ±øÆ÷»¤¾ß·»ÐèÒª",
    "$N¶Ô$nµãÍ·ËµµÀ£ºÏà¹«¸ÕËµÁË£¬ÈÃæªÉíÕ÷¼¯Ê²Ã´",
    "$N¶Ô$nÒ»µãÍ·ËµµÀ£ºÕâÀïÉÐÈ±Ð©",
    "$NÏëÏë¶Ô$nËµµÀ£º¿É·ñ°ïÏà¸®Ñ°µÃ",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  string *quest;
  int delay;
  int i;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬æªÉí¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/armor"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬æªÉí»¹ÅÎ×ÅÄúµÄ"+who->query("quest/pending/armor/name")+"ÄØ£¡\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_armor);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/armor");
  if (i == -1)
  {
    message_vision ("$N¶Ô$nÌ¾ÆøËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "¸Ã×öµÄÊÂ×öÁË²»ÉÙ£¬æªÉí¿´Äú»¹ÊÇÒÔºóÔÙÀ´°É¡£\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_armor[quest_keys[i]];
  who->set("quest/pending/armor/index", i);
  who->set("quest/pending/armor/daoxing", quest_keys[i]);
  who->set("quest/pending/armor/name", quest[IDX_NAME]);
  who->set("quest/pending/armor/id", quest[IDX_ID]);
  who->set("quest/pending/armor/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "£¬\nÕâÎ»"+RANK_D->query_respect(who)+
        "ÄÜ·ñ°ïÏà¸®¸öÃ¦£¿\n";
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  object ob;

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

  if (! who->query("quest/pending/armor"))
    return;

  ob = present (who->query("quest/pending/armor/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/armor/name") != ob->query("name"))
    return;

  message_vision ("$N¼û$nÊÖÉÏÄÃ×Å"+ob->query("name")+"£¬¼±Ã¦Ë«ÊÖ½Ó¹ýÈ¥¡£\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬æªÉí¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/armor"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÏà¸®²»ÐèÒªÕâ¸ö¡£\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;

  if (who->query("quest/pending/armor/name") != ob->query("name"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬æªÉíÅÎ×ÅÄúµÄ"+who->query("quest/pending/armor/name")+
                    "£¬Äúµ¹È´¸øæªÉí"+ob->query("name")+"£¬°¦Ñ½Ñ½¡£\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/armor/id") != ob->query("id"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬æªÉíÅÎ×ÅÄúµÄ"+who->query("quest/pending/armor/name")+
                    "£¬¶«Î÷µ¹Í¦Ïó£¬µ«²»ÊÇÍ¬Ò»¸ö»õ£»æªÉíÒªµÄÊÇ("+
                    who->query("quest/pending/armor/id")+")£¬Äú¸øµÄÊÇ("+
                    ob->query("id")+")£¡\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/armor/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N¶Ô$nÒ¡Í·µÀ£ºÕâÃ´¿ì¾Í»ØÀ´ÁË£¿æªÉíÅÂÊÇÓÐ¼Ù¡£\n",me,who);
    message_vision ("$NÓÖ·Ô¸ÀµÀ£ºÄúÔÙ»¨¸ö"+chinese_number((t-uptime())/60+1)+
                    "·ÖÖÓÈ¥Ñ°Ñ°¡£\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ÈÃÏàÆÅÒªÏÂ¶«Î÷¡£\n");
  }
  rewarding (who, ob);
  call_out ("destruct_ob",1,ob);
  return 1;
}

void destruct_ob (object ob)
{
  destruct (ob);
}

void rewarding (object who, object ob)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "²»´ÇÀÍ¿àÑ°µÃ"+ob->query("name")+"£¬";
  message_vision ("$N¶Ô$nËµµÀ£º¶àÐ»ÕâÎ»"+RANK_D->query_respect(who)+
                  reason+"æªÉí¸Ð¼¤²»¾¡£¡\n",me,who);
  reward = quest_reward(who, quests_armor, "armor");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/armor/times",1);
  who->add("quest/armor/reward",reward);
  reporting (who,reason, reward, "½±·Ö");
  who->delete("quest/pending/armor");
  quest_done(who);
}




ÿ
