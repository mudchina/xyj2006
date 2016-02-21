void do_kill(object who,object me);

void init()
{
   object me = this_object(),who = this_player();

  if( who->query("huoyan/bgl")=="done" &&
       who->query("dntg/huoyan") != "done" ){
   call_out("do_kill",0,this_player(),this_object());
   }
}

void kill_ob(object ob)
{
   object me  = this_object();

   if(!me->query_temp("my_killer") )me->set_temp("my_killer",ob);
   if((object)me->query_temp("my_killer") != ob) me->set_temp("killer_chg",1);
   ::kill_ob(ob);
}

void unconcious()
{
   die();
}

void die()
{
   object me = this_object(),ob;

   if(!ob=me->query_temp("my_killer")) return ::die();
   if(me->query_temp("killer_chg")) return ::die();
   if( !ob->query("huoyan/lingguan_killed")) ob->set("huoyan/lingguan_killed",0);
   ob->add("huoyan/lingguan_killed",1);
   ::die();
}

void do_kill(object who, object ob)
{
   if(!random(4))
   message_vision("$n对$N嘿嘿冷笑了两声:不知天高低厚的东西,竟然敢闯灵霄殿!\n",who,ob);
   ob->kill_ob(who);
   who->kill_ob(ob);
   return;
}
