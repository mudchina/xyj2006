
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

inherit __DIR__"ground2";

#include <ground.h>

int do_report3()
{
  string line = "\n-------------------------------------------------------------------\n";
  string msg = line;
  
  msg += "\n";
  msg += "大会结束阶段：\n";
  msg += "\n";
  msg += "[察看比赛总成绩：exam]\n";
  msg += "[宣布比赛总成绩：post]\n";
  msg += "\n";
  msg += "[存储比赛成绩档案：save]\n";
  msg += "\n";
  msg += "[宣布大会闭幕：close]\n";
  msg += "\n";
  msg += line;
  this_player()->start_more(msg);
  return 1;
}

void order_potentials (mapping potentials)
{
  int i, j;

  for (i = sizeof(potentials)-2; i >= 0; i--)
  {
    reset_eval_cost();
    for (j = 0; j <= i; j++)
    {
      if (potentials[j]["pot"] < potentials[j+1]["pot"])
      {
        mapping potential = potentials[j];
        
        potentials[j] = potentials[j+1];
        potentials[j+1] = potential;
      }
    }
  }
}

void order_teams (mapping teams)
{
  int i, j;
  int bonus = teams["bonus"];

  for (i = 0; i < teams["number"]; i++)
  {
    mapping team = teams[i];
    mapping team_info = team["info"];

    team_info["score"] = bonus + team_info["bonus"] +
                         team_info["wins"] - team_info["loses"];
  }

  for (i = teams["number"]-2; i >= 0; i--)
  {
    reset_eval_cost();
    for (j = 0; j <= i; j++)
    {
      if (teams[j]["info"]["score"] < teams[j+1]["info"]["score"])
      {
        mapping team = teams[j];
        teams[j] = teams[j+1];
        teams[j+1] = team;
      }
    }
  }
}

varargs string report_reward (mapping team, int no_team_name, int team_nb)
{
  mapping potentials = ([ ]);
  string name;
  string msg = "";
  int j;

  if (! no_team_name)
  {
    name = "“"+team["info"]["team_name"]+"”队";
    msg += "  第"+chinese_number(team_nb)+"名"+name+"：";
    msg += "积分"+chinese_number(team["info"]["score"])+"，";
    msg += "（赢了"+chinese_number(team["info"]["wins"])+"场，";
    msg += "输了"+chinese_number(team["info"]["loses"])+"场）。\n";
     }
    
  msg += "    获奖潜能：";
  for (j = 0; j < team["number"]; j++)
  {
    mapping member = team[j];
    mapping team_info;
    mapping team_reward;
    int pot;
    
    team_info = team["info"];
    if (! team_info)
      continue;
    team_reward = team_info["reward"];
    if (! team_reward)
      continue;
    pot = team_reward[member["id"]];
    name = member["name"]+"("+member["id"]+")";
    potentials[j] = ([ "pot" : pot, "name" : name ]);
  }
  order_potentials (potentials);
  for (j = 0; j < team["number"]; j++)
  {
 
    msg += potentials[j]["name"]+potentials[j]["pot"]+" ";
  }
  msg += "\n";
  return msg;
}

string report_score ()
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team;
  string name;
  string msg = "";
  int i;

  // teams will be sorted, have to record events first!
  if (! teams["report_events"])
    teams["report_events"] = report_events (teams);
    
  msg += "比赛方式：“"+modes[mode]+"”。\n";
  switch (mode)
  {
    case MODE_SINGLE_SD:

    {
      msg += report_reward (teams[0],1);
      msg += teams["report_events"];
      break;
    }
    case MODE_SINGLE_LT:
    {
      msg += "擂主是"+teams["current_winner_name"]+
             "("+teams["current_winner_id"]+")。\n";

      msg += report_reward (teams[0],1);
      msg += teams["report_events"];
      break;
    }
    case MODE_TEAM_LT:
    {
      team = find_teams_team(teams,teams["current_winner_id"]);
      name = "“"+team["info"]["team_name"]+"”队";
      msg += "擂台获胜的队是"+name+"，";
      msg += "擂主是"+teams["current_winner_name"]+
             "("+teams["current_winner_id"]+")。\n";
      msg += "各队战况：\n";
      team["info"]["bonus"] = (teams["number"]-1)*team["number"];

      teams["bonus"] = (teams["number"]-1)*team["number"];
      order_teams (teams);
      for (i = 0; i < teams["number"]; i++)
        msg += report_reward (teams[i],0,i+1);
      msg += teams["report_events"];
      break;
    }
    case MODE_TEAM_DZ:
    case MODE_TEAM_XH:
    {
      int cycles = teams["cycles"];
      int sessions = teams["sessions"];
      int total = teams["total"];
      int index = teams["index"];
   
      msg += "总共有"+chinese_number(cycles)+"轮，每轮有"+
              chinese_number(sessions)+"场比赛。\n";
      msg += "各队战况：\n";
      teams["bonus"] = sessions * cycles;
      order_teams (teams);
      for (i = 0; i < teams["number"]; i++)
        msg += report_reward (teams[i],0,i+1);
      msg += teams["report_events"];
      break;
    }
  }
  return msg;
}

int do_exam ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FINISH)
  {  
    write ("比赛还没有结束！\n\n");
    return 1;
  }
  inform (who, report_score(), "魏征告诉$N说，比赛成绩总结如下：\n");
  return 1;
}

int do_post ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FINISH)
  {  
    write ("比赛还没有结束！\n\n");
    return 1;
  }
  announce (report_score());
  return 1;
}

int do_save ()
{
  int step = this_room()->query("match/step");
  mapping teams = this_room()->query("match/teams");
  object who = this_player();
  string msg;

  if (step != STEP_FINISH)
  {  
    write ("比赛还没有结束！\n\n");
    return 1;
  }

  msg = "\n           ——  ※  ——  ※  ——  ※  ——  ※  ——  \n";
  msg += "\n比赛时间："+ctime(time())+"\n";
  msg += report_score();  
  msg += "\n\n";
  log_file("shuiludahui",msg);
  //write_file ("/data/shuiludahui/shdl_result",msg,1);
  teams["save"] = 1;
  inform (who, "比赛成绩存档完毕。\n");
  return 1;
}

void closing (string arg, object who)
{
  if (arg == "y" || arg == "Y")
  {
    inform (who, "比赛成绩不存档。\n");
    announce ("比武大会闭幕！\n");
    this_room()->delete("match");
  }
  else
  {
    write("好，大会暂不闭幕。\n");

  }
}

int do_close ()
{
  int step = this_room()->query("match/step");
  mapping teams = this_room()->query("match/teams");
  object who = this_player();

  if (step != STEP_FINISH)
  {  
    write ("比赛还没有结束！\n\n");
    return 1;
  }
  
  if (! teams["save"])
  {
    write ("比赛成绩尚未存档，您真的要宣布闭幕？(Y/N)\n");
    input_to ((: closing :), who);
    return 1;
  }
  else
  {
    announce ("比武大会闭幕！\n");
  }
  this_room()->delete("match");
  return 1;
}

int do_put () // debug only
{
  object who = this_player ();
  mapping match = this_room()->query("match");

  who->set_temp("match",this_room()->query("match"));
  return 1;
}
          
int do_get () // debug only
{
  object who = this_player ();
  mapping match = this_room()->query("match");
  
  this_room()->set("match",who->query_temp("match"));
  return 1;
}

void init3()
{
  add_action ("do_exam","exam");
  add_action ("do_post","post");
  add_action ("do_save","save");
  add_action ("do_close","close");
  add_action ("do_put","@put@");
  add_action ("do_get","@get@");
}
 
