// blacksh 01/19/99

// 蒸笼老人的作用:	玩家可以想他借法宝(天魔茧),只有这个法宝才可以抓
//			取经人,但要付出的代价就是以后不能参加取经
//			如果下次要参加取经的话,就需要成功的吃到一次取经人
//			取经人被抓后自动被送到老人居住的地方,OBSTACL_D
//			的last_env存放的是取经人被抓的环境,如果玩家救出
//			取经人后就可以ask laoren  about back,而回到原来
//			的地方.

//			当玩家使用天魔茧抓住取经人人后,取经人自动被送到
//			蒸笼房,在那里蒸笼老人就可以蒸取经人,这个地方与
//			老人开始在的地方不相同.玩家要救取经人就要过7个
//			关卡,达到最后的蒸笼房.

//			如果玩家在24小时内没有救出取经人,取经就失败.
//			取经人被蒸成七块,一块归蒸笼老人所有,其他交给借
//			天魔茧的玩家.



inherit NPC;


int ask_fabao();
int do_back();

void create()
{
  set_name("蒸笼老人", ({"zhenglong laoren", "laoren"}));
  set("long", "传说他以前是一个非常会做蒸食的老人,后来变成了一个...\n");
  set("gender", "男性");
  set("age", 5000);
  set("attitude", "peaceful");
  set("str",50);
  set("per",50);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 5000);
  set("max_force", 5000);
  set("force_factor", 500);
  set("max_mana", 5000);
  set("mana", 5000);
  set("mana_factor", 500);
  set("combat_exp", 2000000);
  set_skill("literate", 200);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 200);
  set_skill("jienan-zhi", 200);
  set_skill("dodge", 200);
  set_skill("lotusmove", 200);
  set_skill("parry", 200);
  set_skill("force", 200);
  set_skill("lotusforce", 200);
  set_skill("staff", 200);
  set_skill("lunhui-zhang", 200);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);


  set("inquiry", ([
    "借宝" : (: ask_fabao :),
    "jiebao" : (: ask_fabao :),
    "宝贝" : "我这天魔茧可以缠住如何的东西,包括人",
    "法宝" : "我这天魔茧可以缠住如何的东西,包括人",
    "fabao": "我这天魔茧可以缠住如何的东西,包括人",
    "back" : (: do_back :),
    "回去" : (: do_back :),
  ]) );

  setup();
}


void init ()
{
  add_action("do_kill", "kill");
  add_action("do_kill", "cast");
  add_action("do_kill", "ji");
  add_action("do_kill", "steal");
  add_action("do_accept","accept");
}


int ask_fabao()
{
  object me,who,ob;

  me=this_object();
  who=this_player();

  if (who->query("obstacle/qujing")=="ren")
    {
 	me->command_function("say 想借宝你不够资格");
	return 1;
    }

  if (who->query("combat_exp")<500000)
    {
 	me->command_function("say 想借宝你不够资格");
	return 1;
    }
    
  if (who->query("obstacle/no_qujing"))
    {
      if (time()-who->query("last_ask_fabao")<24*3600)
    	{  //每天一个玩家只能借一次
 		message_vision("$N对$n露出不信任的眼神\n",me,who);
		me->command_function("shake")		;
		return 1;
    	}
    }	

  if (OBSTACLE_D->query("last_jie_id"))
    {
	ob=find_object("tianmo jian");
	if ( ! interactive( environment(ob) ))
          {
           OBSTACLE_D->back()    ;
		//由于tianmo jian可以给,如果玩家将它藏起来,就可以限制抓
		//取经人,因此在这里判断,如果被藏起来就自动返回.
	  }
        else
 	  {
	    me->command_function("say 你来迟一步,已经被借走了");
  	  }
	return 1;
    }

  me->command_function("say 要想借我的法宝,可是要入我魔道的,如果你同意的话,
accept");
  who->set_temp("can_accept",1);
  return 1;    

}

int do_accept()
{
  object me,who,ob;
  me=this_object();
  who=this_player();


  if (who->query_temp("can_accept"))
    {
      me->command_function("ok");
      message_vision("$N把手放在$n的头上,口中念念有词,一股黑气注入$n的脑中\n"
		,me,who);
      who->delete_temp("can_accept");
      who->set("last_ask_fabao",time());
      who->set("obstacle/no_qujing",1);
	//取法宝的人不允许取经,除非成功吃到一次取经人
      ob=new("/d/qujing/qujingren/tianmo/obj/tianmojian");
      ob->move(who);	      
      OBSTACLE_D->delete("open_door");
      OBSTACLE_D->set("last_jie_id",who->query("id")); 
      OBSTACLE_D->back_fabao();
	//一个玩家仅能借一个小时,一个小时还没有抓到取经人就收回法宝.
 	//防止一个玩家借走法宝,以帮助另一个人过关
      return 1;
    }
  return 1;
 
}

int do_back()
{
  object me,who,ob,qjr,where;

  me=this_object();
  who=this_player();

  if (who->query("obstacle/qujing")=="ren")
    {
      if (qjr=present("qujing ren",environment(me)))
        {
	me->command_function("say 好小子,有本事,别让我再遇到你");
        where=load_object(OBSTACLE_D->query("last_env"));
        message_vision("$N和$n忽然被一阵烟雾笼罩住...慢慢的什么都消失了",
		qjr,who);
	qjr->move(where);
	who->move(where);
	OBSTACLE_D->set("where_qujingren",OBSTACLE_D->query("last_env"));
	OBSTACLE_D->delete("last_env");
	OBSTACLE_D->delete("open_door");
	destruct(me);
	return 1;
  	}
    }
  return 1;
}

int do_kill()
{
  object me=this_object();

  me->command_function("say 在我面前......");
  me->command_function("heng");
  this_player()->start_busy(50);
  return 1;

}


void die()
{
  if (environment())
    message("sound", "\n\n蒸笼老人微微一笑！\n\n", environment());

  set("eff_kee", 5000);
  set("eff_gin", 5000);
  set("eff_sen", 5000);
  set("kee", 5000);
  set("gin", 5000);
  set("sen", 5000);
  set("force", 5000);
  set("mana", 5000);
}

void unconcious()
{
  die ();
}



