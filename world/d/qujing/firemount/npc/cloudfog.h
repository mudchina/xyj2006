// created 4/5/1997 by snowcat

void invite_player (object who)
{
  string dir;
  object me = this_object();

  message_vision ("$N将手指一点，石门开了。$n走了进去。\n", me, who);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  who->move(dir+"dongnei.c");
  message_vision ("门外传来$N的声音：别忘了叩见公主。\n", me, who);
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$N说道：这位"+RANK_D->query_respect(who);

  if (who->query("family/family_name")=="翠云山芭蕉洞")
  {
    inform_player (msg+"快请进！\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  if (who->query("obstacle/firemount") == "done")
  {
    inform_player (msg+"失礼了！\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  if (present("palm bone",who))
  {
    inform_player (msg+"送宝来啦，请！\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  if (who->query_temp("won_cloud_fog"))
  {
    inform_player (msg+"功夫过人，请！\n",who);
    call_out("invite_player",1,who);
    return 1;
  }  

  inform_player (msg+"非本门派弟子，又未必是武林高手，不能求见公主。\n",who);
  return 1;
}

int accept_fight(object who)
{
  object me = this_object();

  remove_call_out("check_fight");
  call_out("check_fight", 1, me, who);
  return 1;
}

void player_win (object me, object who)
{
  object tieshan = present("tie shan",me);
  string msg;

  message_vision ("$N对$n说：大师果然身手不凡！\n",me,who);
  who->set_temp("won_cloud_fog",1);
}

void player_lose (object me, object who)
{
}

void check_fight (object me, object who)
{
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  if(!who) return;

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

  if ((my_kee*100/my_max_kee) <= 50)
    player_win (me, who);
  else if ((whos_kee*100/whos_max_kee) <= 50)
    player_lose (me, who);

}

