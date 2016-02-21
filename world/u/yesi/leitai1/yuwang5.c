// create by snowcat jan 21 1998

inherit ROOM;

int max_i = 4;
int max_j = 4;

object ye = 0;
int current_year=30;

int maxi()
{
  return max_i;    
}

int maxj()
{
  return max_j;    
}

void dest(mapping rooms);

void create ()
{
  set ("short", "禹王林");
  set ("long", @LONG

禹王林浓密浩瀚如海，远风吹过，林涛阵阵。雾从脚下生，有如一望
无际万里的纱帐飘渺似烟波海上。近处有一巨大的青铜雕花旗杆，有
一旗帜飘扬，上书“天御玉执禹王爷万年妖魔大会”。

LONG);

  set("exits", ([
        "west" : __DIR__"yuwang4",
        "east" : __DIR__"yuwang6",
      ]));
  set("objects", ([
        __DIR__"npc/zu" :  2,
        __DIR__"npc/ye" :  1,
      ]));

  set("no_fight",1);
  set("no_magic",1);
//  set("alternative_die",1);
// this room doesn't have death protection.
// yuwagn6.c has and is not accessable for playes not attending ymdh.
// mon 11/8/98
  set("outdoors", __DIR__);

  setup();
}

int valid_leave(object me, string dir)
{
    if ( !wizardp(me) && dir == "east" )
	return notify_fail("禹王卒一把拦住了你。\n");
    return ::valid_leave(me, dir);
}

/* mon 11/8/98
void alternative_die(object who)
{
  if (! userp(who) ||
      ! who->query_temp("ymdh/entered") ) {
    set("alternative_die",0);
    who->die();
    set("alternative_die",1);
    return;
  }
  this_object()->die(who);
}
*/
void die(object who)
{
  string name = who->query("name")+"("+who->query("id")+")";
  string str;
  object killer;
  mapping players = query("players");
  string *nameids = keys(players);
  object *obj=values(players);
  
  int kill_bonus=80;

  if (! ye) {
    ye = new(__DIR__"npc/ye");
    ye->move(this_object());
  }
  
//  if (! str) {
    killer = who->query_temp("last_damage_from");
    if (killer) {
      str = "被"+killer->query("name")+"杀死了";
    
    // mon
    if(userp(killer) && member_array(killer, obj)>-1) { // killed by attendee.
	str+="，"+killer->query("name")+"得到"+
	    chinese_number(kill_bonus)+"点潜能！\n";
	killer->add("potential",kill_bonus);
	log_file("ymdh",ctime(time())+" "+
		killer->query("id")+" got "+kill_bonus+" pot.\n");
    } else {
	str+="。\n";
    }
    } else {
        str = who->query_temp("death_msg");
        if (! str)
          str = "被杀死了。\n";
    }

//  }
  str = "妖魔大会："+name+str;
  ye->announce(str);
  who->move(this_object());
  message_vision ("只见$N面如死灰被几位禹王卒七手八脚地从林中抬了出来，"+
	  "从众人前通过。\n",who);
  who->move(__DIR__"yuwang6");
  message_vision ("$N面如死灰被几位禹王卒七手八脚地抬了过来。\n",who);
//  who->unconcious();
  who->clear_condition();
  who->set_temp("ymdh/entered",0);
  who->set("eff_kee",who->query("max_kee"));
  who->set("eff_sen",who->query("max_sen"));
  who->set("kee",who->query("max_kee"));
  who->set("sen",who->query("max_sen"));
  who->remove_all_killer();
  delete("players/"+name);
  who->start_busy(2); // busy so that players can't move out of here
  // immediately. otherwise may die again in some cases.
}

void escaped(string nameid)
{
  string str;
  
  if (! ye) {
    ye = new(__DIR__"npc/ye");
    ye->move(this_object());
  }
  
  str = "妖魔大会："+nameid+"临阵逃脱了。\n";
  ye->announce(str);
  delete("players/"+nameid);
}

void delete_enter(object who)
{
    if(!who) return;
    if(environment(who)!=this_object()) return;
    who->set_temp("ymdh/entered",0);
}

void init ()
{
    add_action ("do_test","test");
    call_out("delete_enter",2,this_player());
    if (! ye)
      ye = present ("yuwang ye", this_object());
}

int adjusted (int n, int max)
{
  if (n < 0)
    n += max;
  if (n >= max)
    n -= max;
	
  return n;
}

object search_for_room (int i, int j)
{
    mapping rooms = query("rooms");
    string id;
    object room;
    
    reset_eval_cost();
    if (! rooms)
    {
	rooms = ([ ]);
	set("rooms", rooms);
    }

    i = adjusted (i, maxi());
    j = adjusted (j, maxj());
    id = "room " + to_chinese(i) + " " + to_chinese(j);
    room = rooms[id];
    if (! room) 
    {
	room = new(__DIR__"milin.c");
	room->set("i",i);
	room->set("j",j);
	rooms[id] = room;
	room->set("year",current_year);
    }
    return room;    
}

object random_room ()
{
    mapping rooms = query("rooms");
    mixed *vals;
    
    return search_for_room (random(maxi()), random(maxj()));

//    if (! rooms)
//       return search_for_room (0, 0);
//       
//    vals = values(rooms);
//    return vals[random(sizeof(vals))];
}

int do_test (string arg)
{
    object room;
    
    if (!wizardp(this_player()))
	return 0;
    room = random_room();
    call_out ("events",1+random(4));
    this_player()->move(room);
    return 1;
}

int start(int year, int restart)
{
    mapping rooms = query("rooms");
    mapping players = query("players");
    object player;
    string *nameids = keys(players);
    int i = sizeof(nameids);
    int j;

    current_year=year;

    delete("rooms");
    if (rooms)
        dest(rooms);

    // mon 9/26/98 set up maze size.
    for(j=2;j<=20;j++) {
	if(j*j>=i) break;
    }
    j++;
    
    max_i=j;
    max_j=j;

    reset_eval_cost();
    while (i--) {
      if(!players[nameids[i]]) {
	  escaped(nameids[i]);
	  continue;
      }
      player = players[nameids[i]];
      player->move(random_room());
      player->set_temp("ymdh/entered",1);
    }
    
    // mon
    if(!restart) {
      call_out ("events",1+random(4));
      call_out ("checks",1);
    }

    return 1;
}

// mon
void dest(mapping rooms)
{
    object* child=children(__DIR__"milin.c");
    int i=sizeof(child), j;
    object *inv;
    
    while(i--) 
	if(clonep(child[i])) {
	    inv=all_inventory(child[i]);
	    j=sizeof(inv);
	    while(j--) {
		if(userp(inv[j])) {
		    tell_object(inv[j],
			    "\n你晕晕乎乎地来到了一个新的地方．．．\n\n");
		    inv[j]->move(__DIR__"yuwang6",1);
		}
	    }
	    destruct(child[i]);
	}
}

void checks  ()
{
    mapping rooms = query("rooms");
    mapping players = query("players");
    string *nameids = keys(players);
    int i = sizeof(nameids);
    object ob, env, env1;
    string str = "", str1;
  
    if (! ye) {
      ye = new(__DIR__"npc/ye");
      ye->move(this_object());
    }

    reset_eval_cost();
    while (i--) {
      ob = players[nameids[i]];
      if (! ob || ! (env=environment(ob)))
	escaped(nameids[i]);
      else {
	  while(env1=environment(env))
	      env=env1;

	  if(!env->query("milin"))
	      escaped(nameids[i]);
          else
	      str += nameids[i];
      }
    }

    i = sizeof(nameids);

    if (i == 0) {
      ye->finish(0);
      delete("players");
      delete("rooms");
      if (rooms)
        dest(rooms);
      return;
    }
    if (i == 1) {
      players[nameids[0]]->remove_all_killer();
      players[nameids[0]]->move(__DIR__"yuwang6");
      ye->finish(players[nameids[0]]);
      delete("players");
      delete("rooms");
      if (rooms)
        dest(rooms);
      return;
    }
    
    // mon
    if(i<=(max_i-2)*(max_j-2)) { // reset room size.
        str1 = "妖魔大会进入新一轮较量！\n";
        ye->announce(str1);

	start(current_year, 1);
    }

    i = add("times",2);
    if (i > 60) {
      set("times",0);
      ye->report(str);
    }	
    call_out ("checks",2);
}

void events ()
{
    mapping rooms = query("rooms");
    int i;
    
    if (! rooms)
       return;
       
    remove_call_out ("events");
    call_out ("events",1+random(10));

    i = maxi()*maxj()/8;
    while (i--) {
	if (random(6))
	  random_room()->switch_on_off();
	else
	  random_room()->trapped();
    }
}

int clean_up ()
{
      return 0;
}

