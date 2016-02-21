#include <ansi.h>

inherit NPC;

void create()
{
  set_name("太子", ({"tai zi", "zi", "prince"}));
  set ("long", "乌鸡国的王太子，成人之后不再常进宫，常以狩猎为乐。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 20);
  set("combat_exp", 300000);
  set_skill("blade", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("unarmed", 90);
  set_skill("force", 90);
  set_skill("changquan", 90);
  set_skill("wuhu-blade", 90);
  set_skill("lengquan-force", 90);
  set_skill("yanxing-steps", 90);
  map_skill("blade", "wuhu-blade");
  map_skill("unarmed", "changquan");
  map_skill("dodge", "yanxing-steps");
  map_skill("parry", "wuhu-blade");
  set("max_sen", 400);
  set("max_kee", 700);
  set("max_force", 800);
  set("force", 1000);
  set("force_factor", 45);
  set("idle",1);		//平常都是发呆状态
  setup();
 
  carry_object("/d/obj/weapon/blade/jindao")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
          if( query("idle")>0) 
   	    {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
 	    }
        }
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "yu gui")
    return 0;
  message_vision ("只看见$N脸色一变，高声叫道："+
                  "“贼人！吾家珍国宝何时落入你手中！”\n",me);

  return 1;
}

/*
void refuse_it (object me, object who, object ob)
{
  message_vision ("$N看见$n脸色一变，高声叫道："+
                  "“贼人！吾家珍国宝何时落入你手中！”\n",me,ob);
  message_vision ("$N怒发冲冠，大喝一声要杀死$n！\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
  destruct (ob);
}

void accept_it (object me, object who, object ob)
{
  message_vision ("$N看见$n脸色一变，禁不住叫道："+
                  "“恩人！此乃吾家珍国宝也！”\n",me,ob);  
  message_vision ("$N涕泪皆下。\n",me);
  call_out ("give_jing",2,me,who);
  destruct (ob);
}

void give_jing (object me, object who)
{
  object ob = new ("/d/qujing/wuji/obj/jing");
  message_vision ("\n$N对$n说道：“恩人，我身边亦有一宝，请笑纳！”\n",me,who);   message_vision ("\n说着$N取出一匣子，拿出一小瓶来。\n",me,who);  
  ob->move(me);
  me->command_function("give "+who->query("id")+" jing");
}
*/

void greeting(object ob)
{
   object me=this_object();
   mixed name;

   if( !ob || !visible(ob) || environment(ob) != environment() ) return;
   if( ob->query("obstacle/qujing")!="ren")return ;
   if( me->query("idle")==2)
     {
     command_function("say 师傅说的极是,恳请救救我父王吧,"
		+"我已经与那看守后花园的宫女说过了\n"); 
     ob->set_temp("obstacle/have_saied",1);     
     set("idle",0);
     return ;
     }       

   if( ob->query_temp("obstacle/have_gui")!=1)return ;
	//必须把玉圭给取经人才可以见太子	
   name=ob->query_temp("apply/name");
   if (sizeof(name)==0)return ;
   if( name[0]!="山鸡")return ;
   
   switch( random(3) ) 
     {  
     case 0:
       message_vision(RED "$N忽然拔箭怒射,一只箭直向$n飞了过来\n" NOR,me,ob);
       if (ob->query_skill("dodge")<20)
         {
	 if (random(20)>ob->query_skill("dodge"))
           {
           message_vision("只怕$N是闪不过去了\n",ob);
           ob->die();		//这样死是不是太残酷了些
	   return ; 
           }
         }
       me->command_function("follow "+ob->query("id"));
       me->set_leader(ob);
       set("idle",0);   
       break;
     }
}

