inherit ROOM;

string maze_file="/d/qujing/baihuling/maze_generator";
object maze_g=0;
mixed rooms;
string milin_file=__DIR__"milin.c";

mapping watch_list=([]);
mapping query_watch() {return watch_list;}
void reset_watch_list() {watch_list=([]);}

int max_i = 4;
int max_j = 4;

object ye = 0;
int current_year=30;

int query_year() {return current_year;}

int maxi()
{
  return max_i;    
}

int maxj()
{
  return max_j;    
}

void dest();

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

void die(object who)
{
  string name = who->query("name")+"("+who->query("id")+")";
  string str;
  object killer;
  mapping players = query("players");
  string *nameids = keys(players);
  object *obj=values(players);
  
  int kill_bonus=100;

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
	int multiplier=who->query_temp("ymdh/yaomokilled");
	int max_mul=killer->query_temp("ymdh/yaomokilled")*3+1;

	who->delete_temp("ymdh/yaomokilled");
	if(multiplier>max_mul) multiplier=max_mul;

	if(multiplier<0) multiplier=0;
	if(multiplier>20) multiplier=20;
	
	kill_bonus*=multiplier;

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
  tell_object(this_object(),
	  "只见"+who->name()+
	  "面如死灰被几位禹王卒七手八脚地从林中抬了出来，"+
	  "从众人前通过。\n",who);
  who->move(__DIR__"yuwang6");
  message_vision ("$N面如死灰被几位禹王卒七手八脚地抬了过来。\n",who);
  who->clear_condition();
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

void init ()
{
    add_action ("do_test","test");
    add_action ("do_watch","watch");
    if (! ye)
      ye = present ("yuwang ye", this_object());

    this_player()->delete_temp("ymdh/entered");
    this_player()->delete_temp("ymdh/yaomokilled");
}

int adjusted (int n, int max)
{
  if (n < 0)
    n += max;
  if (n >= max)
    n -= max;
	
  return n;
}

object search_for_room(int i, int j)
{
    i = adjusted (i, maxi());
    j = adjusted (j, maxj());
    return rooms[0][i][j];
}

object random_room ()
{
    return search_for_room(random(maxi()), random(maxj()));
}

void setup_rooms()
{
    maze_g=load_object(maze_file);
    maze_g->do_setup("1 "+max_i+" "+max_j);
    rooms=maze_g->generate_room(milin_file);
}

int do_test (string arg)
{
    if (!wizardp(this_player()))
	return 0;
    setup_rooms();
    call_out ("events",1+random(4));
    this_player()->move(rooms[0][0][0]);
    maze_g->do_show("1");
    return 1;
}

int start(int year, int restart)
{
    mapping players = query("players");
    object player;
    string *nameids = keys(players);
    int i = sizeof(nameids);
    int j;

    current_year=year;

    // mon 9/26/98 set up maze size. maximum 7x7 matrix.
    for(j=3;j<=6;j++) {
	if(j*j/2>=i) break;
    }
    
    max_i=j;
    max_j=j;

    dest();
    reset_eval_cost();
    setup_rooms();
    while (i--) {
      if(!players[nameids[i]]) {
	  escaped(nameids[i]);
	  continue;
      }
      player = players[nameids[i]];
      player->set_leader(0);
      if(player->move(random_room()))
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
void dest()
{
    object* child=children(milin_file);
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
		    inv[j]->clear_condition();
		    inv[j]->set("eff_kee",inv[j]->query("max_kee"));
		    inv[j]->set("eff_sen",inv[j]->query("max_sen"));
		    inv[j]->set("kee",inv[j]->query("max_kee"));
		    inv[j]->set("sen",inv[j]->query("max_sen"));
		    inv[j]->remove_all_killer();
		    tell_object(inv[j],"你觉得身体完全恢复了！\n");
		}
	    }
	    destruct(child[i]);
	}
    rooms=0;
}

void checks  ()
{
    mapping players = query("players");
    string *nameids = keys(players);
    int i = sizeof(nameids);
    object ob, env, env1;
    string str = "", str1;
  
    remove_call_out("checks");

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
      dest();
      return;
    }
    if (i == 1) {
      players[nameids[0]]->remove_all_killer();
      players[nameids[0]]->move(__DIR__"yuwang6");
      ye->finish(players[nameids[0]]);
      delete("players");
      dest();
      return;
    }
    
    // mon
    if(i>2 && i*2<=(max_i-1)*(max_j-1)) { // reset room size.
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
    int i;
    
    if (!rooms || !sizeof(rooms))
       return;
       
    remove_call_out ("events");
    call_out ("events",2+random(10));

    i = maxi()*maxj()/8;
    while (i--) {
	if (random(10))
	  random_room()->switch_on_off();
	else
	  random_room()->trapped();
    }
}

int clean_up ()
{
      return 0;
}

int do_watch(string str)
{
    int i;
    object obj, *list;
    mapping players = query("players");
    object *plys;
    string *key;

    notify_fail("你想观察谁？\n");
    if(!str) return 0;
    if(!(obj=find_player(str))) return 0;
    if(!this_player()->visible(obj) && wizardp(obj)) return 0;

    notify_fail(obj->name()+"并没有参加妖魔大会。\n");
//    if(!sizeof(players)) return 0;
//    plys=values(players);
//    if(member_array(obj, plys)==-1) return 0;
    
    i=sizeof(watch_list);
    if(i) key=keys(watch_list);
    while(i--) {
	list=watch_list[key[i]];
	if(member_array(this_player(),list)!=-1)
	    list-=({this_player()});
	if(sizeof(list))
	    watch_list[key[i]]=list;
	else
	    map_delete(watch_list,key[i]);
    }

    if(undefinedp(watch_list[str])) {
	watch_list[str]=({this_player()});
    } else {
	watch_list[str]+=({this_player()});
    }
    
    write("你开始观看"+obj->name()+"参加妖魔大会。\n");
    return 1;
}
	    
