//puti.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int cure_longear();
int begin_go();
int bian_yuan();
int fly_sea();
int ask_longjin();
int ask_pansi();

void create()
{
       set_name(HIW"ÆÐÌá×æÊ¦"NOR, ({"master puti","puti", "master"}));
       set("long", "´ó¾õ½ðÏÉÃ»¹¸×Ë£¬Î÷·½ÃîÏà×æÆÐÌá\n");
       set("title", HIC"Ð±ÔÂÈýÐÇ"NOR);
       set("gender", "ÄÐÐÔ");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÀÏÊ¦×æ");
       set("per", 26);
	set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ð¾¦·É»ðÑæ£¬³¤Ä¿¹ýÃ¼ÉÒ¡£");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 10000000);

       set_skill("literate", 180);
       set_skill("unarmed", 180);
       set_skill("dodge", 180);
       set_skill("parry", 180);
	set_skill("stick", 200);
	set_skill("sword", 180);
	set_skill("liangyi-sword", 180);
	set_skill("spells", 200);
	set_skill("dao", 180);
	set_skill("puti-zhi", 180);
	set_skill("wuxiangforce", 200);
	set_skill("force", 200);
	set_skill("qianjun-bang", 180);
	set_skill("jindouyun", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );
    set("inquiry",([
    "ÁéÌ¨¹ÛÀñ": (: begin_go :),
    "°ËÏÉ": (: fly_sea :),
    "×ÏÏ¼": (: ask_pansi :),
    "ÇàÏ¼": (: ask_pansi :),
    "×ÏÏ¼ÏÉ×Ó": (: ask_pansi :),
    "ÇàÏ¼ÏÉ×Ó": (: ask_pansi :),
    "Áú½î": (: ask_longjin :),
	"Ë³·ç¶ú": (: cure_longear :),  
	"ËãÃüÏÈÉú": (: bian_yuan :),  
	"Ô¬ÊØ³Ï": (: bian_yuan :),  
]));
create_family("·½´çÉ½ÈýÐÇ¶´", 1, "À¶");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/lingtai/obj/putibang")->wield();
}

void init()
{
        object me;
    me=this_player();

        ::init();
        
	   if (me->query("fangcun/panlong_accept")=="done")
		   return;
       if (me->query("fangcun/panlong_nowaylingtai"))
		   return;

	   if (me->query("fangcun/panlong_accept")=="begin")
	{
		call_out("panlong_accept",2,me);
		return;
	}
	   
	   
	   if ((me->query("fangcun/panlong_qiansi_finish")==1)&&(!me->query("fangcun/panlong_noway")))
		{
                
			if ((me->query("fangcun/panlong_visite")>=1) && (me->query("fangcun/panlong_visite")<11))
			{
				call_out("begin_visite2",2);
			    return;
			}
			
			if (me->query("fangcun/panlong_visite")>=11)
	      {
            command("say Í½¶ù£¬ÄãµÄÊý¾Ý³öÎÊÌâÁË£¬×îºÃÕÒ¾ÅÌì£¨£ô£á£ë£å£©ÁË½âÒ»ÏÂÇé¿ö\n");
			me->move("/d/wiz/outjail");
            me->save();
			 return;
		  }
				remove_call_out("greeting");
                call_out("greeting", 2, me);
        
	     return;
		 }
    
		

}

int accept_object(object me, object ob)
{
  if ((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))
	{	 
	 if (ob->query("id") == "renshen guo")
	{
	 command ("nod "+me->query("id"));
      command ("say ºÇºÇ£¬Í½¶ùÕæÊÇÐÁ¿àÁË£¡");
      me->delete("fangcun/panlong_nowaywzg2");
      call_out("destroy", 1, ob);
      return 1;
	}
	}
return 0;
}

int begin_go()
{
	object me,ob;
    int visite;
	me=this_player();
	ob=this_object();
  
   if (me->query("fangcun/panlong_accept")=="done")
	{
        command("say " + RANK_D->query_respect(me) + "£¬ÄãÒÑ¾­ÁìÎòÁËÅÌÁú°ËÊ½£¬»¹À´¸ÉÊ²Ã´£¡\n");
		return 0;
	}

   if (me->query("family/family_name")!="·½´çÉ½ÈýÐÇ¶´")
      return 0;
   
  
   if (me->query("fangcun/panlong_nowaylingtai"))
	{
        command("say " + RANK_D->query_respect(me) + "£¬ÄãÒÑ¾­ÑûÇë¹ýÒ»´ÎÁË£¬Õâ¸ö¶ÍÁ¶»ú»á»¹ÊÇÈÃ¸ø±ðÈË°É£¡\n");
		return 0;
	}

	if (me->query("betray/count"))
   {
     me->delete("fangcun");
     command("say Í½¶ù£¬ÄãÅÐÊ¦ºóÀ´Í¶ÎÒ·½´çÉ½£¬ÕâÅÌÁú°ËÊ½ÄãÊÇÑ§²»»áµÄ£®\n");
	 return 0;
   }

   if (!me->query("fangcun/panlong_visite"))
	return 0;
//   sscanf(me->query("fangcun/panlong_visite"),"%d",visite);
   

		if (me->query("fangcun/panlong_visite")<=3)
	       {
	        command("say Í½¶ù£¬ÄãËùÑûÇëµ½µÄÃÅÅÉËÆºõÌ«ÉÙ£¡\n");
            return 1;
		   }     	
	    	
       visite=me->query("fangcun/panlong_visite");
       me->set_temp("panlong_visite",visite);
		   		
		if (me->query("fangcun/panlong_nowayshushan"))
			me->add_temp("panlong_visite",-1);
     	if (me->query("fangcun/panlong_nowayputuo"))
			me->add_temp("panlong_visite",-1);
     	if (me->query("fangcun/panlong_nowaymoon"))
			me->add_temp("panlong_visite",-1);
     	if (me->query("fangcun/panlong_nowaylonggong"))
			me->add_temp("panlong_visite",-1);
     	if (me->query("fangcun/panlong_nowayjjf"))
			me->add_temp("panlong_visite",-1);
     	if (me->query("fangcun/panlong_nowaywzg1"))
			me->add_temp("panlong_visite",-1);
        if (me->query("fangcun/panlong_nowaywzg2"))
			me->add_temp("panlong_visite",-1);
		if (me->query("fangcun/panlong_nowaywzg3"))
			me->add_temp("panlong_visite",-1);
        if (me->query("fangcun/panlong_nowaypansi"))
			me->add_temp("panlong_visite",-1);
		if (me->query("fangcun/panlong_nowayhell"))
			me->add_temp("panlong_visite",-1);
	   if (!me->query("fangcun/panlong_times"))
            me->set("fangcun/panlong_times",1);
	       else
	       {
	         me->set("fangcun/panlong_nowaylingtai",1);
		   }
       if (me->query_temp("panlong_visite")<=4)
	       {
     		  me->delete("fangcun");
			  command("say ÄæÍ½£¬Äã»¹ÓÐÁ³»ØÀ´£¡\n");
	       	  me->set("fangcun/panlong_nowaylingtai",1);

            return 0;
		   }     	
		      
		
		   call_out("finish_visite",1,me);
return 1;
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ÎÒÃÇÐÞÕæÖ®Ê¿×îÖØµÄ¾ÍÊÇµÀÐÐ£¬" + RANK_D->query_respect(ob) + "»¹Ðè¶à¼ÓÅ¬Á¦²ÅÄÜÔçÎò´óµÀ¡£\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "·´¸´ÎÞ³££¬ÀÏ·ò²»Ô­ÔÙÊÕÄãÎªÍ½ÁË£¡\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 35) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "ÎòÐÔÌ«µÍ£¬¿ÖÅÂÊÕÁËÄãÒ²ÄÑÓÐ×÷Îª£¡\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 120 ) {
	command("say ÕâÎ»" + RANK_D->query_respect(ob) + "¶ÔÎÒµÀ¼ÒÏÉ·¨Áì»á»¹²»¹»Éî£¬ÏÖÔÚÊÕÄãÒ²ÊÇÃãÎªÆäÄÑ£¬²»Èç×÷°Õ£¡\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say ÀÏ·ò²»ÊÕÍâÃÅµÜ×Ó£¬" + RANK_D->query_respect(ob) + "»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

int accept_fight(object me, object ob)
{	ob=this_player();
	command("say " + RANK_D->query_rude(ob) + "É±ÐÄÌ«ÖØ£¬¿Ö»ö²»¾ÃÒÑ£¡\n");
	return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\nÆÐÌá×æÊ¦Î¢ÖåÃ¼Í·£¬µÀ£ºÕâØË¹ûÊÇ¸öÌì³ÉµØ¾ÍµÄ£¡\n\n", environment());
        command("sigh");
        message("sound", "\nÆÐÌá×æÊ¦ÉíÐÎÒ»×ª£¬»¯×öÇàÑÌ×ßÁË¡£¡£¡£\n\n", environment());
        }

        destruct(this_object());
}

int fly_sea()
{
      object me;
    me=this_player();
	  if (me->query("fangcun/panlong_wzg")!="begin")
		  return 0;
	message_vision("\nÆÐÌá×æÊ¦ÆþÖ¸Ò»Ëã£¬Ð¦µÀ£ºÄÇÕòÔªÀÏµÀÄÄÀïÊÇ²»Öª°ËÏÉËùÔ¸£¿°ËÏÉËäµÃµÀ¶àÔØ£¬ÆäÌ°Íæ±¾ÐÔÄÑ¸Ä£¬
	                Îå×¯¹ÛÖ÷ÑµÍ½¼«ÑÏ£¬Ö»ºÃ¼Ù×°²»Öª£¬Ïë½èÎÒÍ½¶ùÖ®ÊÖÔ²ËûÍ½ËïÃÇÒ»¸ö
		        ÐÄÔ¸£®ÉµÍ½¶ù£¬ÄãÈ¥ÎÊÎÊ°ËÏÉ"+HIY"ÖØÓÎ¶«º£"+NOR"Ö®ÊÂ£¬±ã¿ÉÖªµÀËûÃÇËùÏëÁË£®\n\n",me);
	me->set_temp("wzg_baxian","go");
	return 1;
}

int ask_longjin()
{
      object me;
    me=this_player();
    if ((me->query("fangcun/panlong_hell_18")=="done")&&(me->query("fangcun/panlong_hell_longjin")=="begin"))
	{
			message_vision("\nÆÐÌá×æÊ¦ÂÔµãÁËµãÍ·µÀ£ºÍ½¶ù£¬ÕâÁú½î¸ÕÈá¼æ¹Ë£¬¼áÈÍ²¢´æ£¬ÄËÊÇÖÆ±Þ×ÓµÄÉÏºÃ²ÄÁÏ£¬Ö»²»¹ýÃ¿ÌõÁúÉí
	              ÉÏÒ²²ÅÒ»ÌõÖ÷½î¿ÉÒÔ¶ÍÔìÄÇÑÖÂÞµØ¸®µÄÉñ±ø--¸¿ÁúË÷¡£"+NOR"ºÎ¿ö£¬ÁúÈôÊ§Æä½î£¬ÑÉ
	              ÄÜ´æ»î£¿ÓûµÃÁú½î±ØÏÈÃðÆäÉí¡£Í½¶ù£¬Äã¿É½ô¼Ç"+HIY"ÈôÉ±¶ñÁú£¬ÔòÎªÃñ³ýº¦£¬Èô´í
                      É±ÉÆÁú£¬ÔòÊÇÀÄÉ±ÎÞ¹¼£¬ÎªÎÒÏÉ¼ÒËù²»³Ü£®\n\n"NOR,me);
	        return 1;
	}
    return 0;
}

int ask_pansi()
{
	object me;
    me=this_player();
	if (me->query("fangcun/panlong_nowaypansi"))
	{
			message_vision("\nÆÐÌá×æÊ¦ÑöÌì³¤Ì¾Ò»ÉùµÀ£ºÄÇÇàÏ¼ºÍ×ÏÏ¼Ô­ÊÇÈçÀ´·ð×æÈÕÔÂÃ÷µÆÉÏ²øÈÆÔÚÒ»ÆðµÄÁ½¸ùµÆÐ¾¡£Òò½ãÃÃÁ©²»ºÏ£¬
			Ë½ÌÓÏÂ½çºóÒ»Ö±Ïà»¥Õù¶·£¬ÊÂµ½Èç½ñÒ²ÊÇÌìÒâÈç´Ë£¬°¦¡£¡£¡£¡£¡£¡£\n\n",me);
    		command ("sigh " + me->query("id"));
			return 1;
	}
	if (me->query("fangcun/panlong_pansi")=="done")
	{
			message_vision("\nÆÐÌá×æÊ¦Î¢Ð¦×ÅµãÍ·µÀ£ºÄÇÇàÏ¼ºÍ×ÏÏ¼Ô­ÊÇÈçÀ´·ð×æÈÕÔÂÃ÷µÆÉÏ²øÈÆÔÚÒ»ÆðµÄÁ½¸ùµÆÐ¾¡£Òò½ãÃÃÁ©²»ºÏ£¬
                      Ë½ÌÓÏÂ½çºóÒ»Ö±Ïà»¥Õù¶·¡£Í½¶ù£¬Äã×îÖÕ»¯½âËý½ãÃÃ¶þÈËÇ§ÄêÔ¹ºÞ£¬Ê¹Æä¶þÈË
                      µÃÒÔð§ÒÀÎÒ·ð£¬ÊµÄË¹¦µÂÎÞÁ¿¡£ÖÁÓÚÎª´ËµÃ×ïÌì½«Ò²²»±ØÌ«·ÅÔÚÐÄÉÏ£¬·²´óÊÂ
                      ²»¾ÐÐ¡½Ú£¬Èç´Ë²ÅºÏÎªÊ¦µÄÐÔ×Ó¡£\n\n",me);
    		command ("haha ");
			return 1;
	}
	return 0;
}

int cure_longear()
{
      object me;
    me=this_player();
	  if (!me->query_temp("putuo/longear"))
		  return 0;

		command ("haha " + me->query("id"));
		call_out("cure_longear1",3);
		return 1;
}

void cure_longear1()
{
   	object me;
    me=this_player();

	message_vision("\nÆÐÌá×æÊ¦¹þ¹þ´óÐ¦µÀ£ºÉµÍ½¶ù£¬¶¨ÊÇÄÇË³·ç¶úÀÏÃ«²¡ÓÖ·¸ÁË£¬ÕâÓÐºÎÄÑ£¿"+HIY"¹·Î²²Ý"+NOR+""+"ÇåÈÈÏûðáÓë"+HIY"Å£»Æ
	            "+NOR""+"Ö®ìî·ç½â¶¾×îÒËÓÃÓÚ×ó¶úÌÛÍ´£®"+HIY"×Ï¾£"+NOR""+"»îÑªÏûÖ×¸¨ÒÔ"+HIY"³ÂÆ¤"+NOR""+"Ë³Æø»¯ÌµÖ®¹¦Ð§ÖÎ
                    ÓÒ¶ú¼²¿ÉÒ©µ½²¡³ý£®\n",me);
}

int bian_yuan()
{
	object me;
    me=this_player();
	  if (me->query_temp("fangcun/panlong_longgong_yuanshoucheng")!="begin")
		  return 0;
    command ("hmm " + me->query("id"));
	call_out("bian_yuan1",3);
    return 1;
}

void bian_yuan1()
{
   	object me;
    me=this_player();
	message_vision("\nÆÐÌá×æÊ¦ÂÔÓÐËùË¼µÀ£ºÍ½¶ù£¬·²ÊÂ¶¼ÊÂ³öÓÐÒò£¬¶«º£ÁúÍõËµËãÃüÏÈÉúÉè¼ÆÏÝº¦ãþºÓÁúÍõ
                    ÄËÖÁÓñµÛ½µÖ¼Õ¶Ö®£¬Äã¿ÉÈ¥ÎÊ¹ýÄÇËãÃüÏÈÉú"+HIY"ãþºÓÁúÍõ"+NOR"Ö®ÊÂ£¬ÌýËû
	            ÈçºÎËµ·¨£¿³ýÐ°·öÕý£¬ÌæÌìÐÐµÀÄËÎÒµÀ¼Ò×ÚÖ¼£¬µ«ÇÐ²»¿ÉÍý×öÍÆ
	            ¶Ï£¬ÎóÉËºÃÈË£®\n\n",me);
}

void greeting(object ob)
{
        command ("nod " + ob->query("id"));
		if( !ob || !visible(ob) || environment(ob) != environment() ) return;
                message_vision("\n\n"NOR,ob);
				command ("say " + "¹ÔÍ½¶ù,×ÔÄãÊ¦ÐÖËïÎò¿ÕÎò³öÇ§¾ù°ô·¨¾øÑ§[ÅÌÁú°ËÊ½]ÒÔºóÇ§ÄêÀ´,ÎÒÁéÌ¨
              ·½´çÉ½ÎÞÒ»µÜ×ÓÄÜ²½Æäºó³¾,½ñÈÕµÃ¼ûÎÒ"+ob->query("name")+"Í½¶ùÎòÐÔÈç´ËÖ®¼Ñ,µ±ÕæÊÇÎÒ
              ·½´çÉ½µÄ¸£·Ö£¡ÎÒÕâ°ãÄê¼ÍÄÜµÃÄãÕâÍ½¶ù,ÀÏÐàÒ²ÐÄÂúÒâ×ãÒÑ£®\n\n" );
	call_out("begin_visite", 1, ob);
}

void begin_visite(object me)
{
command("say " + me->query("name") + ",ÄãÌýºÃÁË[ÅÌÁú°ËÊ½]ÄËÎÒ·½´çÉ½Ç§¾ù°ô·¨ÖÐµÄÖÕ¼«¾øÕÐ,ÊÇÒÔÐ¡ÎÞÏà
              ¹¦×÷Îª¸ù»ù,µÀ¼ÒÏÉ·¨Îª¸¨Öú,ÓëµÐÈËÕ½¶·ÖÐÔËÕæÆøÓÚ°ô·¨ÖÐ,Ò»¿ÚÆøÁ¬³ö
              °ËÕÐ,ÕÐÕÐÐ×ÃÍ.ÈçÄãÈÕºóÄÜÓÐ´ËÔì»¯Ñ§³É[ÅÌÁú°ËÊ½]Ò²²»ÒªÍü¼Ç½µÑý³ýÄ§
              ,ÌæÌìÐÐµÀ,Õü¾ÈÌìÏÂ²ÔÉúµÄ×öÈËÖ®µÀ£¡\n\n");
     call_out("begin_visite1", 1, me);
}

void begin_visite1(object me)
{
	 
      command("say ÏÖÔÚÄã¾ÍÉÏÂ·È¥ÑûÇë¸÷Î»ÏÉ¼ÒµÄÕÆÃÅÇ°À´ÎÒ¡°ÁéÌ¨¹ÛÀñ¡±,½ìÊ±ÎÒµ±ÖÚ´«
	      ÊÚÄã[ÅÌÁú°ËÊ½],ÖÁÓÚÄÜ·ñÁìÂÔÆäÖÐ°ÂÃî¾ÍÈ«¿´ÄãµÄÔµ·ÖÁË,È¥°É,È¥°É£¡\n");
      me->set("fangcun/panlong_visite",1);
}

void begin_visite2()
{
	command("say ¹ÔÍ½¶ù£¬¿ÉÓöµ½Ê²Ã´ÄÑ´¦£¿");
}

void finish_visite(object ob)
{
   command("smile");
   command("say ¹ÔÍ½¶ù,ÊÂÇé¶¼°ìÍêÁË,ÂíÉÏµ½ÕýÔºÀ´.");
   message_vision(HIW"\nÆÐÌá×æÊ¦ËµÍê¾Í²»¼ûÁË£¡\n"NOR,ob);
   this_object()->move("/d/lingtai/inside1");
  // ob->delete("fangcun/panlong_visite");
   ob->set("fangcun/panlong_accept","begin");
   ob->delete("fangcun/panlong_qiansi");
}

void panlong_accept(object me)
{
 int pass;
 me->delete_temp("panlong_nopass");
 me->delete_temp("master");
 me->delete_temp("take_panlong");
 if ((present("bai mei"))&&(!userp(present("bai mei"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/shushan","come");
	}
if ((present("xi wangmu"))&&(!userp(present("xi wangmu"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/moon","come");
	}
if ((present("lao ren"))&&(!userp(present("lao ren"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/jjf","come");
	}
if ((present("guanyin pusa"))&&(!userp(present("guanyin pusa"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/putuo","come");
	}
if ((present("ao guang"))&&(!userp(present("ao guang"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/longgong","come");
	}
if ((present("zhenyuan daxian"))&&(!userp(present("zhenyuan daxian"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/wzg","come");
	}
if ((present("dizang pusa"))&&(!userp(present("dizang pusa"))))
    {
	 me->add_temp("take_panlong",1);
	 me->set_temp("master/hell","come");
	}
if (!me->query("fangcun/panlong_nowaywzg3"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowaywzg2"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowaywzg1"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowayshushan"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowaylonggong"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowaypansi"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowayhell"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowayputuo"))
	 me->add_temp("take_panlong",1);
if (!me->query("fangcun/panlong_nowaymoon"))
	 me->add_temp("take_panlong",1);


pass=random(me->query_temp("take_panlong"));
if (pass<=7)
	me->set_temp("panlong_nopass",1);
me->set_temp("pass/total",me->query_temp("take_panlong"));                          // waring del
me->set_temp("pass/random",pass);                          // waring del
 message("chat",HIC+"¡¼"+HIW+"Î÷ÓÎ¼Ç2006"+HIC+"¡½ÆÐÌá×æÊ¦(Master puti)£ºÎÒÍ½¶ù"+me->query("name")+"Îò³öÅÌÁú¾«Òª£¬½ñÈÕÑûÇë¸÷Î»ÏÉ¼ÒµÀÓÑÍ¬À´ÁéÌ¨¹ÛÀñ£¡\n\n"NOR,users());
message_vision(HIC"\nÖÚÈË¶¼ÏòÆÐÌá×æÊ¦±§È­¼ûÀñ£®\n\n"NOR,me);

message_vision(HIC"\nÆÐÌá×æÊ¦×ª¹ýÉíÀ´¶Ô$NµÀ£º¹ÔÍ½¶ù£¬ÅÌÁú°ËÊ½Ö¼ÔÚÎò£¬¶ø²»ÊÇÑ§£®Äã×¢Òâ¿´ºÃÁË£®\n"NOR,me);
call_out("direct_panlong",5,me);
}

void direct_panlong(object me)
{
	message_vision(HIY"\nÆÐÌá×æÊ¦Ò»°ÚÊÖÖÐÆÐÌáÕÈ£¬¶¸È»¼äÒ»¹É¾¢Æø´ÓÆÐÌá×æÊ¦µÄµÀÅÛÖÐÐÚÓ¿³å³ö£®\n"NOR,me);
    message_vision(HIY"\n\nÆÐÌá×æÊ¦¶ÙÊ±»¯×÷Ò»ÍÅ½ð¹â£¬ÎèÆðÇ§¾ù°ô·¨£¬ÉíÐÎÁé¶¯£¬°µÔÌÉ±»ú£¬ÃÍÈ»¼äÒ»ÉùÇåÐ¥£¬Õð¶úÓûÁû£®\n"NOR,me);
	message_vision(HIY"\n\nÐ¥Éù³õÆð£¬ÆÐÌá×æÊ¦¾¹Ê¹ÆÐÌáÕÈµç¹âÊ¯»ð°ãµÄÁ¬¹¥°ËÕÐ£¬ÄÇ½ð¹âºÃËÆ¡°ÅÌÁú³ö²×º££¬Ì¤ÔÆÐ¥¾ÅÌì¡±£®
	ÆøÊÆÖ®Ëù¼°£¬É²Ê±ÕýÔºÖÐÂäÒ¶¾¡È¥£¬Ê¯µÊÊ¯×À±»ÅÌÁú¾¢ÆøÕðËé³ÉÎÞÊýÐ¡¿é£¬$NÄÚÁ¦²»¼°£¬
        ¾¹Ò²±»ÅÌÁú¾¢ÆøËùÉË£®\n"NOR,me);
    me->set("eff_kee",(me->query("eff_kee"))/20);
	me->set("kee",(me->query("kee"))/10);
	me->set("eff_sen",(me->query("eff_sen"))/20);
	me->set("sen",(me->query("sen"))/10);
    message_vision(HIY"\nÆÐÌá×æÊ¦ÊÕ×¡ÕÐÊ½£¬ÖÚÏÉ¼Ò¾ùÔÞÌ¾½ÐºÃ£®\n"NOR,me);
	message_vision(HIR"\n\n$NÊÜÁËÖØÉË£¬Ö§³Ö²»×¡£¬Ò»ÏÂ×Ó×øµ¹ÔÚµØ£®\n"NOR,me);
	message_vision(HIC"\nÆÐÌá×æÊ¦×ßµ½$NÃæÇ°ºÍÉùµÀ£ºÍ½¶ù£¬ÄãºÃºÃÌå»áÒ»ÏÂ£®¿´¿´ÄÜÎò³öµãÊ²Ã´À´£®\n"NOR,me);
	call_out("direct_panlong1",10,me);
}

void direct_panlong1(object me)
{
	   message_vision(HIC"\n\n\nÆÐÌá×æÊ¦¹°ÊÖ±§È­¶Ô¸÷ÅÉÕÆÃÅµÀ£º½ñÈÕÅÌÁú¹ÛÀñµ½´ËÎªÖ¹£¬¸÷Î»Ô¶µÀ¶øÀ´»¹Çëµ½Æ¶µÀÉ½ÖÐÒ»ÓÎ£¬Ò²ÈÃÆ¶µÀÒ»¾¡µØÖ÷Ö®ÒË£®\n"NOR,me);
   if (me->query_temp("master/shushan"))
	{
            message_vision(HIC"\n°×Ã¼(Bai mei)£ººÃ¸öÅÌÁú£¬ÆøÊÆÖ®°ÔµÀ£¬ÌìÏÂ¾øÕÐÎÞÒ»ÄÜ¼°£®\n"NOR,me);
        destruct(present("bai mei"));
	}
   if (me->query_temp("master/moon"))
	   {
          message_vision(HIC"\nÎ÷ÍõÄ¸(Xi wangmu)£º¶àÄê²»¼û£¬ÆÐÌá´óÊ¦ÒÀÈ»Íþ·ç²»¼õµ±Äê£¬½ÐÈËºÃÉúÅå·þ£®\n"NOR,me);
          message_vision(HIC"ÆÐÌá×æÊ¦(Master puti)£ºÍõÄ¸ÄïÄï¹ý½±ÁË£®\n"NOR,me);
		  destruct(present("xi wangmu"));
		}
   if (me->query_temp("master/jjf"))
	{   
       message_vision(HIC"\n°×·¢ÀÏÈË(Lao ren)£º½ñÈÕÄÜÔÙ¼ûÆÐÌá´óÊ¦µÄÅÌÁú°ËÊ½£¬ÕæÊÇ²»Í÷´ËÐÐÑ½£®\n"NOR,me);
	   destruct(present("lao ren"));
	}
   if (me->query_temp("master/putuo"))
	{
	   message_vision(HIC"\n¹ÛÒôÆÐÈø(Guanyin pusa)£ºÄÑ¹ÖÄÇºï×ÓÒ»ÌõÈçÒâ½ð¹¿°ô´óÄÖÌì¹¬Ö®Ê±£¬Ò»ÕÐÅÌÁúÖÚÌì½«ÎÞÈËÄÜµ²£®\n"NOR,me);
	   destruct(present("guanyin pusa"));
	}
   if (me->query_temp("master/longgong"))
	{
	   message_vision(HIC"\n°¾¹ã(Ao guang)£ºÄÇ¶¨º£ÉñÕëÌú£®£®£®£®£®£®°¦£®£®£®£®£®£®ÐÒ¿÷¾ÍÕâÃ´Ò»Ö»ºï×Ó£®\n"NOR,me);
	   destruct(present("ao guang"));
	}
   if (me->query_temp("master/wzg"))
	{
	   message_vision(HIC"\nÕòÔª´óÏÉ(zhenyuan daxian)£º¹þ¹þ¹þ¹þ£¬ÎÒÄÇ½á°ÝÐÖµÜ±¾ÊÂ¿É²»Ð¡Ñ½£®\n"NOR,me);
	   destruct(present("zhenyuan daxian"));
	}
	if (me->query_temp("master/hell"))
	{
	   message_vision(HIC"\nµØ²ØÍõÆÐÈø(Dizang pusa)£ºÁéÌ¨µÜ×ÓÕæÊÇÓ¢ÐÛ±²³ö£¬´ú´úÓÐÄÜÈË£®\n"NOR,me);
	   destruct(present("dizang pusa"));
	}
       message("chat",HIC+"\n\n¡¼"+HIY+"Î÷ÓÎ¼Ç2006"+HIC+"¡½ÆÐÌá×æÊ¦¹þ¹þ´óÐ¦ÁË¼¸Éù¡£\n"NOR,users());
	message_vision(HIC"\nÆÐÌá×æÊ¦(Master puti)£º¸÷Î»µÀÓÑ£¬ÎÒÃÇÔÝÇÒ²»ÌáÕâºïÍ·£¬ÀÏµÀÕâ¾ÍÍ·Ç°ÁìÂ·´ø´ó¼Ò¿´¿´ÎÒ·½´çÉ½µÄ¾°ÖÂÈçºÎ£¿\n"NOR,me);
	message_vision(HIY"\nÖÚÈËÒ»Í¬ÐÀÈ»±§È­µÀ£ºÇë£®\n"NOR,me);
   message_vision("\n\n$NÅÌÍÈÔÚµØµÈºòÊ¦¸µÊ¾ÏÂ£®Í»È»¶ú±ßÇáÇá´«À´ÆÐÌá×æÊ¦µÄÉùÒô£º\n"NOR,me);
   message_vision(HIR"\nÍ½¶ù£¬ÎÒ´øÖÚÈËÀë¿ª£¬ÎÒËÍÄãµ½Ð¡ÊÒ¾²ÐÄÇ±Ë¼£¬ÄÜ·ñÕÆÎÕ"+HIY"ÅÌÁú°ËÊ½ "+HIR"¾ÍÔÚ´ËÒ»¾Ù£®\n"NOR,me);
   message_vision(HIB"\n$NÅÌÍÈ±ÕÄ¿¾²¾²µÄ»ØÏë¸Õ²ÅÊ¦¸µËùÊ¹µÄ"+HIY"ÅÌÁú°ËÊ½"+NOR"£®\n",me);
   me->start_busy(20);
   me->move("/d/lingtai/lou");
	call_out("direct_panlong2",15,me);
}

void direct_panlong2(object me)
{
   if (!me->query_temp("panlong_nopass"))
	{
	   message_vision(HIR"\n\n\n    $NÇ±Ë¼°ëÈÕ£¬Í»¾õÄÔÖÐÁéÆøËÄÆð£¬ÍðÈç×Ô¼ºÖÃÉíÓÚÒ»Æ¬¿ÕµØÊÖ³Ö"+HIY"½ð¹¿°ô"+HIR"£¬²»Í£ÐªµÄÊ¹³öÅÌ
Áú°ËÊ½£¬Ö±µ½»ëÉíº¹ÈçÓêÏÂ£¬°ëÉÎ$NÕö¿ªÑÛ¾¦£¬ÐÄÀïÈçº£Ð¥À´ÁÙÇ°°ãµÄÆ½¾²£¬ÖÕÓÚÕÆÎÕÁË"+HIY"ÅÌÁú"+HIR"¾ø¼¼£¡\n"NOR,me);
	   me->delete("fangcun");
	   me->set("fangcun/panlong_accept","done");
	   me->set("fangcun/panlong_qiansi_finish",1);
       present("master puti")->move("/d/lingtai/room");
	   return;
	}
   message_vision(HIR"\n\n\n$NÇ±Ë¼°ëÈÕ£¬Í·ÄÔÖÐÒ»Æ¬»ìÂÒ£¬Ö»ÒÀÏ¡¼Ç×¡Ê¦¸µËùÊ¹µÄµÄÕÐÊ½£¬ÖÕ²»ÄÜ»¯Îª¼ºÓÃ£®\n"NOR,me);
   present("master puti")->move("/d/lingtai/room");
   me->delete("fangcun/panlong_accept");
   if (me->query("fangcun/panlong_times"))
   {
	   me->delete("fangcun");
	   me->set("fangcun/panlong_qiansi_finish",1);
       me->set("fangcun/panlong_nowaylingtai",1);
   }
}

void destroy(object ob)
{
  destruct(ob);
}

ÿ
