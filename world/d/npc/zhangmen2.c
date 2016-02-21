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
  set("gender", "男性" );
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("long", "掌门大弟子。" );
  set("attitude", "heroism");
  set("combat_exp", 100000);
  set("current_player","none of us");

  setup();

  carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
  object me = this_object();

  add_action("do_save", "save");
  add_action("do_bandage","bandage");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_exert", "exert");
  add_action("do_perform", "perform");

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

  me->set_name("掌门大弟子", ({ "zhang men", "zhangmen" }) );
  me->set("gender", "男性" );
  me->set("title",me->query("family/family_name")+"掌门");
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
  reset_eval_cost();
  me->reset_me(me);

  me->set("name", ob->query("name") );
  me->set("gender", ob->query("gender") );
  me->set("current_player",ob->query("id"));
  me->set("title",ob->query("family/family_name")+"掌门");
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
  me->set("force_factor", 600);

  skill_status = me->query_skills();
  if ( mapp(skill_status) )
  {
    skillnames = keys(skill_status);

    for(i=0; i<sizeof(skillnames); i++)
      me->set_skill(skillnames[i], 60);
  }

  carry_object("/d/obj/cloth/linen")->wear();
  me->save();

}

int init_identity (object me, object ob)
{
  mapping skill_status;
  string *skillnames;
  int i;

  reset_eval_cost();
  me->setup();
  me->reset_me(me);

  me->set("gender", ob->query("gender") );
  me->set("current_master",ob->query("id"));
  me->set("family/generation",ob->query("family/generation"));
  me->set("family/family_name",ob->query("family/family_name"));
  me->set("title",me->query("family/family_name")+"掌门");
  me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")");
  me->set("new_player",1);

  remove_call_out("self_adjust");
  call_out("self_adjust", 1, me);

  me->move(environment(ob));
  save_record(me, ob);

  return 1;
}

int do_save()
{
  return this_object()->save();
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

  inv = all_inventory(me);
  while (inv && sizeof(inv))
  {
    destruct (inv[0]);
    inv = all_inventory(me);
  }

  if (me->query("weapon"))
  {
    ob = new(me->query("weapon"));
    if(ob->move(me))
      ob->wield();  
  }

  if (me->query("armor"))
  {
    ob = new(me->query("armor"));
    if(ob->move(me))
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
  object who = this_player();

  if (me->query("current_player") == ob->query("id")) 
  {
    command ("say 本弟子不可与己较量！\n");
    return notify_fail("你就是大弟子！\n");
  }
  if (me->is_fighting())
  {
    command ("say 失陪了！\n");
    return notify_fail("这位大弟子尚在比武之中，请稍候。\n");
  }

  fully_recover (me);
  inv = all_inventory(who);
  for(i=0; i<sizeof(inv); i++)  {
     if( inv[i]->query_unique() )
       destruct(inv[i]);
  }

  remove_call_out("check_result");
  call_out("check_result", 1, me, ob);
  
  return 1;
}

int check_result(object me, object ob)
{
  int my_max_kee, his_max_kee;

  my_max_kee  = me->query("max_kee");
  his_max_kee = ob->query("max_kee");

  if (me->is_fighting())
  {
    call_out("check_result",1, me, ob);
    return 1;
  }

  if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 )
  {
    object who;

    if (me->query("current_master"))
      who = present(me->query("current_master"),environment(me));
    if (who == 0)
      who = me;
    message_vision ("$N翻身下拜，连声佩服！\n",me);
    //CHANNEL_D->do_channel(me,"chat","恭喜大弟子"+ob->query("name")+"走马上任！");
    me->set("new_player",1);
    convert_identity (me, ob);
    return 1;
  }

  if (( (int)ob->query("kee")*100/his_max_kee)<=50)
  {
    message_vision ("$N将$n扶起。\n",me,ob);
  }

  return 1;  
}

string query_save_file()
{
  string str = DATA_DIR+"zhangmen/zhangmen_"+query("current_master");
  int i;

  for (i = 0; i < sizeof(str); i++)
    if (str[i]==' ')
      str[i] = '_';

  return str;
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

  if (arg != "sheqi zhang men" &&
      arg != "sheqi zhang" &&
      arg != "sheqi men")
    return 0;

  message_vision ("$N鬼鬼祟祟地一运气。\n",who);
  call_out("no_exert",2,who,me);
  return 1;
}

int do_perform(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N鬼鬼祟祟地一施外功。\n",who);
  call_out("no_exert",2,who,me);
  return 1;
}

void no_exert(object who, object me)
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

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

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
  fully_recover (this_object());
}

void unconcious()
{
  fully_recover (this_object());
}

