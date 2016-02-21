// gao.c

inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("国王", ({"ghost guo wang", "guo wang", "wang", "king"}));
  set("long", "头戴一顶冲天冠，腰束一条碧玉带，身穿一领飞龙舞凤赭黄袍。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 1);
  set_skill("unarmed", 1);
  set_skill("dodge", 1);
  set_skill("parry", 1);
  set("max_gin", 1);
  set("max_kee", 1);
  set("max_sen", 1);
  
  set("inquiry", ([
      "name": "老夫乃是乌鸡国国王，三年前被一道人所害，推下御花园琉璃井。\n",
      "here": "此乃宝林寺也",
      "妖道":"三年前那妖道将朕推下了井，自己变做朕的模样，霸占了朕的江山。\n",
      "报仇":(:give_jade :),
  ]) );

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
  call_out("show_king", 1);
}

int show_king()
{
  object king = this_object();
  message_vision("只听风声一时过处，青烟中现出一个水淋淋的人影。\n", king);
  call_out("talk_king", 5+random(5));
  return 1;
}

int talk_king(){

  object king = this_object();
  string *msgs = ({
    "乌鸡国王眼中垂泪，口里不住的只叫：师父你要替我报仇啊!\n",
    "乌鸡国王叹道：可怜我已死去三年，是个落井伤身的冤屈之鬼啊!\n",
    "乌鸡国王对你说：师父既有本事去西天取经，定能帮我报仇。\n",
    "乌鸡国王对你说：师父若能除去那妖道，定然功德无量啊啊!\n",
    "乌鸡国王叹道：可恨那妖道变做朕的模样，霸占了朕的江山，暗侵了我的国土。\n",
    "乌鸡国王叹道：可恨那妖道神通广大，地府天堂竟无我伸冤之处。\n",
    "乌鸡国王对你说：今日夜游神将我吹来此间，说师父你可以帮朕。\n",
    "乌鸡国王对你说：师父您若能拿住那妖道，辨明邪正，朕当结草衔环报答师父。\n", 
   });

  if (random(7) == 0)
  {
    call_out("king_disappear",5);
    return 1;
  }
  message_vision (msgs[random(sizeof(msgs))],king);
  call_out("talk_king",5+random(15));
  return 1;
}

int give_jade()
{
  object king = this_object(); 
  object who = this_player();
  string id = who->query("id");
  object where = environment(king);
  object jade;

  if (who->query("combat_exp")<50000)
  {
    command("?");
    return 1;
  }
/*
  if (who->query("obstacle/wuji") == "done")
  {
    command("hmm");
    return 1;
  }
*/
  if (present("yu gui",who))
  {
    command("hmm "+id);
    return 1;
  }
  if (where->query("short")!="西厢房")
  {
    command("ah "+id);
    return 1;
  }
  if (where->query("has_given"))
  {
    command("shake "+id);
    return 1;
  }
  where->set_given();
  message_vision ("$N对$n说：师父我留下一件表记与你吧。\n",king,who);
  message_vision ("说着$N给$n一样东西。\n",king,who);
  jade = new("/d/qujing/wuji/obj/jade.c");
  jade->move(who);
  return 1;
}

int king_disappear()
{
  object king = this_object(); 
  message_vision ("冷风一过，你像是猛然惊醒，乌鸡国王已经不见了。\n",king);
  destruct (king);
  return 1;
}

void die ()
{
  object king = this_object(); 
  message_vision ("$N大惊失色，噌地一声化为一缭青烟飞去。\n",king);
  destruct (king);
}

void unconcious()
{
  die();
}

void kill_ob (object ob)
{
  die();
}

int accept_fight (object ob)
{
  command ("ah");
  return 0;
}

