// created by snowcat 12/2/1997

inherit ROOM;

string *msgs = ({
  "$N默默地低头，口中念念有辞地一瞻拜。",
  "$N默默地低头，口中念念有辞地二瞻拜。",
  "$N默默地低头，口中念念有辞地三瞻拜。",
  "$N默默地低头，口中念念有辞地四瞻拜。",
  "$N默默地低头，口中念念有辞地五瞻拜。",
  "$N默默地低头，口中念念有辞地六瞻拜。",
  "$N默默地低头，口中念念有辞地七瞻拜。",
  "$N默默地低头，口中念念有辞地八瞻拜。",
  "$N默默地低头，口中念念有辞地九瞻拜。",
});

string *strs = ({
  "法师缓缓环视，静默无言。",
  "法师向窗外看了一眼，依然无言。",
  "法师将视线转向窗外，象是看见了什么。",
  "天上亮过一道闪电。",
  "天上闪电又亮了一下。",
  "天上闪电频频，连续不断。",
  "天上的闪电大作，几乎将天划破。",
  "法师惊道：天上电娘子有话：披香殿面山塌掉了半边！",
  "法师大惊道：天上电娘子传话：披香殿面山整个儿倒掉了！",
});

void create ()
{
  set ("short", "道场");
  set ("long", @LONG

道场乃新建的施法布道之处，四周是通明窗，南边有一宽槛门，
北面是颂法台。场地为拼花木头，上面铺开素布地毯。场外有
一铜钟，每两时辰便鸣钟数响。
    
LONG);

  set("no_fight",1);
  set("no_magic",1);
  set("exits", ([
        "south"    : __DIR__"jiedao1",
      ]));
  set("objects", ([
        __DIR__"npc/fashi" : 1,
        __DIR__"npc/people2" : 4,
      ]));
  setup();
}

void init ()
{
  add_action ("do_zhanbai", "zhanbai");
}

int do_zhanbai ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/fengxian_zhanbai");
  int j;

  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  if (interactive (who) &&
      who->query("combat_exp") < 10000)
    return notify_fail ("你的道行怕是不够吧！\n");

  if (interactive(who))
    message_vision ("$N两掌对合，双眼微闭。\n",who);

  if (! interactive(who))
    message_vision ("$N默默地低头，口中念念有辞地瞻拜。\n",who);
  else if (i >= size)
  {
    message_vision ("\n法师慌忙将$N搀起。\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_zhanbai",5,who,i);
    call_out ("finish_zhanbai",j,who,i);
  }
  return 1;
}

void start_zhanbai (object who, int i)
{
  message_vision ("\n"+msgs[i]+"\n",who); 
}

void finish_zhanbai (object who, int i)
{
  who->interrupt_me ();
  message_vision ("\n$N呼出一口气，抬起头来。\n",who); 
  message_vision ("\n"+strs[i]+"\n",who); 
  who->set_temp("obstacle/fengxian_zhanbai",i+1);
}
