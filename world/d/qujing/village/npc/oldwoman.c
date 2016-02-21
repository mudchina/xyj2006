//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("¸¾ÈË", ({ "woman", "fu ren"}));
   set("gender", "Å®ÐÔ" );
   set("age", 45);
   set("per",40);
   set("long","Ò»Î»²»Ê©Ö¬·ÛÓÌÃÀ£¬·çÁ÷»¹ËÆÉÙÄê²ÅµÄÃÀ¸¾¡£\n");
   set("combat_exp", 600+random(400));
   set("daoxing", 600+random(400));
   set("attitude", "friendly");
   set_skill("dodge", 10);
   set_skill("unarmed", 10);
   setup();
   carry_object("/d/qujing/dudi/obj/cloth")->wear();
   add_money("silver", 3+random(20));
}

void init()
{
        object ob = this_player();
        add_action("do_yes","yes");
	remove_call_out("checking");
        call_out("checking",1,ob);
}

void checking(object ob)
{	object me = this_object();
        if( ob->query("obstacle/village") == "done" )
                return;
        if( !ob->query("obstacle/liusha") )
                return;

        if( ob->query_temp("yao_killed") <3 
          && ob->query_temp("seen") )
                {
	message_vision(CYN"$N¶Ô$n¿à¿àµÄ°§ÇóµÀ£ºÈ¥°ïÎÒÉ±ÁËÄÇÐ©Ñý¹Ö°É¡£ºÃÂð£¿\n"NOR,me,ob);
        return;
                }
        if( ob->query_temp("yao_killed") 
        && ! ob->query_temp("cao_given") )
          {
        message_vision(CYN"$N¶Ô$nËµµÀ£ºÕâÎ»"+RANK_D->query_respect(ob)+"ÄÜ·ñÔÙ°ïÎÒÈ¥Ñ°ÕÒ"+RED"ÆßÒ¶ÇíÖ¥²Ý"NOR+CYN"£¿\n"NOR,me,ob);
        return;
          }
        message_vision(CYN"$N¶Ô×Å$nËµµÀ£ºÌýËµÕâÎ»"+RANK_D->query_respect(ob)+"ÊÇÈ¥Î÷ÌìÈ¡Õæ¾­µÄ£¬ÄÜ·ñ(yes)°ï¸öÃ¦ÄØ£¿\n"NOR,me,ob);
        
        ob->set_temp("womenask","yes");
        return;
}
int do_yes()
{	object ob=this_object();
	object me=this_player();
	if( me->query_temp("womenask")=="yes")
	{
	message_vision(CYN"$N¶Ô×Å$nµãµãÍ·µÀ£ºÔ¸ÎªÐ§ÀÍ¡£\n"NOR,me,ob);
	call_out("give_task",1+random(2),me,ob);
	return 1;
	}
	return 0;
}
	
int give_task(object me,object ob)
{
	tell_object(me,CYN"¸¾ÈË¶ÔÄãËµµÀ£ºÎÒÃÇ¼Ò±±ÃæÓÐÐ©Ñý¹ÖÔÚ×÷ÂÒ£¬²»ÖªÄãÄÜ·ñ°ïÎÒÉ±ÁËËûÃÇ°¡£¿\n"NOR);
	me->delete_temp("womenask");
	me->set_temp("seen",1);
	return 1;
}


int accept_object(object who,object ob)
{
      

         if( ob->name() == RED "ÆßÒ¶ÇíÖ¥²Ý" NOR )
                {
                if( !who->query_temp("yao_killed") )
                  {
                command("say Äã»¹ÊÇÏÈÈ¥°ïÎÒÉ±ÁËÄÇÐ©Ñý¹Ö°É¡£ºÃÂð£¿");
                return 0;
                  }
                command("smile");
                command("nod");
                who->set_temp("cao_given",1);
                this_object()->set_name("æêÉ½ÀÏÄ¸",({"lishan laomu","lao mu"}));
                call_out("pass",1,this_player());
                return 1;
                }
        return 0;
}

void pass(object ob)
{
  int i;
 if( ! ob->query_temp("yao_killed") )
     return;
  if(! ob->query("obstacle/liusha") )
  return;
 if (ob->query("combat_exp") < 10000)
    return;
  if (ob->query("obstacle/village") == "done")
    return;
  i = random(500);
  ob->add("obstacle/number",1);
  ob->set("obstacle/village","done");
       ob->add("daoxing",i+2000);
  command("chat "+ob->query("name")+"¾­×¡ÄÍÐÄÓëÓÂÆøµÄ¿¼Ñé£¡");
  message("channel:chat",HIY"¡¾¹ý¹ØÕ¶½«¡¿¹ÛÒôÆÐÈø(guanyin pusa)£º"+ob->name()+"´³¹ýÎ÷ÐÐÈ¡¾­[1;37mµÚ°Ë¹Ø£¡\n"NOR,users());
  tell_object (ob,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  ob->delete("seen");
  ob->save();
  destruct(this_object());
  return;
}
