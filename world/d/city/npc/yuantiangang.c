inherit NPC;

string *list=({"yg-putuo","yg-moon","yg-wzg",
	"yg-fangcun","yg-hell","yg-jjf",
	"yg-dragon", "yg-xueshan",
	"yg-wudidong",
	});

int work_me();
int delete_ask(object me);
 
void create()
{
        set_name("袁天罡", ({"yuan tiangang", "yuan"}));
        set("gender", "男性" );
        set("age", 33);
        set("long","袁天罡是天监台总管，听说他法术高深。
他为人正直仗义，脸上总是一股忧国忧民的神情。\n");
        set("int", 30);
	set("per", 25);
        set("combat_exp", 50000);
        set("daoxing", 800000);
	
	// discourage NK yuan.
	set("eff_dx",1000);
	set("nkgain",1);
	set("env/wimpy",100);

        set("attitude", "friendly");
	set("title", "天监台正先生");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 100);
	set_skill("baguazhou", 100);
        set_skill("literate", 50);
        set_skill("sword", 60);  
        set_skill("changquan", 50);  

        map_skill("spells", "baguazhou");
        map_skill("unarmed", "changquan");

        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 6000);
        set("max_mana", 3000);
        set("mana_factor", 100);

	set("chat_chance",5);
	set("chat_msg", ({
		    name()+"叹道：生逢乱世，妖魔横行啊！\n",
		    name()+"问道：可有谁愿去为大唐灭妖吗？\n",
		    }));

        seteuid(getuid());

        set("inquiry", ([
        "mieyao": (: work_me :),
        "kill": (: work_me :),
        "灭妖": (: work_me :),
	"妖魔": (: work_me :),
        ]));

        setup();
	add_money("silver", 5);
        carry_object("/d/obj/cloth/baguapao")->wear();
        carry_object("/d/obj/weapon/sword/taomujian")->wield();
}
int accept_fight(object me)
{
        write("袁天罡凛然道：学武乃是为了强身，不是打打杀杀！\n");
        return 0;
}
int recognize_apprentice(object me)
{
        if((int)me->query("yuan-learn"))
        return 1;
        return notify_fail("袁天罡说道：您太客气了，这怎么敢当？\n");
}

int accept_object(object who,object ob)
{
        if (ob->query("id")=="fan he"){
		if (((string)who->query("family/family_name")=="将军府")){
			who->set("yuan-learn", 1);
			write("袁天罡笑道：将军看起来一表人才，以后定是人前出头之辈！
袁天罡略为沉思，又道：若将军有何问题，可随时和我商讨，天罡若是知晓，定会答复．\n");
			call_out("destroy", 1, ob);
			return 1;
		}
		if (((string)who->query("family/family_name")!="将军府")){
			command("say 多谢多谢，我正饿着哪！");
			command("give 1 silver to " + who->query("id"));			
			call_out("destroy", 1, ob);
                        return 1;
		}
	}
	else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

int work_me()
{
	object ghost, me;
	int t, lvl, dx;
	me=this_player();
	
	dx=(me->query("daoxing")+me->query("combat_exp"))/2;
        if(dx>500000) {
	  message_vision("$N对$n一拱手：这位"+
	    RANK_D->query_respect(me)+
	    "请速去天廷协助灭妖！\n",this_object(),me);
	  return 1;
	}
	    
        if (me->query_temp("asked/yuan")) return 1;
        me->set_temp("asked/yuan",1);
       call_out("delete_ask",2,me);
	//for first time.
	if(!me->query("mieyao")) {
	        me->set_temp("mieyao/level1",0);
		call_out("start_job", 1, me);
		return 1;
	}
	if( (t=(int)me->query("mieyao/time_start1")) &&
		!me->query("mieyao/done1")) {

	    if(t<=time() &&
                    time()<t+120) {
		command("heng");
		command(
 		  "say 在下不是请您去收服"+me->query("mieyao/name1")
		  +"吗？\n");
		return 1;
	    }
	    // failed, decrease lvl.
	    lvl=me->query_temp("mieyao/level1");
	    if(lvl>0) lvl--;
	    me->set_temp("mieyao/level1",lvl);

	    // allow ask again.
	} else { // job done
	    if(t<=time() &&
                    time()<t+(dx>20000?300:0)) {
		message_vision("$N将手中桃木剑缓缓放下，说"+
			"：多谢"+RANK_D->query_respect(me)
			+",妖魔已经除尽了。\n",
			this_object(), me);
		return 1;
	    }
	    // succeed, increase lvl.
	    lvl=me->query_temp("mieyao/level1");
	    if(lvl<9) lvl++; // total 10 levels: 0, ..., 9
	    else
		lvl=5; // reach the top level, reduce difficulty.
	    me->set_temp("mieyao/level1",lvl);

	}
	me->delete("mieyao/time_start1");
	call_out("start_job", 1, me);
	return 1;
}

int start_job(object me)
{	string where;
	object ghost;
	int lvl;
        me->delete_temp("asked/yuan");

	if(environment(me)!=environment()) return 1;
	if(me->query("mieyao/time_start1")) return 1;
	me->delete("mieyao/done1");

	// determine levels.
	// use temp mark, if quit, then start over.
	lvl=me->query_temp("mieyao/level1");
	
        ghost = new(__DIR__+"yg/"+list[random(sizeof(list))]);
        where=ghost->invocation(me, lvl);
	
	message_vision("$N将手中桃木剑向四方一划，对$n说道：\n",
	  this_object(),me);
	message_vision("　　近有"+where+"出没，为害不小，"
		+"请速去收服！\n"
		,this_object(),me);
	me->set("mieyao/time_start1", time());
	me->set("mieyao/name1",ghost->query("name"));
	return 1;
}

int delete_ask(object me)
{
      me->delete_temp("asked/yuan");
      return 1;
}

void die ()
{

           set("eff_kee", 5000);
           set("eff_gin", 5000);
           set("eff_sen", 5000);
           set("kee", 5000);
           set("gin", 5000);
           set("sen", 5000);
           set("force", 5000);
           set("mana", 5000);
           return ;
}



