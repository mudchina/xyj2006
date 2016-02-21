//erlang.c writted by Beeby. 07/30/2000

#include <ansi.h>

inherit NPC;
int begin_chasing();
void create()
{
        set_name("二郎真君", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "他是赤城昭惠英灵圣，显化无边号二郎。
力伏八怪声名远，义结梅山七圣行。\n");
	set("looking", "仪容清俊貌堂堂，两耳垂肩目有光。");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "男性");
        set("title", "昭惠灵显王");
        set("str", 40);
        set("int", 40);
        set("per", 30);
	set("con", 30);
        set("max_kee",3000);
        set("max_sen", 3000);
        set("combat_exp", 1500000);
        set("daoxing", 2500000);

        set("force", 4000);
        set("max_force", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 150);
        set("mana_factor", 120);

        set("eff_dx", 800000);
        set("nkgain", 800);

        set_skill("unarmed", 200);
	set_skill("force", 180);
	set_skill("spells", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("spear", 200);
        set_skill("dao",200);
        set_skill("wuxiangforce",200);
	set_skill("moyun-shou", 200);
	set_skill("moshenbu", 200);
        set_skill("bawang-qiang", 200);
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("force","wuxiangforce");
        map_skill("spells","dao");
        set("inquiry", ([ /* sizeof() == 4 */
  		"me" : (: begin_chasing :),
  		"here" : "我奉玉帝谕旨，正要兴兵捉拿反出天宫的齐天大圣。",
  		"name" : "我乃二郎神杨戬是也。",
  		"齐天大圣" : (: begin_chasing :),
	]) );

        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/drug/jinchuang")->set_amount(random(10));
}

void init()
{
	object me=this_object();
	object who=this_player();
	if (me->query("name") != "二郎真君" && me->query_temp("chasing_status") && 
	environment(me)!=me->query_temp("last_env"))
	{
	   me->set("name","二郎真君");
	   me->set("title","昭惠灵显王");
	   message_vision(HIY"$N口念咒语，身形一晃，现了真身。\n"NOR,me);
	}
	return ::init();
}
			
		     
void die()
{
	object who;
	object me=this_object();
	remove_call_out("check_status");
        if( environment() ) {
        message("sound", "\n\n二郎神怒道：你莫要猖狂，待我上天告御状去！\n\n", environment());
        message("sound", "\n二郎神搭上白云，径往南天门飞去。。。\n\n", environment());
        command("drop all");
        }
	if (query_temp("chasing_status")==5 && !query_temp("chasing_fail")
	    && query_temp("current_player"))
	{
	   who=query_temp("current_player");
	   who->set("dntg/erlang","done");
	   who->add("cor",2);
	   tell_object(who,HIW"你觉得自已的胆识一下子增加了不少！\n"NOR);
	   CHANNEL_D->do_channel(me,"chat",who->query("name")+"你莫要猖狂，待我上天告御状去！");
	} 

        destruct(this_object());
}

void kill_ob(object who)
{
	if (!query_temp("current_player"))
	  return ::kill_ob(who);
	if (query_temp("current_player")!=who)
	  set_temp("chasing_fail",1);
	return ::kill_ob(who);
}

int accept_fight(object who)
{		
	if (query_temp("chasing_status"))
	  {
	    if (query_temp("current_player")!=who)
	     return notify_fail("二郎真君摇了摇头：“等我先收拾了这个臭猴子吧！”\n");
	    else
	     kill_ob(who);
	  }
	return ::accept_fight(who);
}	
	  
	

int receive_damage(string arg,int damage,object me)
{
	if (this_object()->query_temp("no_damage"))
	   return 1;
	else return ::receive_damage(arg,damage,me);
}

int begin_chasing()
{
	object me=this_object(); 
	object who=this_player();
if (!userp(who))
{ 
command("fool");
command("say 小畜生,小心我把你抽筋扒皮,下油锅！");
return 1;
}
	if (who->query("dntg/erlang") == "done" )
	 {
	 	command("shake");
	 	command("say 这位"+RANK_D->query_respect(who)+"的功夫已经领教过了。\n");
	 	return 1;
	 }
if((int)who->query_skill("spells") < 300)
         {
  command("say 就凭你也想做齐天大圣?\n");
                command("haha");
return 1;
}
	if (query_temp("chasing_status"))
	 {
		if (query_temp("current_player")==who)
		  command("say 你乖乖投降罢!");
		else
		  command("say 怎么又来一个？呆会再来收拾你！");
		return 1;
	 }
	command("look "+who->query("id"));
	command("jump");
	command("say 我正愁拿你不到，你却送上门来，真是天助我也！");
	command("follow "+who->query("id"));
	me->set("max_kee",4000);
	me->set("max_sen",4000);
	me->set("eff_kee",4000);
	me->set("eff_sen",4000);
	me->set("kee",4000);
	me->set("sen",4000);
	me->set("force",4000);
	me->set("mana",4000);
	me->kill_ob(who);
	who->kill_ob(me);
	me->set_temp("current_player",who);
	me->set_temp("chasing_status",0);
	me->set_temp("no_damage",1);
	remove_call_out("check_status");
	call_out("check_status",1);
	return 1;
}

void check_status()
{
	object me=this_object();
	object who=query_temp("current_player");
	string *id_list;
	if (!who || who->is_ghost())
	 {  
	    message_vision("$N冷笑一声：“所谓齐天大圣也不过如此罢!”\n"+
	                  "转身架起一朵白云回梅山去了。\n",me);
	    remove_call_out("check_sratus");
	    destruct(me);
	    return;
	 }
	if (me->query("eff_kee") < me->query("max_kee")*9/10 &&
	    present("jinchuang yao",me))
	   command("eat yao");
	if (me->query("kee") < me->query("eff_kee")*9/10 &&
	    me->query("force") > 0)
	   command("exert recover");
	if (me->query("sen") < me->query("eff_sen")*9/10 &&
	    me->query("force") > 0)
	   command("exert refresh");
	if (!present(who,environment(me)))
	 {
	   me->move(environment(who));
	   message_vision("$N走了过来。\n",me);
	 }
        if (id_list=who->query_temp("apply/id"))
	   switch (me->query_temp("chasing_status"))
	   {
	   	case 0:if (member_array("maque",id_list)!=-1 
	   	           && environment(me)->query("short")=="山崖") 
	   		{
	   		 message_vision(HIY"$N手捻口诀，念动真言，摇身一变，变成一只雀鹰！\n"NOR,me);
	   		 me->set_temp("chasing_status",1);
	   		 me->set("name","雀鹰");
	   		 me->set("title","");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 1:if (member_array("ci hu",id_list)!=-1
	   		   && environment(me)->query("short")=="小溪前")
	   		{
	   		 message_vision(HIY"$N手捻口诀，念动真言，摇身一变，变成一只海鹤！\n"NOR,me);
	   		 me->set_temp("chasing_status",2);
	   		 me->set("name","海鹤");
	   		 me->set("title","");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 2:if (member_array("fish",id_list)!=-1
	   		&& environment(me)->query("short")=="小溪")
	   		{
	   		 message_vision(HIY"$N手捻口诀，念动真言，摇身一变，变成一只鱼鹰！\n"NOR,me);
	   		 me->set_temp("chasing_status",3);
	   		 me->set("title","");
	   		 me->set("name","鱼鹰");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 3:if (member_array("shui she",id_list)!=-1
	   		&& environment(me)->query("short")=="小溪")
	   		{
	   		 message_vision(HIY"$N手捻口诀，念动真言，摇身一变，变成一只灰鹤！\n"NOR,me);
	   		 me->set_temp("chasing_status",4);
	   		 me->set("name","灰鹤");
	   		 me->set("title","");
	   		 me->set_temp("last_env",environment(me));
	   		 break;
	   		}
	   	case 4:if (member_array("hua bao",id_list)!=-1
	   		 && environment(me)->query("short")=="小溪前")
	   		{
	   		 me->delete_temp("no_damage");
	   		 me->set_temp("chasing_status",5);
	   		}
	   }
	 
	remove_call_out("chech_status");
	call_out("check_status",1);
	return;
}   
