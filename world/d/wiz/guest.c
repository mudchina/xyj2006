// Room: /d/wiz/guest.c    snowcat

inherit ROOM;

int clean_up();

void create()
{
  set("short", "迎客厅");
  set("long", @LONG

对不起，您的地址在西游记的信誉被别人破坏了，为了保证
包括您在内的大多数玩家能够愉快地游戏，我们不得不限制
从您的网络ＩＰ地址的连线。请您在客厅稍候，西游记巫师
会尽快作出相应处理。同时，您可以阅读帮助文件(help)或
游戏故事(story)。

LONG
);

  set("valid_startroom", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("objects", ([
    __DIR__"npc/guest":1,
  ]));
  setup();
  (load_object("/obj/board/guestroom_b"))->move(this_object());
}

int nb_guests (object where)
{
  int i = 0;
  int j = 0;
  object *obs = all_inventory(where);

  j = sizeof(obs);
  while (j--)
  {
    if (userp(obs[j]) && !wizardp(obs[j]))
      i++;
  } 
  return i;
}

void init()
{  
  object who = this_player(); 
  object where = this_object();

  if (!wizardp(who)&&userp(who))
  {
    if (who->query("banned_approved")==1)
    {
      tell_object (who,"欢迎您进入西游记世界！\n");
      who->move(who->query("startroom"));
      MONITOR_D->report_system_object_msg (who,  
        "由被禁的IP进入，已被批准直入西游记世界。"); 
      return; 
    }
    who->set("startroom","/d/wiz/guest");
    who->save();
    add_action("block_cmd","",1);  
    MONITOR_D->report_system_object_msg (who,  
      "的IP被禁，现被引入西游记迎客厅(/d/wiz/guest.c)。");  
    if (nb_guests(where) > 10)
    {
      tell_object ("对不起，迎客厅里客人太多，请下次再来。\n",who);
      who->command_function("quit");
      return;
    }
  }
  else
  {
//    call_out ("inform_wiz",1,who);
//    add_action ("do_approve", "approve");
  }
}

int clean_up()
{      //special for this room. no clean_up.

       return 0;
}

void inform_wiz (object who)
{
  tell_object (who,"你可以使用approve来批准玩家进入西游记世界。\n");
}

int block_cmd()
{
  string verb = query_verb();
  if (verb=="say") return 0; 
  if (verb=="help") return 0;
  if (verb=="who") return 0;
  if (verb=="look") return 0;
  if (verb=="story") return 0;
  if (verb=="quit") return 0;
  if (verb=="post") return 0;
  return 1;
}

int do_approve (string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();

  if (! arg)
    return notify_fail ("批准谁？\n");
  who = present (arg);
  if (who == me)
    return notify_fail ("批准您自己？\n");
  tell_object (me,"您批准"+who->query("name")+"进入西游记世界！\n");
  tell_object (who,"欢迎您进入西游记世界！\n");
  who->set("banned_approved",1);
  who->set("startroom","/d/city/kezhan");
  who->move("/d/city/kezhan");
  who->save();
  return 1;
}
