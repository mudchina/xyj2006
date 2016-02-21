// by snowcat 10/06/1997
// wu.h 武进士

#define DIRNAME "/d/huanggong/"

#define MYFILE "/d/huanggong/npc/wu??.c"

#define MAXCATEGORY 5
#define MAXPOSITION 3

string *categories = ({
  "金榜",
  "银榜",
  "铜榜",
  "铁榜",
  "锡榜",
 });

string *positions = ({
  "状元",
  "榜眼",
  "探花",
 });

int *limits = ({
  200000,
  100000,
  50000,
  10000,
  1000,
 });

string *rooms = ({
  "b",
  "a",
  "c",
 });

int get_category_int ();
int get_position_int ();

string get_position_str ()
{
  return chinese_number(get_position_int ());
}

string get_honor_str ()
{
  return categories[get_category_int()-1]+
         positions[get_position_int()-1];
}

string get_respect_str ()
{
  return get_honor_str ();
}

void reset_me (object me)
{
  int i;
  object *inv;
  mapping skill_status, map_status;
  string *skillnames, *mapnames;
    
  reset_eval_cost();
  if ( mapp(map_status = me->query_skill_map()) )
  {
    mapnames = keys(map_status);
	for(i=0; i<sizeof(mapnames); i++)
    {
      me->map_skill(mapnames[i]);
    }
  }

  if ( mapp(skill_status = me->query_skills()) )
  {
    skillnames = keys(skill_status);
	for(i=0; i<sizeof(skillnames); i++)  
    {
      me->delete_skill(skillnames[i]);
    }
  }

  inv = all_inventory(me);
  for(i=0; i<sizeof(inv); i++)
  {
    destruct (inv[i]);
  }

  me->set_name("武进士", ({ "jin shi", "jin", "shi" }) );
  me->set("title", get_honor_str());
  me->set("gender", "男性" );
  me->set("long",get_respect_str()+"。\n");
  me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
  me->set("attitude", "heroism");
  me->set("current_player","none of us");

  me->set("str", 30);
  me->set("per", 30);
  me->set("int", 30);
  me->set("age", 18);

  me->set("weapon", 0);
  me->set("armor", 0);

  me->set_skill("force",  1); 
  me->set_skill("spells", 1); 
  me->set_skill("unarmed",1);
  me->set_skill("sword",  1);
  me->set_skill("dodge",  1);
  me->set_skill("parry",  1);

  me->set("max_gin", 100);
  me->set("eff_gin", 100);
  me->set("gin", 100);
  me->set("max_kee", 100);
  me->set("eff_kee", 100);
  me->set("kee", 100);
  me->set("max_sen", 100);
  me->set("eff_sen", 100);
  me->set("sen", 100);
  me->set("force", 10);
  me->set("max_force", 10);
  me->set("mana", 10);
  me->set("max_mana", 10);
  me->set("force_factor", 1);

  //me->set("no_clean_up",1);
  me->set("no_unconcious",1);
  me->set("combat_exp", 100);
  me->set("daoxing",100);

  me->delete_temp("apply");
  //me->setup();
  reset_eval_cost();

}

int save_record(object me, object ob)
{
  object *inv;
  mapping hp_status, skill_status, map_status;
  string *skillnames, *mapnames;
  int i, weapon_cnt, armor_cnt;

  reset_eval_cost();
  hp_status = ob->query_entire_dbase();

  me->set("str", hp_status["str"]);
  me->set("per", hp_status["per"]);
  me->set("int", hp_status["int"]);
  me->set("age", hp_status["age"]);

  me->set("max_gin",     hp_status["max_gin"]);
  me->set("eff_gin",     hp_status["eff_gin"]);
  me->set("gin",         hp_status["gin"]);
  me->set("max_kee",     hp_status["max_kee"]);
  me->set("eff_kee",     hp_status["eff_kee"]);
  me->set("kee",         hp_status["kee"]);
  me->set("max_sen",     hp_status["max_sen"]);
  me->set("eff_sen",     hp_status["eff_sen"]);
  me->set("sen",         hp_status["sen"]);
  me->set("max_force",   hp_status["max_force"]);
  me->set("force",       hp_status["force"]);
  me->set("max_mana",    hp_status["max_mana"]);
  me->set("mana",        hp_status["mana"]);
  //me->set("force_factor",hp_status["force_factor"]);
  me->set("gender",      hp_status["gender"]);
  me->set("combat_exp",  hp_status["combat_exp"]);
  me->set("daoxing",hp_status["daoxing"]);

  me->set("eff_gin", me->query("max_gin"));
  me->set("gin",     me->query("max_gin"));
  me->set("eff_kee", me->query("max_kee"));
  me->set("kee",     me->query("max_kee"));
  me->set("eff_sen", me->query("max_sen"));
  me->set("sen",     me->query("max_sen"));
  me->set("force",   me->query("max_force")*2);
  me->set("mana",    me->query("max_mana")*2);

  skill_status = me->query_skills();
  if ( mapp(skill_status) )
  {
    skillnames  = keys(skill_status);

    for(i=0; i<sizeof(skillnames); i++) {
      me->delete_skill(skillnames[i]);
    }
  }

  skill_status = ob->query_skills();
  if ( mapp(skill_status) )
  {
    skillnames  = keys(skill_status);

    for(i=0; i<sizeof(skillnames); i++) {
      me->set_skill(skillnames[i], skill_status[skillnames[i]]);
    }
  }
  
  // increase npc's enforce by 50%, as players have more options, e.g.
  // powerup, etc.
  me->set("force_factor",ob->query_skill("force")*3/4);

  reset_eval_cost();
  if (! me->query("new_player"))
  {
    me->save();
    reset_eval_cost();
    return 1;
  }

  me->set("new_player",0);

  if ( mapp(map_status = me->query_skill_map()) ) {
    mapnames = keys(map_status);

    for(i=0; i<sizeof(mapnames); i++) {
      me->map_skill(mapnames[i]);
    }
  }

  map_status = ob->query_skill_map();
  if ( mapp(map_status) ) 
  {
    mapnames  = keys(map_status);

    for(i=0; i<sizeof(mapnames); i++) {
      me->map_skill(mapnames[i], map_status[mapnames[i]]);
    }
  }
  
  inv = all_inventory(me);
  for(i=0; i<sizeof(inv); i++) {
	 destruct(inv[i]);
  }

  // save once here, an external bug might stop the following
  me->delete_temp("apply");
  //me->setup();
  me->save();

  weapon_cnt = 0;
  armor_cnt = 0;
  inv = all_inventory(ob);
  for(i=0; i<sizeof(inv); i++) {
    if ( !inv[i]->query_unique() && inv[i]->query("skill_type") &&
        inv[i]->query("equipped") && !weapon_cnt ) {
      object obj = new(base_name(inv[i]));
      if (obj)
      {
        if(obj->move(me)) // mon 8/13/97
          obj->wield();
	obj->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
      }
      me->set("weapon", base_name(inv[i]));
      weapon_cnt = 1;
    }
    else if ( !inv[i]->query_unique() && !inv[i]->query("skill_type") && 
        inv[i]->query("equipped") && !armor_cnt ) {
      object obj = new(base_name(inv[i]));
      if (obj)
      {
        if(obj->move(me))
          obj->wear();   //mon 8/13/97
	obj->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
      }
      me->set("armor", base_name(inv[i]));
      armor_cnt = 1;
    }
	else if( weapon_cnt && armor_cnt )
                 break;
  }

  //me->setup();
  me->save();
  reset_eval_cost();

  return 1;
}

int convert_identity (object me, object ob)
{
  reset_eval_cost();
  me->reset_me(me);
  if (ob->query("id") == "jin shi")
  {
    string current_player = ob->query("current_player");

    me->set("current_player",current_player);
    if (! current_player ||
        current_player == "none of us")
    {
      //me->set("short",me->get_honor_str()+"("+capitalize(me->query("id"))+")");
      me->save();
      return 1;
    }
    else
    {
      me->set("name", ob->query("name") );
      me->set("gender", ob->query("gender") );
      me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
    }
  }
  else
  {
    me->set("name", ob->query("name") );
    me->set("gender", ob->query("gender") );
    me->set("current_player",ob->query("id"));
    me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");

    ob->set_temp("apply/short", ({ob->query("title")+" "+me->get_respect_str()+
                 " "+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
  }

  save_record(me, ob);

  return 1;
}

int do_save()
{
//  write("储存档案...\n");
  return this_object()->save();
}

object find_and_restore (string name)
{
  object me = find_object(name);

  if (! me ||
      ! me->restore())
    me = new (name);
  //me->setup();
  return me;
}

object find_in_room (int i, int j)
{
  string name = DIRNAME+"ywc"+sprintf("%d%s",i,rooms[j-1]);
  object room;

  call_other(name, "???");
  room = find_object(name);
  if (room)
    return present ("jin shi",room);
  else
  {
    name = DIRNAME+"npc/wu"+sprintf("%d%d",i,j);
    return find_and_restore (name);
  }
}

int check_player_position (object who)
{
  int i,j;

  i = get_category_int();
  for (j = 1; j < get_position_int(); j++)
  {
    //object ob = find_and_restore(npc);
    object ob = find_in_room(i,j);
    reset_eval_cost();
    if (ob->query("current_player") == who->query("id"))
      return 0;
  }
  return 1;
}

void log_positions ()
{
  int i,j;
  string file_name = "huanggong.results";

  log_file (file_name,"\n "+ctime(time())+":\n");
  for (i = 1; i <= MAXCATEGORY; i++)
  {
    for (j = 1; j <= MAXPOSITION; j++)
    {
      object ob = find_in_room(i,j);
      string name = ob->query("name");
      string id = ob->query("id");
      log_file (file_name,sprintf("  %d.%d: %s %s\n",i,j,name,id));
    }
  }
}

int remove_previous_position (object who, int position)
{
  int i, j;

  for (i = get_category_int()+1; i <= MAXCATEGORY; i++)
  {
    for (j = 1; j <= MAXPOSITION; j++)
    {
      object ob = find_in_room(i,j);
      reset_eval_cost();
      if (ob &&
          ob->query("current_player") == who->query("id"))
      {
        ob->reset_me(ob);
        ob->save();
        ob->restore();
      }
    }
  }
  for (j = position+1; j <= MAXPOSITION; j++)
  {
    object ob = find_in_room(get_category_int(),j);
    reset_eval_cost();
    if (ob &&
        ob->query("current_player") == who->query("id"))
    {
      ob->reset_me(ob);
      ob->save();
      ob->restore();
      return j;
    }
  }
  return MAXPOSITION;
}

int push_other_positions (object me, int position, int previous_position)
{
  int j;
  string src, dst;
  object who;
  object ob;

  for (j = previous_position-1; j >= position; j--)
  {
    reset_eval_cost();
    who = find_in_room(get_category_int(),j);
    ob = find_in_room(get_category_int(),j+1);
    if (ob)
    {
      ob->set("new_player",1);
      convert_identity(ob,who);
    }
  }
  return 1;
}

int fully_recover (object me)
{
  object *inv;
  object ob;
  string player_name;
  object current_player;

  reset_eval_cost();

  me->set("eff_gin", me->query("max_gin"));
  me->set("gin",     me->query("max_gin"));
  me->set("eff_kee", me->query("max_kee"));
  me->set("kee",     me->query("max_kee"));
  me->set("eff_sen", me->query("max_sen"));
  me->set("sen",     me->query("max_sen"));
  me->set("force",   me->query("max_force")*2);
  me->set("mana",    me->query("max_mana")*2);

// disable autocopy feature
/*
  player_name = me->query("current_player");
  if (! player_name ||
      player_name == "none of us")
    return 1;
  
  if (current_player = LOGIN_D->find_body(player_name))
  {
    save_record (me, current_player);
  }
  else
  {
    seteuid(player_name);
    current_player = new(USER_OB);
    current_player->set("id", player_name);
    if (!current_player->restore()){
      destruct(current_player);
      return 1;
    }
    export_uid(current_player);
    seteuid(getuid());
    current_player->setup();
    save_record (me, current_player);
    destruct (current_player);
  }
*/

  inv = all_inventory(me);
  while (inv && sizeof(inv))
  {
    destruct (inv[0]);
    inv = all_inventory(me);
  }

  if (me->query("weapon"))
  {
    ob = new(me->query("weapon"));
    if(ob) if(ob->move(me))
      ob->wield(); 
   ob->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n"); 
  }

  if (me->query("armor"))
  {
    ob = new(me->query("armor"));
    if(ob) if(ob->move(me))
      ob->wear();
   ob->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n"); 
  }

  reset_eval_cost();
  return 1;
}

int accept_fight(object ob)
{
  int i;
  object* inv;

  object me = this_object();
  object who = this_player();
  object pang = present("pang xuanling",environment(me));

  if (! pang)
  {
    command ("say 大宰相不在，如何比武也？\n");
    return notify_fail("还是请大宰相房玄龄来吧。\n");
  }
  if (check_player_position (ob) == 0)
  {
    command ("say 本进士不敢！\n");
    return notify_fail("你的榜次已经比这位武进士高了。\n");
  }
  if (me->query("current_player") == ob->query("id")) 
  {
    command ("say 进士不可与己较量！\n");
    return notify_fail("你就是这位武进士。\n");
  }
  if (me->is_fighting())
  {
    command ("say 进士失陪了！\n");
    return notify_fail("这位武进士尚在比武之中，请稍候。\n");
  }
  if (! interactive(ob))
  {
    command ("say 进士失陪了！\n");
    return notify_fail("You are a NPC.\n");
  }
  if (! pang->execute_approve_fight(who,me,get_position_int(),get_category_int()))
  {
    return notify_fail("看来大宰相不允许你比武。\n");
  }

  fully_recover (me);
  inv = all_inventory(who);
  for(i=0; i<sizeof(inv); i++)  {
     if( inv[i]->query_unique() ) {
       message_vision("突然间，$n化一道白光飞去，无影无踪！\n",me,inv[i]);
       destruct(inv[i]);
     }
  }

  remove_call_out("check_result");
  call_out("check_result", 1, me, ob);
  
  return 1;
}

void pang_execute_fight_result (object pang, object me, object ob, int i)
{
  pang->execute_fight_result(me, ob, i);
}

int check_result(object me, object ob)
{
  object pang = present("pang xuanling",environment(me));
  int my_max_kee, his_max_kee;

  my_max_kee  = me->query("max_kee");
  his_max_kee = ob->query("max_kee");

  if (me->is_fighting())
  {
    call_out("check_result",1, me, ob);
    return 1;
  }

  if (pang == 0)
    pang = find_living ("pang xuanling");
  if (!present(ob, environment()))
  {
    remove_call_out ("pang_execute_fight_result");
    call_out("pang_execute_fight_result",1,pang,me,ob,0);
    return 1; 
  }

  if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
  {
    int previous_position;
    message_vision ("$N翻身下拜，连声佩服！\n",me);
    previous_position = remove_previous_position (ob,get_position_int());
    push_other_positions (me,get_position_int(),previous_position);
    me->set("new_player",1);
    pang_execute_fight_result (pang,me,ob,1);
    convert_identity (me, ob);
    call_out("log_positions",1);
    return 1;
  }

  if (( (int)ob->query("kee")*100/his_max_kee)<=50)
  {
    message_vision ("$N将$n扶起。\n",me,ob);
  }

  call_out("pang_execute_fight_result",1,pang,me,ob,0);
  return 1;  
}

string query_save_file()
{
  return DATA_DIR+"huanggong/wu"+sprintf("%d%d",get_category_int(),get_position_int());
}

int do_bandage(string arg)
{
  object who = this_player();
  object me = present("jin shi",environment(who));

  if (! arg || me != present(arg, environment(me)))
    return 0;

  message_vision ("$N别有用心地要给$n包扎伤口。\n",who,me);
  call_out("no_bandage",2,who,me);
  return 1;
}

void no_bandage(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N摸摸索索地掏出什么法宝想祭一祭。\n",who);
  call_out("no_ji",2,who,me);
  return 1;
}

void no_ji(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg == "transfer")
    return 0;

  message_vision ("$N张开嘴，结结吧吧地念了几声咒语。\n",who);
  call_out("no_cast",2,who,me);
  return 1;
}

void no_cast(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg != "sheqi jin shi" &&
      arg != "sheqi jin" &&
      arg != "sheqi shi")
    return 0;

  message_vision ("$N鬼鬼祟祟地一运气。\n",who);
  call_out("no_exert",2,who,me);
  return 1;
}

void no_exert(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N鬼鬼祟祟地一施外功。\n",who);
  call_out("no_perform",2,who,me);
  return 1;
}

void no_perform(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N伸出手，鬼鬼祟祟地想偷什么东西。\n",who);
  call_out("no_steal",2,who,me);
  return 1;
}

void no_steal(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_bian(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N鬼鬼祟祟地想变成什么东西。\n",who);
  call_out("no_bian",2,who,me);
  return 1;
}

void no_bian(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if(!arg || present(arg,environment(me))!=me) return 0;
  //allow kill others. mon 2/16/98

  message_vision ("$N眼露凶光，看样子动了杀机！\n",who);
  call_out("no_kill",2,who,me);
  return 1;
}

void no_kill(object who, object me)
{
  message_vision ("$N向$n摇了摇头。\n",me,who);
}

void die()
{
  //fully_recover (this_object());
}

void unconcious()
{
  //fully_recover (this_object());
}

