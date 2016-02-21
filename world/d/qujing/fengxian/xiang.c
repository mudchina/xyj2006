// created by snowcat 12/2/1997

inherit ROOM;

string *msgs = ({
  "$N虔诚地伏在地上，慢慢地一磕头。",
  "$N虔诚地伏在地上，慢慢地二磕头。",
  "$N虔诚地伏在地上，慢慢地三磕头。",
  "$N虔诚地伏在地上，慢慢地四磕头。",
  "$N虔诚地伏在地上，慢慢地五磕头。",
  "$N虔诚地伏在地上，慢慢地六磕头。",
  "$N虔诚地伏在地上，慢慢地七磕头。",
  "$N虔诚地伏在地上，慢慢地八磕头。",
  "$N虔诚地伏在地上，慢慢地九磕头。",
});

string *strs = ({
  "庙祝面无表情，四周似乎没有什么动静。",
  "庙祝侧耳细听，似乎听见了什么。",
  "外面隐约有人说：起风了。",
  "天上开始刮起风来。",
  "天上的风呼呼作响。",
  "天上的风刮得大了。",
  "天上的狂风大作。",
  "庙祝大喜道：天上风神传话：披香殿米山倒了一半！",
  "庙祝狂喜道：天上风神传话：披香殿米山全都倒了！",
});

void create ()
{
  set ("short", "香庙");
  set ("long", @LONG

香庙建在城墙角下，红砖青瓦木檐。庙里面墙壁上挂着雷神，
雨神，龙神等各种神龛。靠背墙有一长长的旧彩木仙桌，上面
几个香炉正在冒着丝丝香烟。
    
LONG);

  set("no_fight",1);
  set("no_magic",1);
  set("exits", ([
        "north"    : __DIR__"jiedao14",
      ]));
  set("objects", ([
        __DIR__"npc/miaozhu" : 1,
        __DIR__"npc/people2" : 4,
      ]));
  setup();
}

void init ()
{
  add_action ("do_ketou", "ketou");
}

int do_ketou ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/fengxian_ketou");
  int j;

  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  if (interactive (who) &&
      who->query("combat_exp") < 10000)
    return notify_fail ("你的道行怕是不够吧！\n");

  if (interactive(who))
    message_vision ("$N双膝并拢，躬身下跪。\n",who);

  if (! interactive(who))
    message_vision ("$N虔诚地伏在地上，慢慢地磕头。\n",who);
  else if (i >= size)
  {
    message_vision ("\n庙祝笑着将$N扶起。\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_ketou",5,who,i);
    call_out ("finish_ketou",j,who,i);
  }
  return 1;
}

void start_ketou (object who, int i)
{
  message_vision ("\n"+msgs[i]+"\n",who); 
}

void finish_ketou (object who, int i)
{
  who->interrupt_me ();
  message_vision ("\n$N缓缓起身。\n",who); 
  message_vision ("\n"+strs[i]+"\n",who); 
  who->set_temp("obstacle/fengxian_ketou",i+1);
}
