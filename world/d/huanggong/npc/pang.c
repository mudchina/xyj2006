// created 10/05/1997 by snowcat
#include <ansi.h>

inherit NPC;

#define DEBUG 0

#define MYFILE "/d/huanggong/npc/pang.c"

#define MAXCATEGORY 5
#define MAXPOSITION 3

string *categories = ({
  "金榜",
  "银榜",
  "铜榜",
  "铁榜",
  "锡榜",
 });

string *positions = ({
  "状元",
  "榜眼",
  "探花",
 });

int *limits = ({
  200000,
  100000,
  50000,
  10000,
  1000,
 });

#define LEVEL_NONE 0
#define LEVEL_ASKED 1
#define LEVEL_RANKED 2

int interval_set = 0;
int fight_times = 0;
string FST = 0;

void create()
{
  set_name("房玄龄", ({ "pang xuanling", "pang", "xuanling" }));
  set("title", "大宰相");
  set("gender", "男性");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();

}

int execute_help();
int execute_ask();

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_exert", "exert");
  add_action("do_perform", "perform");
  add_action("do_bian", "bian");
  set("inquiry", ([
        "?":   (: execute_help() :),
        "help":   (: execute_help() :),
        "fight":  (: execute_ask() :),
        "投状":   (: execute_ask() :),
        "状元":   (: execute_ask() :),
        "武状元": (: execute_ask() :),
        "比武":   (: execute_ask() :),
      ]));
  if (FST == 0)
  {
    FST = "/d/huanggong/fst";
  }
}

string randomize (string *strs)
{
  return strs[random(sizeof(strs))];
}

string get_name (object who)
{
  return who->query("name");
}

string get_respect (object who)
{
  return "这位"+RANK_D->query_respect(who);
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"◆ "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                    "，宫内岂可动粗！\n",me,who);
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                    "，宫内不可妄念杀人！\n",me,who);
    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg == "transfer")
    return 0;

  message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                  "，宫内岂可乱施妖术！\n",me,who);
  return 1;
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "sheqi pang xuenling" &&
      arg != "sheqi pang" &&
      arg != "sheqi xuenling")
    return 0;

  message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                  "，宫内岂可私施邪功！\n",me,who);
  return 1;
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                  "，宫内岂可私施邪功！\n",me,who);
  return 1;
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                  "，宫内岂能行窃！\n",me,who);
  return 1;
}

int do_bian(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N对$n慌忙示意: "+get_respect(who)+
                  "，宫内岂能随便变鬼！\n",me,who);
  return 1;
}

int execute_help ()
{
  object who = this_player();
  object me = this_object();

  switch (me->query_temp("huanggong/level"))
  {
    case LEVEL_NONE:
    {
      message_vision ("$N对$n说道："+get_respect(who)+
                      "入宫应招投状，有何难处请问便是。\n",me,who);
      break;
    }
    case LEVEL_ASKED:
    {
      message_vision ("$N对$n说道："+get_respect(who)+
                      "可凭自身武功高低，先去金榜银榜铜榜铁榜锡榜中选其一榜，"+
                      "再择状元榜眼探花之一与之挑战。\n",me,who);
      break;
    }
    case LEVEL_RANKED:
    {
      message_vision ("$N对$n说道："+get_respect(who)+
                      "可凭自身武功高低，先去金榜银榜铜榜铁榜锡榜中选其一榜，"+
                      "再择状元榜眼探花之一与之挑战。\n",me,who);
      break;
    }
  }
  return 1;
}

void reset_interval ()
{
  interval_set = 0;
  fight_times = 0;
}

int execute_ask ()
{
  object who = this_player();
  object me = this_object();

  if (who->query("combat_exp") >= limits[0])
  {
    message_vision ("$N对$n慌忙摇头：以"+get_respect(who)+
                    "的武功修为，那里还用的着争这小小的虚名!\n",me,who);
    return 1;
  }

  if (me->query_temp("huanggong/is_busy"))
  {
    message_vision ("$N对$n摇摇头："+get_respect(who)+
                    "，老夫正忙得不可开交，恕罪失陪了。\n",me,who);
    return 1;
  }

  if(me->query_temp("huanggong/level") < LEVEL_ASKED)
  {
    if (interval_set)
    {
      message_vision ("$N对$n摇摇头："+get_respect(who)+
                      "，投状时间已过，恕罪恕罪。\n",me,who);
      return 1;
    }

    announce (me,who->query("name")+get_respect(who)+"前来入宫投状！\n");
    message_vision ("$N对$n说道："+get_respect(who)+
                    "，老夫这就启奏陛下，报请恩准天下比武封选武状元！\n",me,who);
    message_vision ("$N一甩长袖，风一样离去。\n",me);
    //me->set("env/invisibility",9);
    me->set_temp("huanggong/reappear",environment(me));
    load_object("/obj/empty");
    me->move("/obj/empty");
    remove_call_out ("make_asked");
    call_out ("make_asked",10,me,who);
    return 1;  
  }
  // LEVEL_ASKED, LEVEL_RANKED
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);
  return 1;  
}

void make_asked (object me, object who)
{
  int i;
  object *list;

  if (!who ||
      !environment(who) ||
      environment(who) != me->query_temp("huanggong/reappear"))
  {
    me->move(me->query_temp("huanggong/reappear"));
    message_vision ("$N甩着长袖，风一样飘了过来。\n",me);
    return;
  }

  announce (me,"陛下恩准天下比武封选武状元！");
  announce (me,"五湖四海各路武进士恭请进宫投状！");

  interval_set = 1;
  fight_times = 0;
  call_out ("reset_interval", 14400); // 4h
  me->set_temp("no_return",1);
  me->set_temp("huanggong/level",LEVEL_ASKED);
  //me->set("env/invisibility",0);
  me->move(me->query_temp("huanggong/reappear"));
  message_vision ("$N甩着长袖，风一样飘了过来。\n",me);
  remove_call_out ("continue_asked");
  call_out ("continue_asked",1,me,who);

}

void continue_asked (object me, object who)
{
  message_vision ("$N对$n说道："+get_respect(who)+
                  "带老夫去揭榜挑战。\n",me,who);
  message_vision ("$N一甩长袖，紧紧飘在$n后面。\n",me,who);
  who->set_leader(me);
  me->set_leader(who);
}

int execute_approve_fight(object who, object ob, int position, int category)
{
  object *all, *list, *inv;
  int i, j;
  object me = this_object();

  if (who->query("combat_exp") >= limits[0])
  {
    message_vision ("$N对$n说道：以"+get_respect(who)+
                    "的武功修为，那里还用的着争这小小的虚名!\n",me,who);
    return 0;
  }

  if (who->query("combat_exp") >= limits[category-1])
  {
    message_vision ("$N对$n说道：以"+get_respect(who)+
                    "的武功修为，拜揭"+categories[category-1]+"还不是手到擒来?不用比了,不用比了。\n",me,who);
    return 0;
  }

  if (category < MAXCATEGORY &&
      who->query("combat_exp") < limits[category])
  {
    message_vision ("$N对$n说道："+get_respect(who)+
                    "的武功修为似乎还不到拜揭"+categories[category-1]+"的地步,量力而行吧。\n",me,who);
    return 0;
  }

  announce (me,who->query("name")+"前来拜揭"+categories[category-1]+
            "，与"+ob->query("name")+"比武争夺"+positions[position-1]+"！\n");
  
  me->set_temp("huanggong/is_busy",1);
  me->set_leader(0);
  call_out("reset_is_busy",60,me);
  return 1;
}

int execute_fight_result (object who, object ob, int success)
{
  object me = this_object();
  int i, y, d, h;

  reset_eval_cost();
  call_out("reset_is_busy",5,me);

  if (! success)
    return 1;
  if (!ob)
    return 1;
  if (!present(ob, environment(me)))
    return 1;

  announce (me,ob->query("name")+environment(me)->query("short")+
            "击败"+who->query("name")+"！\n");
  announce (me,"陛下有旨，封"+ob->query("name")+"为"+
            who->get_honor_str()+"！\n");
  i = ob->query("huanggong/wins")+1;
  ob->set("huanggong/wins",i);
  i = (MAXPOSITION*MAXCATEGORY*9)/i + random(9);
  ob->add("combat_exp",i);
  /*
  y = i/1000;
  d = (i - y*1000) / 4;
  h = (i - y*1000 - d*4) * 3;
  if (y > 0)
    tell_object(ob,"你的道行增加了"+chinese_number(y)+"年"+
                chinese_number(d)+"天"+chinese_number(h)+"时辰！\n\n");
  else if (d > 0)
    tell_object(ob,"你的道行增加了"+
                chinese_number(d)+"天"+chinese_number(h)+"时辰！\n\n");
  else if (h > 0)
    tell_object(ob,"你的道行增加了"+
                chinese_number(h)+"时辰！\n\n");
  */
  tell_object(ob,"你的武学修为增加了"+chinese_number(i)+"点!\n\n");
  me->set_temp("huanggong/current_player",ob->query("id"));
  me->set_temp("huanggong/level",LEVEL_RANKED);

  fight_times++;
  if (fight_times > (MAXPOSITION*MAXCATEGORY/2))
  {
    announce (me,"陛下有旨封选武状元结束各路武进士恭请离宫！\n");
    message_vision ("$N甩一甩长袖，风一般飘走了。\n",me);
    me->move(FST);
    me->set_temp("huanggong/is_busy",0);
    me->set_temp("huanggong/level",LEVEL_NONE);
    return 1;
  }

  message_vision ("$N若还有武进士欲继续挑战，"+
                  "可带老夫去揭榜。\n",me);
  message_vision ("$N一甩长袖，飘在$n身后。\n",me,ob);
  me->set_leader(ob);
  return 1;
}

void reset_is_busy(object me)
{
  me->set_temp("huanggong/is_busy",0);
}

