// by snowcat 

inherit NPC;

#include <quest_fd.h>
#include <quest_gv.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("圣悲", ({"sheng bei", "sheng", "bei"}));
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
    "圣悲法师叹道：多灾多难哪。\n",
    "圣悲法师自言自语地说道：近闻他乡受灾，令人彻夜难眠也。\n",
    "圣悲法师说道：乡下水祸成灾，痛心也。\n",
    "圣悲法师叹言道：普天之下，有多少民众仍处于水深火热之中也。\n",
    "圣悲法师说道：救人之急也。\n",
    "圣悲法师说道：恨不能亲身赴汤蹈海，以解八方之难也。\n",
  }));
  set("inquiry", ([
        "here":   "此乃禹王台也，水陆大会将不期举行，本法师在此预做法场以事天下灾民难民。\n",
        "name":   "圣悲法师，在此做法以事天下灾民难民。\n",
        "give":   (: test_player() :),
        "灾民":   (: test_player() :),
        "难民":   (: test_player() :),
        "穷人":   (: test_player() :),
        "受灾":   (: test_player() :),
        "解难":   (: test_player() :),
        "救灾":   (: test_player() :),
        "救":   (: test_player() :),
        "给":   (: test_player() :),
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
    "$N拿起一根签，对$n说道：近闻他乡受灾，正想请人去给$w送点$o。\n",
    "$N对$n点点头说道：老夫刚求了一签，知道$w有难，想送点$o去。\n",
    "$N对$n说道：正好正好，老夫占签得知$w现急需$o。\n",
    "$N不语，从盒里啪地抽出一签，缓缓地对$n说：现闻$w需要$o。\n",
    "$N点点头，顺手将手中的签打开，惊叹道：有$w正急需$o也。\n",
    "$N从打开签盒取出一签对$n说道：他乡有难，请去给$w送点$o。\n",
    "$N将手中签一读，对$n说道：签曰现有$w急需$o。\n",
    "$N一扬签对$n说道：事不宜迟请去给$w送点$o。\n",
  });  
  object me = this_object();
  object who = this_player();
  int *quest_keys;
  int *food_keys;
  string *quest;
  string *food;
  string objectname, objectid, str;
  int delay;
  int i, j;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/give"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是请您去给"+who->query("quest/pending/give/name")+
                    "送"+who->query("quest/pending/give/objectname")+"吗？\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  food_keys = me->query_temp("food_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_give);
    food_keys = sort_quests (quests_food);
    me->set_temp("quest_keys",quest_keys);
    me->set_temp("food_keys",food_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/give");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，老夫看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + 120 + uptime();
  quest = quests_give[quest_keys[i]];
  if (sscanf(quest[IDX_OBJ],"%s(%s)",objectname,objectid) != 2)
  {
    j = random(30);
    food = quests_food[food_keys[j]];
    objectname = food[IDX_NAME];
    objectid = food[IDX_ID];
  }
  who->set("quest/pending/give/index", i);
  who->set("quest/pending/give/daoxing", quest_keys[i]);
  who->set("quest/pending/give/name", quest[IDX_NAME]);
  who->set("quest/pending/give/id", quest[IDX_ID]);
  who->set("quest/pending/give/objectname", objectname);
  who->set("quest/pending/give/objectid", objectid);
  who->set("quest/pending/give/time", delay);
  str = strs[random(sizeof(strs))];
  str = replace_string (str, "$w", quest[IDX_NAME]);
  str = replace_string (str, "$o", objectname);
  message_vision (str,me,who);
  informing (me, who, str);
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

  if (! who->query("quest/pending/give"))
    return;

  if (! who->query("quest/pending/give/done"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，老夫不是说过请速去给"+who->query("quest/pending/give/name")+
                    "送"+who->query("quest/pending/give/objectname")+"，事不宜迟也。\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/give/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n惊叹道：您已经回来了？不会这么快吧。\n",me,who);
    message_vision ("$N拿起签又读了一下，说道：签上说您还得花个"+chinese_number((t-uptime())/60+1)+
                    "分钟。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让圣悲直接认可。\n");
  }
  rewarding (who);
}

void rewarding (object who)
{
  object me = this_object();
  string reason;
  int reward;

  reason = "救人之急，为"+who->query("quest/pending/give/name")+
           "送去"+who->query("quest/pending/give/objectname")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"真是品行可嘉也。\n",me,who);
  reward = quest_reward(who, quests_give, "give");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/give/times",1);
  who->add("quest/give/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/give");
  call_out ("quest_done",1,who);
}


