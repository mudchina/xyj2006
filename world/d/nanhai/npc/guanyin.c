// guanyin.c ¹ÛÒôÆĞÈø
// By ¾ÅÌì(take) 


inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int begin_go();
int do_drop(object, object);

void create()
{
	set_name("¹ÛÒôÆĞÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
	set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ğÉí¡£Ã¼ÈçĞ¡ÔÂ£¬ÑÛËÆË«ĞÇ¡£À¼ĞÄĞÀ×ÏÖñ£¬
Ş¥ĞÔ°®µÃÌÙ¡£Ëı¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
	set("gender", "Å®ĞÔ");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "Æ¶É®");
	set("rank_info/respect", "ÆĞÈøÄïÄï");
	set("class", "bonze");
        	set("str",24);
	set("per",100);//means no rong-mao description.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 145);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

	set_skill("literate", 150);
	set_skill("spells", 200);
	set_skill("buddhism", 200);
	set_skill("unarmed", 150);
	set_skill("jienan-zhi", 150);
	set_skill("dodge", 180);
	set_skill("lotusmove", 180);
	set_skill("parry", 180);
	set_skill("force", 180);
	set_skill("lotusforce", 180);
	set_skill("staff", 180);
	set_skill("lunhui-zhang", 180);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
	}) );
	set("inquiry",([
      "ÁéÌ¨¹ÛÀñ"    : (: begin_go :),
      "¾»Æ¿": "Ç°Ğ©Ìì£¬¸£ĞÇ½èÎÒµÄ¾»Æ¿ÓÃ£¬µ½ÏÖÔÚÒ²Ã»ÓĞ»¹£¬ÄãÈ¥¿´¿´°É¡£" ]));



	//let's use cast bighammer to protect her...weiqi:)
	create_family("ÄÏº£ÆÕÍÓÉ½", 1, "ÆĞÈø");

	setup();
	carry_object("/d/nanhai/obj/jiasha")->wear();
	carry_object("/d/nanhai/obj/nine-ring")->wield();
}

void attempt_apprentice(object ob)
{
	if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say ÎÒ·ğÃÅÉñÍ¨¹ã´ó£¬" + RANK_D->query_respect(ob) + "Óû³ÉÕı¹û£¬ÏÈÈëÎÒÃÅ¡£\n");
		write("¿´Ñù×Ó¹ÛÒôÆĞÈø¶ÔÄãÎ´Ìê¶È³ö¼ÒÆÄÎª²»¿ì¡£\n");
		return;
	}	
	if (((int)ob->query_skill("buddhism", 1) < 100 )) {
		command("say " + RANK_D->query_respect(ob) + "²»ÔÚ·ğ·¨ÉÏ¿àĞŞ£¬¿ÖÅÂÄÑ³ÉÕı¹û¡£\n");
		return;
	}
	command("pat " + ob->query("id") );
	command("say ºÃ£¡Õâ²ÅÊÇÎÒ·ğÃÅµÄºÃµÜ×Ó¡£Ö»Òª¶à¼ÓÅ¬Á¦£¬¶¨¿ÉÔç³ÉÕı¹û¡£\n");

	command("recruit " + ob->query("id") );
	return;	
}
void die()
{
	int i;
	string file;
	object *inv;

        if( environment() ) {
        message("sound", "\n\n¹ÛÒôÆĞÈøÒ¡Í·Ì¾µÀ£º¸ÕÀëÃÔÕÏ£¬ÓÖÈëÄ§ÕÏ£¬ÊÀ¼ä¼²¿à£¬ºÎÈË¶ÈÖ®£¡\n\n", environment());
        command("sigh");
        message("sound", "\n¹ÛÒôÆĞÈø¼İÏéÔÆ£¬µÇ²ÊÎí£¬¾¶ÍùÎ÷·½È¥ÁË¡£¡£¡£\n\n", environment());
        inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("no_drop")) continue;
		do_drop(this_object(), inv[i]);
//		if (stringp(file = find_command("drop")) && 
//			call_other(file, "do_drop", this_object(), inv[i])) ;
	}
	}

	destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
            else {
                 message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n",
                 undefinedp(obj->query_temp("unit"))?
	                 "¸ö":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
           else {
             message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"ÒòÎªÕâÑù¶«Î÷²¢²»ÖµÇ®£¬ËùÒÔÈËÃÇ²¢²»»á×¢Òâµ½ËüµÄ´æÔÚ
		   ¡£\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
	die();
}

int accept_object(object me,object ob)
{       
	    string myname=RANK_D->query_respect(me), thing=(string)ob->query("id");
		object who;
        who=this_object();
      
	if (me->query("fangcun/panlong_putuo")=="begin")
	{
	  if (ob->query("name") == "¡¼µ¶·¨ÈëÃÅ¡½")
      {
      command ("nod");
      command ("say ÕâÊÇ³¤°²³ÇÀïÈıÁªÊé¾ÖµÄµ¶·¨ÈëÃÅ£¡");
      me->set_temp("putuo/basic_blade","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼È­·¨ÈëÃÅ¡½")
      {
      command ("nod");
      command ("say ÕâÊÇ³¤°²³ÇÀïÈıÁªÊé¾ÖµÄÈ­·¨ÈëÃÅ£¡");
      me->set_temp("putuo/basic_unarmed","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼µÀµÂ¾­¡½")
      {
      command ("smile");
      command ("say ÕâÊÇ³µ³Ù¹úÈıÇå¹ÛÄÚ²Ø¾­Â¥µÄµÀµÂ¾­»¹ÊÇÁéÌ¨·½´çÉ½µÄ¾­¸óÖĞµÄÊÕ²ØÄØ£¿");
     me->set_temp("putuo/daode","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼·üÄ§É½ĞÄ¾­¡½")
      {
      command ("ah");
      command ("say Õâ±¾¡¼·üÄ§É½ĞÄ¾­¡½ÔÌº¬×ÅÇóÊéÕß²»ÉÙµÄĞÄÑª,µÃÀ´Õâ±¾Êé×ÅÊµ²»Ò×£¡");
     me->set_temp("putuo/forcebook","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼Å®¶ù¾­¡½")
      {
      command ("nod");
      command ("say Õâ±¾¡¼Å®¶ù¾­¡½ÔÚÔÂ¹¬Á·¹¦·¿ÄËÎªÆäÅ®µÜ×Ó¶ÁÊéÊ¶×ÖÖ®ÓÃ£¡");
     me->set_temp("putuo/girlbook","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
      if (ob->query("name") == "¡¼ÇàÁ«½£Æ×¡½")
      {
      command ("nod");
      command ("say ÕâÊÇÊ«ÏÉÖ®Îï,Ö»ÅÂÊÇÓÃ¹ğ»¨¾Æ»»À´µÄ£¡");
     me->set_temp("putuo/jianpu","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼½ğ¸Õ¾­¡½")
      {
      command ("bow");
      command ("say ´ËÄËÎÒ·ğÈçÀ´Ö®´ó³É·ğ·¨,Ò»Ö±ÁôÔÚÄÏº£ÆÕÍÓÊéÔºÖĞ£¡");
     me->set_temp("putuo/jingang","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼¾ÉÊé¡½")
      {
      command ("nod");
      command ("say ÕâÊÇ³¤°²³Ç¶«,ÍûÄÏ½ÖÄÚµÄÎäÑ§Êé¼®,ÉÏÃæ¼ÇÔØÁËµ¶£¬¸«£¬²æ£¬´¸£¬ïµ£¬îÙ£¬Ç¹£¬ÕÈ£¬°ô£¬½£Ê®ÖÖ»ù±¾Îä¹¦£¡");
     me->set_temp("putuo/misc","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼ÎŞ×ÖÌìÊé¡½")
      {
      command ("nod");
      command ("say ´ËÄËÔ¬ÊØ³Ï´¦µÃÀ´µÄ·¨ÊõÒªÁì£¡");
     me->set_temp("putuo/nowords","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼¸ñ¶·ÃØ¾÷¡½")
      {
      command ("nod");
      command ("say "+RANK_D->query_respect(me)+ "°ïÖú¸ßÔ±Íâ³ıÈ¥Ç¿µÁ,Æ·ĞĞ¿É¼Î£¡");
     me->set_temp("putuo/parry_book","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼Ç§×ÖÎÄ¡½")
      {
      command ("nod");
      command ("say ÊÇÁéÌ¨·½´çÉ½¹ãôË×ÓµÀ³¤ÊÖÀïµÄ¡¼Ç§×ÖÎÄ¡½Âğ£¿");
     me->set_temp("putuo/qian","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼È­¾­¡½")
      {
      command ("nod");
      command ("say ÕâÊÇ³¤°²Îä¹İ·¶ÇàÆ½Ëù²Ø¸ñ¶·¼¼ÇÉ£®");
     me->set_temp("putuo/quanjing","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
      if (ob->query("name") == "¡¼Èı×Ö¾­¡½")
      {
      command ("nod");
      command ("say Õâ¡¼Èı×Ö¾­¡½Ò»ÊéÎÒÄÏº£ÆÕÍÓÊéÔº,³¤°²ÊéÉçÒÔ¼°ÔÂ¹¬Á·¹¦·¿¶¼ÊÕÓĞ´ËÊé,µ±ÕæÊÇÁ÷´«Éõ¹ã£®");
     me->set_temp("putuo/san","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	   if (ob->query("name") == "¡¼Ç¹·¨¼ò½é¡½")
      {
      command ("nod");
      command ("say ÕâÊÇ´óÌÆ½«¾ü¸®ÄÚµÄ²ØÊé,¼ÇÔØÁËÇ¹·¨µÄÔËÓÃ£®");
     me->set_temp("putuo/spearbook","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	   if (ob->query("name") == "¡¼ÕÈ·¨¼òÒª¡½")
      {
      command ("nod");
      command ("say ´ËÄËÎÒÄÏº£ÆÕÍÓÊéÔºÖ®Îï£®");
     me->set_temp("putuo/staffbook","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "Ëé²¼Í·")
      {
      command ("hmm");
      command ("say ÕâËé²¼Í·Õ´ÂúÉ±Æø,"+RANK_D->query_respect(me)+ "ÎªºÎÒòÒ»ÉíÍâÖ®Îï´ó¿ªÉ±½ä£¿");
     me->set_temp("putuo/stickbook","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  if (ob->query("name") == "¡¼·çË®¡½")
      {
      command ("nod");
      command ("say ÕâÊÇ¶«º£°¾À´¹úÀÏ¸¾ÈËµÄ¼Ò´«Êé¼®£®");
     me->set_temp("putuo/windwater","done");
      call_out("destroy", 1, ob);
      return 1;
	  }
	  else
      {
      command ("say ÕâÊÇÊ²Ã´£¿");
      call_out("dropthing", 1, thing);
      return 1;
      }
     }
  else
  command ("shake ");
  return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

void dropthing(string thing)
{
  command("drop "+thing);
  return;
}

int begin_go()
{
	object me,ob;
    int dx,dx1,wx,qn;
	me=this_player();
	ob=this_object();
	dx=(me->query("daoxing"))/20;
if (dx>=100000) dx=100000;
	dx1=dx/1000;
	wx=(me->query("combat_exp"))/20;
if (wx>=10000) wx=10000;
	qn=30000;
    
		if (!me->query("fangcun/panlong_visite"))
	return 0;
		if (me->query("guanli/putuo"))
	return 0;

		if (me->query("fangcun/panlong_putuo")=="done")
	{
        message_vision(HIW"\n¹ÛÒôµÀ£º¼ÈÈ»"+RANK_D->query_respect(me)+ "À´Çë,ÎÒÃÇÕâ¾Í¶¯Éí°É£¡\n"NOR,me);
        message_vision(HIY"\n¹ÛÒôÆĞÈøÒÑÈ»¼İÏéÔÆÍùÎ÷±±·½ÏòÈıĞÇ¶´·ÉÈ¥£¡\n"NOR,me);
		ob->move("/d/lingtai/inside1");
        return 1;
	}
   		
		if ((me->query_temp("putuo/basic_blade")=="done") 
			&& (me->query_temp("putuo/basic_unarmed")=="done")
			&& (me->query_temp("putuo/daode")=="done")
			&& (me->query_temp("putuo/forcebook")=="done")
			&& (me->query_temp("putuo/girlbook")=="done")
			&& (me->query_temp("putuo/jianpu")=="done")
			&& (me->query_temp("putuo/jingang")=="done")
			&& (me->query_temp("putuo/misc")=="done")
			&& (me->query_temp("putuo/nowords")=="done")
			&& (me->query_temp("putuo/parry_book")=="done")
			&& (me->query_temp("putuo/qian")=="done")
			&& (me->query_temp("putuo/quanjing")=="done")
			&& (me->query_temp("putuo/san")=="done")
			&& (me->query_temp("putuo/spearbook")=="done")
			&& (me->query_temp("putuo/staffbook")=="done")
			&& (me->query_temp("putuo/stickbook")=="done")
			&& (me->query_temp("putuo/windwater")=="done"))
	{
		me->add("fangcun/panlong_visite",1);
		me->set("fangcun/panlong_putuo","done");
       message("chat",HIC+"¡¼"+HIW+"Î÷ÓÎ¼Ç2006"+HIC+"¡½¹ÛÒôÆĞÈø(Guanyin pusa)£º"+me->query("name")+"ÖúÎÒÊÕÆëÎäÑ§¾«Òª,½ìÊ±Æ¶É®Ò»¶¨ÉÏÁéÌ¨¹ÛÀñ£¡\n"NOR,users());
             message("chat",HIC+"¡¼"+HIW+"Î÷ÓÎ¼Ç2006"+HIC+"¡½¹ÛÒôÆĞÈø(Guanyin pusa)£º"+me->query("name")+"µÃµ½½±Àø£ºµÀĞĞ"+chinese_number(dx1)+"Äê£¬ÎäÑ§"+wx+"µã£¬Ç±ÄÜ30000µã£®\n"NOR,users());
		if (me->query("family/family_name")=="·½´çÉ½ÈıĞÇ¶´")
           message_vision("\n¹ÛÒôÆĞÈøµÀ£º¹ÛÀñÖ®ÈÕ»¹Çë" + RANK_D->query_respect(me) + "ÔÙÀ´¸æÖªÒ»Éù.\n"NOR,me);
		me->add("daoxing",dx);
		me->add("combat_exp",wx);
		me->add("potential",30000);
	    if ((me->query("family/family_name")!="·½´çÉ½ÈıĞÇ¶´")||(me->query("fangcun/panlong_noway")))
			me->set("guanli/putuo",1);
		return 1;
	}				
		if ((me->query("fangcun/panlong_putuo")!="begin")&&(me->query("fangcun/panlong_visite")))
    {
  command("say "+me->query("name")+"À´µÄ²»´ÕÇÉ,ÎÒÕıÎªÊÕ¼¯¶«ÍÁ´óÌÆËùÓĞ»ù±¾ÎäÑ§Êé¼®Ã¦Âµ,ÒªÈ¥ÁéÌ¨¹ÛÀñÖ»ÅÂÃ»ÓĞ¿ÕÏĞ£¡\n");
  command("sigh ");
   me->set("fangcun/panlong_putuo","begin");
	return 1;
	}

  message_vision("\n¹ÛÒôÆĞÈø×ÔÑÔ×ÔÓïµÄËµµÀ£º¾İËµË³·ç¶úÏûÏ¢ÁéÍ¨,ÎÊËû¹ØÓÚÎäÑ§Êé¼®µÄÊÂÇé,ËûÓ¦¸ÃÂÔÓĞËùÖª.\n"NOR,me);
  return 1;
}

ÿ
