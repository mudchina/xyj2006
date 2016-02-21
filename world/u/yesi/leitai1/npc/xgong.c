// by snowcat 

inherit NPC;

#include <quest_wp.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("Ïà¹«", ({"xiang gong", "xiang", "gong"}));
  set("gender", "ÄÐÐÔ");
  set("title", "Óù´Í");
  set("age", 80);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 20000);
  set("daoxing", 100000);

  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",10);
  set("chat_chance",10);
  set("chat_msg",({
    "Ïà¹«Ï²ÐÎÓÚÉ«µØËµ£º½üÀ´¸÷ÀàÎäÆ÷Õ÷¼¯ÁË²»ÉÙ£¬ÕÒ¸öÊ±¼äÅÉÈËËÍµ½¾©³Ç¡£\n",
    "Ïà¹«×ÔÑÔ×ÔÓïµÀ£ºÎäÆ÷¾«Æ·½«²»ÆÚ½ø¹±¸ø»Ê¹¬¡£\n",
    "Ïà¹«ÄÅÄÅµØËµµÀ£º¾ü»ú´ó³¼ÅÉÈË´ßÎÊ¿É·ñÅªµÃÎäÆ÷¼ÑÆ·¡£\n",
    "Ïà¹«Ëµ£ºÊ²Ã´±øÆ÷¶¼Òª£¬¿ÉÒÔ¸ÄÁ¼»ò·ÂÖÆÒ²¡£\n",
    "Ïà¹«µÍÉùËµµÀ£ºÊÕ¼¯µÄÎäÆ÷¸Ã·ÖÀà´¦ÖÃ¡£\n",
    "Ïà¹«×ÔÑÔµÀ£ººÃ£¬¸÷Â·Ó¢ÐÛºÀ½Ü¶¼·×·×Ç°À´Ï×±¦¡£\n",
  }));
  set("inquiry", ([
        "here":   "´ËÄËÓù´ÍÏà¸®Ò²£¬ÀÏ·ò±»Óù×¼ÔÚ´ËÊÕ¼¯ÎäÆ÷¡£\n",
        "name":   "ÐÕÏàÃûÁ¼Ò²¡£\n",
        "weapon":   (: test_player() :),
        "ÎäÆ÷":   (: test_player() :),
        "±øÆ÷":   (: test_player() :),
        "·¨±¦":   (: test_player() :),
        "ÊÕ¼¯":   (: test_player() :),
        "Õ÷¼¯":   (: test_player() :),
        "±¦":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$NÂÔÓÐËùË¼£¬È»ºó¶Ô$nËµµÀ£ºÀÏ·òÕýÏëÇëÈËÈ¥ÕÒ",
    "$NÏëÁËÒ»ÏÂ£¬¶Ô$nËµµÀ£ºÀÏ·òÌýËµ¾üÎñ´¦ÏëÒª",
    "$N¶Ô$nËµµÀ£º¾ü»ú´ó³¼ÒÑÍÐÈË´«»°£¬ËµÊÇ½üÀ´ÐèÒªÊ²Ã´",
    "$N¶Ô$nËµµÀ£ºÀÏ·ò¼´½«Ç²ÈËËÍ±øÆ÷È¥¾©³Ç£¬ÉÐÈ±",
    "$N¶Ô$nÒ»µãÍ·ËµµÀ£ºÀÏ·òÇåµãÁËÒ»ÏÂ±øÆ÷¿â£¬·¢ÏÖ»¹ÉÙ",
    "$NÏëÏë¶Ô$nËµµÀ£º×î½üÓÐÐ©±øÆ÷À´»õ²»×ã£¬ÓÈÆäÊÇÉÙÁË",
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
                    "£¬ÀÏ·ò¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/weapon"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·ò»¹ÅÎ×ÅÄúµÄ"+who->query("quest/pending/weapon/name")+"ÄØ£¡\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_weapon);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/weapon");
  if (i == -1)
  {
    message_vision ("$N¶Ô$nÌ¾ÆøËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "¸Ã×öµÄÊÂ×öÁË²»ÉÙ£¬ÀÏ·ò¿´Äú»¹ÊÇÒÔºóÔÙÀ´°É¡£\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_weapon[quest_keys[i]];
  who->set("quest/pending/weapon/index", i);
  who->set("quest/pending/weapon/daoxing", quest_keys[i]);
  who->set("quest/pending/weapon/name", quest[IDX_NAME]);
  who->set("quest/pending/weapon/id", quest[IDX_ID]);
  who->set("quest/pending/weapon/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "£¬\nÕâÎ»"+RANK_D->query_respect(who)+
        "ÄÜ·ñ°ïÀÏ·ò¸öÃ¦£¿\n";
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

  if (! who->query("quest/pending/weapon"))
    return;

  ob = present (who->query("quest/pending/weapon/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/weapon/name") != ob->query("name"))
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
                    "£¬ÀÏ·ò¼ûÄãÉíÉÏÏéÔÆ»·ÈÆ£¬ºÎ²»È¥´ÓËÙ¸°³¤°²½ø¹¬ÇëÉÍ£¿\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/weapon"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÀÏ·ò²»ÐèÒªÕâ¸ö¡£\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;
  
  if (who->query("quest/pending/weapon/name") != ob->query("name"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·òÅÎ×ÅÄúµÄ"+who->query("quest/pending/weapon/name")+
                    "£¬Äúµ¹È´¸øÀÏ·ò"+ob->query("name")+"£¬¿È¿È¡£\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/weapon/id") != ob->query("id"))
  {
    message_vision ("$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(who)+
                    "£¬ÀÏ·òÅÎ×ÅÄúµÄ"+who->query("quest/pending/weapon/name")+
                    "£¬¶«Î÷µ¹Í¦Ïó£¬µ«²»ÊÇÍ¬Ò»¸ö»õ£»ÀÏ·òÒªµÄÊÇ("+
                    who->query("quest/pending/weapon/id")+")£¬Äú¸øµÄÊÇ("+
                    ob->query("id")+")£¡\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/weapon/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N¶Ô$nÒ¡Í·µÀ£ºÕâÃ´¿ì¾Í»ØÀ´ÁË£¿ÀÏ·òÅÂÊÇÓÐ¼Ù¡£\n",me,who);
    message_vision ("$NÓÖ·Ô¸ÀµÀ£ºÄúÔÙ»¨¸ö"+chinese_number((t-uptime())/60+1)+
                    "·ÖÖÓÈ¥Ñ°Ñ°¡£\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: ÈÃÏà¹«ÒªÏÂ¶«Î÷¡£\n");
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
                  reason+"ÀÏ·ò¸Ð¼¤²»¾¡£¡\n",me,who);
  reward = quest_reward(who, quests_weapon, "weapon");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/weapon/times",1);
  who->add("quest/weapon/reward",reward);
  reporting (who,reason, reward, "½±·Ö");
  who->delete("quest/pending/weapon");
  quest_done(who);
}



ÿ
