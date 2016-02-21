// by snowcat 

inherit NPC;

#include <quest_ak.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("圣善", ({"sheng shan", "sheng", "shan"}));
  set("long", "一位身披仙袍，面容严肃慈善的大法师。\n");
  set("title", "大法师");
  set("gender", "男性");
  set("age", 100);
  set("per", 35);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
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
    "圣善法师说道：善哉善哉哪。\n",
    "圣善法师自语道：世上贤人，有求必应哪。\n",
    "圣善法师说道：祭祖求贤，乃水陆大会前之必需也。\n",
    "圣善法师叹言道：天下招贤，利国利民之大策也。\n",
    "圣善法师说道：八方求贤也。\n",
    "圣善法师说道：焚香祭祖，以招天下招贤士。\n",
  }));
  set("inquiry", ([
        "here":   "此乃禹王台也，水陆大会将不期举行，本法师在此预做法场以祭祖求贤。\n",
        "name":   "圣善法师，在此做法祭祖求贤。\n",
        "ask":   (: test_player() :),
        "祭祖":   (: test_player() :),
        "求贤":   (: test_player() :),
        "招贤":   (: test_player() :),
        "贤人":   (: test_player() :),
        "贤士":   (: test_player() :),
        "善哉":   (: test_player() :),
        "招":   (: test_player() :),
        "求":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/xianpao")->wear();
}

void rewarding (object who);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N燃起一根香祭祀一番，对$n说道：祖灵在天，想请您去拜见$w并询问有关$o一事。\n",
    "$N将手中香点燃对$n说道：老夫刚祭毕祖宗，得知有$w知道$o之事，您可否去请见？\n",
    "$N拈香向祖宗一拜，转身对$n说道：可否去拜见$w，并告知$o一事？\n",
    "$N将香点燃，对$n说道：在天祖灵让您去就$o一事拜访$w，请尽早动身也。\n",
    "$N对$n说道：老夫拜了祖宗，正缺人去拜访$w，去告知$o之事。\n",
    "$N燃香完毕，回头对$n说道：不知可否去拜见$w，并探问$o一事。\n",
    "$N在香火中缓缓向祖宗一拜，再对$n说道：祖灵在天请您去寻找$w并告知$o之事。\n",
  });  
  string *acks = ({
    "知道了。\n",
    "我这就会动身，您请先回吧。\n",
    "好的。\n",
    "多谢来访，我这就去办。\n",
    "好，我马上就去准备。\n",
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
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/ask"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是请您去见"+who->query("quest/pending/ask/name")+
                    "询问"+who->query("quest/pending/ask/topic")+"一事吗？\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_ask);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/ask");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，老夫看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + 120 + uptime();
  quest = quests_ask[quest_keys[i]];
  who->set("quest/pending/ask/index", i);
  who->set("quest/pending/ask/daoxing", quest_keys[i]);
  who->set("quest/pending/ask/name", quest[IDX_NAME]);
  who->set("quest/pending/ask/id", quest[IDX_ID]);
  who->set("quest/pending/ask/topic", quest[IDX_OBJ]);
  who->set("quest/pending/ask/acknowledge", acks[random(sizeof(acks))]);
  who->set("quest/pending/ask/time", delay);
  str = strs[random(sizeof(strs))];
  str = replace_string (str, "$w", quest[IDX_NAME]);
  str = replace_string (str, "$o", quest[IDX_OBJ]);
  message_vision (str,me,who);
  informing (me,who,str);
  return 1;
}

void check_player (object who)
{
  object me = this_object();
  int t;

  if (!visible(who))
      return;

  if (! who || environment(who)!=environment(me))
    return;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

  if (! who->query("quest/pending/ask"))
    return;

  if (! who->query("quest/pending/ask/done"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是说过请去拜见"+who->query("quest/pending/ask/name")+
                    "并告之"+who->query("quest/pending/ask/topic")+"一事吗？\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/ask/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n惊叹道：您已经回来了？不会这么快吧。\n",me,who);
    message_vision ("$N看了一眼香说道：这香还需"+chinese_number((t-uptime())/60+1)+
                    "分钟才燃尽，到时您再来吧。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让圣善直接认可。\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "祭祖拜贤，就"+who->query("quest/pending/ask/topic")+
           "一事拜见了"+who->query("quest/pending/ask/name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"真是品行可嘉也。\n",me,who);
  reward = quest_reward(who, quests_ask, "ask");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/ask/times",1);
  who->add("quest/ask/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/ask");
  call_out ("quest_done",1,who);
}


