inherit NPC;

#include <ansi.h>
//   4  #define NAME_D "/adm/daemons/named.c"

void copy_status(object me, int level);
void set_skills(int max_value, int level);
void set_hp_status(object me, int level);
object owner() {return query("owner");}

void setname()
{
	mapping name;
	if(random(3)==1){
	name=NAME_D->random_name("male");
        } 
        else if(random(3)==2){
	name=NAME_D->random_name("female");	
        } 
	else {	
	name=NAME_D->random_name("yaoguai");
	}
	set_name(name["name"], name["id"]);	
		
}

void create()
{        
	setname();
	set("age", 100+random(80));
	set("gender", random(2)?"男性":"女性");
	set("attitude", "heroism");
	set("per", 40);
        set("str", 100);
        set("cor", 40);
        set("con", 40);
        set("int", 40);
        set("spi", 40);
        set("cps", 40);
        set("kar", 40);
        set("max_gin", 1000);
        set("food", 10000);
        set("water", 10000);
        set_weight(30000);
        set("no_steal",1);
        set("taskguai",1);
        set_temp("apply/dodge",100);
        set("chat_chance", 5);
	set("chat_msg", ({
	     (: random_move :)
	}) );
	
	setup();
}

void copy_status(object me, int level)
{
	mapping me_skill;
	int *skill_value, max_value, i;
	
	me_skill = me->query_skills();
	i=sizeof(me_skill);
	if(i>0) {
		skill_value=values(me_skill);
		max_value=skill_value[0];
		while(i--) { // 找出玩家skill最大值
		    if(skill_value[i]>max_value)
			max_value=skill_value[i];
		}
	  } else max_value=1;
	 	 
	  set_skills(max_value, level);
	  
	  set_hp_status(me,level);
	    
}	  
	  
void set_skills(int max_value, int level)
{
	object guai=this_object();	 
	int guai_value;
	
	if (level==1) guai_value = max_value+max_value/8;
	else if (level==2) guai_value = max_value+max_value/6;
	else guai_value = max_value+max_value/4;
	
	set_skill("unarmed", guai_value+random(16));
	set_skill("dodge", guai_value+random(16));
	set_skill("parry", guai_value+random(16));
	set_skill("force", guai_value+random(16));
	set_skill("spells", guai_value+20+random(16));
}	


void set_hp_status(object me, int level)
{       int max_kee,max_sen,skill_force,maximum_mana,exp,daoxing;
        max_kee = me->query("max_kee");
        max_sen = me->query("max_sen");
        skill_force = query_skill("force");
        maximum_mana = me->query("maximum_mana");
        exp = me->query("combat_exp");
        daoxing = me->query("daoxing");
	
	set("max_force", skill_force*10);
	set("force", skill_force*20);
	set("force_factor", skill_force/2);
	set("mana_factor", query_skill("spells",1));
	
	if (level==1)
	   {
	   	set("max_kee", max_kee*2);
	   	set("eff_kee", max_kee*2);
	   	set("max_sen", max_sen*2);
	   	set("eff_sen", max_sen*2);
	   	set("kee", max_kee*2);
	   	set("sen", max_sen*2);
	   	set("max_mana", maximum_mana*3/2);
	   	set("mana",maximum_mana*3);
	   	set("combat_exp", exp+exp*1/16+random(exp*1/16));
	   	set("daoxing", daoxing+daoxing*1/16+random(daoxing*1/16));
	        set_temp("apply/armor", 400);
	        set_temp("apply/damage", 180);
	   }
	   
	else if (level==2)
	   {
	   	set("max_kee", max_kee*3);
	   	set("eff_kee", max_kee*3);
	   	set("max_sen", max_sen*3);
	   	set("eff_sen", max_sen*3);
	   	set("kee", max_kee*3);
	   	set("sen", max_sen*3);
	   	set("max_mana", maximum_mana*2);
	   	set("mana",maximum_mana*4);
	   	set("combat_exp", exp+exp*1/12+random(exp*1/12));
	   	set("daoxing", daoxing+daoxing*1/12+random(daoxing*1/12));
	        set_temp("apply/armor",450);
	        set_temp("apply/damage", 250);
	   }   
	   
	   else
	   {
	   	set("max_kee", max_kee*4);
	   	set("eff_kee", max_kee*4);
	   	set("max_sen", max_sen*4);
	   	set("eff_sen", max_sen*4);
	   	set("kee", max_kee*4);
	   	set("sen", max_sen*4);
	   	set("max_mana", maximum_mana*5/2);
	   	set("mana",maximum_mana*5);
	   	set("combat_exp", exp+exp*1/6+random(exp*1/6));
	   	set("daoxing", daoxing+daoxing*1/6+random(daoxing*1/6));
	        set_temp("apply/armor", 500);
	        set_temp("apply/damage", 300);
	   }   
}

int accept_fight(object ob)
{	
        object me=this_object();
	if (ob != owner())
	{message_vision(CYN"$N说道：快走开，要不我吃了你。\n"NOR,me);
	 return 0;
	}
	
	else {if ( query("kind")!="降" )
	           {
	           	command("say 我不找你，你倒送上门来了，我就成全了你。");
	                me->kill_ob(ob);
	                return 1;
                   }
                else {  
                	if ( query("eff_kee") < query("max_kee") 
                	     || query("eff_sen") < query("max_sen")
                	     || query("kee")< query("max_kee") )
                	     {message_vision(CYN"$N说道：我受伤了，这样打不公平吧。\n"NOR,me);
                	      return 0;
                	     }
                	command("say 废话少说，尽管放马过来，看谁怕谁。");
                	remove_call_out("check_result");
	                call_out("check_result", 1, me, ob);
                	return 1;
                     }
              }                  
}                 

void init ()
{       int i=0;
        add_action("do_persuade", "persuade");
        add_action("do_shou", "shoufu");  
        if(!i) {
        	call_out("destruct_it",600);
        	i=1;
        	}
}	
void destroy_it()
{
	message_vision("一阵风吹来，" + (string)this_object()->query("name") + "踏云而起，竟然慢慢随风而去。\n", environment(this_object()));
	destruct(this_object());
}
void heart_beat()
{  object guai = this_object();
   ::heart_beat();
   
   if ( !is_fighting()
        && query("eff_kee") >= query("max_kee") / 2 
        && !query_skill("tonsillit",1)
        && !query_skill("shushan-force",1)
        && query("kind") != "降" 
        && query("eff_kee") <  query("max_kee") )
     command("exert heal");
      
   if (query("kee") < query("eff_kee")-10 
       && query("kind") != "降"
       && random(2)==0)
         command("exert recover");
   if (query("sen") < query("eff_sen")-10  && random(2)==0) 
     command("exert refresh");
   if (query("force") < query("max_force") && random(3)==0)
     command("cast transfer");
   if (!owner() || owner()->query("canoetask/fail") )    
        destruct(guai);
   
}       


int check_result(object me, object ob)
{
	int guai_max_kee, ob_max_kee;

	guai_max_kee  = me->query("max_kee");
	ob_max_kee = ob->query("max_kee");
	
	if (me->is_fighting())
	{
		call_out("check_result",1, me, ob);
		return 1;
	}
	
	if ( !living(me) 
		|| (int)me->query("kee") < 1 
		|| (int)me->query("sen") < 1 ) return 1;
		
	if (((int)me->query("kee")*100/guai_max_kee) <= 50 )
	      {
	      	if ( !living(me) 
			|| (int)me->query("kee") < 1 
			|| (int)me->query("sen") < 1 ) return 1;
			
		if (random(3) < 1)  command ("say 我还没准备好，你就开打了，不算数。");
		      else { if (ob->query_temp("canoetask/fight_time"))
		                   { command ("say 我现在方知天外有天，人外有人，我还要回山多多修炼，告辞了。");
		   	             ob->set("canoetask/accomplish",1);
		   	             ob->set("canoetask/end_time",time());
		   	             ob->delete_temp("canoetask/fight_time");
		   	             ob->delete("canoetask/get");
		   	             destruct(me);
		   	             return 1;
		   	            }
		   	       
		   	         else { command ("say 我一时大意，也没尽全力，我不服，再比一次。");
		   	                ob->set_temp("canoetask/fight_time",1);
		   	                return 1;
		   	              }
                            }
               }
                    
            else  {
                 	command("say 哈哈，你输了，我天下无敌。");
                 	return 1;
                  }
}

int do_persuade(string arg)
{
	object me =this_player();
	object ob;
	int guai_max_kee,guai_eff_kee;
	
	if(!arg) return 0;
	ob = present(arg, environment(me));
	if (!ob)   return notify_fail("你要劝谁？\n");
	if (me->query("canoetask/kind") != "劝"  || ob->query("kind") != "劝") return 0;
	
	if (me->is_busy())
	     return notify_fail("你正忙着呢。\n");
	
	me->command("say 放下屠刀，立地成佛。");
	
	if ( !living(ob) )   return notify_fail("很显然，"+ob->name()+"听不见你说的话。\n");
	
	if ( me != ob->query("owner") || !ob->is_fighting(me) )
	     { message_vision(CYN"$N说道：你罗嗦些什么，快滚开。\n"NOR,ob);
	       return 1;
	      }
	 	 
	 guai_max_kee = ob->query("max_kee");
	 guai_eff_kee = ob->query("eff_kee");
	 
	 if ( guai_eff_kee*100/guai_max_kee < 15 )
	      {
	      	command("say 你说的有道理，我这就回山去。");
	      	me->set("canoetask/accomplish",1);
	      	me->set("canoetask/end_time",time());
	      	me->delete("canoetask/get");
	        destruct(ob);
	        return 1;
	       }
	       
	   else if ( guai_eff_kee*100/guai_max_kee < 20 )
	        {
	        	command("say 你看我现在，不比做佛快乐吗。");
	        	me->start_busy(1+random(3));
                        return 1;
                 }
                 
            else {
            	     me->start_busy(3);
            	     return notify_fail(ob->name()+"正专心致志战斗，懒得理你。\n");
            	  }
}


void die()
{       object me = owner();
	if (me->query("canoetask/kind") == "杀"  && query("kind") == "杀")
	     {me->set("canoetask/accomplish",1);
	      me->set("canoetask/end_time",time());
	      me->delete("canoetask/get");
	     }	     
	else { me->delete("canoetask/get");
	       me->set("canoetask/fail",1);
	     } 
	::die();
}


int accept_object (object who, object ob)
{
  object guai;
  guai = this_object();
  
  if ( ob->name() != "金创药" || ob->query("id") != "jinchuang yao" )
       { message_vision(CYN"$N说道：这是什么玩意儿，想毒死我啊。\n"NOR,guai);
         return 0;
        }
    else { guai->receive_curing("kee", 100);
           guai->receive_curing("sen", 100);
           command("exert recover");
           call_out ("destruct_ob",1,ob);
           if ( query("eff_kee") == query("max_kee") )
                message_vision(CYN"$N说道：我好了，来来来，咱们再大战三百回合。\n"NOR,guai);
           return 1;
          }
}

void destruct_ob (object ob)
{
  destruct (ob);
}

void kill_ob (object ob)
{
	  object me = this_object();  
	  if (me->query("level")>1)
	      me->set_leader(ob);
	    ::kill_ob(ob);
}	    

int do_shou(string arg)
{
	object me =this_player();
	object ob;
	int guai_max_kee,guai_eff_kee;
	
	if(!arg) return 0;
	ob = present(arg, environment(me));
	if (!ob)   return notify_fail("你要收谁？\n");
	if (me->query("canoetask/kind") != "收"  || ob->query("kind") != "收") return 0;
	
	if (me->is_busy())
	     return notify_fail("你正忙着呢。\n");
	if (!me->is_fighting())
  	     return notify_fail("只有战斗中才能收服对方。\n");
  	if ((int)me->query("mana") < 1000)
  	     return notify_fail("你的法力不够了。\n");
    	if ((int)me->query("force") < 1000)
  	     return notify_fail("你的法力不够了。\n");
    	if( (int)me->query("sen") < 300)
    	    return notify_fail ("你无法集中精神念咒语。\n");
   	if(!present("zijin hu", me))
	     return notify_fail("你身上有紫金炼妖壶？\n");
	if ( !living(ob) )   
	     return notify_fail("紫金炼妖壶不能对晕倒的物体使用。\n");
	
	message_vision(CYN"$N喝道：“妖孽！还不速降？”手中"HIY"紫金炼妖壶"NOR CYN"冉冉升至半空！\n"HIY"紫金炼妖壶"NOR HIW"散发出刺眼的红光对着$n射去！\n"NOR,me,ob);
	if ( me != ob->query("owner") || !ob->is_fighting(me) )
	     return notify_fail(ob->name()+"说道：你好烦呀你！滚开，搞得我心情郁闷死了。\n");
	 	 
	 guai_max_kee = ob->query("max_kee");
	 guai_eff_kee = ob->query("eff_kee");
	 
	 if ( guai_eff_kee*100/guai_max_kee < 15 )
	      {
	      	message_vision(HIR"$n抵抗不住吸力，一声惨叫，化作一团黑气钻进了"HIY"紫金炼妖壶"HIR"。\n"NOR, me,ob);
	      	me->set_temp("canoetask/shoufu",1);
	      	me->set("canoetask/end_time",time());
	      	me->delete("canoetask/get");
	        destruct(ob);
	        return 1;
	       }
	       
	   else if ( guai_eff_kee*100/guai_max_kee < 20 )
	        {
	        	me->add("mana",-300);
	        	me->start_busy(1+random(3));
                        return notify_fail(ob->name()+"轻轻一跳，红光擦着它身边射入地中！\n");
            	  }
                 
            else {
            	     me->start_busy(3);
            	     me->add("mana",-500);
            	     return notify_fail(ob->name()+"见来势汹涌，机灵地往旁边一闪躲过去了。\n");
            	  }
}



