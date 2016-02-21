// created 4/5/1997 by snowcat
#define NAME "小公主"
inherit NPC;

int test_player(object who);
int test_player_male (object me);
int test_player_female (object me);

void create()
{
  set_name(NAME, ({"xiliang princess", "princess"}));
  set("title", "西梁掩面娇玉");
  set("gender", "女性");
  set("age", 23);
  set("long", "西梁愁红痴绿抛心引郎娇玉小公主。\n");
  set("rank_info/respect", "娇玉公主");
  set("max_kee", 900);
  set("max_gin", 900);
  set("max_sen", 900);
  set("force", 800);
  set("max_force", 800);
  set("mana", 800);
  set("max_mana", 800);
  set("combat_exp", 200000);
  set("force_factor", 45);
  set_skill("snowsword", 75);
  set_skill("sword", 75);
  set_skill("dragonfight", 75);
  set_skill("unarmed", 75);
  set_skill("dodge", 75);
  set_skill("parry", 75);
  set_skill("dragonstep", 75);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("eff_dx",20000);
  set("nkgain",110);
  set("inquiry", ([
        "name": "我是寂寞的西梁愁红痴绿抛心引郎娇玉小公主。\n"+
                "想找个郎君，也想找一些伴娘。",
        "here": "西梁国虽为女儿国，一向也有比武招亲的传统。",
        "news": "没有听说公主我一直想寻个王子结婚吗？",
        "求情": "唉，也只有她偶尔能说得动我。",
        "冰露珠项链": "是个国宝，我有但不轻易给人，也有人在后宫找到过。",
        "郎君": (: test_player_male :),
        "结婚": (: test_player_male :),
        "招亲": (: test_player_male :),
        "招附": (: test_player_male :),
        "marriage": (: test_player_male :),
        "伴娘": (: test_player_female :),
        "company": (: test_player_female :),
      ]));
  set("chat_chance",1);
  set("chat_msg",({
         NAME+"说道：宫里大事一直让公主操心：招附，寻伴娘……\n",
         NAME+"叹一声：真是隔年寂寞数鹤信啊。\n",
         NAME+"喃喃说道：亏她总是乔扮成妇人在外闲游。\n",
         NAME+"自言自语：冰露珠项链是个珍贵物儿，难得一赠。\n",
         NAME+"说：年前那主儿治痊了腹水孕也算是了不得的大事。\n",
      }));

  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/huazheboots")->wear();
  carry_object("/d/obj/misc/necklace")->wear();
  carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void init()
{
  ::init();
  add_action("do_answer", "answer");
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
}

void throw (object who, string where)
{
  string dir;

/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;  
*/
  dir = "/d/qujing/nuerguo/";
  who->move(dir+where+".c");
  switch (random(4))
  {
    case 0:
      message_vision("$N被几个大胖女人拖过。\n",who);
      break;
    case 1:
      message_vision("几个胖女人七手八脚地拖着$N走过。\n",who);
      break;
    case 2:
      message_vision("一阵哭嚎声中，$N让几个胖女人倒拖着走过。\n",who);
      break;
    case 3:
      message_vision("只见$N连滚带爬地被几个胖女人拖过。\n",who);
      break;
  }
}

void throws (object who)
{
  message_vision("话音未落，从门外早已冲进几个大胖女人，将$N拖起就走！\n",who);
  throw(who,"fronthall");
  throw(who,"entry");
  throw(who,"towna2");
  throw(who,"towna3");
  throw(who,"townb3");
  throw(who,"townc3");
  throw(who,"sanchalu");
  throw(who,"westriver");
  throw(who,"eastriver3");
  message_vision("哗啦一声水响，$N整整凌乱的衣冠，从河里勉强地爬上来。\n",who);
  who->interrupt_me();
}

void throw_player (object who)
{
  say(NAME+"大喝一声：来人！把这个混帐给轰出国！\n");
  call_out ("throws",1,who);
}

void reject_player (string msg, object who)
{
  say(msg, who);
  
  // mon 2/28/99
  // prevent player uses the rejection to remove the busy one has.
  if(who->is_busy()) return;

  who->start_busy(3,3);
  call_out ("throw_player",1,who);
}

void invite_player (object who)
{
  string dir;

/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;  
*/
  dir = "/d/qujing/nuerguo/";
  message_vision("门外的几个大胖女人走进来，十分老练地簇拥起$N就走！\n",who);
  who->move(dir+"greenyard.c");
  message_vision("大胖女人们将$N留在这里，什么都没说就匆匆地走了。\n",who);
}

void ask_player (object who)
{
  string msg;
  msg = NAME+"大喜道："+RANK_D->query_respect(who);

  if (who->query("gender") != "女性")
    say(msg+"想做我的郎君？\n\n");
  else
    say(msg+"想陪我散闷，做一位伴娘？\n\n");
  call_out ("ask_condition",1,who);
}

void ask_condition (object who)
{
  string msg;
  msg = NAME+"继续吩咐道：";

  say(msg+"公主我有一个条件，想先留你在宫里小住数日，看你是否合适。\n");
  say("愿意的话，我这就陪你去后宫。\n");
  say("不愿意的话，你现在就可以向我挑战。\n");
  if (who->query("gender") != "女性")
    say("若是你赢了我的话，你就可以马上娶我为妻；"+
        "若是你输了的话，莫怪我无情！\n");
  else
    say("若是你赢了我的话，你当公主我做你的伴娘；"+
        "若是你输了的话，莫怪我无情！\n");
  who->set_temp("princess_answer",1);
  tell_object(who,"\n请用answer回答。\n");
}

int test_player(object who)
{
  object queen;
  string msg;
  msg = NAME+"说道：这位"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<2000)
  {
    reject_player (msg+"看上去就没有什么道行，来这凑什么热闹！\n",who);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "done")
  {
    queen = new (__DIR__"queen");
    queen->refuse_player (who);
    destruct (queen);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "stomachache")
  {
    reject_player (msg+"怀了一水胎，居然挺着大肚子来见我！\n",who);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "marriage")
  {
    say(msg+"不是已经来求过婚了吗？还是回后院去吧！\n");
    call_out ("invite_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/nuerguo") == "company")
  {
    say(msg+"不是已经答应做我的伴娘了吗？还是请去后院去吧！\n");
    call_out ("invite_player",1,who);
    return 1;
  }
    
  call_out ("ask_player",1,who);
  return 1;
}

int test_player_male (object me)
{
  object who;
  string msg;
  who = this_player();
  msg = NAME+"说道：这位"+RANK_D->query_respect(who);

  if (who->query("gender") != "男性")
  {
    reject_player (msg+"！你根本就不是男的，开什么玩笑！\n",who);
    return 1;
  }
  return test_player(who);
} 

int test_player_female (object me)
{
  object who;
  string msg;
  who = this_player();
  msg = NAME+"说道：这位"+RANK_D->query_respect(who);

  if (who->query("gender") != "女性")
  {
    reject_player (msg+"！你根本就不是女的，开什么玩笑！\n",who);
    return 1;
  }
  return test_player(who);
} 

void send_to_greenyard (object who)
{
  string msg;
  msg = NAME+"说道：这位"+RANK_D->query_respect(who);

  message_vision (msg+"既然愿意，就先请去后院休息几天去吧！\n",who);
  if (who->query("gender") != "女性")
    who->set("obstacle/nuerguo", "marriage");
  else
    who->set("obstacle/nuerguo", "company");
  who->save();
  call_out ("invite_player",1,who);
} 

void fight_player (object who)
{
  message_vision (NAME+"对$N迷人地一笑：好吧，让我俩比试比试，进招罢！\n",who);
  message_vision (NAME+"从宝座上起身，一个轻跃飘到$N面前。\n",who);
  who->set_temp ("princess_fight", 1);
} 

int do_answer(string arg)
{
  object who;

  who = this_player();

  if (! who->query_temp("princess_answer"))
    return notify_fail("什么？\n");

  if (!arg)
    return notify_fail("你要回答什么？\n");

  who->set_temp("princess_answer",0);
  message_vision("$N答道："+arg+"\n", who);
  if (arg == "愿意")
    send_to_greenyard (who);
  else if (arg == "不愿意")
    fight_player (who);
  else
    message_vision (NAME+"对$N皱起眉头。\n",who);
  return 1;
}

int accept_fight(object who)
{
  object me;
  me = this_object();

  if (! who->query_temp("princess_fight"))
    return 0;

  who->set_temp("princess_fight",0);
  remove_call_out("check_fight");
  call_out("check_fight", 1, me, who);
  return 1;
}

void player_win (object me, object who)
{
  object queen;
  string msg;
  msg = RANK_D->query_respect(who);

  queen = new (__DIR__"queen");
  queen->announce_success (who,"比武战胜小公主");
  destruct (queen);
  say (NAME+"叹了一口气：公主我天性好胜好强，自幼难容比我厉害的人。\n");
  say (msg+"如此武艺高强，公主无法挽留，还是请"+msg+"自行上路西天，多多保重！\n"); 

}

void player_lose (object me, object who)
{
  string msg;
  msg = RANK_D->query_respect(who);

  say (NAME+"微微一笑：你们唐人个个如此，果然不行！\n");
  say (NAME+"补充道：看你这样子西天取经自然是去不了啦。\n");
  call_out ("player_lose_info",2,who);
}

void player_lose_info (object who)
{
  string msg;
  msg = RANK_D->query_respect(who);

  if (random(5) == 0)
    say ("旁边有小宫女偷偷说道：作孽哟，唉，"+msg+
         "何不找个人向小公主求求情！\n"); 
}

void check_fight (object me, object who)
{
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  my_kee = me->query("kee");
  whos_kee = who->query("kee");
  my_max_kee = me->query("max_kee");
  whos_max_kee = who->query("max_kee");

  if (me->is_fighting())
  {
    call_out ("check_fight",2,me,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

if ((my_kee*100/my_max_kee) <=(whos_kee*100/whos_max_kee))
//if ((my_kee*100/my_max_kee) <=10) // xintai 2/8/2001
player_win (me, who);
else player_lose (me, who);

}

int do_fight(string arg)
{
  object who;
  object me;
  who = this_player();
  me = this_object();

  if (me->is_fighting())
  {
    message_vision (NAME+"对$N摇摇头：一个一个地来，不要一拥而上！\n",who);
    return 1;
  }
  
  if (who->query_temp("princess_fight"))
  {
    me->set("kee", me->query("max_kee"));
    me->set("eff_kee", me->query("max_kee"));
    return 0; // can fight
  }

  message_vision (NAME+"对$N摇摇头：比武招亲可以，打架不行！\n",who);
  return 1;
}

int do_cast(string arg)
{
  object who;
  object me=this_object();
  who = this_player();

  if(!arg || present(arg,environment(me))!=me) return 0;

  if (who->query_temp("princess_fight"))
    return 0; // can fight

  message_vision (NAME+"对$N喝道：谁让你乱念咒文的！\n",who);
  message_vision ("$N吓得将下半句咒文咽了回去。\n",who);
  return 1;
}

int do_steal(string arg)
{
  object who;
  object me=this_object();
  who = this_player();

  if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision (NAME+"突然对$N喝道：好你这个小偷，住手！\n",who);
  message_vision ("$N吓得将手缩了回去。\n",who);
  return 1;
}

int do_kill(string arg)
{
  object who;
  object me=this_object();
  who = this_player();

  if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision (NAME+"突然对$N喝道：想谋害公主，你好大的胆！\n",who);
  message_vision ("$N一下子吓得瘫倒在地。\n",who);
  return 1;
}
