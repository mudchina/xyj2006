// gao.c


inherit NPC;


void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "头戴一顶冲天冠，腰束一条碧玉带，身穿一领飞龙舞凤赭黄袍。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("max_kee", 1000);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 10);
  set("max_mana", 800);
  set("mana", 1200);
  set("mana_factor", 75);
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("force", 70);
  set_skill("parry", 70);
  set_skill("fork", 70);
  set_skill("spells", 100);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 70);
  set_skill("dragonforce", 70);
  set_skill("fengbo-cha", 70);
  set_skill("dragonstep", 70);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");
  set("eff_dx",-30000);
  set("nkgain",180);
  set("firstdie",0);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void autokill (object me)
{ 
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  if (me->is_fighting())
    return;

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  message_vision ("$N对$n大喝一声：“妖怪魔头，竟敢欺世盗名变做朕的模样！”\n",
                  me,king2);
  message_vision ("$N与$n立刻撕打了起来！\n",me,king2);
  me->kill_ob(king2);
  king2->kill_ob(me);
}

void init ()
{
  autokill (this_object());  
}


void to_observe(object ob)
  {	//在这里有一个问题就是如果是别的玩家observe也算通过,最好的办法是在
        //observe命令中做修改.这样就可以直接叫妖怪现出原形同时还可以知道哪个
	//玩家observe的

  object me=this_object();

  if ( me->query_temp("d_mana")>0)
    {
    remove_call_out("to_observe");
    call_out("to_observe", 2, this_player());
    return;
    }
  me->delete("no_kill"); 
  me->delete("no_magic");
  return ;
  }

void unconcious()
{
  die();  
}

void die ()
{
  object ob;
  object me = this_object ();
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);
  object longpao = present("long pao",me);  
  
  string qujingren="qujing ren";

  if (me->query("first_die")==0)
   {  //第一次死的话,将会变成和取经人一样,这样就需要玩家observe
   ob=present(qujingren,where);
   if( !ob ) ob = find_living((string)qujingren);
   if( !ob ) ob = LOGIN_D->find_body(qujingren);   
 
   if (!ob) return ; //如果找不到取经人就无法继续,本关一直过不了.
   where= environment(ob);
  
   me->move(where);
   me->remove_all_killer();  
   me->command_function("bian qujingren");
   me->set("gin",2000);
   me->set("kee",2000);
   me->set("sen",2000);
   me->set("mana",2000);
   me->set("first_die",1);
   me->set("no_kill",1);  	//当妖怪变成取经人,不能杀仅能observe
   me->set("no_magic",1);
   remove_call_out("to_observe");
   call_out("to_observe", 1, this_player());
   
   return ;
   }

  message_vision ("$N发出一声长长的哀鸣，在尘土里现了青毛狮子的原身！\n",me);
  message_vision ("\n青毛狮子瞪着琉璃盏红眼，喘着粗气。\n",me);
  me->set_name("青毛狮子", ({"blue lion", "lion"}));
  me->delete("title");
  me->delete("long");
  if (longpao)
    destruct (longpao);  
  me->setup();
  me->remove_all_killer();
  me->set("gin",2000);
  me->set("kee",2000);
  me->set("sen",2000);
  call_out("destruct_me",5,me);

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  king2->announce_success();
}

void destruct_me (object me)
{
  message_vision ("一道金光照住$N，将$N唰地一声收去。\n",me);
  message_vision ("天上远远传来文殊菩萨的笑声。\n",me);
 
  destruct (me);   
}

