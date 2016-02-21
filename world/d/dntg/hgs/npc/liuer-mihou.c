//liuer-mihou.c weiqi...98/05/13

#include <ansi.h>
#define MAX_TRY 20
#define MAX_TRY1 200
inherit NPC;

void set_skills();
void finished();
void killed_enemy(object victim);
string do_accuse(string tar);
string ask_me();
void create()
{
	set_name("六耳猕猴", ({"liuer mihou", "liuer", "mihou"}));
	set("title", "灵通子");
	set("gender", "男性" );
	set("age", 35);
	set("per", 14);
	set("str", 30);
	set("long", "六耳猕猴早年拜在镇元大仙门下，学得一身好本领。\n后来他自觉跟镇元大仙差不多了，便开始不安分起来，\n居然去果园偷吃人参果，结果是果子没吃着反而被镇元大仙逮住，\n痛加斥责后逐出了门墙。\n");
	set("class", "xian");
	set("attitude", "peaceful");
	//create_family("五庄观", 2, "弟子");
	set("rank_info/respect", "猴爷");

	set_skills();

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	
	set("chat_chance", 2);
	set("chat_msg", ({ 
		(: random_move :)
		}));

	set("chat_chance_combat", 60);
	set("chat_msg_combat", 
	({
		(: cast_spell, "zhenhuo" :),
	}) );

	set("inquiry", ([
		"name": "齐天大圣孙悟空是也。\n",
		"here": "。。。\n",
		"人参果": "猴爷我最喜欢的就是人参果。\n",
		"杀人": "杀人？只要你有人参果，什么都好商量。\n",
		"秘诀": "秘诀？只要你有人参果，什么都好商量。\n",
		"猕猴手记": "手记？只要你有人参果，什么都好商量。\n",
                "包裹"     : (: ask_me :),
                "真假"     : (: ask_me :),
	]) );

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}

void set_skills()
{
	set("combat_exp", 1800000);
  set("daoxing", 4000000);

	set_skill("unarmed", 260);
	set_skill("wuxing-quan", 260);
	set_skill("dodge", 260);
	set_skill("baguazhen", 260);
	set_skill("parry", 260);
	set_skill("hammer", 260);
	set_skill("kaishan-chui", 260);
	set_skill("force", 260);   
	set_skill("zhenyuan-force", 260);
	set_skill("literate", 260);
	set_skill("spells", 260);
	set_skill("taiyi", 260);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("dodge", "baguazhen");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 5000);
	set("max_force", 2500);
	set("mana", 6000);
	set("max_mana", 3000);	
	set("force_factor", 200);
	set("mana_factor", 250);
}

void set_skills2()
{
        set("combat_exp", 1500000);
  set("daoxing", 2000000);

        set_skill("unarmed", 180);
        set_skill("wuxing-quan", 180);
        set_skill("dodge", 180);
        set_skill("baguazhen",180);
        set_skill("parry", 180);
        set_skill("hammer", 180);
        set_skill("kaishan-chui", 180);
        set_skill("force", 180);
        set_skill("zhenyuan-force", 180);
        set_skill("literate", 150);
        set_skill("spells", 180);
        set_skill("taiyi", 180);
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("unarmed", "wuxing-quan");
        map_skill("dodge", "baguazhen");
        map_skill("hammer", "kaishan-chui");

	set("max_kee", 2000);
        set("max_sen", 2000);
        set("force", 2000);
        set("max_force", 2000);
        set("mana", 2000);
        set("max_mana", 2000);
        set("force_factor", 100);
        set("mana_factor", 80);
}

void init()
{
    if(this_player()==query_leader()) kill_ob(this_player());
/*
    remove_call_out("to_say");
    call_out("to_say", 1);
*/    
    add_action("do_get","get");
    ::init();
}

int do_get(string arg)
{
    object who=this_player();
    object tar=query_leader();
    object obj;
    
    if(!tar || !who) return 0;
    if(!(obj=present(arg, environment(this_object())))) return 0;
    
    if(obj==tar) {
	message_vision("$N对$n一瞪眼：猴爷眼皮底下也敢救人？\n",
		this_object(), who);
	return 1;
    }
    return 0;
}

void to_say()
{

    if(is_fighting() || this_object()->is_busy()) return;

        if(random(10)==0) { message_vision(
	 "$N开口说道：诸位如见杀人越货，尽可附耳说来(whisper liuer PKer_id)，"
	   + "\n定当尽力打报不平！\n",this_object());
	}
}

// this function is called from combatd.c
// after this_object() killed a victim.
void killed_enemy(object victim)
{
    if (victim!=query_leader()) return;
    
    // ok, now killed the target.
    finished();
}

void finished()
{
		command("bian");
		delete_temp("I_am_busy");
		delete_temp("kill_count");
		delete_temp("kill_count1");
		remove_call_out ("try_kill");
		remove_call_out ("autokill");
		remove_call_out ("check_finish");
		
		set_skills(); // set back skills.
		this_object()->move("/d/4world/houshan3");
}

string do_accuse(string tar)
{
    object me=this_object();
    object target;
    object env;
    int no_pk;

    if(!tar) return 0;
    target=find_player(tar);

    if((int)this_player()->query_condition("no_pk_time")>0)
        return "哼！你也配？！\n";
    if(!target || !interactive(target) ||wizardp(target))
        return "找不到这个人。\n";
//    if(wizardp(target)) return 0;
    
    no_pk=(int)target->query_condition("no_pk_time");
    if(!no_pk) return "你怎能诬陷无辜呢？！\n";
    if(no_pk<250)
        return "此物尚未恶贯满盈，且放它去吧！\n";
    env=environment(target);
    if(!env || env->query("no_fight"))
        return target->name()+"现在躲起来了，我也伤不了它：（\n";

    set_temp("kill_count", 1);
    set_temp("kill_count1", MAX_TRY1);
	    
    remove_call_out ("try_kill");
    call_out ("try_kill", 2, tar);
    call_out ("check_finish", 3, tar);

    return "好，你就静候佳音吧！\n";
}


int accept_object(object me, object ob)
{
	object book;

	if ( (string)ob->query("id") != "renshen guo" ) {
		message_vision("六耳猕猴尖声叫道：去！去！去！你家猴爷没空理你！\n", me);
		command("kick " + me->query("id"));
		//call_out("do_drop", 2, ob);
		return 1;
	}

	else {
		command("jump ");
		command("say 这位" + RANK_D->query_respect(me) + "果然是痛快人！\n");
		//first give a book...
		book = new("/d/obj/book/mihou-book");
		book->move(me);
		message_vision("$N对$n道：那猴爷我也不能小气。说罢递给$n一本小册子。\n", this_object(), me);

		//then promise a kill...
		command("whisper " + me->query("id")+
			" 除了这本书外，别的我帮不上，但杀个人是没问题的。"+
			"\n你要杀人的话，尽可附耳说来"+
			"(whisper liuer enemy_id)。\n");
		me->set_temp("rsg_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}

void relay_whisper(object me, string msg)
{
	object target, where;

	if( query_temp("I_am_busy") == 1 )
	{
		message_vision((string)this_object()->query("name") 
			+ "对$N道：我现在正忙着，你等会再来吧。\n", me);
		return;
	}

	if (me->query_temp("rsg_given") != 1)
	{
	   /* string result=do_accuse(msg);
	    
	    if(result) write(result);
	    else*/
		message_vision((string)this_object()->query("name") + 
			"对着$N冷冷地看了一眼。\n", me);
	    return;
	}
	
	target = find_player(msg);
	if( !target )
	{ 
		message_vision((string)this_object()->query("name") 
			+ "对$N说道：好像找不到这个人。\n", me);
		return;
	}

	where = environment(target);
	if( !where )
	{ 
		message_vision((string)this_object()->query("name") 
			+ "对$N说道：这个人是有，但是躲起来了。\n", me);
		return;
	}

	//now got the target player...
	message_vision((string)this_object()->query("name") 
		+ "对$N说道：好，你就静候佳音吧！\n", me);

	me->delete_temp("rsg_given");
	set_temp("I_am_busy", 1);
	set_temp("kill_count", MAX_TRY);
        set_temp("kill_count1", MAX_TRY1);
	set_skills();
	remove_call_out ("try_kill");
	call_out ("try_kill", 2, msg);
	call_out ("check_finish", 3, msg);
	//note, here we still use target id for future trying...
}

void check_finish(string target_id)
{
	object target;

	//here alway set fali back, since liuer mihou is in a "bian" status...
	if( (int)this_object()->query("mana") < (int)this_object()->query("max_mana") )
		this_object()->set("mana", 2*(int)this_object()->query("max_mana"));
	
	add_temp("kill_count1",-1);
	if(query_temp("kill_count1")<0) {
	    finished();
	    return;
	}

	target = find_player(target_id);
	if( !target )
	{
	    command("bian");
		remove_call_out ("check_finish");
		call_out ("check_finish", 3, target_id);//try every 3 second.
		return; 
	}

	if( target->is_ghost() )
	{//means the target is dead.
	    finished();
	    return;
	}
	else
	{
	    object env1, env=environment(target);
	    
	    if(env!=environment() &&
		    !env->query("no_fight")) {
		if(env->is_character()) { //someone picked up.
		    env1=environment(env);
		    if(env1!=environment()) {
		       this_object()->move(env1);
		       message_vision("$N走了过来。\n", this_object());
		    }
		    kill_ob(env);
		} else {
		  this_object()->move(env);
		  message_vision("$N走了过来。\n", this_object());
		  kill_ob(target);
		}
	    } 

		remove_call_out ("check_finish");
		call_out ("check_finish", 3, target_id);//try every 3 second.
		return; 
	}
}

void  try_kill(string target_id)
{
	object target, where;

	if( (int)query_temp("kill_count") <= 0 )
	{//tried too long
	    finished();
	    return;
	}

	target = find_player(target_id);
	if( !target )
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 930, target_id);//try every 15 minutes.
		return; 
	}

	where = environment(target);
	if( !where ||
		where->query("no_fight")) // mon added check no_fight
	{
		remove_call_out ("try_kill");
		call_out ("try_kill", 890, target_id);//try every 15 minutes.
		return; 
	}

	//now kill...
	command("bian");
	if( where != environment(this_object()) )
	{
		this_object()->move(where);
		message_vision(YEL "只见几道金光乱晃不止，$N一个筋斗翻了出来。\n" NOR, this_object());
	}
	message_vision(RED "$N抓耳挠腮地对$n尖声说道：到了阎王那儿休怪猴爷无情。阁下要是有人参果我一样能替你杀人。\n" NOR, this_object(), target);

	// check whether copy data. -- mon 8/6/98
	// always   copy data. -- mon 8/18/98
//	if(target->query("combat_exp")>1000000) 
	{
	    object qm=new("/d/changan/npc/qianmian.c");
	    if(qm) {
		mapping skill=target->query_skills();
		int i=sizeof(skill);
		int *level, max_level;
		
		if(i>0) {
		    level=values(skill);
		    max_level=level[0];
		    while(i--) { // find out victim's maximum level
			if(level[i]>max_level)
			    max_level=level[i];
		    }
		    if( (int)query_temp("kill_count")<2)
		      max_level=max_level*22/20;
		    else
		      max_level=max_level*18/20;
		} else max_level=200;

		if( (int)query_temp("kill_count")<2)
		  qm->copy_status(this_object(), target, 25); // tobe 125% strong.
		else
		  qm->copy_status(this_object(), target, 20); // tobe 100% strong.
		destruct(qm);
		// mihou will use the following skills, so set to max.
	        set_skill("hammer", max_level);
	        set_skill("kaishan-chui", max_level);
	        set_skill("taiyi", max_level);
		map_skill("hammer", "kaishan-chui");
	        map_skill("spells", "taiyi");
	    }
	} 
//	else set_skills(); // set back skills.

	if( (int)query_temp("kill_count")<2) {
	  set("force_factor", query_skill("force")/2);
	  set("mana_factor", query("max_mana")/20+1);
	}

//	if( (int)query_temp("kill_count") == MAX_TRY ) 
//	{//first time, always need to initialize kill...
		command("bian " + target_id);
//	}

	        this_object()->set_leader(target); // follow.
		this_object()->kill_ob(target);    // kill
		target->kill_ob(this_object());
		
		// no problem here. kill_ob also check no_fight.
		// - mon 8/6/98
		//need consider this carefully, is it ok to make safe place unsafe?
	    
		//command("kill " + target_id);
		//command("bian " + target_id);
//	}
//	else command("kill " + target_id);
	//problem here, if kill_ob(), may bypass no_fight, ...etc;
	//if kill command, may confuse with NPC of the same name?
//	command("follow "+target_id);

	add_temp("kill_count", -1);

	remove_call_out ("try_kill");
	call_out ("try_kill", 837, target_id);//try every 15 minutes.
}

//LPG 19990925 真假美猴王

string ask_me()
{
    if (this_player()->query("obstacle/liuer-mihou") != "done")
    { 
        this_player()->set_temp("liuer-mihou_ask","done");
	set_skills2();
    }
        call_out("autokill",1,this_player(),this_object());
        return "嘿嘿";
}
void autokill (object me, object who)
{
  message_vision ("$n大喝一声要杀死$N！\n",me,who);
  who->set_leader(me);
  me->kill_ob(who);
  who->kill_ob(me);
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  int dx;
  if(!ob) return;
  if (ob->query_temp("liuer-mihou_ask")=="done") { 
  message_vision ("\n$N大怒：哪个泼贼子冒充你家猴爷！\n",me);
  set_temp("my_killer",ob);
  this_player()->kill_ob(me);
  call_out ("check_finish", 3, ob->query("id"));
  return;
  } else {
  dx=ob->query("combat_exp");
  if(dx>me->query("combat_exp")) me->set("combat_exp", dx*2);
  ::kill_ob(ob);
  call_out ("check_finish", 3, ob->query("id"));
  return;
  }
}

void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object baoguo;
  message_vision(HIY "\n观音突然从彩云间现身。\n" NOR,me);
  message_vision(HIY "\n观音对$N一点手，你这猴头！\n" NOR,me);
  message_vision(HIY "$N哎呀一声，现了真身。\n\n" NOR,me);
  if ((ob) && (ob->query_temp("liuer-mihou_ask") == "done"))
  {
        ob->set_temp("obstacle/liuer-mihou/liuer-mihou_killed",1);
        message_vision(HIC "观音说道：这厮我带走，你安心取经去吧。\n\n" NOR,me);
//      baoguo = new ("/d/obj/misc/baoguo");
//      baoguo -> move(ob);
        message_vision("$N拿出个包裹。\n\n",me);
        call_out ("guan_appearing",1,ob);
  }
  if (ob) 
   ob->set_temp("liuer-mihou_ask","no");
  message_vision("$N悻悻地走了。\n\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void guan_appearing (object who)
{
  object guan = new ("/d/nanhai/npc/guanyin");
  guan->announce_success (who);
  destruct (guan);
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
   unconcious();
}

