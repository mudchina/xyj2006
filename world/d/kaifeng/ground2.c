// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

inherit __DIR__"ground1";

#include <ground.h>

void randomize_schedule (mapping events, int total, int sessions)
{
  int base = total - sessions;
  int times = sessions*4;

  while (times--)
  {
    int *item;
    int i = base + (times%sessions);
    int j = base + random(sessions);
    int k;

    reset_eval_cost();
    item = events[i];
    if (random(2))
    {
      k = item[0];
      item[0] = item[2];
      item[2] = k;
      k = item[1];
      item[1] = item[3];
      item[3] = k;
    }  
    
    events[i] = events[j];  
    events[j] = item;
  }
}

void schedule_teams_dz (mapping teams)
{
  int cycles = teams[0]["number"];
  int sessions = 0;
  int total = 0;
  int nb_teams = teams["number"];
  int i, j, k;
  mapping events = ([ ]);
  
  for (i = 0; i < cycles; i++)
  {
    sessions = 0;
    reset_eval_cost();
    for (j = 0; j < nb_teams-1; j++)
    {
      for (k = j+1; k < nb_teams; k++)
      {
        events[total] = ({j,i,k,i,0});
        sessions++;
        total++;
      }
    }
    randomize_schedule(events,total,sessions);
  }
  teams["cycles"] = cycles;
  teams["sessions"] = sessions;
  teams["total"] = total;
  teams["events"] = events;
}

void schedule_teams_xh (mapping teams)
{
  int cycles = teams[0]["number"];
  int sessions = 0;
  int total = 0;
  int nb_teams = teams["number"];
  int i, j, k, l;
  mapping events = ([ ]);
  
  for (i = 0; i < cycles; i++)
  {
    sessions = 0;
    reset_eval_cost();
    for (j = 0; j < nb_teams-1; j++)
    {
      for (k = j+1; k < nb_teams; k++)
      {
        for (l = 0; l < cycles; l++)
        {
          events[total] = ({j,i,k,l,0});
          sessions++;
          total++;
        }
      }
    }
    //randomize_schedule(events,total,sessions);
  }
  randomize_schedule(events,total,total);
  teams["cycles"] = cycles;
  teams["sessions"] = sessions;
  teams["total"] = total;
  teams["events"] = events;
}

string show_team (mapping team)
{
  int i;
  string str = "  ";

  for (i = 0; i < team["number"]; i++)
  {
    mapping member = team[i];

    str += member["name"]+"("+member["id"]+") ";
  }
  str += "\n";
  return str;

}

string show_teams (mapping teams)
{
  int i;
  string str = "";

  for (i = 0; i < teams["number"]; i++)
  {
    mapping team = teams[i];

    str += "  第"+chinese_number(i+1)+"队“"+team["info"]["team_name"]+"”：";
    str += show_team (team);
  }
  return str;
}

void announcing_start ()
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team;
  string msg = "本大会比赛方式乃是“"+modes[mode]+"”，"+
                mode_hints[mode]+"。\n";

  announce (msg);
  teams["start"] = 1;
  if (teams && teams["number"] > 0)
  {
    int i;

    teams["current_winner_name"]  = 0;
    teams["current_winner_id"]  = 0;
    teams["current_player0_name"] = 0;
    teams["current_player0_id"] = 0;
    teams["current_player1_name"] = 0;
    teams["current_player1_id"] = 0;
    for (i = 0; i < teams["number"]; i++)
    {
      teams[i]["current_index"] = 0;
    }
  }

  switch (mode)
  {
    case MODE_SINGLE_SD:
    {
      announce (modes[mode]+"无须组队，请巫师将两名玩家邀入场内比赛！\n");
      break;
    }
    case MODE_SINGLE_LT:
    {
      team = teams[0];
      msg = modes[mode]+"，选手按以下弱强顺序依次上场打擂：\n";
      msg += show_team(team);
      announce (msg);
      break;
    }
    case MODE_TEAM_LT:
    {
      msg = modes[mode]+"，共有"+chinese_number(teams["number"])+"组参赛队伍：\n";
      msg += show_teams(teams);
      announce (msg);
      announce ("各队将依按弱强顺序依次上场打擂！\n");
      break;
    }
    case MODE_TEAM_DZ:
    {
      msg = modes[mode]+"，共有"+chinese_number(teams["number"])+"组参赛队伍：\n";
      msg += show_teams(teams);
      announce (msg);
      schedule_teams_dz (teams);
      announce ("本赛将有"+chinese_number(teams["cycles"])+"轮对阵，"+
                "每轮将有"+chinese_number(teams["sessions"])+"场比赛！\n");
      break;
    }
    case MODE_TEAM_XH:
    {
      msg = modes[mode]+"，共有"+chinese_number(teams["number"])+"组参赛队伍：\n";
      msg += show_teams(teams);
      announce (msg);
      schedule_teams_xh (teams);
      announce ("本赛将有"+chinese_number(teams["cycles"])+"轮循环，"+
                "每轮将有"+chinese_number(teams["sessions"])+"场比赛！\n");
      break;
    }
  }
  call_out ("announcing_next",3);
}


void announcing_next ()
{
  object who = this_player();
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team0;
  mapping team1;
  string name0;
  string name1;
  mapping member0;
  mapping member1;
  int done = 0;

  if (mode != MODE_SINGLE_SD)
  {
    tell_room (this_room(),"\n魏征从衣袖子里抽出透明丝绢望空一抛，口中念念有辞。\n");
    tell_room (this_room(),"朝天一拜之后，魏征一把将丝绢顺手接住迅速一瞥。\n");
  }
  switch (mode)
  {
    case MODE_SINGLE_SD:
    {
      inform (who, "现邀请两名玩家前来入场比赛！\n");
      break;
    }
    case MODE_SINGLE_LT:
    {
      team0 = teams[0];
      if (! teams["current_winner_id"])
      {
        int current_index = 0;

        team0["current_index"] = 2;
        member0 = team0[0];
        member1 = team0[1];
        teams["current_player0_name"] = member0["name"];
        teams["current_player0_id"] = member0["id"];
        teams["current_player1_name"] = member1["name"];
        teams["current_player1_id"] = member1["id"];
        announce ("现邀请玩家"+teams["current_player1_name"]+
                   "("+teams["current_player1_id"]+")"+
                  "与玩家"+teams["current_player0_name"]+
                   "("+teams["current_player0_id"]+")"+
                  "前来摆阵打擂！\n");
      }
      else if (team0["current_index"] < team0["number"])
      {
        int current_index = team0["current_index"];

        team0["current_index"] = current_index+1;
        member1 = team0[current_index];
        teams["current_player0_name"] = teams["current_winner_name"];
        teams["current_player0_id"] = teams["current_winner_id"];
        teams["current_player1_name"] = member1["name"];
        teams["current_player1_id"] = member1["id"];
        announce ("现邀请玩家"+teams["current_player1_name"]+
                   "("+teams["current_player1_id"]+")"+
                  "前来挑战擂主"+teams["current_player0_name"]+
                   "("+teams["current_player0_id"]+")"+
                  "！\n");
      }
      else
      {
        done = 1;
      }
      break;
    }
    case MODE_TEAM_LT:
    {
      int i, j, k;

      if (! teams["current_winner_id"])
      {
        int current_index = 0;

        j = random(teams["number"]);
        team0 = teams[j];
        member0 = team0[0];
        team0["current_index"] = 1;
        teams["current_player0_name"] = member0["name"];
        teams["current_player0_id"] = member0["id"];
      }
      else
      {
        team0 = find_teams_team(teams,teams["current_winner_id"]);
        teams["current_player0_name"] = teams["current_winner_name"];
        teams["current_player0_id"] = teams["current_winner_id"];
      }
      
      teams["current_player1_name"] = 0;
      teams["current_player1_id"] = 0;
      k = teams[0]["number"];
      for (i = 0; i < teams["number"]; i++)
      {
        team1 = teams[i];
        if (find_team_member(team1,teams["current_player0_id"]))
          continue;
        if (k > team1["current_index"])
        { 
          k = team1["current_index"];
          j = i;
        }
      }

      if (k < teams[0]["number"])
      {
        team1 = teams[j];
        member1 = team1[k];

        team1["current_index"] = k+1;
        teams["current_player1_name"] = member1["name"];
        teams["current_player1_id"] = member1["id"];

        name0 = "“"+team0["info"]["team_name"]+"”队";
        name1 = "“"+team1["info"]["team_name"]+"”队";
        if (! teams["current_winner_id"])
          announce ("现邀请"+name1+"选手"+teams["current_player1_name"]+
                     "("+teams["current_player1_id"]+")"+
                    "与"+name0+"选手"+teams["current_player0_name"]+
                     "("+teams["current_player0_id"]+")"+
                    "前来摆阵打擂！\n");
        else
          announce ("现邀请"+name1+"选手"+teams["current_player1_name"]+
                     "("+teams["current_player1_id"]+")"+
                    "前来挑战"+name0+"擂主"+teams["current_player0_name"]+
                     "("+teams["current_player0_id"]+")"+
                    "！\n");
      }
      else
      {
        done = 1;
      }
      break;
    }
    case MODE_TEAM_DZ:
    case MODE_TEAM_XH:
    {
      int cycles = teams["cycles"];
      int sessions = teams["sessions"];
      int total = teams["total"];
      int index = teams["index"];
      mapping events = teams["events"];
   
      if (index < total)
      {
        int *item = events[index];

        team0 = teams[item[0]];
        team1 = teams[item[2]];
        member0 = team0[item[1]];
        member1 = team1[item[3]];
        teams["current_player0_name"] = member0["name"];
        teams["current_player0_id"] = member0["id"];
        teams["current_player1_name"] = member1["name"];
        teams["current_player1_id"] = member1["id"];
        teams["index"] = index+1;
        name0 = "“"+team0["info"]["team_name"]+"”队";
        name1 = "“"+team1["info"]["team_name"]+"”队";
        announce ("大会第"+chinese_number(index/sessions+1)+"轮第"+
                  chinese_number(index%sessions+1)+"场比赛：\n");
        announce ("现邀请"+name1+"选手"+teams["current_player1_name"]+
                   "("+teams["current_player1_id"]+")"+
                  "与"+name0+"选手"+teams["current_player0_name"]+
                   "("+teams["current_player0_id"]+")"+
                  "前来上场较量！\n");
      }
      else
      {
        done = 1;
      }
      break;
    }
  }
  teams["done"] = done;
  if (done)
    inform (who, "差不多了，可以结束比赛了！\n");
}

string report_check (int brief)
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team;
  string msg = "比赛方式“"+modes[mode]+"”，"+
                mode_hints[mode]+"。\n";

  switch (mode)
  {
    case MODE_SINGLE_SD:
    {
      if (brief)
        return msg;
      msg += "\n请巫师将任意两名玩家邀入场内比赛。\n";
      break;
    }
    case MODE_SINGLE_LT:
    {
      msg += modes[mode]+"，选手按以下弱强顺序依次上场打擂：\n";
      msg += show_team(teams[0]);
      if (brief)
        return msg;
      msg += "\n赢者为擂主，接受新选手的挑战。\n";
      break;
    }
    case MODE_TEAM_LT:
    {
      msg += modes[mode]+"，共有"+chinese_number(teams["number"])+"组参赛队伍：\n";
      msg += show_teams(teams);
      if (brief)
        return msg;
      msg += "\n各队将依按输赢结果依次上场打擂。\n";
      break;
    }
    case MODE_TEAM_DZ:
    {
      msg += modes[mode]+"，共有"+chinese_number(teams["number"])+"组参赛队伍：\n";
      msg += (show_teams(teams));
      if (brief)
        return msg;
      msg += "\n每队选手依次与别队同级选手较量。\n";
      break;
    }
    case MODE_TEAM_XH:
    {
      msg += modes[mode]+"，共有"+chinese_number(teams["number"])+"组参赛队伍：\n";
      msg += (show_teams(teams));
      if (brief)
        return msg;
      msg += "\n每队选手依次与别队所有的选手较量。\n";
      break;
    }
  }
  return msg;
}

string report_contest (int brief)
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team0;
  mapping team1;
  string name0;
  string name1;
  string msg = "";
  
  if (teams && ! teams["start"])
    return "比赛还没有开始。\n";
    
  if (! teams["current_player0_id"] &&
      (mode != MODE_SINGLE_SD))
    return "赛场尚未准备就绪，请稍候几秒。\n";

  switch (mode)
  {

    case MODE_SINGLE_SD:
    {
      msg += modes[mode]+"，任意两名玩家均可参加比赛。\n";
      break;
    }
    case MODE_SINGLE_LT:
    {
      if (! teams["current_player1_id"])
        msg += "玩家"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "上场打擂。\n";
      else if (! teams["current_winner_id"])
        msg += "玩家"+teams["current_player1_name"]+
                 "("+teams["current_player1_id"]+")"+
                "与玩家"+teams["current_player0_name"]+
                 "("+teams["current_player0_id"]+")"+
                "摆阵打擂。\n";
      else
        msg += "玩家"+teams["current_player1_name"]+
                 "("+teams["current_player1_id"]+")"+
                "前来挑战擂主"+teams["current_player0_name"]+
                 "("+teams["current_player0_id"]+")"+
                "。\n";
      break;
    }
    case MODE_TEAM_LT:
    {

      team0 = find_teams_team(teams,teams["current_player0_id"]);
      team1 = find_teams_team(teams,teams["current_player1_id"]);
      name0 = "“"+team0["info"]["team_name"]+"”队";
      if (team1)
        name1 = "“"+team1["info"]["team_name"]+"”队";

      if (! teams["current_player1_id"])
        msg += name0+"选手"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "上场打擂。\n";
      else if (! teams["current_winner_id"])
        msg += name1+"选手"+teams["current_player1_name"]+
               "("+teams["current_player1_id"]+")"+
               "与"+name0+"选手"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "摆阵打擂。\n";
      else
        msg += name1+"选手"+teams["current_player1_name"]+
               "("+teams["current_player1_id"]+")"+
               "前来挑战"+name0+"擂主"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "。\n";
      break;
    }
    case MODE_TEAM_DZ:
    case MODE_TEAM_XH:
    {
      team0 = find_teams_team(teams,teams["current_player0_id"]);
      team1 = find_teams_team(teams,teams["current_player1_id"]);
      name0 = "“"+team0["info"]["team_name"]+"”队";
      if (team1)
        name1 = "“"+team1["info"]["team_name"]+"”队";

      if (! teams["current_player1_id"])
        msg += name0+"选手"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "上场。\n";
      else         
        msg += name1+"选手"+teams["current_player1_name"]+
               "("+teams["current_player1_id"]+")"+
               "与"+name0+"选手"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "比赛。\n";
      break;
    }
  }
  if (brief)
    return msg;          
  if (!  teams["done"])  
    msg += "\n请巫师将他们邀入(summon)场内比赛。\n";
  return msg;
}

string report_events (mapping teams)
{
  int mode = this_room()->query("match/mode");
  int cycles = teams["cycles"];
  int sessions = teams["sessions"];
  int total = teams["total"];
  int index = teams["index"];
  mapping events = teams["events"];
  mapping team0;
  mapping team1;
  mapping member0;
  mapping member1;
  string name0;
  string name1;
  string msg = "";
  int *item;
  int win;
  int i, j;
   
  if (! events)
    return "";
    
  if (teams["done"])
    j = total; // done, index is not incremented
  else
    j = index - 1;  
  msg += "比赛结果：\n";
  for (i = 0; i < j; i++)
  {
    item = events[i];
    team0 = teams[item[0]];
    team1 = teams[item[2]];
    member0 = team0[item[1]];
       member1 = team1[item[3]];
    win = item[4];
    if (mode == MODE_SINGLE_SD ||
        mode == MODE_SINGLE_LT)
    {
      name0 = "";
      name1 = "";
    }    
    else
    {
      //name0 = "“"+team0["info"]["team_name"]+"”队选手";
      //name1 = "“"+team1["info"]["team_name"]+"”队选手";
      name0 = "“"+team0["info"]["team_name"]+"”队";
      name1 = "“"+team1["info"]["team_name"]+"”队";
    }  
    msg += "  "+to_chinese(i+1)+". ";
    msg += name0+member0["name"]+"("+member0["id"]+")";
    if (win)
      msg += "战胜";
    else
      msg += "输给";
    msg += name1+member1["name"]+"("+member1["id"]+")\n";
  }
  
  if (index >= total)
    return msg;
    
  msg += "即将开始的比赛：\n";
  for (i = index; i < total; i++)
  {
    item = events[i];
    team0 = teams[item[0]];
    team1 = teams[item[2]];
    member0 = team0[item[1]];
    member1 = team1[item[3]];
    win = item[4];
    name0 = "“"+team0["info"]["team_name"]+"”队";
    name1 = "“"+team1["info"]["team_name"]+"”队";
    msg += "  "+to_chinese(i-index+1)+". ";
    msg += name0+"选手"+member0["name"]+"("+member0["id"]+")";
    msg += "迎战";
    msg += name1+"选手"+member1["name"]+"("+member1["id"]+")\n";
  }
  return msg;
}

string report_result  ()
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team0;
  mapping team1;
  mapping member0;
  mapping member1;
  int *item;
  int win;
  string name0;
  string name1;
  string msg = "";
  int i, j, k;

  if (teams && ! teams["start"])
    return "请稍候几秒，比赛马上就开始。\n";

  if (! teams["current_player0_id"] &&
      (mode != MODE_SINGLE_SD))
    return "请稍候几秒，赛场立刻就准备就绪。\n";
    
  switch (mode)
  {
    case MODE_SINGLE_SD:
    {
      msg = report_events (teams);
      if (msg == "")
        msg = "请稍候几秒，比赛立刻就开始。\n";
      return msg;  
      break;
    }
    case MODE_SINGLE_LT:
    {
      int current_index;
      
      team0 = teams[0];
      current_index = team0["current_index"];

      msg += modes[mode]+"：";
      if (! teams["current_winner_id"])
        return msg+"还没有赛出擂主。\n";

      msg += "擂主是"+teams["current_winner_name"]+
             "("+teams["current_winner_id"]+")";
      if (teams["current_player1_id"])
      {
        msg += "，接受"+teams["current_player1_name"]+
               "("+teams["current_player1_id"]+")"+"的挑战。\n";
      }
      else
      {
        msg += "。\n";
      }
      msg += report_events (teams);
/*      
      msg += "被击败的玩家是：";
      for (i = 0; i < current_index; i++)
      {
        mapping member = team0[i];
        
        if (member["id"] != teams["current_winner_id"])
          msg += member["name"]+"("+member["id"]+") ";
      }
      msg += "\n";
*/      
      if (current_index < team0["number"])
        msg += "尚未上场的玩家是：";
      for (i = current_index; i < team0["number"]; i++)
      {
        mapping member = team0[i];
        
        msg += member["name"]+"("+member["id"]+") ";
      }
      msg += "\n";
      break;
    }
    case MODE_TEAM_LT:
    {
      msg += modes[mode]+"：";
      if (! teams["current_winner_id"])
        return msg+"还没有赛出擂主。\n";

      team0 = find_teams_team(teams,teams["current_winner_id"]);
      name0 = "“"+team0["info"]["team_name"]+"”队";
      msg += "擂主是"+name0+"的"+teams["current_winner_name"]+
             "("+teams["current_winner_id"]+")";
      if (teams["current_player1_id"])
      {
        team1 = find_teams_team(teams,teams["current_player1_id"]);
        name1 = "“"+team1["info"]["team_name"]+"”队";
        msg += "，接受"+name1+"的"+teams["current_player1_name"]+
               "("+teams["current_player1_id"]+")"+"的挑战。\n";
      }
      else
      {
        msg += "。\n";
      }

      msg += report_events (teams);
      msg += "各队战况：\n";
      for (i = 0; i < teams["number"]; i++)
      {
        int current_index;
        
        team0 = teams[i];
        current_index = team0["current_index"];
        name0 = "“"+team0["info"]["team_name"]+"”队";
        msg += "  "+name0+"：";
        msg += "赢了"+chinese_number(team0["info"]["wins"])+"场，";
        msg += "输了"+chinese_number(team0["info"]["loses"])+"场。\n";
/*        
        msg += "    被击败的选手是：";
        for (j = 0; j < current_index; j++)
        {
          mapping member = team0[j];
          
          if (member["id"] != teams["current_winner_id"])
            msg += member["name"]+"("+member["id"]+") ";
        }
        msg += "\n";
*/ 
        msg += "    尚未上场的选手是：";
        for (j = current_index; j < team0["number"]; j++)
        {
          mapping member = team0[j];
        
          msg += member["name"]+"("+member["id"]+") ";
        }
        msg += "\n";
      }
      break;
    }
    case MODE_TEAM_DZ:
    case MODE_TEAM_XH:
    {
      int cycles = teams["cycles"];
      int sessions = teams["sessions"];
      int total = teams["total"];
      int index = teams["index"];
      mapping events = teams["events"];
   
      msg += "总共有"+chinese_number(cycles)+"轮，每轮有"+
              chinese_number(sessions)+"场比赛。\n";
      if (teams["done"])
      {
        msg += "现在赛事已完。\n";
      }
      else if (index/sessions+1 <= cycles)
      { 
        msg += "现在是第"+chinese_number((index-1)/sessions+1)+"轮第"+
                chinese_number((index-1)%sessions+1)+"场，";
        msg += "合计第"+chinese_number(index)+"场。\n";
      }  
      msg += "现在上场的是";
      team0 = find_teams_team(teams,teams["current_player0_id"]);
      name0 = "“"+team0["info"]["team_name"]+"”队";
      if (teams["current_player1_id"])
      {
        team1 = find_teams_team(teams,teams["current_player1_id"]);
        name1 = "“"+team1["info"]["team_name"]+"”队";
        msg += name1+"选手"+teams["current_player1_name"]+
               "("+teams["current_player1_id"]+")"+
               "与"+name0+"选手"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+
               "比赛。\n";
      }  
      else
        msg += name0+"选手"+teams["current_player0_name"]+
               "("+teams["current_player0_id"]+")"+"。\n";

      msg += "\n各队战况：\n";
      for (i = 0; i < teams["number"]; i++)
      {
        team0 = teams[i];
        name0 = "“"+team0["info"]["team_name"]+"”队";
        msg += "  "+name0+"：";
        msg += "赢了"+chinese_number(team0["info"]["wins"])+"场，";
        msg += "输了"+chinese_number(team0["info"]["loses"])+"场。\n";
      }
      
      msg += report_events (teams);
      break;
    }
  }
  return msg;
}

int do_report2()
{
  string line = "\n-------------------------------------------------------------------\n";
  string msg = line;
  
  msg += "\n";
  msg += "大会比赛阶段：\n";
  msg += "\n";
  msg += report_check(1);
  msg += "[检查正在进行的比赛：check]\n";
  msg += "\n";
  msg += report_contest(1);
  msg += "[察看上场选手：contest]\n";
  msg += "\n";
  msg += "[察看已赛出的结果：result]\n";
  msg += "\n";
  msg += "[正常结束比赛：finish]\n";
  msg += "[紧急取消比赛：abort]\n";
  msg += "\n";
  msg += line;
  this_player()->start_more(msg);
  return 1;
}

int do_check ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FIGHT)
  {  
    write ("现在并没有比赛！\n\n");
    return 1;
  }
  who->start_more(report_check(0));
  return 1;
}

int do_contest ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FIGHT)
  {  
    write ("现在并没有比赛！\n\n");
    return 1;
  }
  who->start_more(report_contest(0));
  return 1;
}

int do_result ()
{
  int step = this_room()->query("match/step");
  object who = this_player();

  if (step != STEP_FIGHT)
  {  
    write ("现在并没有比赛！\n\n");
    return 1;
  }
  inform (who, report_result(), "魏征告诉$N说，比赛近况总结如下：\n");
  //who->start_more(report_result());
  return 1;
}

int do_finish ()
{
  int step = this_room()->query("match/step");
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  string msg = "";

  object who = this_player();

  if (step != STEP_FIGHT)
  {  
    write ("现在并没有比赛！\n\n");
    return 1;
  }

  if (teams && ! teams["start"])
  {
    write ("比赛还没有开始。\n");
    return 1;
  }

  if ((mode == MODE_SINGLE_SD && teams["number"] == 0) ||
      (mode != MODE_SINGLE_SD && ! teams["done"]))
  {
    write ("比赛还没有赛完！\n");
    return 1;
  }
  this_room()->set("match/step",STEP_FINISH);
  inform (who, "那就结束比赛吧。\n");
  return 1;
}

void aborting (string arg, object who)
{
  if (arg == "y" || arg == "Y")
  {
    inform (who, "比赛紧急取消。\n");
    this_room()->delete("match");
  }
  else
  {
    write("好，继续比赛。\n");
  }
}

int do_abort ()
{
  int step = this_room()->query("match/step");
  mapping teams = this_room()->query("match/teams");

  object who = this_player();

//  if (step != STEP_FIGHT)
//  {  
//    write ("现在并没有比赛！\n\n");
//    return 1;
//  }

  write ("如果取消比赛，现有比赛结果将全部丢失！\n");
  write ("您真的要紧急取消比赛？(Y/N)\n");
  input_to ((: aborting :), who);
  return 1;

}

int valid_player (object who)
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
    
  if (mode == MODE_SINGLE_SD)
    return 1;
  if (! teams)
    return 0;  
  if (who->query("id") == teams["current_player0_id"])
    return 1;
  if (who->query("id") == teams["current_player1_id"])
    return 1;
  return 0;  
}

int arbit (string arg)
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  mapping team0;
  mapping team1;
  mapping team_info0;
  mapping team_info1;
  mapping events;
  int total;
  int index;
  int wins;
  object ob;
  
  // check valid fight here:
  team0 = find_teams_team(teams,teams["current_player0_id"]);
  team1 = find_teams_team(teams,teams["current_player1_id"]);
  if (team0)
    team_info0 = team0["info"];
  if (team1)
    team_info1 = team1["info"];
  events = teams["events"];
  total = teams["total"];
  index = teams["index"];
  
  wins = (arg  && arg != "0");

  if (mode == MODE_SINGLE_SD ||
      mode == MODE_SINGLE_LT ||
      mode == MODE_TEAM_LT)
  {
    int i, j, k, l;
    
    if (mode == MODE_SINGLE_SD)
    {
      if (teams["number"] == 0)
      {
        team_info0 = ([ ]);
        team0 = ([ "number" : 0, "info" : team_info0 ]);
        teams["number"] = 1;
        teams[0] = team0;
      }
      else
      {
        team0 = teams[0];
        team_info0 = team0["info"];
      }
      team1 = team0;  
      team_info1 = team_info0;  
      if (find_member_index (team0, teams["current_player0_id"]) == -1)
        add_team_member (team0, find_player(teams["current_player0_id"]),1);
      if (find_member_index (team0, teams["current_player1_id"]) == -1)
        add_team_member (team0, find_player(teams["current_player1_id"]),1);
    }
        
    i = find_team_index (teams, team0);
    j = find_member_index (team0, teams["current_player0_id"]);
    k = find_team_index (teams, team1);
    l = find_member_index (team1, teams["current_player1_id"]);
    if (! events)
    {
      events = ([ ]);
      teams["events"] = events;
    }  
    events[total] = ({i,j,k,l,wins});
    teams["total"] = total+1;
    teams["index"] = total+2;
  }
  else
  {
    events[index-1][4] = wins;
  }
  
  if (wins)
  {
    teams["current_winner_name"]  = teams["current_player0_name"];
    teams["current_winner_id"]  =  teams["current_player0_id"];
    if (team_info0)
      team_info0["wins"]++;
    if (team_info1)  
      team_info1["loses"]++;
  }
  else
  {
    teams["current_winner_name"]  = teams["current_player1_name"];
    teams["current_winner_id"]  =  teams["current_player1_id"];
    if (team_info0)
      team_info0["loses"]++;
    if (team_info1)  
      team_info1["wins"]++;
    teams["current_player0_name"] = teams["current_winner_name"];
    teams["current_player0_id"] = teams["current_winner_id"];
    team0 = team1;
    team_info0 = team_info1;
  }
  teams["current_player1_name"] = 0;
  teams["current_player1_id"] = 0;
  announce (teams["current_winner_name"]+"比武获胜！\n");
  announce ("赐"+teams["current_winner_name"]+"个人"+chinese_number(REWARD)+"点潜能！\n");
  ob = find_player (teams["current_winner_id"]);
  if (! ob)
    ob =  LOGIN_D->find_body(teams["current_winner_id"]);
  if (! team_info0)
  {
    team_info0 = ([ ]);
    team0["info"] = team_info0;
  }  
  if (! team_info0["reward"])
    team_info0["reward"] = ([ ]);
  team_info0["reward"][teams["current_winner_id"]] += REWARD;
  if (ob && !DEBUG)
  {
    ob->add("potential",REWARD);
    tell_object (ob,"你获得了"+chinese_number(REWARD)+"点潜能！\n");
  }  
  else if (ob && DEBUG)
  {
    //write ("debug:"+ob->query("name")+"获得了"+chinese_number(REWARD)+"点潜能！\n");
  }
  if (mode == MODE_TEAM_LT ||
      mode == MODE_TEAM_DZ ||
      mode == MODE_TEAM_XH)
  {
    int i;
    announce ("赐"+team_info0["team_name"]+"队其他选手每人"+
              chinese_number(REWARD/4)+"点潜能！\n");
    team_info0["reward"]["all of us"] += REWARD/4;
    for (i = 0; i < team0["number"]; i++)
    {
      ob = find_player (team0[i]["id"]);
      if (! ob)
        continue;
      if (teams["current_winner_id"]==ob->query("id"))
        continue;
      team_info0["reward"][ob->query("id")] += REWARD/4;
      if (ob && !DEBUG)
      {
        ob->add("potential",REWARD/4);
        tell_object (ob,"你获得了"+chinese_number(REWARD/4)+"点潜能！\n");
      }  
      else if (ob && DEBUG)
      {
        //write ("debug:"+ob->query("name")+"获得了"+chinese_number(REWARD/4)+"点潜能！\n");
      }
                  
    }
  }
  call_out ("announcing_next",3);
  return 1;
}

void alternative_die (object me)
{
  int mode = this_room()->query("match/mode");
  mapping teams = this_room()->query("match/teams");
  object ob = me->query_temp("last_opponent");
  
  me->set("kee", 1);
  me->set("sen", 1);
  me->set("eff_kee",me->query("max_kee"));
  me->set("eff_sen",me->query("max_sen"));
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
      
  if (! userp(me))
  {
    message_vision ("\n$N重重地摔倒在地，被候在两边的伺官扶走。\n",me);
    destruct(me);
    return;
  }
  message_vision ("\n$N重重地摔倒在地，魏征急忙上来将两人拉开。\n",me);
  message_vision ("地下传来崔判官的声音：水陆大会比武，不伤阳寿！\n",me);
  message_vision ("\n$N慢慢从地上爬将起来，被候在两边的伺官扶起向南走去。\n",me);
  me->move(__DIR__"south");
  message_vision ("$N被人扶着慢慢走了过来。\n",me);
  
  if (! ob)
    ob = me->query_temp("last_damage_from");
  if (! ob)
    return;  
  if (! teams)
    return;  
  if (mode != MODE_SINGLE_LT &&
      mode != MODE_TEAM_LT)  
  {
    message_vision ("\n几位伺官上来拥着得胜的$N向北走去。\n",ob);
    ob->move(__DIR__"north");
    message_vision ("$N由几位伺官拥着走了过来。\n",ob);
  }
      
  if (mode == MODE_SINGLE_SD)
  {
    teams["current_player0_id"] = ob->query("id");
    teams["current_player0_name"] = ob->query("name");
    teams["current_player1_id"] = me->query("id");
    teams["current_player1_name"] = me->query("name");
    arbit ("1");
  }
  else if (teams["current_player0_id"] == ob->query("id") &&
           teams["current_player1_id"] == me->query("id"))
  {
    arbit ("1");
  }
  else if (teams["current_player0_id"] == me->query("id") &&
           teams["current_player1_id"] == ob->query("id"))
  {
    arbit ("0");
  }
  else if (DEBUG)
  {
    write ("current_player0_id:"+teams["current_player0_id"]+" "+
           "current_player1_id:"+teams["current_player1_id"]+" "+
           "my id:"+me->query("id") + " " + "ob id:"+ob->query("id"));
  }
}

int do_debug (string arg)
{
  mapping teams = this_room()->query("match/teams");
  string s0, s1, s2;
  object ob0, ob1;
  
  if (sscanf(arg, "%s %s %s", s0, s1, s2) != 3)
  {
    write ("debug: @debug@ id0 id1 0/1\n");
    return 1;
  }
  if (! teams)
  {
    write ("debug: no teams\n");
    return 1;
  }
  if (s0 != "-" && s1 != "-")
  {
    ob0 = find_player(s0);
    ob1 = find_player(s1);
    if (! ob0)
    {
      write ("debug: no player ob 0\n");
      return 1;
    }
    if (! ob1)
    {
      write ("debug: no player ob 1\n");
      return 1;
    }
    teams["current_player0_id"] = s0;
    teams["current_player0_name"] = ob0->query("name");
    teams["current_player1_id"] = s1;
    teams["current_player1_name"] = ob1->query("name");
  }  
  if (s0 == "-" && ! teams["current_player0_id"])
  {
    write ("debug: no player ob 0\n");
    return 1;
  }
  if (s1 == "-" && ! teams["current_player1_id"])
  {
    write ("debug: no player ob 1\n");
    return 1;
  }
  arbit (s2);
  return 1;
}

void init2()
{
  add_action ("do_check","check");
  add_action ("do_contest","contest");
  add_action ("do_result","result");
  add_action ("do_finish","finish");
  add_action ("do_abort","abort");
  add_action ("do_debug","@debug@");
}
 
