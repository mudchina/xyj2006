//雪影 2000/2  解迷九色祥云系统
inherit NPC;

#include <quest_wr.h>
#include <reporting.h>

int test_player();

void create()
{
  set_name("玉兰", ({"yu lan", "yu", "lan"}));
  set("gender", "女性");
  set("age", 25);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 4500);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  set_skill("baihua-zhang", 40);
  set_skill("moondance", 40);
  set_skill("moonshentong", 40);
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
    "玉兰咯咯一笑：首饰鞋冠陆陆续续募捐了不少。\n",
    "玉兰宛尔一笑说道：那些想出嫁的姑娘及娶亲的光棍真有福份也。\n",
    "玉兰又说道：捐了不少了，想出嫁的姑娘们真可以有点嫁妆了。\n",
    "玉兰说：近来捐的鞋冠真多，该让那些期盼的穷光棍们来挑一挑了。\n",
  }));
  set("inquiry", ([
        "here":   "此乃高姓兰亭府也，姑娘在此募捐首饰鞋冠。\n",
        "name":   "高家小姐玉兰也。\n",
        "wearing":   (: test_player() :),
        "首饰鞋冠":   (: test_player() :),
        "募捐":   (: test_player() :),
        "首饰":   (: test_player() :),
        "鞋冠":   (: test_player() :),
        "捐":   (: test_player() :),
        "鞋":   (: test_player() :),
        "冠":   (: test_player() :),
      ]));
  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

void rewarding (object who, object ob);

void init ()
{
  call_out ("check_player",1,this_player());
  add_action ("do_quxiao","quxiao");
  add_action ("do_quxiao","cancel");
}

int test_player()
{
  string *strs = ({
    "$N对$n一笑：这不，有一穷家子想成亲正想要",
    "$N对$n咯咯地笑道：好来，姑娘听说有人家想给儿子取房媳妇，还缺",
    "$N对$n说道：巧极了，有户人家要成亲，没钱办事又急需",
    "$N对$n点头笑着说道：昨天有户穷苦人家正打听什么",
    "$N微笑着对$n一点头说道：姑娘正许愿替一办喜事的破落户找一找",
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

  if (who->query("quest/pending/wearing"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘还盼着您的"+who->query("quest/pending/wearing/name")+"呢！\n",me,who);
    return 1;
  }

  quest_keys = me->query_temp("quest_keys");
  if (! quest_keys)
  {
    quest_keys = sort_quests (quests_wearing);
    me->set_temp("quest_keys",quest_keys);
  }
  i = quest_accurate_index (quest_keys, who->query("combat_exp"));
  i = quest_random_index (quest_keys, i, who, "quest/cache/wearing");
  if (i == -1)
  {
    message_vision ("$N对$n叹气说道：这位"+RANK_D->query_respect(who)+
                    "该做的事做了不少，姑娘看您还是以后再来吧。\n",me,who);
    return 1;
  }
  delay = MAXDELAY * i / sizeof(quest_keys) + DELAY_CONST + uptime();
  quest = quests_wearing[quest_keys[i]];
  who->set("quest/pending/wearing/index", i);
  who->set("quest/pending/wearing/daoxing", quest_keys[i]);
  who->set("quest/pending/wearing/name", quest[IDX_NAME]);
  who->set("quest/pending/wearing/id", quest[IDX_ID]);
  who->set("quest/pending/wearing/time", delay);
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

  if (! who->query("quest/pending/wearing"))
    return;

  ob = present (who->query("quest/pending/wearing/id"),who);
  if (! ob || ! ob->query("no_give"))
    return;

  if (who->query("quest/pending/wearing/name") != ob->query("name"))
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

  if (! who->query("quest/pending/wearing"))
  {
    message_vision ("$N对$n说道：姑娘暂时不需要这个。\n",me,who);
    return 0;
  }

  if(ob->is_character()) return 0;
  
  if (who->query("quest/pending/wearing/name") != ob->query("name"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘说过需要"+who->query("quest/pending/wearing/name")+
                    "，您倒给姑娘"+ob->query("name")+"，好玩好玩。\n",me,who);
    return 0;
  }

  if (who->query("quest/pending/wearing/id") != ob->query("id"))
  {
    message_vision ("$N对$n说道：这位"+RANK_D->query_respect(who)+
                    "，姑娘是想要"+who->query("quest/pending/wearing/name")+
                    "，东西倒挺象，但不是同一个货；姑娘要的是("+
                    who->query("quest/pending/wearing/id")+")，您给的是("+
                    ob->query("id")+")！\n",me,who);
    return 0;
  }

  t = who->query("quest/pending/wearing/time");

  if (t > uptime() && (t-MAXDELAY) <= uptime())
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
  reward = quest_reward(who, quests_wearing, "wearing");
  who->add("quest/reward",reward);
  who->set("quest/reason",reason);
  who->add("quest/wearing/times",1);
  who->set_temp("quest/wearing/yun",1);
who->set_temp("quest/food/ok",0);
who->set_temp("quest/cloth/ok",0);
who->set_temp("quest/furniture/ok",0);
who->set_temp("quest/weapon/ok",0);
who->set_temp("quest/armor/ok",0);
who->set_temp("quest/ask/ok",0);
who->set_temp("quest/give/ok",0);
who->set_temp("quest/kill/ok",0);
  who->set_temp("quest/wearing/lasttime",time());
  who->set_temp("quest/wearing/ok",1);
  who->add("quest/wearing/reward",reward);
  reporting (who,reason, reward, "奖分");
  who->delete("quest/pending/wearing");
  call_out ("quest_done",1,who);
}


int do_quxiao (string arg)
{
  object who = this_player ();
  object silver = present ("gold",who);
  int amount, val;
  string item;
  object obj;
    obj=silver;
    amount=5;
if (!obj || (int)obj->query_amount() < 5)
           return notify_fail("你身上没有那么多的黄金呀。\n");
obj->set_amount((int)obj->query_amount()-amount);
  who->delete("quest/pending/wearing");
write(HIC""+who->query("name")+"偷偷地交给了玉兰五两黄金。\n玉兰看了看"+who->query("name")+"，笑道：还挺会来事儿的，好吧，这次就放过你。\n"NOR);
return 1;
}
