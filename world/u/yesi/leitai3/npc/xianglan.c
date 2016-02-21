// by snowcat 

inherit NPC;

#include <quest_ms.c>
#include <reporting.c>

int test_player();

void create()
{
  set_name("香兰", ({"xiang lan", "xiang", "lan"}));
  set("gender", "女性");
  set("age", 28);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 5500);
  set_skill("unarmed", 45);
  set_skill("dodge", 45);
  set_skill("parry", 45);
  set_skill("force", 45);
  set_skill("spells", 45);
  set_skill("baihua-zhang", 45);
  set_skill("moondance", 45);
  set_skill("moonshentong", 45);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moonshentong");
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "香兰咯咯一笑：各类异宝可不少。\n",
    "香兰宛尔一笑说道：天下善人多也。\n",
    "香兰说：大开眼界，乐也乐也。\n",
  }));
  set("inquiry", ([
        "here":   "此乃高姓兰亭府也，姑娘在此收集奇珍异宝。\n",
        "name":   "高家小姐香兰也。\n",
        "cloth":   (: test_player() :),
	"异宝":   (: test_player() :),
        "募捐":   (: test_player() :),
        "捐":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
}

int test_player()
{
  string *strs = ({
    "$N对$n一笑：姑娘想起有人想要",
    "$N对$n咯咯地笑道：正好正好，姑娘募捐，听说有人打听能否寻得",
    "$N对$n说道：哦，对了，姑娘想帮人找一找什么",
    "$N对$n点头笑着说道：谢谢啦，姑娘想替人找",
    "$N微笑着对$n一点头说道：有人曾打听是否有",
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
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 1;
  }

  if (who->query("quest/pending/cloth"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘还盼着您的"+who->query("quest/pending/cloth/name")+"呢！\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_misc);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who);
  i = quest_random_index (quest_keys, i, who, "quest/cache/cloth");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，姑娘看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_misc[quest_keys[i]];
  who->set("quest/pending/cloth/index", i);
  who->set("quest/pending/cloth/daoxing", quest_keys[i]);
  who->set("quest/pending/cloth/name", quest[IDX_NAME]);
  who->set("quest/pending/cloth/id", quest[IDX_ID]);
  who->set("quest/pending/cloth/time", delay);
  str = strs[random(sizeof(strs))]+quest[IDX_NAME]+
        "，\n这位"+RANK_D->query_respect(who)+
        "能否替姑娘想个办法？\n";
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
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "身上祥云环绕，请速赴长安进宫请赏！\n",me,who);
    return;
  }

  if (! who->query("quest/pending/cloth"))
    return;

  ob = present (who->query("quest/pending/cloth/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/cloth/name") != ob->query("name"))
    return;

  message_vision ("$N见$n手上拿着"+ob->query("name")+"，笑着连忙接了过去。\n",me,who);
  rewarding (who, ob);
  destruct (ob);
}

int accept_object(object who, object ob)
{
  object me = this_object();
  int t;

  if (who->query("quest/reward") > 0)
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘见你身上祥云环绕，何不去从速赴长安进宫请赏？\n",me,who);
    return 0;
  }

  if (! who->query("quest/pending/cloth"))
  {
    message_vision ("$N对$n说道：姑娘暂时不需要这个。\n",me,who);
    return 0;
  }

  if (ob->is_character()) return 0;
  
  if (who->query("quest/pending/cloth/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘说过需要"+who->query("quest/pending/cloth/name")+
                    "，您倒给姑娘"+ob->query("name")+"，好玩好玩。\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/cloth/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘是想要"+who->query("quest/pending/cloth/name")+
                    "，东西倒挺象，但不是同一个货；姑娘要的是("+
                    who->query("quest/pending/cloth/id")+")，您给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/cloth/time");

  if (t >= uptime() && (t-MAXDELAY) <= uptime())
  {
    message_vision ("$N对$n摇头道：这么快就回来了？姑娘想要真货也。\n",me,who);
    message_vision ("$N又吩咐道：您再花个"+chinese_number((t-uptime())/60+1)+
                    "分钟去寻寻。\n",me,who);
    if (! DEBUG)
      return 0;
    else
      tell_object (who,"NOW DEBUG MODE: 让姑娘要下东西。\n");
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

  reason = "替"+me->query("name")+"寻得"+ob->query("name")+"，";
  message_vision ("$N对$n说道：多谢这位"+RANK_D->query_respect(who)+
                  reason+"姑娘好个开心！\n",me,who);
  reward = quest_reward(who, quests_misc, "cloth");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/cloth/times",1);
  who->add("quest/cloth/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/cloth");
  quest_done(who);
}




