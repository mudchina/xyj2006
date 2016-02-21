

void init()
{
   object me = this_object(),who = this_player();

  if( who->query("huoyan/bgl")=="done" &&
       who->query("dntg/huoyan") != "done" &&
       living(me)){
      me->kill_ob(who);
      who->kill_ob(me);
   }
}

void kill_ob(object ob)
{
   object me  = this_object();

   if(!me->query_temp("my_killer") )me->set_temp("my_killer",ob);
   if((object)me->query_temp("my_killer") != ob) me->set_temp("killer_chg",1);
   remove_call_out("hurting");
   call_out("hurting",3+random(3),me,ob);
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
   if( !ob->query("huoyan/tianwang_killed")) ob->set("huoyan/tianwang_killed",0);
   ob->add("huoyan/tianwang_killed",1);
   if(me->query("id")=="xusheng zhenjun")return ::die();
   message_vision("$NÏÅµÃ²Ö»ÊÌÓ×ßÁË£¡\n",me);
   destruct(me);
   return;
}




