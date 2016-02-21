// by snowcat

inherit NPC;

#include <quest_kl.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("圣志", ({"sheng zhi", "sheng", "zhi"}));
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
    "圣志法师怒发冲冠，将惊堂木啪地一拍，喝道：杀！\n",
    "圣志法师怒道：杀尽天下妖魔鬼怪！\n",
    "圣志法师拍着惊堂木吼道：妖贼！\n",
    "圣志法师怒不可遏：斩尽杀绝！\n",
    "圣志法师哼了一声：杀！\n",
    "圣志法师说道：要扫除一切牛鬼蛇神！\n",
  }));
  set("inquiry", ([
        "here":   "此乃禹王台也，水陆大会将不期举行，本法师在此预做法场，杀尽妖魔鬼怪！\n",
        "name":   "圣志法师，在此做法，以杀尽妖魔鬼怪！\n",
        "kill":   (: test_player() :),
        "妖魔":   (: test_player() :),
        "妖贼":   (: test_player() :),
        "鬼怪":   (: test_player() :),
        "牛鬼":   (: test_player() :),
        "蛇神":   (: test_player() :),
        "杀尽":   (: test_player() :),
        "杀":   (: test_player() :),
        "斩":   (: test_player() :),
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
    "$N迅速地一占卦，将惊堂木啪地一拍对$n说道：去将$w降服了！\n",
    "$N哼了一声对$n说道：老夫刚占了一卦，已知$w的阳寿已尽，去去，将之斩了！\n",
    "$N低头一看卦，对$n说道：$w罪该万死，您去一遭将此事了之。\n",
    "$N看完卦对$n说道：老夫正缺人去降服$w，您可否走一趟？\n",
    "$N怒发冲冠，对$n说道：$w为非作歹，您火速去将之了结掉！\n",
    "$N将卦一占，回头对$n说道：好，正是时候！您去将$w降服掉！\n",
    "$N占卦完毕对$n说道：去去，将$w杀掉！\n",
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

  if (who->query("quest/pending/kill"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是请您去降服"+who->query("quest/pending/kill/name")+"吗？\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_kill);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/kill");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，老夫看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + 120 + uptime();
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

  if (! who->query("quest/pending/kill"))
    return;

  if (! who->query("quest/pending/kill/done"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是请您去降服"+who->query("quest/pending/kill/name")+"吗？\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/kill/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n惊叹道：您已经回来了？不会这么快吧。\n",me,who);
    message_vision ("$N俯身又看了一眼卦说道：您还是"+chinese_number((t-uptime())/60+1)+
                    "分钟后再来吧。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让圣志直接认可。\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "除妖灭怪，降服了"+who->query("quest/pending/kill/name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"真是品行可嘉也。\n",me,who);
  reward = quest_reward(who, quests_kill, "kill");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/kill/times",1);
  who->add("quest/kill/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/kill");
  call_out ("quest_done",1,who);
}


