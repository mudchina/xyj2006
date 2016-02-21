
inherit NPC;

#define NONE 0
#define INVITE 1
#define FIGHT 3
#define DONE 7
#define DELAY 10

#define BONUS 1000
//#define BONUS 500
//#define INTERVAL 10800
#define INTERVAL 18000
#define SUB_INTERVAL 1200
#define FIGHT_DURATION 1800
// each time has 5 rounds.
#define MAXROUND 5

#define NEXT_GAME (INTERVAL-FIGHT_DURATION*sizeof(levels))

int *levels=({3000, 100, 1000, 10000, 300});
int level=0;
string title;

int round=MAXROUND;
int bonus=BONUS;
string *winner=({});

string *reward=({
	"/d/obj/drug/jiaoli",
	"/d/obj/drug/huozao",
	"/d/obj/drug/biou",
	"/d/obj/drug/mihoutao",
	});
// 7/9/99 mon
string *reward1=({
	"/d/obj/drug/renshen-guo",
	});

void announce (string str);
void set_status (int i);
void set_title(int year);
string query_title(int year);
int random_action();
void start_ymdh(int i);
void deduct_pot();
int query_status();

int get_level()
{
    int j=time();
    int k=sizeof(levels);

    j=j/INTERVAL;
    j=j-(j/k)*k;
    return j;
}

// called by wiz to manually adjust levels.
void next_level() 
{
    level++;
    if(level>=sizeof(levels)) level=0;
    set_title(levels[level]);
    round=MAXROUND;
    set_status(NONE);
    remove_call_out("reset_init");
    call_out("reset_init", SUB_INTERVAL);
    tell_room(environment(this_object()),title+"\n");
}

string convert_time(int t)
{
	int hour=t/60;
	int min=(t-hour*60);
	string str="";
	
	if(t<1) {hour=0;min=1;}
	if(hour) str=chinese_number(hour)+"小时";
	if(min) str+=chinese_number(min)+"分钟";
	return str;
}

string check_schedule()
{
    int i=sizeof(levels);
    int k=i, j=level, remain=0;
    mixed info;
    string str;

    info = filter_array(call_out_info(), (: $1[1]=="reset_init" :));
    if(sizeof(info)>=1) { // should be only 1.
	remain=info[0][2];
    }
    
    str="\n\n";
    if(query_status()!=DONE) {
	str+=sprintf("%-16s：　正在举行\n",title);
	j=j+1; k=k-1;
	remain=INTERVAL;
    } 
    
    while(k--) {
	if(j>=i) j=0;
	str+=sprintf("%-16s：　约于%s后举行\n",query_title(levels[j]),
		convert_time(remain/60));
	j++;
	remain+=INTERVAL;
    }
    str+="\n";
    return str;
}

void set_bonus(int i)
{
//    bonus=BONUS; // can set variable bonus depending # of players.
    if(i<10) bonus=0;
    else {
	bonus=BONUS/MAXROUND+(i-10)*5;
	if(bonus>2*BONUS/MAXROUND) bonus=2*BONUS/MAXROUND;
    }
}

void create()
{
  set_name("禹王爷", ({ "yuwang ye", "yuwang", "yu", "wang", "ye" }));
  set("title", "天御玉执");
  set("gender", "男性");
  set("age", 100);
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
  set("chat_chance", 100);
  set("chat_msg", ({
     (: random_action :)
  }));
  set("inquiry", ([
    "here":      "此乃禹王林，妖魔大会在此定期(schedule)举行也。\n",
    "?":         "此乃禹王林，妖魔大会在此定期(schedule)举行也。\n",
    "妖魔大会":  "妖魔大会乃一迷宫大阵设在禹王林中，雾瘴蔽天妖魔野兽横行，玩家务必尽其全部本领杀尽所有对手，伤亡不损元神，赢者自有重赏也。玩家使init申请大会开始，再使join参加大会，巫师可使join_all让全体玩家参加大会。\n",
    "ymdh":      "妖魔大会乃一迷宫大阵设在禹王林中，雾瘴蔽天妖魔野兽横行，\n"+
     "玩家务必尽其全部本领杀尽所有对手，伤亡不损元神，赢者自有重赏也。\n"+
     "玩家用schedule查询赛程，watch id观看别人比赛，使init申请大会开始，\n"+
     "再使join参加大会，巫师可使join_all让全体玩家参加大会。\n",
    "schedule":  (: check_schedule :),
    ]));
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
  if(clonep()) {
    set_status(NONE);
    level=get_level();
    set_title(levels[level]);
    round=MAXROUND;
    announce(title+"现在开始！\n");
    remove_call_out("reset_init");
    call_out("reset_init",SUB_INTERVAL);
  }
}

int random_action ()
{
  return 0;
}

string query_title(int year)
{
    string str;
    str=chinese_number(year)+"年妖魔大会";
//    if(str[0..1]=="一")
//	str=str[2..];
    return str;
}
void set_title(int year)
{
    title=query_title(year);
}

void announce (string str)
{
  //tell_object (find_player("snowcat")," ◇ "+str);
  command_function ("sldh "+str);
}

int query_status()
{
  return query("my_status");
}

void set_status (int i)
{
  set("my_status",i);
}

void init ()
{
  add_action ("do_init","init");
  add_action ("do_join","join");
  add_action ("do_join_all","join_all");
}

void deduct_pot()
{
  object me = this_object();
  object room;
  mapping players;
  string *nameids;
  int j;
  
  room = environment(me);
  if (! room || room->query("short") != "禹王林") 
    return 0;

  players = room->query("players");
  if (! players)
    return 0;
  
  nameids = keys(players);
  j = sizeof(nameids);
  while (j--) {
    players[nameids[j]]->add("potential",-20);
    tell_object(players[nameids[j]],"你的潜能减少了二十点！\n");
  }
}

int check_players ()
{
  object me = this_object();
  object room, who;
  mapping players;
  string *nameids;
  int i, j;
  
  room = environment(me);
  if (! room || room->query("short") != "禹王林") 
    return 0;

  players = room->query("players");
  if (! players)
    return 0;
  
  nameids = keys(players);
  i = sizeof(nameids);
  j = i;
  while (j--) {
      who=players[nameids[j]];
    if (! players[nameids[j]]) {
      i--;
      announce(nameids[j]+"临阵脱逃，退出大会。\n");
      room->delete("players/"+nameids[j]);
    } else if(((int)who->query("potential")-
	    (int)who->query("learned_points"))<20) {
	i--;
        announce(nameids[j]+"潜能不足，退出大会。\n");
	room->delete("players/"+nameids[j]);
    }
  }
  return i;
}

void reset_init()
{
  object me = this_object();
  object room = environment(me);
  mapping players;

  remove_call_out("reset_init");
  if(!room) return;

  if (query_status() != FIGHT) {
    players = room->query("players");
    round--; // if no one plays reduce round.
    if(round<=0) {
      set_status(DONE);
      //call_out("reset_init",INTERVAL);
      call_out("reset_init", NEXT_GAME);
      winner=({});
      level++;
//      level=get_level()+1;
      round=MAXROUND+1;
      if(level>=sizeof(levels)) level=0;
      if(players)
	  announce(title+"时间用尽，");
      set_title(levels[level]);
      if(players) {
	  room->delete("players");
	  room->reset_watch_list();
          //announce(title+"将于"+chinese_number(INTERVAL/3600)+
          announce(title+"将于"+chinese_number((NEXT_GAME+1800)/3600)+
		  "小时后举行！\n");
      }
    } else {
      winner=({});
      set_status(NONE);

      if(round>=MAXROUND) {
	  announce(title+"现在开始！\n");
	  room->delete("players");
	  room->reset_watch_list();
	  call_out("reset_init",SUB_INTERVAL);
	  return;
      }

      if(players) {
	  announce(title+"第"+chinese_number(MAXROUND-round)+
		  "场时间已尽，现在进行下一场！请继续报名参加。\n");
//	  room->delete("players");
          call_out("reset_init", SUB_INTERVAL);
      } else {
	  room->delete("players");
	  room->reset_watch_list();
	  round=1; // no one join, then finish this meeting.
	  reset_init();
      }
    }
  } else {
      // time up for a single fight.
      object env=environment(this_object());

      env->set("players",([]));
      announce(title+"第"+chinese_number(MAXROUND-round+1)+
	      "场时间用尽，不分胜负！\n");
      env->checks();
//      call_out("reset_init",1800);
  }
}

int do_init (string arg)
{
  object me = this_object();
  object who = this_player();
  object room = environment(me);
  int i, j, exp, low, high;

  if (room->query("short") != "禹王林") 
    return 0;

  exp=(who->query("combat_exp")/1000+
	  who->query("daoxing")/1000)/2;
  low=10;

  if (exp < low) {
    message_vision ("$N对$n摇摇头：道行不足也。\n",me,who);
    return 1;
  }

  if (query_status() == DONE) {
      mixed info;

//    message_vision ("$N对$n摇摇头：妖魔大会已经结束。\n",me,who);
    
    // mon
    info = filter_array(call_out_info(), (: $1[1]=="reset_init" :));
    if(sizeof(info)>=1) { // should be only 1.
	int remain=info[0][2]/60+1;
	int hour=remain/60;
	int min=(remain-hour*60);
	string str="";
	
	if(hour) str=chinese_number(hour)+"小时";
	if(min) str+=chinese_number(min)+"分钟";
//	message_vision("$N又补充到：您过"+str+"再来吧。\n",me);
	message_vision("$N对$n说道："+title+
		"将于"+str+"后举行！到时您再来吧。\n",me,who);
    } else
	message_vision ("$N对$n摇摇头：妖魔大会已经结束。\n",me,who);

    return 1;
  }

  if (query_status() == FIGHT) {
    message_vision ("$N对$n摇摇头：妖魔大会已经开始。\n",me,who);
    return 1;
  }

  if (query_status() == INVITE) {
    i = sizeof(users()) / 20;
    if (i < 5)
      i = 5;
    j = check_players();
    if (j < i) {
      message_vision ("$N对$n摇摇头："+title+
	      "尚需"+chinese_number(i-j)+"名玩家参加方可举行也。\n",me,who);
      return 1;
    }
    announce (title+"将于一分种后开始！玩家准备入场就位！\n");
    set_status(DELAY);
    call_out("start_ymdh", 60, i);

    return 1;
  }
  
  if (query_status() == DELAY) {
      message_vision ("$N对$n摇摇头："+title+
	      "正在准备中，即将开始！\n",me,who);
      return 1;
  }

  announce(who->query("name")+"前来邀请各位玩家参加"+title+"！\n");
  if(round==MAXROUND)
      announce("妖魔大会乃一迷宫大阵设在禹王林中，雾瘴蔽天妖魔野兽横行，玩家务必尽其全部本领杀尽所有对手，伤亡不损元神，赢者自有重赏也。\n");
  remove_call_out("reset_init");
  call_out("reset_init",SUB_INTERVAL);
  set_status(INVITE);
  who->command("join");
  return 1;
}

void start_ymdh(int i)
{
    int j = check_players();
    object room = environment(this_object());
    
    if(query_status()!=DELAY) {
	return;
    }
    if(j<i) {
	set_status(INVITE);
	announce(title+"玩家人数不够了！\n");
	return;
    }
    deduct_pot();
    announce (title+"现在开始！玩家入场就位！\n");
//    set_bonus(j);
    room->start(levels[level],0);
    set_status(FIGHT);
    remove_call_out("reset_init");
    call_out("reset_init",FIGHT_DURATION);
}

int do_join (string arg)
{
  object me = this_object();
  object who = this_player();
  object room = environment(me);
  string str, id=who->query("id");
  mapping players;
  int i, exp, low, high;

  if (room->query("short") != "禹王林") 
    return 0;

  exp=(who->query("combat_exp")/1000+
	  who->query("daoxing")/1000)/2;
  low=10;
  high=levels[level];
  if(high<=100) low=1;
  if(high>=10000) high=100000;

  if (exp < low) {
    message_vision ("$N对$n摇摇头：道行不足也。\n",me,who);
    return 1;
  }

  if (((int)who->query("potential")-(int)who->query("learned_points"))
	  <20) {
    message_vision ("$N对$n摇摇头：潜能不足也。\n",me,who);
    return 1;
  }

  if(exp>high) {
      message_vision ("$N对$n摇摇头：道行过高也。\n",me,who);
      return 1;
  }

  // mon
  if((i=member_array(id, winner))>-1) { // won before.
      if(i<(sizeof(winner)-1))
        if(member_array(id, winner, i+1)>-1) {// won twice
	  message_vision("$N对$n摇摇头：您已经赢两次了，"+
		  "给别人留点机会吧：）\n",me,who);
	  return 1;
        }
  }
	  
  // mon
  if (who->query_condition("no_pk_time")) {
    message_vision ("$N对$n摇摇头：您刚杀过人，还是等会儿再来吧！\n",me,who);
    return 1;
  }

  if (query_status() == DONE) {
    message_vision ("$N对$n摇摇头：妖魔大会已经结束。\n",me,who);
    return 1;
  }

  if (query_status() == FIGHT) {
    message_vision ("$N对$n摇摇头：妖魔大会已经开始。\n",me,who);
    return 1;
  }

  if (query_status() == INVITE || 
	  query_status() == DELAY) {
    players = room->query("players");
    str = who->query("name")+"("+who->query("id")+")";
    if (! players) {
      players = ([ ]);
      room->set("players",players);
    }
    if (players[str]) {
      message_vision ("$N对$n摇摇头：妖魔大会您已在邀也。\n",me,who);
      return 1;
    }
    players[str] = who;
    announce (title+str+"前来应邀！\n");
    return 1;
  }

  message_vision ("$N对$n摇摇头："+title+"尚未开始。\n",me,who);
  message_vision ("$N说道：请使init命令也。\n",me,who);
  return 1;
}

int do_join_all (string arg)
{
  object me = this_object();
  object who = this_player();
  object room = environment(me);
  object *all_users;
  mapping players;
  string str;
  int i;

  if (room->query("short") != "禹王林") 
    return 0;

  if (! wizardp (who)) {
    message_vision ("$N对$n摇摇头：巫师方可使此命令也。\n",me,who);
    return 1;
  }

  if (query_status() == DONE) {
    message_vision ("$N对$n摇摇头：妖魔大会已经结束。\n",me,who);
    return 1;
  }

  if (query_status() == FIGHT) {
    message_vision ("$N对$n摇摇头：妖魔大会已经开始。\n",me,who);
    return 1;
  }

  if (query_status() == INVITE) {
    players = ([ ]);
    all_users = users();
    i = sizeof(all_users);
    while (i--) {
      if (wizardp(all_users[i]))
	continue;
      str = all_users[i]->query("name")+"("+all_users[i]->query("id")+")";
      players[str] = all_users[i];
    }
    announce (title+"现在开始！玩家入场就位！\n");
    room->set("players",players);
    set_bonus(sizeof(players));
    room->start(levels[level],0);
    set_status(FIGHT);
    remove_call_out("reset_init");
    call_out("reset_init",FIGHT_DURATION);
    return 1;
  }

  message_vision ("$N对$n摇摇头："+title+"尚未开始。\n",me,who);
  message_vision ("$N说道：请使init命令也。\n",me,who);
  return 1;
}

void report (string str)
{
  announce ("妖魔大会场内尚有玩家："+str+"。\n");
}

void finish (object who)
{
  int i = bonus;
  announce (title+"第"+chinese_number(MAXROUND-round+1)+
	  "场结束！嬴家："+
	  (who?who->query("name"):"(无)")+"！\n");
  
  // mon
  round--;
  if(round<=0) {
      set_status(DONE);
      remove_call_out("reset_init");
      //call_out("reset_init",INTERVAL);
      call_out("reset_init",NEXT_GAME);
      winner=({});
      level++;
//      level=get_level()+1;
      round=MAXROUND+1;
      if(level>=sizeof(levels)) level=0;
      set_title(levels[level]);
  } else {
      remove_call_out("reset_init");
      set_status(NONE);
      call_out("reset_init",SUB_INTERVAL); // mon
  }

  if (who) {
      object ob;
      int kill_bonus=100;
      int multiplier=who->query_temp("ymdh/yaomokilled");
      
      who->delete_temp("ymdh/yaomokilled");
      if(multiplier<0) multiplier=0;
      if(multiplier>20) multiplier=20;
      kill_bonus*=multiplier;

      if(random(15)==0)
        ob=new(reward1[random(sizeof(reward1))]);
      else
        ob=new(reward[random(sizeof(reward))]);
      if(!ob->move(who))
	  ob->move(environment(who));
      announce("奖"+who->query("name")+"一"+
	      ob->query("unit")+ob->name()+"及"+
	      chinese_number(kill_bonus)+"点潜能！\n");
      who->add("potential",kill_bonus);
      log_file("ymdh",who->query("id")+" got "+kill_bonus+" qianneng.\n");

      winner+=({who->query("id")});
  }
}

void die ()
{
  object me = this_object();

  message_vision ("\n天上传来雷鸣般的声音：$N乃天御玉执也！\n",me);
  message_vision ("\n$N从地上甩袖爬将起来。\n",me);
  set("kee", 3000);
  set("sen", 3000);
}

void unconcious()
{
  die();
}

void accept_fight (object ob)
{
  object me = this_object();

  message_vision ("$N连忙闪身：老夫有天御玉执在身，失陪！\n",me);
}

void kill_ob (object ob)
{
  object me = this_object();

  message_vision ("$N连忙闪身：老夫有天御玉执在身，失陪！\n",me);
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
}
