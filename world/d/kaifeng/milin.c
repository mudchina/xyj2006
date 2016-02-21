//Cracked by Roath
// create by snowcat.c 9/18/1998

#include <ansi.h>
inherit ROOM;

#define OUTROOM __DIR__"yuwang5"
#define DEATH __DIR__"yuwang6"

void switch_on_off();
int maxi ()
{
  OUTROOM->maxi();
}

int maxj ()
{
  OUTROOM->maxj();
}

int query_year() {return OUTROOM->query_year();}

void receive_damage(object who, int amount)
{
    int year=query_year();
    mapping ind=(["100":10,"300":8,
	    "1000":5,"3000":3,
	    "10000":1]);
    int factor;
    string ye;

    if(!who) return;
    ye=sprintf("%d",year);
    if(undefinedp(ind[ye])) factor=5;
    else factor=ind[ye];
    
    if(random(2)==0) {
	who->receive_damage("sen",amount/factor);
//	COMBAT_D->report_sen_status(who);
    } else {
	who->receive_damage("kee",amount/factor);
//	COMBAT_D->report_status(who);
    }
}

void create ()
{
  set ("short", "禹王林");
  set ("long", @LONG

……　禹王林里浓雾遮天，你熏熏晕晕什么也看不清　……

LONG);

  set("objects", ([
        __DIR__"npc/yaomo"  : 1+random(2),
      ]));
  
  seteuid(getuid());
  set("no_mieyao",1); // mon 7/9/99
  set("broadcast",1);
  set("alternative_die",1);
  set("milin",1);
  set("no_look",1);
  if(random(4)) switch_on_off();
  setup();
}

void alternative_die(object who)
{
  if (! userp(who) ||
    ! who->query_temp("ymdh/entered")) {
    set("alternative_die",0);
    who->die();
    set("alternative_die",1);
    return;
  }
  who->delete_temp("last_fainted_from");
  DEATH->die(who);
}

int clean_up ()
{
  return 0;
}

void switch_off ()
{
  set ("long", @LONG

……　禹王林里浓雾遮天，你熏熏晕晕什么也看不清　……

LONG);

  set("outdoors", 0);
  tell_room (this_object(),"一阵浓雾袭来，你什么都看不清了。\n");

}

void switch_on ()
{
  set ("long", @LONG

……　禹王林里飘着淡淡的一层雾气，树木林立，枝叶茂盛　……

LONG);

  set("outdoors", "milin");
  tell_room (this_object(),"风吹来，雾气渐渐地淡了。\n");

}

void switch_on_off()
{
  int no_look = 1-query("no_look");
  
  if (no_look) {
    if (random(3)) // adjusted off times
      return;
    switch_off();
  } else
    switch_on();
  set("no_look",no_look);
}

void detecting (object me, int extra)
{
  int d, i, j, k, my_i, my_j;
  object *inv;
  string str, str1, str2;

  if (! me)
    return;
  if (! interactive(me))
    return;
  if (this_object() != environment(me))
    return;
  if (me->is_fighting())
    return;
  
  extra = random(10)+extra;
  if (extra < 600)
    call_out ("detecting",extra,me,extra);

  my_i = this_object()->query("my_j");
  my_j = this_object()->query("my_k");
  inv = all_inventory(this_object());
  for(k=0; k<sizeof(inv); k++) {
    if (living(inv[k]) && inv[k]!=me && !me->is_fighting()) {
      tell_object (me, "你似乎觉得你身边有什么动静……\n");
      return;
    }
  }
  for(d=1; d<((maxi()+maxj())/3); d++) {
    for(i=my_i-d; i<=my_i+d; i++) {
      for(j=my_j-d; j<=my_j+d; j++) {
        //reset_eval_cost();
        inv = all_inventory(OUTROOM->search_for_room(i,j));
        for(k=0; k<sizeof(inv); k++) {
          if (living(inv[k]) && inv[k]!=me) {
	    str = "你仿佛觉得";
	    if (j < my_j)
		str += "东";
	    else if (j > my_j)
		str += "西";
	    if (i < my_i)
		str += "北";
	    else if (i > my_i)
		str += "南";
	    str += "边";
            if (d <= (maxi()+maxj())/9)
		str += "近处";
	    else if (d <= (maxi()+maxj())*2/9)
		str += "不远处";
	    else
		str += "远处";
            tell_object (me, str+"有什么东西正向你悄悄逼近……\n");
            return;
          }
        }
      }
    }
  }
}

void init ()
{
  object who = this_player();
  object *usr;
  int i;

  if(!userp(who)) return;

  // mon
//  add_action("do_cast","cast");
  add_action("do_quit","quit");
  add_action("do_follow","follow");
  add_action("do_go","go");

  if (who && interactive(who)) {
    call_out ("detecting",1,this_player(),5);
    
    // mon 9/26/98 auto attacking others.
    // if cast yinshen, then has probability to auto-attack.
    // so that one can't hide for ever.
    if(!who->query("env/invisibility")) return;
    if(random(3)>0) return;
    if(wizardp(who)) return;

    usr=all_inventory(this_object());
    i=sizeof(usr);
    while(i--) {
	if(!userp(usr[i])) continue;
	if(who==usr[i]) continue;
	who->kill_ob(usr[i]);
	usr[i]->kill_ob(who);
    }
  }
}

int do_follow(string arg)
{
    return 1;
}

int do_go(string arg)
{
    int no_look=query("no_look");
    if(no_look) {
	tell_object(this_player(),
		HIR"你在浓雾里踉跄着一头撞了个空。\n"NOR);
	receive_damage(this_player(),200);
    } else {
	receive_damage(this_player(),20);
    }

    return 0;
}

int do_quit(string arg)
{
    return 1;
}

/*
int do_cast(string arg)
{
    if(!arg) return 0;

    while(sscanf(arg,"%s %*s",arg)==2);

    if(arg!="qiankun") return 0;
    
    write("禹王林里枝叶茂盛，你的大袖实在是施展不开：（\n");
    return 1;
}
*/

void trapped ()
{
  object *inv;
  int k;

  inv = all_inventory(this_object());
  for(k=0; k<sizeof(inv); k++) {
    if (interactive(inv[k])) {
      message_vision ("一股瘴气袭来，$N脚一歪被软软地卷走了。\n",inv[k]);
      inv[k]->move(OUTROOM->random_room());
      message_vision ("$N被一股浓烈的瘴气卷了过来。\n",inv[k]);
      receive_damage(inv[k],100);
      return;
    }
  }
}

void broadcast (string str)
{
  string prefix = HIY"【禹王林】"NOR;
  string s1 = str, s2 = "";
  object room=load_object(OUTROOM);
  object *user;

  if(!room) return;

//  tell_room(room,"<>"+str);
  user=filter_array(all_inventory(this_object()), (:userp:));
  if(!sizeof(user)) {
      if(this_player(1) && userp(this_player(1)))
	  user=({this_player(1)});
      else
	  return; // only broadcast rooms with players in.
  }

  reset_eval_cost();

  // remove extra trailing NOR. mon 7/13/99
  s1=replace_string(s1,"\n"NOR,"\n");

  while (strsrch(s1,"\n\n") != -1)
    s1 = replace_string(s1,"\n\n","\n");

  if (s1[strlen(s1)-1]=='\n')
  {
    s1 = s1[0..strlen(s1)-2];
    s2 = "\n";
  }
  if (strlen(s1) == 0)
    return;
  s1 = replace_string(s1,"\n","\n"+prefix)+NOR+"\n";

  room->do_broadcast(prefix+s1, user);     
}

// called by move()
mixed no_leave(object who, object where)
{
    string file;
    
    // allow wiz or wiz summon out.
    if(this_player(1) && wizardp(this_player(1))) return 0;

    if(where) file=base_name(where);
    else return 0;

    if(member_array(file, ({__DIR__"milin",
		    __DIR__"yuwang5",
		    __DIR__"yuwang6",
		    }))>-1) return 0;
    return "一股浓烈的瘴气挡住了你。\n";
}


