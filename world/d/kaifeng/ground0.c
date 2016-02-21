
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

#include <ground.h>

object my_room = 0;
object this_room ()
{
  if (! my_room)
    my_room = load_object(__DIR__"ground");
  return my_room;
}

void announcing (string str)
{
  if (DEBUG)
  {
    object snowcat = find_player ("snowcat");

    if (wizardp(snowcat))
      tell_object (snowcat," ◇ "+str);
  }
  else
  {
    object wei = load_object (__DIR__"npc/wei");
    wei->command_function("chat "+str);
  }
}

void announce (string str)
{
  string s = str;
  int i, j;
  
  while ((i = strlen(s)) > 0)
  {
    j = strsrch (s, "\n");
    if (j < 0)
    {
      announcing (s);
      return;
    }  
    announcing (s[0..j]);
    s = s[j+1..i];
  }
}

varargs void inform (object who, string str, string msg)
{
  string *msgs = ({
    "\n魏征对$N点头说道：好，",
    "\n魏征向$N一拜道：遵命，",
    "\n魏征对$N点点头：是，",
    "\n魏征连忙对$N说道：行，",
  });
  if (who)
  {
    if (msg)
      message_vision (msg+str,who);
    else
      message_vision (msgs[random(sizeof(msgs))]+str,who);
  }
  else
    tell_room (this_room(),"\n魏征点点头："+str);  
}

void broadcast_room (object room, string str)
{
  string prefix = "〖赛场内〗";
  string s1 = str, s2 = "";

  reset_eval_cost();

  s1 = replace_string (s1, NOR, "");
  s1 = replace_string (s1, BLK, "");
  s1 = replace_string (s1, RED, "");
  s1 = replace_string (s1, GRN, "");
  s1 = replace_string (s1, YEL, "");
  s1 = replace_string (s1, BLU, "");
  s1 = replace_string (s1, MAG, "");
  s1 = replace_string (s1, CYN, "");
  s1 = replace_string (s1, MAG, "");
  s1 = replace_string (s1, WHT, "");
  s1 = replace_string (s1, HIB, "");
  s1 = replace_string (s1, HIR, "");
  s1 = replace_string (s1, HIG, "");
  s1 = replace_string (s1, HIY, "");
  s1 = replace_string (s1, HIB, "");
  s1 = replace_string (s1, HIM, "");
  s1 = replace_string (s1, HIC, "");
  s1 = replace_string (s1, HIM, "");
  s1 = replace_string (s1, HIW, "");

  while (strsrch(s1,"\n\n") != -1)
    s1 = replace_string(s1,"\n\n","\n");

  if (s1[strlen(s1)-1]=='\n')
  {
    s1 = s1[0..strlen(s1)-2];
    s2 = "\n";
  }
  if (strlen(s1) == 0)
    return;
  s1 = replace_string(s1,"\n","\n"+prefix)+s2;
  if (room)
  {
    tell_room (room, HIY + prefix+s1 + NOR);     
  }
}

void broadcast (string str)
{
  broadcast_room(load_object(__DIR__"east"),str);
  broadcast_room(load_object(__DIR__"west"),str);
  broadcast_room(load_object(__DIR__"south"),str);
  broadcast_room(load_object(__DIR__"north"),str);
/*
  call_out ("broadcast_room",1,load_object(__DIR__"east"),str);
  call_out ("broadcast_room",1,load_object(__DIR__"west"),str);
  call_out ("broadcast_room",1,load_object(__DIR__"north"),str);
  call_out ("broadcast_room",1,load_object(__DIR__"south"),str);
*/
}

string write_item (string str, int selected)
{
  if (selected)
    return "●"+str;
  else
    return "○"+str;
}

int do_report1();
int do_report2();
int do_report3();

int do_report ()
{
  int step = this_room()->query("match/step");

  switch (step)
  {
    case STEP_PREPARE: 
    {
      do_report1();
      break;
    }
    case STEP_FIGHT: 
    {
      do_report2();
      break;
    }
    case STEP_FINISH: 
    {
      do_report3();
      break;
    }
  }
  return 1;
}

void init0()
{
  add_action ("do_report","?");
  add_action ("do_report","what");
}
