// created by snowcat 12/2/1997

inherit ROOM;

string *msgs = ({
  "$N取过第一根香将其点燃，诚心拈香。",
  "$N取过第二根香将其点燃，诚心拈香。",
  "$N取过第三根香将其点燃，诚心拈香。",
  "$N取过第四根香将其点燃，诚心拈香。",
  "$N取过第五根香将其点燃，诚心拈香。",
  "$N取过第六根香将其点燃，诚心拈香。",
  "$N取过第七根香将其点燃，诚心拈香。",
  "$N取过第八根香将其点燃，诚心拈香。",
  "$N取过第九根香将其点燃，诚心拈香。",
});

string *strs = ({
  "祭官朝天一拜。",
  "祭官朝天又是一拜。",
  "人群中有人低声道了一声：雷声也。",
  "天边传来隐约的雷声。",
  "天边有雷声传来。",
  "天上雷声轰鸣，连接不断。",
  "天上雷声轰轰烈烈，震耳欲聋。",
  "祭官喝道：天上雷公有话：披香殿金锁即将燎断！",
  "祭官大惊道：天上雷公有话：披香殿金锁已断！",
});

void create ()
{
  set ("short", "祭坛");
  set ("long", @LONG

一座由楠木建筑的坛场，地上铺有青砖，上有无数蒲团。坛台
由红砖砌成，分下中上三层坛阶。台上供有紫铜香鼎，烟火不
断，青雾袅袅。
    
LONG);

  set("no_fight",1);
  set("no_magic",1);
  set("exits", ([
        "east"    : __DIR__"jiedao8",
      ]));
  set("objects", ([
        __DIR__"npc/jiguan" : 1,
        __DIR__"npc/people2" : 4,
      ]));
  setup();
}

void init ()
{
  add_action ("do_nianxiang", "nianxiang");
}

int do_nianxiang ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/fengxian_nianxiang");
  int j;

  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  if (interactive (who) &&
      who->query("combat_exp") < 10000)
    return notify_fail ("你的道行怕是不够吧！\n");

  if (interactive(who))
    message_vision ("$N俯身低首。\n",who);

  if (! interactive(who))
    message_vision ("$N取过一根香将其点燃，诚心拈香。\n",who);
  else if (i >= size)
  {
    message_vision ("\n祭官赶紧将$N扶起。\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_nianxiang",5,who,i);
    call_out ("finish_nianxiang",j,who,i);
  }
  return 1;
}

void start_nianxiang (object who, int i)
{
  message_vision ("\n"+msgs[i]+"\n",who); 
}

void finish_nianxiang (object who, int i)
{
  who->interrupt_me ();
  message_vision ("\n$N香毕，又一俯拜。\n",who); 
  message_vision ("\n"+strs[i]+"\n",who); 
  who->set_temp("obstacle/fengxian_nianxiang",i+1);
}
