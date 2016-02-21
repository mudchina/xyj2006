// qianmian guai
// mon 8/7/97

inherit NPC;

object curr_user, new_user, curr_env;
object last_steal;
int steal_time=0, fresh=1;
int MAX_MANA=4000, SPELLS=200, DAOXING=300000;
int just_bianed=0, no_player=0, just_steal=0;
int doing_kill=0;

void copy_status(object me, object ob, int power);
string check_give(object obj);
int random_walk();
void remove_kill();
void find_obj();
void find_newplace();
void del_bian();
void del_steal();
void auto_recovery();
void move_away();
void do_give(object user);
void to_kill(object tar);
int find_user();
object find_players();
void do_steal(object me, object user);

void create()
{
	set_name("千面怪", ({ "qianmian guai", "guai", "qianmian", "qm" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "\n");
	set("attitude", "heroism");

	set("chat_chance", 3);
	set("chat_msg", ({
	     (: random_walk :),
        }));
        set("chat_chance_combat", 3);
        set("chat_msg_combat", ({
             (: random_walk :), 
        }));

	set("str", 40);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_kee", 1000);
	set("max_gin", 1000);
	set("max_sen", 1000);
	set("max_force", 1000);
	set("max_mana", MAX_MANA);
	set("mana", MAX_MANA);

	set("combat_exp", DAOXING);

	set_skill("spells",SPELLS);
	set_skill("force", 140); 
	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);

        setup();
        add_money("gold", 5);
	carry_object("/d/obj/weapon/blade/blade")->wield();

}

void init()
{
   object me=this_object(), tar=this_player();

   ::init();
   if(!wizardp(this_player())){
     add_action("do_sleep","sleep");
   }
//     add_action("do_accuse","report");
   
   if(!environment()) return;
   if(environment()->query("no_fight")) return;

   if((int)tar->query_condition("no_pk_time")>200 ) {
       // this is an PKer.
       int ran=6-sizeof(users())/20;
       ran=ran-(int)tar->query_condition("no_pk_time")/220;
       if(ran<2) ran=2;
       if(random(ran)==0)
         call_out("to_kill", 2+random(5), tar);
   }
   
//   remove_call_out("to_say");
//   call_out("to_say", 1);
}

/* this part moved to liuer-mihou.
void to_say()
{
    if(random(20)==0) {
	message_vision("$N开口说道：诸位如见杀人越货，可告知在下(report name)，"+
		"\n定当打报不平！\n",this_object());
    }
}

int do_accuse(string tar)
{
    object me=this_object();
    object target;
    object env;

    if(!tar) return 0;
    target=find_player(tar);
    
    if((int)this_player()->query_condition("no_pk_time")>0)
	return notify_fail("哼！你也配？！\n");
    if(!target || !interactive(target))
	return notify_fail("找不到这个人。\n");
    if(wizardp(target)) return 0;
    if((int)target->query_condition("no_pk_time")<400)
	return notify_fail("此物尚未恶贯满盈，且放它去吧！\n");
    env=environment(target);
    if(!env || env->query("no_fight"))
	return notify_fail("现在我也伤不了它:(\n");
    command("get all");
    command("wield all");
    command("wear all");
    message_vision("$N往地里一钻，不见了。\n", me);
    me->move(env);
    message_vision("$N走了过来。\n",me);
    to_kill(target);
    return 1;
}
*/

void to_kill(object tar)
{
    if(doing_kill) return;
    if(!tar || environment(tar)!=environment()) return;
    
    if(tar->query("combat_exp")>1000000)
    copy_status(this_object(), tar, 23);
    else
    copy_status(this_object(), tar, 21);
    doing_kill=1;
    
    call_out("remove_kill",120);
    message_vision("$N对$n说到：杀人偿命，欠债还钱。你这"+
	    RANK_D->query_rude(tar)+"拿命来吧！\n", this_object(), tar);
    if(tar->query("combat_exp")>20000)
	command("follow "+tar->parse_command_id_list()[0]);
    this_object()->kill_ob(tar);
    tar->kill_ob(this_object());
}

void remove_kill()
{
    doing_kill=0;
  //  this_object()->remove_all_killer();
    command("follow none");
}

int do_sleep(string str)
{
   object me=this_player();

   if(!me) return 0;
   remove_call_out("do_steal");
   call_out("do_steal",2,this_object(),me);

   return 0;
}

int random_walk()
{
    int ran;
    object user, me=this_object();

    if(doing_kill) return 1;

    if(!user=find_players()) {
      command("get all");
      if(random(3)==0) {
        command("remove all");
	command("unwield all"); // this one is not working now.
	command("wield all");
	command("wear all");
      }
      no_player++;
      if(no_player>10) {
	no_player=0;
	find_newplace();
	return 1;
      } 
      // try move away.
      move_away();
      return 1;
    }

// try stealing?
    ran=random(30);
    if(ran<3 && just_steal==0) {
      do_steal(me,user);
      return 1; 
    } else if(ran<15 && just_steal==0) {
      if (is_fighting()) return 1;
      move_away();
      return 1;
    } else if(ran<20 && user!=last_steal) {
      do_give(user);
      return 1;
    }

    return 1; //40% chance to stay.
}

void do_steal(object me, object user)
{
      int stealing,size,i,j;
      object *tar;
      string target;

      if(doing_kill) return;

      if(user->query("combat_exp")<10000) return;
      //don't steal newbie. mon 10/18/97

      stealing=user->query("sen")*2/5+200;  // 1/3 chance of stealing success.
      if(user->is_fighting()) {
        stealing*=10;
      }
      if(me->is_fighting()) {
        stealing*=2;
      }
      if(user==last_steal) {
        steal_time++;
	if(steal_time>5) {
          //steal too many times for same user.
	  no_player++;
	  return;
	}
      } else {
        steal_time=0;
	last_steal=user;
      }
      me->set("thief",0);
      copy_status(me,user,0);
      me->set_skill("stealing",stealing);
      tar=all_inventory(user);
      size=sizeof(tar);
      j=-1;
      if(size) {
        for(i=0;i<size;i++)
	  if(tar[i]->query("max_liquid")>0) {j=i;break;};
      }
      if(j!=-1) target=tar[j]->parse_command_id_list()[0];
        else target="jitui";
      command("sys try steal "+target+" from "+
        user->parse_command_id_list()[0]);
      command("steal "+
	target+" from "+
        user->parse_command_id_list()[0]);
      just_steal=1;
      call_out("del_steal",20);
      return; 
}

string check_give(object obj)
{
    string str;

    str=obj->parse_command_id_list()[0];
    if(obj->query_amount()) str="1 "+str;
    return str;
}

void do_give(object ob)
{
    object *inv;
    string obj;
    int size;

    inv=all_inventory(this_object());
    size=sizeof(inv);
    if(size){
      obj=check_give(inv[random(size)]);
      command("sys try give "+obj+" to "+
        ob->parse_command_id_list()[0]);
      command("give "+obj+
	" to "+ob->parse_command_id_list()[0]);
    }
    return;
}

object find_players()
{
    object *obj, me=this_object(), ob;
    int size, i;

    obj=all_inventory(environment(me));
    size=sizeof(obj);
    if(size) { 
      for(i=0;i<size;i++) {
        if(userp(obj[i])&&!wizardp(obj[i])) {
	  ob=obj[i];
	  if(random(3)==0) return ob;
        }
      }
      if(ob) return ob;
    }
    return 0;
}

void move_away()
{
      int i;

      for(i=0;i<3;i++) {  //try 3 times, if can't move.
       if(random_move()) {
         find_obj();
         return;
       } 
      } 
      find_newplace();
      return;
}

void find_newplace()
{
  object *inv, me=this_object();
  int size;

  remove_kill();

  inv=all_inventory(me);
  size=sizeof(inv);
  if(size) {
    command("drop "+ 
      check_give(inv[random(size)]));
  }
  message_vision("$N向地里一钻，消失得无影无踪了。\n",me);
  
  if(find_user() && 
    me->move(curr_env=environment(new_user))) {
    curr_user=new_user;
//    command("sys "+curr_user->query("id"));
    just_steal=0;
    if(random(5)==0) do_steal(me,new_user);
  } else {
    curr_env=({"/d/city/kezhan"})[random(1)];
    me->move(curr_env);
//    command("sys kz");
  }

  me->remove_all_killer();
  message_vision("$N走了过来。\n",me);

  return;
}

void find_obj()
{
     object *obj,me=this_object();
     int size,i,p_count=0;

     if(just_bianed) return;

     obj=all_inventory(environment(me));
     size=sizeof(obj);
     if(size>2)size=2;
     if(size>1) {
       for(i=0;i<size;i++) {
	 if(userp(obj[i])) continue;
         if(member_array(obj[i]->parse_command_id_list()[0],
	   me->parse_command_id_list())!=-1) continue;
	 me->set("max_mana",MAX_MANA);
	 me->set("mana",MAX_MANA);
	 if(me->query_skill("spells")<SPELLS/2) 
	   me->set_skill("spells",SPELLS);
	 if(!command("bian "+obj[i]->parse_command_id_list()[0]))
	   continue;
         just_bianed=1;
	 call_out("del_bian",20);
         break;
       }
     }
     
     return;
}

void del_steal()
{
   just_steal=0;
}

void del_bian()
{
   just_bianed=0;
}

int find_user()
{    object *user,ob,env;
     int size, i;
    
     user=users();
     size=sizeof(user);

     if(size>20) { // don't do it if too few players online.
       for(i=0;i<10;i++) {
         ob=user[random(size)];
	 if(wizardp(ob)) continue;
	 if(ob==curr_user) continue;
	 if(!env=environment(ob)) continue;
	 if(env->query("no_fight")) continue;
	 if(env==curr_env) continue;
	 new_user=ob;
         return 1;
       }
     }
     return 0;
}

int accept_fight(object ob)
{
	object me;

	me = this_object();

	if (is_fighting()) return 0;
	if(doing_kill) return 0;

	copy_status(me,ob,0);
	if(just_steal==0 && random(5)==0) do_steal(me,ob);

	return 1;
}

void kill_ob(object ob)
{
   object me=this_object();

   if(!doing_kill) 
       copy_status(me,ob,0);
   ::kill_ob(ob);
}

// this copy function is used by some other NPCs also,
// so if need to change here, please consider carefully.
// mon 1/13/99
void copy_status(object me, object ob, int ratio)
{
        mapping hp_status, skill_status, map_status;
        string *sname, *mname;
	int i,j, base=20;

	if(ratio<1) ratio=base;

        // delete old skills.
        if(skill_status = me->query_skills()) {
           sname  = keys(skill_status);
	   j=sizeof(skill_status);
           for(i=0; i<j; i++) {
	     me->delete_skill(sname[i]);
           }
        }

        //copy new skills.
	if (skill_status = ob->query_skills() ) {
	   sname  = keys(skill_status);
	   for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], 
			skill_status[sname[i]]*ratio/base);
	   }
        }
	
	//delete old skill mappings.
	if(map_status = me->query_skill_map()) {
	  mname  = keys(map_status);
	  j=sizeof(map_status);
	  for(i=0; i<j; i++) {
	    me->map_skill(mname[i]);
          }
        }
         
        //add new skill mappings.
	if (map_status = ob->query_skill_map()) {
	  mname  = keys(map_status);
	  for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	  }
        }

	hp_status = ob->query_entire_dbase();

	me->set("str", hp_status["str"]*ratio/base);
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]);
	me->set("cps", hp_status["cps"]);
	me->set("cor", hp_status["cor"]);
	me->set("spi", hp_status["spi"]);
	me->set("per", hp_status["per"]);
	me->set("kar", hp_status["kar"]);
 
        if(fresh==1) {
	        fresh=0;
		me->set("eff_kee",    hp_status["max_kee"]*ratio/base);
		me->set("eff_gin",  hp_status["max_gin"]*ratio/base);
		me->set("eff_sen",  hp_status["max_sen"]*ratio/base);

		me->set("max_mana",     hp_status["maximum_mana"]*ratio/base);
		me->set("mana",     hp_status["maximum_mana"]*2*ratio/base);
		me->set("kee",        hp_status["max_kee"]*ratio/base);
		me->set("gin",        hp_status["max_gin"]*ratio/base);
		me->set("sen",        hp_status["max_sen"]*ratio/base);

                me->set("eff_dx", me->query("combat_exp"));
	        if(COMBAT_D->check_family(ob->query("family/family_name"))
	           >0)
	        me->set("eff_dx", -me->query("eff_dx"));

		if(me->query("combat_exp")>10000)
		  me->set("nkgain",150); //maximum gain for killing qm.
        }
	me->set("max_kee",    hp_status["max_kee"]*ratio/base);
	me->set("max_gin",  hp_status["max_gin"]*ratio/base);
	me->set("max_sen",  hp_status["max_sen"]*ratio/base);
	me->set("max_force", hp_status["maximum_force"]*ratio/base);
	me->set("force",     hp_status["maximum_force"]*ratio/base);
	me->set("force_factor",     hp_status["force_factor"]*ratio/base);
  	if(ratio>base) {
	    me->set("max_mana",     hp_status["maximum_mana"]*ratio/base);
	    me->set("mana",     hp_status["maximum_mana"]*2*ratio/base);
	    me->set("kee",        hp_status["max_kee"]*ratio/base);
	    me->set("gin",        hp_status["max_gin"]*ratio/base);
	    me->set("sen",        hp_status["max_sen"]*ratio/base);
  	}
	me->set("mana_factor",     hp_status["mana_factor"]*ratio/base);
	me->set("combat_exp",hp_status["combat_exp"]/100*ratio/base*100+
	        hp_status["combat_exp"]/50*ratio/base);
	me->set("daoxing",hp_status["daoxing"]/100*ratio/base*100+
	        hp_status["daoxing"]/50*ratio/base);

	return ;
}

void unconcious()
{
   die();
}

void die()
{
   object killer;

   if( objectp(killer = query_temp("last_damage_from")) ) {
       set_temp("my_killer", killer->query("id"));
       COMBAT_D->killer_reward(killer,this_object());
   }

   auto_recovery();
   find_newplace();
}

void auto_recovery()
{
        object me=this_object();

	me->set("eff_gin", (int)me->query("max_gin"));
	me->set("gin", (int)me->query("max_gin"));
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));
	me->set("sen", (int)me->query("max_sen"));
        
        me->set("force", (int)me->query("max_force"));
        me->set("atman", (int)me->query("max_atman"));
        me->set("mana", (int)me->query("max_mana"));

        me->delete("eff_dx");
	me->delete("nkgain");

	fresh=1;
}

/*
int heal_up()
{
   return -1; // no heal up at all.
}
*/
