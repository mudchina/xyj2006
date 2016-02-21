//liuer-mihou.c 
// tomcat
#include <ansi.h>
inherit NPC;

void set_target();
void bian_target();
void copy_skills();
int find_user();
void copy_weapon();
object target() {return query("target");}

void create()
{
	set_name("六耳猴", ({"liuer hou", "liuer", "hou"}));
	set("gender", "男性" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	setup();
}



void init()
{
   if(query("wiz_set")) return ;
   if(query("target")) return ;
   remove_call_out("set_target");
   call_out("set_target",10);
 //  return ::init();

}
 


void unconcious()
{
    die();
}

void die()
{
  object target=target();
  object me = this_object();
  object ob = query_temp("last_damage_from");
  object last =query_temp("last_killed_by");
  message_vision("$N惨叫一声现了原形,原来是只六耳猴。\n\n",me);
  message_vision(RED "六耳猴抓耳挠腮地对$n尖声说道：你小子等着,我还会来找你的。说完一溜烟跑了。\n" NOR,me,target);
  
  if(ob&&last)
  {
  if(target->query("id")==ob->query("id"))
  {
  // 自己杀的有奖励	 
     target->add("daoxing",3000);
     tell_object (target,"你赢得了"+chinese_number(3)+"年的道行！\n");
                target->save();
  }
  }	
  destruct(me);
  return;
}

void heart_beat() {
   
  
   
   object target=target();
   object me = this_object();
   
   
   if (target && target->is_ghost()) {
      message_vision(HIY"$N哈哈大笑：“就这么点本事，也敢冒充爷爷我？”\n"NOR,this_object());
      command("kick corpse");
      message_vision(HIY"$N化做一道狂风不见了。”\n"NOR,this_object());
      destruct(me);
      return;
   }

//    if (!target || environment(this_object())!=environment(target)) {
//       message_vision(HIY"$N哈哈大笑：“假的假的，跑了跑了。”\n"NOR,this_object());
//       message_vision(HIY"$N化做一道狂风不见了。”\n"NOR,this_object());
//       destruct(me);
//       return;
//   }
    
        if (me->query("eff_kee") < me->query("max_kee")*9/10 &&
	    present("jinchuang yao",me))
	   command("eat yao");
	if (me->query("kee") < me->query("eff_kee")*9/10 &&
	    me->query("force") > 0)
	   command("exert recover");
	if (me->query("sen") < me->query("eff_sen")*9/10 &&
	    me->query("force") > 0)
	   command("exert refresh");

  	if (!present(target,environment(me)))
	 {
	   me->move(environment(target));
	   message_vision("$N走了过来。\n",me);
	 }
  
          bian_target();
          if( !me->is_fighting())
          {
          	 me->set_leader(target);
          	 me->kill_ob(target);
            	 target->kill_ob(me);
          }
   
   ::heart_beat();
}

void set_target()
{
     if(query("wiz_set")) return ;
     remove_call_out("set_target");
     find_user();
     copy_skills();
     copy_weapon();
     remove_call_out("end_target");
     call_out("end_target",300);
   
}

void bian_target()
{
     string *id_list,*id_list2;
     object target=target();
     object me = this_object();
     string id_name = target->name();
     
     if (target && target->is_ghost()) return ;
     me->set_temp("apply/name",({target->name()}));
     me->set_temp("apply/id",target->parse_command_id_list());
     me->set_temp("apply/short", ({target->short()}));
     me->set_temp("apply/long", ({target->long()}));
     
     
    if((int)target->query_temp("d_mana")>0){
     me->set_temp("is_living", target->query_temp("is_living"));
     me->set_temp("unit",target->query_temp("unit"));
     me->set_temp("is_character",target->query_temp("is_character"));
     me->set_temp("gender",target->query_temp("gender"));
     me->set_temp("age",target->query_temp("age"));
     me->set_temp("race",target->query_temp("race"));
     me->set_temp("family",target->query_temp("family"));
     }else{
            me->set_temp("is_living",living(target));
	    me->set_temp("unit",target->query("unit"));
            me->set_temp("is_character",target->is_character());
	    me->set_temp("gender",target->query("gender"));
	    me->set_temp("age",target->query("age"));
	    me->set_temp("race",target->query("race"));
	    me->set_temp("family",target->query("family"));
	}
     
}

int find_user()

 { 
     object *user,ob,env;
     int size, i;
    
     user=users();
     size=sizeof(user);
//	 if(wizardp(ob)) continue;
       for(i=0;i<size;i++) {
         ob=user[random(size)];
	 if(!env=environment(ob)) continue;
	 if(env->query("no_fight")) continue;
	 
	 if(ob->query("combat_exp")<1000000) continue;
	 set("target",ob);
         return 1;
       }
     
     return 0;
}

void copy_skills()
{
        mapping hp_status, skill_status, map_status;
        string *sname, *mname;
	int i,j, base=20;
        object target=target();
        object me = this_object();
	int ratio=base;

        
        //copy new skills.
	if (skill_status = target->query_skills() ) {
	   sname  = keys(skill_status);
	   for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], 
			skill_status[sname[i]]*ratio/base);
	   }
        }
	     
        //add new skill mappings.
	
	if (map_status = target->query_skill_map()) {
	  mname  = keys(map_status);
	  for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	  }
        }

	hp_status = target->query_entire_dbase();

	me->set("str", hp_status["str"]*ratio/base);
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]);
	me->set("cps", hp_status["cps"]);
	me->set("cor", hp_status["cor"]);
	me->set("spi", hp_status["spi"]);
	me->set("per", hp_status["per"]);
	me->set("kar", hp_status["kar"]);
 
	me->set("eff_kee",    hp_status["max_kee"]*ratio/base);
	me->set("eff_gin",  hp_status["max_gin"]*ratio/base);
	me->set("eff_sen",  hp_status["max_sen"]*ratio/base);
	me->set("max_mana",     hp_status["maximum_mana"]*ratio/base);
	me->set("mana",     hp_status["maximum_mana"]*2*ratio/base);
	me->set("kee",        hp_status["max_kee"]*ratio/base);
	me->set("gin",        hp_status["max_gin"]*ratio/base);
	me->set("sen",        hp_status["max_sen"]*ratio/base);
        me->set("eff_dx", me->query("combat_exp"));
        me->create("family/family_name",target->query("family/family_name"));  
	me->set("nkgain",150); //maximum gain for killing qm.
	me->set("max_kee",    hp_status["max_kee"]*ratio/base);
	me->set("max_gin",  hp_status["max_gin"]*ratio/base);
	me->set("max_sen",  hp_status["max_sen"]*ratio/base);
	me->set("max_force", hp_status["maximum_force"]*ratio/base);
	me->set("force",     hp_status["maximum_force"]*ratio/base);
	me->set("force_factor",     hp_status["force_factor"]*ratio/base);

	me->set("combat_exp",hp_status["combat_exp"]);
	me->set("daoxing",hp_status["daoxing"]);

	return ;
}

void end_target()
{
      object me = this_object(); 
       message_vision(HIY"$N哈哈大笑：“假的假的，跑了跑了。”\n"NOR,this_object());
       message_vision(HIY"$N化做一道狂风不见了。”\n"NOR,this_object());
       remove_call_out("end_target");
       destruct(me);
       return;
}

void copy_weapon()
{
  object *inv;
  object ob=target();
  int i;
  inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++)
        {
                if( inv[i]->query("weapon_prop") 
                &&  inv[i]->query("equipped")
                &&  !inv[i]->query_unique() ) {
                        carry_object(base_name(inv[i]))->wield();
                }
                else if( inv[i]->query("armor_prop") 
                &&  inv[i]->query("equipped") 
                &&  !inv[i]->query_unique() ) {
                        carry_object(base_name(inv[i]))->wear();
                }

        }
}

void wiz_set(string trg)
{
  object ob = find_player(trg);
  if(!ob) return 0;
  set("target",ob);
      set("wiz_set",1);
copy_skills();
     copy_weapon();
     remove_call_out("end_target");
     call_out("end_target",300);
}

