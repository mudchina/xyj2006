// by snowcat 10/05/1997
// zhangmen.c 掌门

inherit NPC;
inherit F_CLEAN_UP;
inherit F_SAVE;

#define DIRNAME "/d/npc/"

#define MYFILE "/d/npc/zhangmen.c"

void create()
{
  set_name("掌门大弟子", ({ "zhang men", "zhangmen" }) );
  if (! query("default_name"));
    set("default_name","掌门大弟子");
  set("gender", "男性" );
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "heroism");
  set("combat_exp", 100000);
  set("current_player","none of us");

  setup();

  if (query("gender")=="男性")
    carry_object("/d/obj/cloth/linen")->wear();
  else
    carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  object me = this_object();

  add_action("do_bandage","bandage");

  if (me->query("current_player")=="none of us")
    me->reset_me(me);    
  me->restore();
  me->fully_recover(me);
  me->setup();

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

  me->set_name(me->query("default_name"), ({ "zhang men", "zhangmen" }) );
  me->set("gender", "男性" );
  me->set("title",me->query("family/family_name"));
  me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
  me->set("attitude", "heroism");
  me->set("current_player","none of us");

  me->set("str", 30);
  me->set("per", 30);
  me->set("int", 30);
  me->set("age", 30);

  me->set("weapon", 0);
  me->set("armor", 0);

  me->set_skill("force",  60); 
  me->set_skill("spells", 60); 
  me->set_skill("unarmed",60);
  me->set_skill("sword",  60);
  me->set_skill("dodge",  60);
  me->set_skill("parry",  60);

  me->set("max_gin", 600);
  me->set("eff_gin", 600);
  me->set("gin", 600);
  me->set("max_kee", 600);
  me->set("eff_kee", 600);
  me->set("kee", 600);
  me->set("max_sen", 600);
  me->set("eff_sen", 600);
  me->set("sen", 600);
  me->set("force", 600);
  me->set("max_force", 600);
  me->set("mana", 600);
  me->set("max_mana", 600);
  me->set("force_factor", 600);

  //me->set("no_clean_up",1);
  me->set("no_unconcious",1);
  me->set("combat_exp", 100000);

  me->setup();
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
  me->set("gender",      hp_status["gender"]);
  me->set("combat_exp",  hp_status["combat_exp"]);

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
  
  me->set("force_factor",me->query_skill("force")*3/4);

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
  me->setup();
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
      }
      me->set("armor", base_name(inv[i]));
      armor_cnt = 1;
    }
	else if( weapon_cnt && armor_cnt )
                 break;
  }

  me->setup();
  me->save();
  reset_eval_cost();

  return 1;
}

int convert_identity (object me, object ob)
{
  object who;
  string default_name = me->query("default_name");

  reset_eval_cost();

  who = find_player(me->query("current_player"));
  if (! who)
  {
    // nobody to recover
  }
  else if (who->query("zhangmen/title_old"))
  {
    who->set("title",who->query("zhangmen/title_old"));
  }
  else if (who->query("family/family_name"))
  {
    who->set("title",
             sprintf("%s第%s代%s",
                     who->query("family/family_name"),
                     chinese_number(who->query("family/generation")),
                     who->query("family/title")));
    who->save();
  }
  ob->set("zhangmen/base_name",base_name(me));
  ob->set("zhangmen/data_name",me->query_save_file());
  ob->set("zhangmen/title_old",ob->query("title"));
  ob->set("zhangmen/title",ob->query("family/family_name")+default_name);
  ob->set("title",ob->query("family/family_name")+default_name);
  ob->save();

  me->reset_me(me);
  me->set("name", ob->query("name") );
  me->set("gender", ob->query("gender") );
  me->set("current_player",ob->query("id"));
  me->set("title",ob->query("family/family_name")+default_name);
  me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");

  save_record(me, ob);

  return 1;
}

void self_adjust (object me)
{
  mapping skill_status;
  string *skillnames;
  int i;

  me->set("max_gin", 600);
  me->set("eff_gin", 600);
  me->set("gin", 600);
  me->set("max_kee", 600);
  me->set("eff_kee", 600);
  me->set("kee", 600);
  me->set("max_sen", 600);
  me->set("eff_sen", 600);
  me->set("sen", 600);
  me->set("force", 600);
  me->set("max_force", 600);
  me->set("mana", 600);
  me->set("max_mana", 600);
  me->set("force_factor", 60);
  me->set("combat_exp", 100);

  skill_status = me->query_skills();
  if ( mapp(skill_status) )
  {
    skillnames = keys(skill_status);

    for(i=0; i<sizeof(skillnames); i++)
      me->set_skill(skillnames[i], 60);
  }

  if (query("gender")=="男性")
    carry_object("/d/obj/cloth/linen")->wear();
  else
    carry_object("/d/obj/cloth/skirt")->wear();
  me->save();

}

int init_identity (object me, object master, object where)
{
  mapping skill_status;
  string *skillnames;
  int i;

  reset_eval_cost();
  me->setup();

  me->move(where);
  me->set("where",base_name(where));

  me->set("gender", master->query("gender") );
  me->set("current_master",master->query("id"));
  me->set("current_master_base_name",base_name(master));
  me->set("family/generation",master->query("family/generation"));
  me->set("family/family_name",master->query("family/family_name"));
  me->set("title",me->query("family/family_name"));
  me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");

  me->restore();
  if (me->query("current_player")!="none of us")
    return 1;

  remove_call_out("self_adjust");
  call_out("self_adjust", 1, me);

  me->reset_me(me);
  me->set("new_player",1);
  save_record(me, master);

  return 1;
}

object find_and_restore (string name)
{
  object me = find_object(name);

  if (! me ||
      ! me->restore())
    me = new (name);
  me->setup();
  return me;
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

  player_name = me->query("current_player");
  if (! player_name ||
      player_name == "none of us")
    return 1;
  
  if (current_player = find_player(player_name))
  {
    if (current_player->query("combat_exp")>me->query("combat_exp"))
      save_record (me, current_player);
  }
  else if (current_player = LOGIN_D->find_body(player_name))
  {
    if (current_player->query("combat_exp")>me->query("combat_exp"))
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
    if (current_player->query("combat_exp")>me->query("combat_exp"))
      save_record (me, current_player);
    destruct (current_player);
  }

  inv = all_inventory(me);
  while (inv && sizeof(inv))
  {
    destruct (inv[0]);
    inv = all_inventory(me);
  }

  if (me->query("weapon"))
  {
    ob = new(me->query("weapon"));
    if(ob && ob->move(me))
      ob->wield();  
  }

  if (me->query("armor"))
  {
    ob = new(me->query("armor"));
    if(ob && ob->move(me))
      ob->wear(); 
  }

  reset_eval_cost();
  return 1;
}

int accept_fight(object ob)
{
  int i;
  object* inv;
  object me = this_object();
  string default_name = me->query("default_name");

  if (me->query("family/family_name") != ob->query("family/family_name")) 
  {
    command ("say 你与本门派无缘无故，掌门之事从何谈起！\n");
    return notify_fail("看来"+default_name+"无意与你交手。\n");
  }
  if (ob->query("betrayer") || ob->query("betray/count"))
  {
    command ("say 你曾叛师欺祖，言无信行不轨，岂能掌门！\n");
    return notify_fail("看来"+default_name+"无意与你交手。\n");
  }
  if (me->query("current_player") == ob->query("id")) 
  {
    command ("say 本"+default_name+"不可与己较量！\n");
    return notify_fail("你就是"+default_name+"！\n");
  }
  if (me->is_fighting())
  {
    command ("say 失陪了！\n");
    return notify_fail("这位"+default_name+"尚在比武之中，请稍候。\n");
  }

  me->set_temp("zhangmen/kill",0);
  remove_call_out("check_result");
  call_out("check_result", 1, me, ob);
  
  fully_recover (me);
  inv = all_inventory(ob);
  for(i=0; i<sizeof(inv); i++)  {
     if( inv[i]->query_unique() ) {
       message_vision("突然间，$n化一道白光飞去，无影无踪！\n",me,inv[i]);
       destruct(inv[i]);
     }
  }

  return 1;
}

int check_result(object me, object ob)
{
  int my_max_kee, his_max_kee;

  my_max_kee  = me->query("max_kee");
  his_max_kee = ob->query("max_kee");

  if (me->query_temp("zhangmen/kill"))
    return;

  if (me->is_fighting())
  {
    call_out("check_result",1, me, ob);
    return 1;
  }

  if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
  {
    object who;

    message_vision ("$N翻身下拜，连声佩服！\n",me);

    if (me->query("current_master"))
      who = present(me->query("current_master"),environment(me));
    if (who && who->query("id")!=me->query("current_master"))
      who = 0;

    if (who)
    { 
      call_out("master_announce",1,me,who,ob);
    }
    else
    {
      message_vision ("$N躬身对$n说道：恭请拜见师父。\n",me,ob);
      command ("follow "+ob->query("id"));
      if (! me->query("where"))
        me->set("where",base_name(environment(me)));
      remove_call_out("find_master");
      call_out("find_master", 1, me, ob);
    }
    return 1;
  }

  if (( (int)ob->query("kee")*100/his_max_kee)<=50)
  {
    message_vision ("$N将$n扶起。\n",me,ob);
  }

  return 1;  
}

void find_master (object me, object ob)
{
  object who = present(me->query("current_master"),environment(me));

  if (who && who->query("id")!=me->query("current_master"))
    who = 0;

  if (! who)
  {
    remove_call_out("find_master");
    call_out("find_master", 1, me, ob);
  }
  else
  {
    message_vision ("$N见了师父赶紧下拜，又抬起头朝$n使了个眼色。\n\n",me,ob);
    message_vision ("$N微微地点了点头。\n\n",who);
    message_vision ("$N退下。\n\n",me);
    me->set_leader(0);
    call_out("master_announce",1,me,who,ob);
    me->move(me->query("where"));
  }
}

void master_announce (object me, object who, object ob)
{
  string default_name = me->query("default_name");

  CHANNEL_D->do_channel(who,"chat","恭喜"+default_name+ob->query("name")+"走马上任！");
  me->set("new_player",1);
  convert_identity (me, ob);
}

string query_save_file()
{
  string str = query("save_file");
  int i;

  if (str)
    return str;

  str = DATA_DIR+"zhangmen/zhangmen_"+query("current_master");
  for (i = 0; i < sizeof(str); i++)
    if (str[i]==' ')
      str[i] = '_';

  return str;
}

void set_save_file(string str)
{
  set("save_file",str);
}

int do_bandage(string arg)
{
  object who = this_player();
  object me = present("zhang men",environment(who));

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

void kill_ob(object ob)
{
  object me = this_object();
  object master;

  if (me->query("current_master"))
    master = present(me->query("current_master"),environment(me));
  if (master)
    master->kill_ob(ob);
  else
  {
    /*
    master = find_living(me->query("current_master"));

    if (! master)
      master = new (me->query("current_master_base_name"));
    if (master)
    {
      message_vision (master->query("name")+"闻讯赶来，要杀死$n！\n\n",me,ob);
      message_vision ("但见"+master->query("name")+"对$n一指$n！\n\n",me,ob);
      ob->unconcious();
      message_vision (master->query("name")+"走了出去。\n",me,ob);
    }
    */
  }
  me->set_temp("zhangmen/kill",1);
  ::kill_ob(ob);
}

void set_minimun_conditions(object me)
{
  me->set("gin",1);
  me->set("kee",1);
  me->set("sen",1);
}

void die()
{
  object me = this_object();

  //fully_recover (me);
  message_vision("\n$N停下不打了，叹了口气。\n",me);
  set_minimun_conditions(me);
  me->remove_all_killer();
  all_inventory(environment())->remove_killer(me);
}

void unconcious()
{
  object me = this_object();

  //fully_recover (me);
  message_vision("\n$N停下不打了，叹了口气。\n",me);
  set_minimun_conditions(me);
  me->remove_all_killer();
  all_inventory(environment())->remove_killer(me);
}

int create_identity (mixed master, mixed where)
{
  object master_ob, where_ob;

  if (this_object()->query("created"))
    return;
  this_object()->set("created",1);

  if (objectp(master))
    master_ob = master;
  else
  {
    master_ob = new (master);
    master_ob->restore();
  }

  if (objectp(where))
    where_ob = where;
  else
  {
    call_other(where,"???");
    where_ob = find_object(where);
  }
  init_identity (this_object(), master_ob, where_ob);
  this_object()->set("age",30);
}

